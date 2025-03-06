/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:53 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/07 19:25:40 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_putnbr(int num);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_line_length(int fd);
int		ft_atoi(const char *nptr);
int		ft_count_c(char *s, char c);
int		ft_printf(char const *s, ...);
int		ft_convert(va_list v1, const char s);
int		ft_count_lines(int fd, int x, int img_w);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_numsize(long num);
size_t	ft_strlen(const char *s);

#endif
