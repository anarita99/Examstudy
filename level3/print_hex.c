/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return(res);
}

void	put_hex(int nb)
{
	char *hex = "0123456789abcdef";
	if(nb >= 16)
		put_hex(nb / 16);
	write(1, &hex[nb % 16], 1);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		int n;
		n = ft_atoi(av[1]);
		put_hex(n);
	}
	write(1, "\n", 1);
	return(0);
}
