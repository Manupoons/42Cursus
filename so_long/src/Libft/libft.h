/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:53 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/03 11:52:20 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd, int x, int img_w);
int		ft_line_length(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);

#endif
