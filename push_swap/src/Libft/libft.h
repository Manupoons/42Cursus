/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:53 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/19 16:29:39 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char *str);
int				ft_isdigit(int c);
int				ft_isspace(char c);
char			**ft_split(char *s, char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_free_split(char **split);

#endif
