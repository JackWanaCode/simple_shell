# simple_shell

## Simple Shell project for holberton

This is efforts of Jack Tran and Robert Glatzel to create a program that works like Shell.

The Simple Shell is a program to take keyboard commands and pass them to the operating system to carry out.

When the program start, we will see like this:\
user@name$\
Because it is an "imitation" of Shell, it is called shell prompt and ready to receive input.

The Simple Shell will handler command lines with arguments as same as Shell does. Within the scope of project, Simple Shell will handler following commands:\
. ls [OPTION] : List directory contents.

. pwd : print Name of current/working directory.

. cd [PATH]: Change directory.

. exit [STATUS] : Cause normal process termination.

. _setenv [NAME] : Initialize a new environment variable, or modify an existing one.

. -getenv [NAME] : Get an environment variable.

. Handling Ctrl+C: The simple shell will be terminated.

. Handling Ctrl+D: The simple shell will be terminated.

The simple shell will return status value when user want to exit the shell.