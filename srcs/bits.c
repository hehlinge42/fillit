#include "../libft/includes/libft.h"

void	ft_print_bits(unsigned int n) 
{ 
	unsigned int	i; 
	int				count;

	count = 0;
	i = (1 << 31);
	while (i > 0)
	{
		if (n & i)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (count % 8 == 7)
			ft_putchar(' ');
		i /= 2;
		count++;
	}
	ft_putchar('\n');
}
