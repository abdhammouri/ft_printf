*This activity has been created as part of the 42 curriculum by aalhammo.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function.

The main goal of this project is to understand variadic functions in C and learn how formatted output can be handled using a variable number of arguments.

The project produces a static library named:

```text
libftprintf.a
```

The main function prototype is:

```c
int	ft_printf(const char *format, ...);
```

The implementation supports the following conversions:

- `%c` — prints a single character.
- `%s` — prints a string.
- `%p` — prints a pointer address in hexadecimal format.
- `%d` — prints a signed decimal integer.
- `%i` — prints a signed integer in base 10.
- `%u` — prints an unsigned decimal integer.
- `%x` — prints an unsigned integer in lowercase hexadecimal.
- `%X` — prints an unsigned integer in uppercase hexadecimal.
- `%%` — prints a percent sign.

The function returns the total number of printed characters.

## Project Structure

The project is divided into multiple functions so that each function has a clear responsibility.

```text
ft_printf.c
ft_format.c
ft_putchr.c
ft_putstr.c
ft_putnbr.c
ft_putunsigned.c
ft_puthex.c
ft_putptr.c
ft_printf.h
Makefile
README.md
```

`ft_printf.c` contains the main parsing logic.

`ft_format.c` acts as a dispatcher and decides which helper function should handle each format specifier.

The remaining files contain helper functions used to print characters, strings, signed numbers, unsigned numbers, hexadecimal values, and pointers.

## Algorithm

The main `ft_printf()` function reads the format string one character at a time.

If the current character is not `%`, it is written directly to standard output.

If `%` is found, the function moves to the next character and sends the format specifier to `ft_format()`.

`ft_format()` then retrieves the correct argument using `va_arg()` and calls the appropriate helper function.

The general flow is:

```text
format string
     |
     v
read character
     |
     +-- normal character --> write()
     |
     +-- '%' --> read specifier
                    |
                    v
                ft_format()
                    |
        +-----------+-----------+
        |           |           |
      string      number      pointer
```

Each helper function returns the number of characters it printed.

`ft_printf()` adds these values to a counter and finally returns the total number of printed characters.

## Variadic Arguments

The project uses the variadic argument tools provided by `<stdarg.h>`:

```c
va_list
va_start
va_arg
va_end
```

`va_start()` initializes access to the variable arguments.

`va_arg()` retrieves the next argument using the type expected by the current format specifier.

For example:

```text
%c -> int
%s -> char *
%d -> int
%i -> int
%u -> unsigned int
%x -> unsigned int
%X -> unsigned int
%p -> void *
```

`%c` is retrieved as an `int` because of the default argument promotions applied to variadic arguments.

## Number Conversion

Signed and unsigned decimal numbers are printed recursively.

For example, when printing:

```text
42
```

the number is divided by 10:

```text
42 / 10 = 4
42 % 10 = 2
```

The function first prints the higher-order digits and then prints the final digit.

For signed integers, a `long` variable is used internally so that the minimum integer value can be handled safely.

Hexadecimal conversion works with the same recursive idea, but uses base 16 instead of base 10.

For lowercase hexadecimal:

```text
0123456789abcdef
```

For uppercase hexadecimal:

```text
0123456789ABCDEF
```

For example:

```text
26 decimal = 1a hexadecimal
```

## Pointer Handling

The `%p` conversion receives a `void *`.

The pointer value is converted to an `unsigned long` and printed in lowercase hexadecimal format with the `0x` prefix.

A null pointer is handled by printing:

```text
(nil)
```

## NULL Handling

For `%s`, if the string pointer is `NULL`, the function prints:

```text
(null)
```

For `%p`, if the pointer is `NULL`, the function prints:

```text
(nil)
```

If the format string itself is `NULL`, this implementation returns `-1`.

## Compilation

Compile the library using:

```bash
make
```

The Makefile uses:

```text
cc -Wall -Wextra -Werror
```

and creates the static library using:

```text
ar rcs
```

The generated library is:

```text
libftprintf.a
```

Available Makefile rules:

```bash
make
make all
make clean
make fclean
make re
```

`make clean` removes object files.

`make fclean` removes object files and `libftprintf.a`.

`make re` performs a complete rebuild.

## Usage

Include the project header:

```c
#include "ft_printf.h"
```

Example:

```c
int	main(void)
{
	ft_printf("Hello %s\n", "42");
	ft_printf("Number: %d\n", -42);
	ft_printf("Unsigned: %u\n", 42u);
	ft_printf("Hex: %x\n", 255u);
	ft_printf("Pointer: %p\n", (void *)0);
	return (0);
}
```

Compile a test program with:

```bash
cc main.c libftprintf.a -o test
```

Then run:

```bash
./test
```

## Testing

The implementation was tested by comparing its output and return value with the original `printf()`.

Important cases included:

```text
%c
%s
%p
%d
%i
%u
%x
%X
%%
NULL strings
NULL pointers
INT_MIN
INT_MAX
UINT_MAX
zero
negative values
mixed conversions
```

The Makefile was also tested to ensure that running `make` again without changing source files does not unnecessarily relink the library.

## Resources

Resources used during this project:

- The official 42 `ft_printf` subject.
- C documentation for variadic functions and `<stdarg.h>`.
- C documentation for `write()`.
- Concepts previously learned in the Libft project.
- Peer discussion and testing.

### AI Usage

AI was used as a learning and debugging tool during the project.

It was used to:

- explain variadic functions;
- explain `va_list`, `va_start`, `va_arg`, and `va_end`;
- review signed and unsigned integers;
- explain decimal and hexadecimal conversion;
- explain pointers and memory addresses;
- discuss calling conventions, CPU registers, stack usage, and ABI concepts;
- identify compiler and Makefile errors;
- suggest edge cases for testing;
- review project structure;
- assist in drafting this README.

The project was developed progressively, with the goal of understanding each function and concept before adding it to the implementation.
