*This project has been created as part of the 42 curriculum by tchijiwa*

# Description
this project is aimed to reimplement the function `printf`. but, the function `ft_printf` need not to malloc the buff size and the number of that specifiers is less than `printf`.

### the functions (ft_printf and so on) explanation
**int ft_printf(const char \*format, ...)**

The function writes the output to the standard output (`stdout`) under the control of a format string that specifies how subsequent arguments are converted for output.

* **Parameters:**
  * `format`: A character string containing ordinary characters and conversion specifications.
  * `...`: A variable number of arguments to be formatted and printed.
* **Return Value:**
  * Returns the **total number of characters printed** (excluding the terminating null byte used to end output to strings).
  * Returns **-1** when not outputting at the function `write` or malloc error.

### Supported Conversions

This implementation handles the following mandatory format specifiers:

| Specifier | Description | Expected Argument Type |
| :---: | :--- | :--- |
| **`%c`** | Prints a single character. | `int` (promoted from `char`) |
| **`%s`** | Prints a string of characters. | `char *` |
| **`%p`** | Prints a pointer address in hexadecimal format. | `void *` |
| **`%d`** | Prints a signed decimal (base 10) number. | `int` |
| **`%i`** | Prints a signed integer (base 10). | `int` |
| **`%u`** | Prints an unsigned decimal (base 10) number. | `unsigned int` |
| **`%x`** | Prints a hexadecimal (base 16) number in lowercase. | `unsigned int` |
| **`%X`** | Prints a hexadecimal (base 16) number in uppercase. | `unsigned int` |
| **`%%`** | Prints a literal percent sign (`%`). | None |

# instruction

all function's file(.c) will be compiled by the flags of `cc -Wall -Wextra -Werror`.
* `make` or `make all`: this compiles functions and make the static library, `libftprintf.a`
* `make clean`: this removes the object files(*.o) organized when compiling.
* `make fclean`: this run the command, `make clean`, and in addition the static library, `libftprintf.a` will be removed.
* `make re`: recompiling command.

# Resources
* man page (glibc) - Used as the primary reference for the specifications and behaviors of standard functions.
* [Qiita](https://qiita.com/) - Used for articles regarding macros for handling variadic functions, the behavior of the `%p` specifier which was unclear in the man page, and to recall the return value of `printf` that I had forgotten.
* Discord - Used as a reference to learn about the pitfalls and important points encountered by senior peers.

## Use of AI
I mainly used AI when I had difficulty understanding the English in the man page regarding the exception handling and detailed usage of `printf`. Additionally, I sought assistance from AI when a tester threw a memory-related error—even though I had finished implementing `ft_printf` and the output was working perfectly—and I could not find the solution despite reviewing the code multiple times.
