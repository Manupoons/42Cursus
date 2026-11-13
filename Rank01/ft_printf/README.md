# ft_printf

A re-implementation of libc's `printf`, built as `libftprintf.a`.

Supported conversions: `%c %s %p %d %i %u %x %X %%`. No flags, width or precision.

```
make                # builds libftprintf.a
make clean / fclean / re
```

Use it by including `ft_printf.h` and linking with the library. `main.c` is a small test program.
