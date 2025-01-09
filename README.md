# Simple Shell

## Overview
This project is a basic implementation of a shell program in C. It imitates the behavior of a Unix shell, allowing users to execute commands interactively or through script files.

## Features
- Interactive mode: Displays a prompt (`$`) and waits for user input.
- Non-interactive mode: Executes commands from a script.
- Built-in commands:
  - `exit`: Exits the shell.
  - `env`: Displays the current environment variables.
- Command execution using the system's `PATH`.
- Handles input parsing and memory management.

## Files
### Source Code Files
- `main.c`: Entry point of the program.
- `simple_shell.c`: Contains the core shell loop and command handling logic.
- `help_functions_one.c`: Utility functions for string comparison, word counting, and memory management.
- `help_functions_two.c`: Functions for path searching, command execution, and environment handling.
- `help_functions_three.c`: Additional memory management utilities.

### Header File
- `main.h`: Contains function prototypes, constants, and struct definitions.

## Compilation
To compile the project, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

## Usage
### Interactive Mode
Run the shell without arguments to enter interactive mode:

```bash
./simple_shell
```
You will see a prompt (`$`). Enter commands to execute them.

### Non-Interactive Mode
Provide commands as input through a script or pipe:

```bash
echo "ls -l" | ./simple_shell
```

### Built-in Commands
- `exit`: Type `exit` to terminate the shell.
- `env`: Type `env` to print the current environment variables.

## Example Session
```bash
$ ./simple_shell
$ ls -l
-rw-r--r-- 1 user user 12345 Jan 1 12:34 file.c
$ env
HOME=/home/user
PATH=/usr/bin:/bin
$ exit
```

## Function Descriptions
### Core Functions
- `simple_shell(void)`: Main loop of the shell that handles input, parsing, and command execution.

### Utility Functions
- `str_comparing`: Compares strings for specific commands like `exit`.
- `counting_words`: Counts the words in a sentence.
- `transform_to_array`: Converts a sentence into an array of arguments.
- `_which`: Searches for a command in the `PATH`.
- `_getenv`: Retrieves the value of an environment variable.

## Memory Management
All dynamically allocated memory is properly freed to prevent memory leaks:
- Buffers are freed after processing.
- Argument arrays are deallocated after command execution.

## Error Handling
- Displays appropriate error messages if a command is not found or execution fails.
- Handles invalid input and continues the shell loop.

## Limitations
- Does not handle advanced shell features like piping (`|`) or file redirection (`>`).
- No support for shell scripting or aliases.

## License
This project is open-source and available under the MIT License.

## Authors
Korneel Loy & Luke Holley-Boutillier

## **Flowchart**
![Simple shell flowchart]("C:\Users\lukeh\Downloads\Simple_shell_flow.drawio.png")
