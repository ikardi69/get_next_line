<h1 align="center">📝 Get Next Line (GNL)</h1>

A C function that reads a line from a file descriptor, handling multiple file descriptors efficiently.

<p align="center">
  <h1>📝 Description</h1>
</p>

`get_next_line` is a function that returns a line read from a file descriptor. When called repeatedly, it allows reading the content of a file line by line until the end is reached.

This implementation includes both the mandatory requirements and bonus features:
- Handles reading from any file descriptor
- Works with standard input
- Manages multiple file descriptors simultaneously using only one static variable
- Compatible with various buffer sizes

<p align="center">
  <h1>🛠️ Function Prototype</h1>
</p>

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- On success: The next line from the file (including the newline character `\n` if present)
- On failure or end of file: `NULL`

<p align="center">
  <h1>🔧 Compilation</h1>
</p>

Compile the function with your program using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> <your_program.c> get_next_line.c get_next_line_utils.c
```

For the bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> <your_program.c> get_next_line_bonus.c get_next_line_utils_bonus.c
```

You can define any buffer size you want by changing `<size>`. If not specified, a default value will be used.

<p align="center">
  <h1>📁 Files</h1>
</p>

### Mandatory Part
- `get_next_line.c`: Contains the main function implementation
- `get_next_line_utils.c`: Contains helper functions
- `get_next_line.h`: Header file with prototypes and necessary includes

### Bonus Part
- `get_next_line_bonus.c`: Bonus implementation handling multiple file descriptors
- `get_next_line_utils_bonus.c`: Bonus helper functions
- `get_next_line_bonus.h`: Bonus header file

<p align="center">
  <h1>⚙️ How It Works</h1>
</p>

1. Allocates a buffer of size `BUFFER_SIZE` to read from the file descriptor
2. Reads into the buffer and stores characters until a newline is found or EOF is reached
3. Returns the line including the newline character (if present)
4. Keeps track of remaining characters for subsequent calls
5. In bonus version: maintains separate reading states for each file descriptor

<p align="center">
  <h1>🚀 Usage Example</h1>
</p>

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line;
    
    // Reading alternately from two files
    line = get_next_line(fd1);
    printf("File 1, line 1: %s", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("File 2, line 1: %s", line);
    free(line);
    
    line = get_next_line(fd1);
    printf("File 1, line 2: %s", line);
    free(line);
    
    close(fd1);
    close(fd2);
    return (0);
}
```

<p align="center">
  <h1>⚠️ Important Notes</h1>
</p>

- Each line returned by `get_next_line` must be freed by the caller
- The function handles files that don't end with a newline character
- Works with any valid file descriptor (regular files, stdin, pipes, etc.)
- Exhibits undefined behavior if the file is modified between calls or when reading binary files


<p align="center">
  <h1>⚠️ Important Notes</h1>
</p>

The implementation has been tested with:
- Various buffer sizes (1, 42, 9999, etc.)
- Multiple file descriptors
- Empty files
- Files without newlines
- Very large files
- Reading from standard input

<p align="center">
  <h1>📜 License</h1>
</p>

This project was completed as part of the curriculum at 42 School.

<p align="center">
  <h1>👤 Author</h1>
</p>

<p align="center">
  <h1>Mouhssine</h1>
</p>

<p align="center">
  <h1>1337 Student</h1>
</p>
