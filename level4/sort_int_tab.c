/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

#include <unistd.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int	tmp;

	i = 0;
	while(i < size - 1)
	{
		j = 0;
		while(j < size - 1 - i)
		{
			if(tab[i] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void printnb(int nb)
{
	char c;
	if (nb >= 10)
		printnb(nb);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

int	main(void)
{
	int tab[] = {5,7,2,3,8};
	unsigned int size = 6;
	unsigned int i = 0;
	sort_int_tab(tab, size);
	while(i < size)
	{
		printnb(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}