# Matrix Operations Program

This program performs basic matrix operations including **addition**, **multiplication**, and **transpose**. It is a console-based application written in C that prompts the user for input, performs computations, and displays the results.

## Features

- Accepts user-defined matrix sizes and entries
- Dynamically allocates memory for matrices
- Performs the following operations:
  - Matrix A + Matrix A
  - Transpose of Matrix B
  - Matrix B × Transpose of Matrix B
- Displays all matrices and results on screen
- Frees allocated memory before exiting

## How It Works

1. **Input for Matrix A**
   - User is prompted to enter the dimensions and values of Matrix A.
   - Matrix A is dynamically allocated and printed.

2. **Input for Matrix B**
   - User is prompted to enter the dimensions and values of Matrix B.
   - Matrix B is dynamically allocated and printed.

3. **Automatic Operations**
   - Matrix A is added to itself.
   - Matrix B is transposed.
   - The transpose of Matrix B is multiplied by the original Matrix B.
   - All resulting matrices are printed to the screen.

4. **Memory Management**
   - All dynamically allocated memory is freed before the program exits.

## Requirements

- C compiler (e.g., `gcc`)
- Compatible with any OS that supports standard C libraries

## Compilation

```bash
gcc -o matrix_ops matrix_ops.c
```

## Usage

```bash
./matrix_ops
```

Follow the on-screen prompts to enter matrix sizes and values.
