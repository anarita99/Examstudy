/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if(!str)
		return(NULL);
	i = 0;
	while(src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}

#include <stdio.h>

int main()
{
	char	*a;
	a = "Hello World";
	printf("%s\n", ft_strdup(a));
}