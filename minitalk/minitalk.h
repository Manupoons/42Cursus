/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:25:15 by mamaratr          #+#    #+#             */
/*   Updated: 2024/11/27 11:16:56 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(int c);
void	ft_putnbr(int num);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif
