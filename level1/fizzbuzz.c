/*

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>

*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
	

void	ft_putnbr(long nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb < 0)
	{
		nb = - nb;
		ft_putchar('-');
	}
	ft_putchar(nb % 10 + 48);
}
int main(void)
{
	int nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 != 0)
			write(1, "fizz", 4);
		else if (nb % 3 != 0 && nb % 5 == 0)
			write(1, "buzz", 4);
		else if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else
		{
			ft_putnbr(nb);
		}
		write(1, "\n", 1);
		nb++;
	}
}