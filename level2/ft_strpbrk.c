/*Função ft_strpbrk(s1, s2:
    Para cada posição i em s1:
        Para cada posição j em s2:
            Se s1[i] for igual a s2[j]:
                Devolver ponteiro para s1[i] (ou índice i, neste pseudocódigo)
    Se nenhum carácter foi encontrado:
        Devolver NULL
*/

#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while(s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if(s1[i] == s2[j])
				return(s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
