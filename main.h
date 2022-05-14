#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFFSIZE 32

void sh_loop(void);
char *eval_str(char *str, char **nxt_ptr, const char *delim);
char *check_str(char *str, const char *delim);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_getenv(char *name);
char **get_args(char *line);
int _strlen(char *s);
char *_strcat(char *src, char *dest);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
int built_in(char **args);
int execute_cmd(char **args);
int check_execute(char **args);
int check_dir(char **args);
void execute(char **args);
int exec_cmd(char **args);
extern char **environ;

#endif
