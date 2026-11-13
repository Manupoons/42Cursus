# get_next_line

A function that reads a file descriptor and returns it **one line per call**, including the trailing `\n` when there is one. It returns `NULL` at end of file or on error.

```c
char *get_next_line(int fd);
```

- Reads in chunks of `BUFFER_SIZE` bytes (default 42). Override it with `-D BUFFER_SIZE=n` at compile time.
- **Bonus** (`*_bonus.c`): keeps separate state per file descriptor, so several files can be read in turn.

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`main.c` is a small test program.
