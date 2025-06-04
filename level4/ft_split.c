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

char    **ft_split(char *str);
*/

#include <stdlib.h>

int	is_del(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return(0);
}

int	count_words(char *str)
{
	int in_word = 0;
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if (!is_del(str[i]) && in_word == 0)
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

char *word_dup(char *start, int len)
{
	char *word;
	int	i;

	i = 0;
	word = malloc(sizeof(char) * len + 1);
	while(i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}

char **ft_split(char *str)
{
	int words;
	char **res;
	int i = 0;

	words = count_words(str);
	res = malloc((words + 1) * sizeof(char *));
	while(*str)
	{
		while(is_del(*str))
			str++;
		if(*str)
		{
			char *start = str;
			int len = 0;
			while(str[len] && !is_del(str[len]))
				len++;
			res[i] = word_dup(start, len);
			i++;
			str += len;
		}
	}
	res[i] = NULL;
	return(res);
}
#include <stdio.h>

int	main(void)
{
	char s[] = " adasd sadda dda   sdaa";
	int i = 0;
	char **res = ft_split(s);
	while(res[i])
	{
		printf("%s\n",res[i]);
		i++;
	}
}