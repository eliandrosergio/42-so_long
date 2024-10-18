#include "libft.h"

static	void	ft_type_percent(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putnbru(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, len);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, len);
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_type_percent(str[i], args, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
