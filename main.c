#include "simple_shell.h"


/**
 * get_custom_env - retrieves the value of an environment
 * variable similar to getenv
 * @variable: the name of the environment variable to retrieve
 *
 * Return: A pointer to the value of the environment variable if found,
 * or NULL if not found.
 */
char *get_custom_env(char *variable)
{
	int index = 0;
	char ch1, ch2;
	int count = _strlen(variable);

	for (index = 0; environ[index]; index++)
	{
		char *env_var = environ[index];
		int i;

		for (i = 0; i < count; i++)
		{
			ch1 = env_var[i];
			ch2 = variable[i];

			if (ch1 == '\0' || ch1 != ch2)
				break;
		}

		if (i == count)
			return (&env_var[count]);
	}

	return (NULL);
}

/**
 * find_command_path - Finds the executable path of a command
 * in the system's directories
 * @cmd: Command to find the executable path for
 *
 * Return: The executable path of the command if found, otherwise NULL.
 */
char *find_command_path(char *cmd)
{
	char *path = _strdup(get_custom_env("PATH"));
	char *path_token = _strtok(path, ":");
	char *path_array[100];
	char *command_path = NULL;
	struct stat buf;
	int i = 0, j = 0;

	while (path_token != NULL)
	{
		path_array[i++] = path_token;
		path_token = _strtok(NULL, ":");
	}
	path_array[i] = NULL;

	for (j = 0; path_array[j]; j++)
	{
		size_t len_path_arr = _strlen(path_array[j]), len_cmd = _strlen(cmd);

		command_path = malloc(sizeof(char) * len_path_arr + len_cmd + 2);
		_strcpy(command_path, path_array[j]);
		_strcat(command_path, "/");
		_strcat(command_path, cmd);

		if (stat(command_path, &buf) == 0)
		{
			free(path);
			return (command_path);
		}

		free(command_path);
		command_path = NULL;
	}

	free(path);

	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));

	return (NULL);
}

/**
 * run_command - Executes the specified command
 * @cmd_array: Array containing the command and its arguments
 * @shell_name: Name of the shell
 *
 * Return: 0 on success, 3 if the command is not found.
 */
int run_command(char *cmd_array[], const char *shell_name)
{
	char *executable_path = NULL;
	char *command = NULL;
	pid_t child_pid;
	int status;

	command = cmd_array[0];
	executable_path = find_command_path(command);

	if (executable_path == NULL)
	{
		ft_printf_fd(2, "%s: %s: No such file or directory\n", shell_name, command);
		return (3);
	}

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (child_pid > 0)
		wait(&status);
	else if (child_pid == 0)
	{
		(execve(executable_path, cmd_array, environ));
		perror("Error:");
		exit(1);
	}
	free(executable_path);

	return (0);
}

/**
 * execute_command - Executes the provided command
 * @input: Input string containing the command
 * @read_size: Size of the input string
 * @shell_name: Name of the shell
 *
 * Return: 2 if the command is "exit", otherwise 0.
 */
int execute_command(char *input, size_t __attribute__((unused)) read_size,
		const char *shell_name)
{
	char *token = NULL;
	char *cmd_array[100];
	int i, index;

	if (_strcmp(input, "exit") == 0)
		return (2);
	if (_strcmp(input, "env") == 0)
	{
		for (index = 0; environ[index] != NULL; index++)
		{
			ft_printf_fd(1, "%s\n", environ[index]);
		}

		return (0);
	}

	token = _strtok(input, " ");
	for (i = 0; token; i++)
	{
		cmd_array[i] = token;
		token = _strtok(NULL, " ");
	}
	cmd_array[i] = NULL;

	return (run_command(cmd_array, shell_name));
}

/**
 * main - Entry point of the shell program
 * @argc: The argument count (unused)
 * @argv: Array of input arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t read_size = 0;
	const char *shell_name;

	(void)argc;
	shell_name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			ft_printf_fd(1, "$ ");
		read_size = getline(&input, &buffer_size, stdin);

		if (read_size == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				ft_printf_fd(1, "\n");
			break;
		}

		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0';
		if (*input == '\0')
			continue;
		if (execute_command(input, read_size, shell_name) == 2)
			break;
	}
	free(input);
	input = NULL;

	return (0);
}
