#include "../incs/miniRT.h"

int	token_count(char **token, int cnt)
{
	int		i;

	i = 0;
	while (i < cnt)
	{
		if (!token[i])
			return (1);
		i++;
	}
	if (i >= cnt && token[i])
		return (1);
	return (0);
}

int	check_comma(char *str)
{
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	while (str)
	{
		if (*str == ',')
		{
			str++;
			break ;
		}
		str++;
	}
	if (*str == ',')
		return (1);
	while (str)
	{
		if (*str == ',')
		{
			str++;
			break ;
		}
		str++;
	}
	if (*str == ',')
		return (1);
	return (0);
}
