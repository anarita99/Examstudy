int	ft_atoi_base(char *str, int base)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;
	int	val;

	while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9' && (str[i] - 48 < base)) 
		|| ((str[i] >= 'a' && str[i] <= 'f') && (str[i] - 'a' + 10 < base))
		|| ((str[i] >= 'A' && str[i] <= 'F') && (str[i] - 'A' + 10 < base)))
	{
		if(str[i] >= '0' && str[i] <= '9')
			val = str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			val = str[i] - 'a' + 10 ;
		else
			val = str[i] - 'A' + 10;
		result = result * base + val;
		i++;
	}
	return (sign * result);
}
