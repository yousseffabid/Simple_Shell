# Simple shell

This projec simulates a basic Unix Shell with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell.

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

![exemple](/shell_draft/assets/shell.png?raw=true "")

## Features

- Iterractive and non interractive mode
- Executing commands
- Adding and removing environement varibles

 
## Flowchart

How our shell is working

![flowchart](/shell_draft/assets/Flowchart.png?raw=true "")

## Authors

- [@yousseffabid](https://github.com/yousseffabid)
- [@Aleph235](https://github.com/Aleph235)
