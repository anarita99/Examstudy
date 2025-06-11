/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

# include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size = 0;
	int	i = 0;
	int	*arr;

	if (end > start)
		size = end - start + 1;
	else
		size = start - end;
	arr = malloc(sizeof(int) * size);
	if (end > start)
	{
		while(i < size)
		{
			arr[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		while(i < size)
		{
			arr[i] = end;
			i++;
			end++;
		}
	}
	return(arr);
}

#include <stdio.h>

int	main(void)
{
	int start = 0;
	int	i = 0;
	int end = -3;
	int *arr= ft_rrange(start, end);
	while(i <= 3)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}