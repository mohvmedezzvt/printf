# Printf - Custom Implementation of the C `printf` Function

## Description
This project is a custom implementation of the C `printf` function, designed to handle various format specifiers, including integers, characters, strings, and hexadecimal numbers. Additionally, it includes custom specifiers for binary and ROT13 encoding.

## Files

- `0_funcs.c`: Contains functions to handle the format specifiers `%c`, `%s`, `%`, `%d`, `%i`, and `%b`.
- `1_funcs.c`: Contains functions to handle the format specifiers `%u`, `%o`, `%x`, `%X`, and `%p`.
- `2_funcs.c`: Contains functions to handle the format specifiers `%S`, `auxiliary functions for %X`, `%r`, and `%R`.
- `main.h`: Header file containing function prototypes and the `format_t` struct definition.
- `_printf.c`: The main function `_printf` that mimics the standard `printf` function, iterating through the format string and calling appropriate handler functions.

## Usage
To compile and use the custom `_printf` function, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/mohvmedezzvt/printf.git
   ```

2. Navigate to the project directory:
   ```bash
   cd printf
   ```

3. Compile the source files:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o printf
   ```

4. Include the main.h header file in your code and use the `_printf` function as follows:
   ```c
   #include "main.h"

   int main(void)
   {
       _printf("Character: %c\n", 'H');
       _printf("String: %s\n", "Hello, World!");
       _printf("Integer: %d\n", 123);
       _printf("Binary: %b\n", 5);
       _printf("Hexadecimal: %x\n", 255);
       _printf("ROT13: %R\n", "Hello, World!");

       return 0;
   }
   ```

Feel free to contribute to this project by forking the repository and submitting pull requests. Your contributions are welcome!
