<p align="center">
    <img src="../Task1_adminLinux/linux_logo.png" width="200" height="150">
</p>

# My Own Printf Implementation

This project contains two custom implementations of print functions in C: `printAli` for strings and a more advanced `printAli` function that mimics the functionality of `printf` using variadic arguments.

## Table of Contents
1. [Overview](#overview)
2. [printAli_str.c - String Only Print Function](#printAli_strc---string-only-print-function)
3. [printAli.c - Custom printf with Variadic Arguments](#printAli.c---custom-printf-with-variadic-arguments)
4. [How it Works](#how-it-works)
5. [Running the Code](#running-the-code)

## Overview

In this project, I created two versions of the `printAli` function. The first is a simpler version that handles string-only printing, while the second implements a custom `printf`-like function capable of printing integers, characters, floating-point numbers, and strings using variadic arguments. Both functions use system calls to write directly to the standard output.

## printAli_str.c - String Only Print Function

The first version of `printAli` focuses on printing a string to the standard output.

### Code Explanation

```c
#include <unistd.h>
#define STD_OUT_FD 1

unsigned long stringLen(char data[])
{
    unsigned long count = 0;
    while (*data != '\0')
    {
        data++;
        count++;
    }
    return count;
}

void printAli(char data[]){
    unsigned long len = stringLen(data);
    write(STD_OUT_FD, data, len);
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        printAli(argv[1]);
    }
    else
    {
        printAli("Error no args provided");
    }
    return 0;
}
```

### How It Works

- **stringLen Function:** This function calculates the length of a string by iterating over each character in the input array until it reaches the null-terminator (`\0`).
- **printAli Function:** This function accepts a string as input, calculates its length using `stringLen`, and then writes the string to the standard output using the `write` system call.
- **write System Call:** The `write` system call is used to output data to a file descriptor. In this case, we use file descriptor `1`, which corresponds to the standard output (`STD_OUT_FD`).
- **Main Function:** It checks if command-line arguments are passed and prints the first argument. If no arguments are provided, it prints an error message.

### Key Points

- **No formatting**: This function only handles plain strings and writes them directly to the output.
- **System Call**: The `write` system call bypasses higher-level functions like `printf` and directly interfaces with the system's output mechanism.

---

## printAli.c - Custom printf with Variadic Arguments

The second version of `printAli` is more sophisticated. It mimics the behavior of the `printf` function by accepting a format string and a variable number of arguments.

### Code Explanation

```c
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define STD_OUT_FD 1
#define BUFFER_SIZE 512

void* memoryCopy(void* dest, void* src, size_t size){
    char* d = (char*) dest;
    char* s = (char*) src;
    while (size--)
    {
        *d++ = *s++;
    }
    return dest;
}

unsigned long stringLen(char data[])
{
    unsigned long count = 0;
    while (*data != '\0')
    {
        data++;
        count++;
    }
    return count;
}

void printAli(char* format, ...)
{
    va_list args;
    va_start(args, format);

    char buffer[BUFFER_SIZE];
    int bufferIndex = 0;

    while (*format != '\0')
    {
        char temp[BUFFER_SIZE / 2];
        int length = 0;

        if (*format == '%')
        {
            switch (*(++format))
            {
                case 'd':
                    int intVal = va_arg(args, int);
                    length = sprintf(temp, "%d", intVal);
                    break;
                case 'c':
                    char charVal = (char)va_arg(args, int);
                    length = sprintf(temp, "%c", charVal);
                    break;
                case 'f':
                    float floatVal = (float)va_arg(args, double);
                    length = sprintf(temp, "%f", floatVal);
                    break;
                case 's':
                    char* stringVal = va_arg(args, char*);
                    length = stringLen(stringVal);
                    memoryCopy(temp, stringVal, length);
                    break;
                default:
                    if (bufferIndex < BUFFER_SIZE - 2) {
                        buffer[bufferIndex++] = '%';
                        buffer[bufferIndex++] = *format;
                    }
                    break;
            }

            if ((bufferIndex + length) < sizeof(buffer))
            {
                memoryCopy(&buffer[bufferIndex], temp, length);
                bufferIndex += length;
            }
        }
        else
        {
            if (bufferIndex < BUFFER_SIZE - 1)
            {
                buffer[bufferIndex++] = *format;
            }
        }
        format++;
    }

    va_end(args);

    write(STD_OUT_FD, buffer, bufferIndex);
}

int main(int argc, char* argv[])
{
    printAli("Integer: %d, Character: %c, Float: %f, String: %s\n", 5, 'A', 3.14, "Hello!");
    return 0;
}
```

### How It Works

- **Variadic Function:** The `printAli` function is a variadic function, which means it can accept a variable number of arguments. It uses the `stdarg.h` library to handle the arguments.
- **`va_list`, `va_start`, `va_arg`, and `va_end`:**
  - `va_list args`: Declares a list of arguments.
  - `va_start(args, format)`: Initializes the `args` list, with `format` being the last fixed argument.
  - `va_arg(args, type)`: Extracts the next argument of the specified type.
  - `va_end(args)`: Cleans up after processing the arguments.
- **Buffer Management:** The function processes the format string character by character. When it encounters a format specifier (`%`), it checks the next character to determine the type of the argument (e.g., `d` for integer, `s` for string, `f` for float).
- **Memory Management:** It uses a custom `memoryCopy` function to copy data into the buffer for output.
- **write System Call:** After processing the format string and arguments, the `write` system call is used to output the contents of the buffer to standard output.

### Key Points

- **Format Specifiers:** The custom `printAli` function supports basic format specifiers: `%d` (integer), `%c` (character), `%f` (floating-point number), and `%s` (string).
- **Handling Different Types:** For each specifier, the appropriate type is extracted from the variadic arguments, and the value is formatted into a temporary buffer.
- **System Call for Output:** As with the first function, the `write` system call is used to output the formatted string to the console.

---

## How it Works

- **String-Only Print (`printAli_str.c`)**: This simple implementation calculates the length of a string and outputs it using the `write` system call.
  
- **Custom `printf` (`printAli.c`)**: This implementation mimics `printf` by using variadic arguments to handle a variety of formats. The function processes the format string, extracts arguments, and builds a result that is written to the standard output.

- **System Calls:** Both implementations make use of the `write` system call, which writes raw data to a file descriptor (standard output, in this case), bypassing the usual buffered I/O mechanisms of the C standard library.

## Running the Code

To run the code:

1. **Compile the Code:**
   - `gcc printAli_str.c -o printAli_str`
   - `gcc printAli.c -o printAli`

2. **Run the Executable:**
   - For `printAli_str.c`: 
     ```
     ./printAli_str HelloWorld
     ```
   - For `printAli.c`:
     ```
     ./printAli "Integer: %d, Character: %c, Float: %f, String: %s" 10 'B' 5.67 "World"
     ```

---

*Ali Mohamed Ali Elmansoury*  
*ITI Embedded Systems - Intake 45*