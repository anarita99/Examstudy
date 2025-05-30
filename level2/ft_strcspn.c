/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t j;

	i = 0;
	while(s[i])
	{
		j = 0;
		while(reject[j])
		{
			if (reject[j] == s[i])
				return(i);
			j++;
		}
		i++;
	}
	return(i);
}
#include <stdio.h>
int main()
{
	char *s = "hello";
	const char *reject = "el";
	printf("%zu\n", ft_strcspn(s, reject));
}