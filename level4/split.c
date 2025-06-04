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

char	**ft_split(char *str);
*/
#include <stdlib.h>

int	is_del(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	return (0);
}
int	count_words(char *str)
{
	int	in_word;
	int	i;
	int	count;

	in_word = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!isdel(str[i]) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_del(str[i]))
			in_word = 0;
		i++;
	}
	return (count);
}
char	*word_dup(char *start, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char	**ft_split(char *str)
{
	int		words;
	char	**res;
	int		i;
	int		len;
	char	*start;

	words = count_words(str);
	res = malloc((words + 1) * sizeof(char *));
	while (*str)
	{
		while (is_del(*str))
			str++;
		if (*str)
		{
			len = 0;
			i = 0;
			while (str[len] && !isdel(str[len]))
				len++;
			start = str;
			res[i] = word_dup(start, len);
			i++;
			str += len;
		}
	}
	res[i] = NULL;
	return (res);
}
int	main(void)
{
	char *str = "Hello sdas sdad ";
	char **res = ft_split(str);
	int i = 0;
	while (res)
	{
		printf("%s\n", res[i]);
		i++;
	}
}