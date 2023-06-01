# Monty Project - ALX SE Program

This is a project developed as part of [ALX SE Program](https://www.alxafrica.com/). It is an interpreter for Monty Bytecode files. The Monty language is a simple programming language that uses stack and queue data structures for its operations. This project was written in C.

## Interactive Interpreter
(Branch: `interactive-interpreter`)

In the `interactive-interpreter` branch, an interactive mode has been implemented, allowing users to execute Monty instructions directly from the command line without the need for a Monty Bytecode file. This interactive interpreter provides a prompt where users can type Monty instructions and see the results immediately.

[Screencast from 2023-06-01 14-52-10.webm](https://github.com/Ahmedsaed/monty/assets/37080003/fdef1653-6274-4259-b3cf-d03a89ffed7a)

To use the interactive interpreter, follow these steps:

1. Switch to the `interactive-interpreter` branch by running the following command:
```bash
git checkout interactive-interpreter
```

2. Compile and run the program by typing the following command:
```bash
make build run
```

3. The program will display a prompt where you can type Monty instructions. Here's an example:
```bash
$ ./monty
In [1]: push 1
In [2]: push 2
In [3]: pall
2
1
In [4]: add
In [5]: pall
3
```

## Usage

To use the Monty program, follow these steps:

1. Clone the repository from GitHub to your local machine:
```bash
git clone https://github.com/Ahmedsaed/monty.git
```

2. Compile the program by running the following command:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

3. Run the program by typing the following command:
   `./monty file.m`

   Replace `file.m` with the path to the Monty Bytecode file you want to execute.

4. The program will read the instructions from the Monty Bytecode file and execute them accordingly.

## Makefile Usage

We have provided a Makefile that can be used to automate various tasks such as checking the code style, compiling the program, running tests, and more.

To use the Makefile, open a terminal and navigate to the project directory. Then, type `make` followed by the recipe you want to run. Here's a list of the available recipes:

- `all`: This is the default recipe and it checks for code style issues, compiles the program, run unit and integration tests and checks for memory leaks.

- `check_style`: This recipe checks the code style of all C files in the project using the Betty style checker. This requires the `betty-style` and `betty-doc` programs to be installed.

- `build`: This recipe compiles the shell. It generates an executable file called `shell.out`.

- `run_tests`: This recipe runs unit and integration tests on the shell. The integration tests requires `python 3` to be installed

- `check_memory`: This recipe checks for memory leaks and errors using Valgrind. It requires the `Valgrind` program to be installed.

Note that some of the recipes require specific programs to be installed, such as `valgrind`, `betty-style`, and `betty-doc`. If you encounter any errors when running the Makefile, make sure that these programs are installed on your system.

To run a recipe, type `make` followed by the recipe name. For example, to compile the program, type:

```bash
make build
```

This will generate an executable file called monty. To run the program, type:

```bash
make run
```

To run all the recipes, type:

```bash
make [all]
```

where `all` is optional.

## Monty Bytecode Instructions

The Monty language uses a set of instructions that can be used in Monty Bytecode files. Here are some examples of the supported instructions:

| Instruction | Description                                                          |
|-------------|----------------------------------------------------------------------|
| `push <int>`| Pushes an element onto the stack.                                     |
| `pall`      | Prints all the values on the stack.                                   |
| `pint`      | Prints the value at the top of the stack.                             |
| `pop`       | Removes the top element from the stack.                               |
| `swap`      | Swaps the top two elements of the stack.                              |
| `add`       | Adds the top two elements of the stack.                               |
| `sub`       | Subtracts the top element from the second element of the stack.       |
| `mul`       | Multiplies the top two elements of the stack.                         |
| `div`       | Divides the second element by the top element of the stack.           |
| `mod`       | Computes the modulus of the second element by the top element of the stack. |
| `pchar`     | Prints the character value of the top element of the stack.           |
| `pstr`      | Prints the string contained in the stack.                             |
| `rotl`      | Rotates the stack to the top.                                         |
| `rotr`      | Rotates the stack to the bottom.                                      |
| `stack`     | Sets the format of the data to a stack (default behavior).            |
| `queue`     | Sets the format of the data to a queue.                               |

Note: `<int>` represents an integer value.
## Examples

Here are some examples of how to use the Monty program:

- Push values onto the stack and print them:

```bash
$ cat bytecodes/00.m
push 1
push 2
push 3
pall
$ ./monty bytecodes.m
3
2
1
```

- Perform arithmetic operations:

```bash
$ cat bytecodes.m
push 1
push 2
add
push 5
mul
pall
$ ./monty bytecodes.m
10
1
```

- Manipulate the stack::

```bash
$ cat bytecodes.m
push 1
push 2
push 3
swap
pall
$ ./monty bytecodes.m
2
3
1
```

# Authors

This program was developed by [Ahmed Saed](https://www.github.com/Ahmedsaed) as part of the ALX SE Program.
