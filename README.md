# Simple Shell - A Hell of a Shell (In a Shell...) 
 - Jessica Bathel and Yashar Mateen

### simple_shell:
 simple_shell is basically a lite version of the Unix shell command line interpreter
that is used to control the execution of a system. Our shell receives input from the user
 by displaying a prompt and then executes that command. It works in interactive mode by
invoking `./hsh` and also in non-interactive mode by invoking for example `echo "/bin/ls" | ./hsh`

## List of allowed functions and system calls
*       `access` (man 2 access)
*       `chdir` (man 2 chdir)
*       `close` (man 2 close)
*       `closedir` (man 3 closedir)
*       `execve` (man 2 execve)
*       `exit` (man 3 exit)
*       `_exit` (man 2 _exit)
*       `fflush` (man 3 fflush)
*       `fork` (man 2 fork)
*       `free` (man 3 free)
*       `getcwd` (man 3 getcwd)
*       `getline` (man 3 getline)
*       `isatty` (man 3 isatty)
*       `kill` (man 2 kill)
*       `malloc` (man 3 malloc)
*       `open` (man 2 open)
*       `opendir` (man 3 opendir)
*       `perror` (man 3 perror)
*       `read` (man 2 read)
*       `readdir` (man 3 readdir)
*       `signal` (man 2 signal)
*       `stat` (__xstat) (man 2 stat)
*       `lstat` (__lxstat) (man 2 lstat)
*       `fstat` (__fxstat) (man 2 fstat)
*       `strtok` (man 3 strtok)
*       `wait` (man 2 wait)
*       `waitpid` (man 2 waitpid)
*       `wait3` (man 2 wait3)
*       `wait4` (man 2 wait4)
*       `write` (man 2 write)

## Contents
*       AUTHORS
*       conversions.c - 
*       err_handlers.c -
*       man_1_simple_shell - man page for our shell
*       pathfuncs.c - 
*       README.md (this file)
*       shell.c - main file that contains the code for an executable program that works \
like an interactive shell
*       shell.h - header file including all of our libraries, prototypes, and struct def\
initions to be used in our shell.c file
*       signal_control.c - 
*       strops.c - contains functions that handle string operations and manipulations

## Compilation:
 The program is compiled with the following command: 
 `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Usage:
The way to use it in interactive mode is to type the command:
 `./hsh` This will display another shell prompt beginning with `($)` (TBD)