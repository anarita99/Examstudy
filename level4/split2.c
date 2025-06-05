/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:


*/

#include <stdlib.h>

int count_words(char *str)
{
	int	i;
	int in_word = 0;
	int count = 0;
	while(str[i])
	{
		if(!is_del(str[i]) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if(is_del(str[i]))
			in_word = 0;
		i++;
	}
	return(count);
}



char	**ft_split(char *str)
{
	char *arr;
	int words;
	int len = 0;
	int i = 0;

	words = count_words(str);
	arr = malloc(sizeof(char) * (words + 1));
	if(!arr)
		return(NULL);
	while(str)
	{
		while(is_del(*str))
			str++;
		if(*str)
		{
			while(str[len] && !isdel(str[len]))
				len++;
			char *start = str;
			arr[i] = word_dup(start, len);
			i++;
			str += len;
		}
		arr[i] = NULL;
	}
	return(arr);
}