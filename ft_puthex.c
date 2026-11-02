/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhammo <aalhammo@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:16:30 by aalhammo          #+#    #+#             */
/*   Updated: 2026/10/26 20:33:28 by aalhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n, char specifier)
{
	char	*base;
	int		count;

	count = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else if
		(specifier == 'X')
			base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, specifier);
	count += ft_putchr(base[n % 16]);
	return (count);
}
