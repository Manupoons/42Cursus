/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:25:33 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/30 11:25:34 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_numsize(unsigned int num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_uns_numsize(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_putuns_nbr(unsigned int num)
{
	int		len;
	char	*n;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		n = ft_uitoa(num);
		len += ft_putstr(n);
		free(n);
	}
	return (len);
}
