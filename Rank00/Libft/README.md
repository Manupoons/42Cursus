# Libft

My own C standard-library subset, built as a static library (`libft.a`) and reused in later projects.

- **Libc re-implementations:** `ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_strlcpy`, `ft_calloc`, ...
- **Extra string/memory helpers:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, ...
- **File-descriptor output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Bonus:** singly linked list functions (`ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`, ...), in the `*_bonus.c` files

```
make          # builds libft.a
make bonus    # adds the list functions
make clean / fclean / re
```

Use it by including `libft.h` and linking with `-L. -lft`.
