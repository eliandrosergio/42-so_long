/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:13:34 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/18 19:13:35 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_putnbru(unsigned int n, int *len)
{
	if (n > 9)
		ft_putnbru(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}
