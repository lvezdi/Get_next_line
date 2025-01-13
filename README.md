<div align="center">
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/bonus-included-success"/>
  	<img src="https://img.shields.io/badge/-125%2F100-success?logo=42&logoColor=fff" />
	<a href="https://github.com/lvezdi/Get_next_line/blob/main/Documentation/README.md" >
   	<img src="https://img.shields.io/badge/Cambiar_Idioma-Español-blue" align="right"></a>
</div>

# Get_next_line
`Get_next_line` is a C function that allows you to read a full line of a given `file descriptor (fd)` and return it as a string. This function is useful for reading `text files` line by line, allowing easier handling of large data.

### Project Goal
The main goal of the project is to create a function that can read and return a complete line from a file each time it is called. This function must properly handle different cases, such as large files, the presence of `newline`, and the need to `temporarily store data` between function calls.

## Functions

- `take_after_new_line`: This function gets the part of the string after the newline and frees the original string.

- `take_until_new_line`: This function takes the part of the string up to the `new_line`.

- `read_until_new_line`: This function `reads` the `file_descriptor` until a new line is found or until the end of the file.

- `get_next_line`: The `main function` that uses the above functions to `return a complete line of the file`.

## How does it work?
Each time `get_next_line` is called, the function reads from the file until it finds a `newline` or reaches the `end of file`. It uses a buffer of size `BUFFER_SIZE` to read blocks of data and looks for the `\n` character to identify the end of each line. The data read is stored temporarily and processed to return a full line each time the function is called.

This approach allows text files to be handled efficiently and avoids memory problems associated with loading large files into memory all at once.
