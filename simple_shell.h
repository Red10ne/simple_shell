#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define hex "0123456789abcdef"

extern char **environ;

int ft_printf_fd(int fd, char *format, ...);
int run_command(char *cmd_array[], const char *shell_name);
int _strcmp(const char *str1, const char *str2);

char *get_custom_env(char *variable);
char *find_command_path(char *cmd);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
char *_strpbrk(const char *str, const char *charset);

size_t _strlen(const char *s);

void *_memcpy(void *dest, const void *src, size_t n);


#endif /* SIMPLE_SHELL_H */
