/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

*/

#include <stdlib.h>

int	count_len(long nb)
{
	int	count = 0;	
	if (nb < 0)
		count++;	
	if(nb == 0)
		count = 1;
	while(nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char *numstr;
	int numlen;
	long n;

	n = (long)nbr;
	numlen = count_len(nbr);
	numstr = malloc(sizeof(char) * (numlen + 1));
	if(n < 0)
	{
		numstr[0] = '-';
		n = -n;
	}
	else if(n == 0)
	{
		numstr[0] = '0';
	}
	numstr[numlen] = '\0';
	while(n != 0)
	{
		numstr[--numlen] = (n % 10) + 48;
		n = n / 10;
	}
	return(numstr);
}
#include <stdio.h>

int main(void)
{
	int n = -147;
	printf("%s\n", ft_itoa(n));
}
