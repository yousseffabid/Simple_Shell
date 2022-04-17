# Simple shell

This project simulates a basic Unix Shell with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell.
It is a project of the first semester at Holberton School.

## Documentation

[Linux manual](https://www.man7.org/linux/man-pages/man1/man.1.html)


## Deployment

To deploy this project run

```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c shell.h -o hsh
  ./hsh
```


## Usage

After executing the program you will be able to try the following and more:

![exemple](/assets/shell.png?raw=true "")

## Features

- Iterractive and non interractive mode
- Can handle commands with options and arguments
- Exit built-in, it exits the shell with a status
- Ctrl+C signal handeled: the shell will not quit when the user inputs ^C it quits when you type ^D.
- Adding and removing environement varibles
- Changing directory with the builtin command cd
- If executable is not found, prints an error message and displays prompt again


## Flowchart

How our shell is working

![flowchart](/assets/Flowchart.jpg)

## Authors

- [@yousseffabid](https://github.com/yousseffabid)
- [@Aleph235](https://github.com/Aleph235)
