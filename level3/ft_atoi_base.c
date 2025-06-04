int	ft_atoi_base(char *str, int base)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;
	int	val;

	// Ignorar espaços em branco
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	// Sinal
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Processar apenas dígitos válidos para a base
	while (
		(str[i] >= '0' && str[i] <= '9' && (str[i] - '0' < base)) ||
		(str[i] >= 'a' && str[i] <= 'f' && (str[i] - 'a' + 10 < base)) ||
		(str[i] >= 'A' && str[i] <= 'F' && (str[i] - 'A' + 10 < base))
	)
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			val = str[i] - 'a' + 10;
		else // (str[i] >= 'A' && str[i] <= 'F')
			val = str[i] - 'A' + 10;
		result = result * base + val;
		i++;
	}
	return (sign * result);
}
