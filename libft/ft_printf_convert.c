#include "libft.h"

void	ft_puthex(unsigned int n, int uppercase, int *len)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex(n / 16, uppercase, len);
		ft_putchar(base[n % 16], len);
	}
	else
		ft_putchar(base[n % 16], len);
}

static	void	ft_putptrhex(unsigned long addr, int *len)
{
	if (addr > 15)
		ft_putptrhex(addr / 16, len);
	ft_putchar("0123456789abcdef"[addr % 16], len);
}

void	ft_putptr(void *ptr, int *len)
{
	if (!ptr)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	if ((unsigned long)ptr == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	ft_putptrhex((unsigned long)ptr, len);
}
