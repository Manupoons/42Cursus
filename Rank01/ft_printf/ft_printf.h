/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:52:06 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/30 09:52:07 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(char const *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char	*str);
int		ft_convert(va_list v1, const char s);
int		ft_putnbr(int num);
size_t	ft_numsize(long num);
char	*ft_itoa(int n);
int		ft_uns_numsize(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_putuns_nbr(unsigned int num);
int		ft_puthex(unsigned long long num, int caps);
int		ft_putptr(void *ptr);

#endif
