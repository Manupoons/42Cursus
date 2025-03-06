/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:35 by mamaratr          #+#    #+#             */
/*   Updated: 2024/09/30 11:41:36 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long num, int caps)
{
	int		len;
	char	base_low;
	char	base_cap;

	len = 0;
	base_low = "0123456789abcdef"[num % 16];
	base_cap = "0123456789ABCDEF"[num % 16];
	if (num >= 16)
		len += ft_puthex(num / 16, caps);
	if (!caps)
		len += ft_putchar(base_low);
	else
		len += ft_putchar(base_cap);
	return (len);
}
