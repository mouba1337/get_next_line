# get_next_line

A 42 project implementing a function that reads a file descriptor and returns one line at a time.

## What I learned

* File descriptors
* Static variables
* Dynamic memory management
* Buffer handling
* Reading from files and standard input

The bonus version also supports reading from multiple file descriptors independently.

## Usage

```c
char *get_next_line(int fd);
```

The function returns the next available line from the given file descriptor, including the newline character when present.

## Language

C

