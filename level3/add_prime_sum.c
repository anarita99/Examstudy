/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>

int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while(i < nb)
	{
		if (nb % i == 0)
			return(0);
		i++;
	}
	return(1);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}
	
int ft_atoi(char *str)
{
	int	i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return(sign * result);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int main(int ac, char **av)
{
	int sum = 0;
	if(ac != 2 || ft_atoi(av[1]) <= 0)
	{
		write(1, "0\n", 2);
		return(0);
	}
	else
	{
		int n = ft_atoi(av[1]);
		while(n > 1)
		{
			if(is_prime(n))
				sum += n;
			n--;
		}
		ft_putnbr(sum);
		ft_putchar('\n');
		return(0);
	}
}
