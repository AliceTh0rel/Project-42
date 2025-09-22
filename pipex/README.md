# pipex

This project is a custom implementation that reproduces shell behavior with pipes and redirections.


## Objectives

- Reproduce < infile cmd1 | cmd2 > outfile

- Learn to use fork, execve, pipe, and dup2

- Understand file descriptors and process management


## Supported features

- Execution of two commands connected by a pipe

- Input redirection from infile

- Output redirection to outfile

- Command search in the system PATH

- Error handling for missing files or invalid commands


## Usage

make
./pipex infile "cmd1" "cmd2" outfile
