# <a href="url"><img src="https://cdn3.iconfinder.com/data/icons/egg/500/Egg_food_cracked_whipped-512.png" align="middle" width="100" height="100"></a> simple_shell


## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Description
simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. This shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. 
Standard functions and system calls employed in simple_shell include:
   `access, execve, exit, fork, free, getline, malloc, perror, stat, wait, write.`

## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [main.h](main.h) - program header file
* [builtin.c](builtin.c) - major builtin functions
  * `setenv_cat` - concats name and value about to be set
  * `_setenv` - initializes a new environment variable, or modifies an existing one
  * `_unsetenv` - removes an environment variable
* [shbuilt_in.c](shbuilt_in.c) - helper functions for the builtins
  * `builtin_args` - evaluates built in commands
  * `bui_unsetenv` - unset an env variableenvironment array
  * `bui_exit` - built_in exit
  * `bui_env` - get environment variables
  * `bui_setenv` - set an environmental variable
* [is_getenv.c](is_getenv.c) - functions related to the environment
  * `_getenv` - gets environmental variable
* [getargs.c](getargs.c) - functions related to getting arguments from command line
  * `get_args` - creates an array of pointers to tokens
  * `check_cwd` - checks if command is in current working dir
  * `check_cmd_tty` - checks if command is from terminal and print error message
* [is_getline.c](is_getline.c) - reading line from a stream
  * `_getline` - reads entire line from a stream
* [execute_args.c](execute_args.c) - functions related to executing commands
  * `execute_cmd` - executes a command in the PATH
  * `exec_cmd` -  execute a args that are not directories
  * `check_execute` - checks if the command exist in the PATH
  * `execute` - executes a command in a child process
  * `check_dir` - checks if the command contains an absolute path
* [main.c](main.c) - entry point to the shell
  * `main` - the main function of the program
* [strfunc.c](strfunc.c) - functions related to string manipulation
  * `_strdup` - duplicates a string
  * `_strcmp` - compares two strings
  * `_strcat` - concatenates two strings with a `/` in the middle
  * `_strlen` - calculates the length of a string
  * `_atoi` - converts a string into a non-negative integer
* [is_strtok.c](is_strtok.c) - tokenizing function
  * `_strtok` - creates an array of tokens from a buffer with a specified delimiter

## Requirements

simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

## Installation

   - Clone this repository: `git clone "https://github.com/Theocode12/simple_shell.git"`
   - Change directories into the repository: `cd simple_shell`
   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Or run the shell in non-interactive mode: example `echo "pwd" | ./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [ ] handles **;**
- [ ] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [x] exit
- [x] env
- [x] setenv
- [x] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
$ # This is our rendition of the shell
$ ls -al
total 100
drwxrwxr-x  3 vagrant vagrant  4096 May 18 22:49 .
drwxr-xr-x 14 vagrant vagrant  4096 May 17 22:37 ..
-rw-rw-r--  1 vagrant vagrant   144 May 18 17:16 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2367 May 19 22:33 builtin.c
-rw-rw-r--  1 vagrant vagrant  2764 May 19 22:14 shbuilt_in.c
-rw-rw-r--  1 vagrant vagrant   710 May 16 01:03 execute_args.c
-rw-rw-r--  1 vagrant vagrant  1217 May 16 03:24 getargs.c
drwxrwxr-x  8 vagrant vagrant  4096 May 19 22:34 .git
-rwxrwxr-x  1 vagrant vagrant 32287 May 19 22:34 hsh
-rw-rw-r--  1 vagrant vagrant  1792 May 19 22:12 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   484 May 15 20:09 is_getenv.c
-rw-rw-r--  1 vagrant vagrant  1273 May 18 21:00 is_getline.c
-rw-rw-r--  1 vagrant vagrant  3427 May 19 22:06 is_strtok.c
-rw-rw-r--  1 vagrant vagrant  2347 May 19 22:49 README.md
-rw-rw-r--  1 vagrant vagrant  1769 May 19 22:04 main.h
-rw-rw-r--  1 vagrant vagrant  1480 May 18 21:15 main.c
-rw-rw-r--  1 vagrant vagrant  2111 May 16 01:10 strfunc.c
```
## Bugs
At this time, there are some bugs.

## Authors
 Maduagwu Valentine | [GitHub](https://github.com/Theocode12) | [Twitter](https://twitter.com/Val_blazere)

Yahaya Azeez Adebayo | [GitHub](https://github.com/azconcept-droid) | [Twitter](https://twitter.com/yalecttech)

## License
simple_shell is open source and therefore free to download and use without permission.
