<h1 align="center">
	📄 get_next_line
</h1>

<p align="center">
	<b><i>Read a file line by line, like a pro.</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/TiagoDev88/get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/TiagoDev88/get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/TiagoDev88/get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/TiagoDev88/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/TiagoDev88/get_next_line?color=green" />
</p>

<h3 align="center">
	<a href="#️-about">About</a>
	<span> · </span>
	<a href="#️-usage">Usage</a>
	<span> · </span>
	<a href="#️-example">Example</a>
</h3>

---

## 💡 About

> _get_next_line is a project from 42 that requires reading from a file descriptor line by line, handling any buffer size, and managing memory safely._

It helped me improve skills in:
- File I/O with file descriptors
- Static variables and memory management
- String manipulation
- Buffer handling and edge case management

---

## 🛠️ Usage

### Requirements

- GCC compiler
- Make

### Instructions

**1. Clone the repository**

```bash
git clone https://github.com/TiagoDev88/get_next_line.git
cd get_next_line
```

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
You can change the BUFFER_SIZE to test different behaviors.

## 🧪 Example

```bash
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("example.txt", O_RDONLY);
	char *line;

	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
Compile and run:
``` bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out
```

## 📁 Project files
get_next_line.c

get_next_line_utils.c

get_next_line.h

get_next_line_bonus.c

get_next_line_utils_bonus.c

get_next_line_bonus.h

## ⚠️ Notes
Works with any file descriptor (including stdin and pipes)

Handles files with and without newline at the end

Returns NULL at EOF or on error

One line is returned per call to get_next_line

**👤 Author**
Tiago Filipe

42 login: tfilipe-

GitHub: @TiagoDev88
