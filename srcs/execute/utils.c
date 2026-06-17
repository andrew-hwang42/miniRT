#include "../incs/miniRT.h"

void	free_obj(t_obj **obj)
{
	int	i;

	i = 0;
	while (obj[i])
		free(obj[i++]);
	free(obj);
}

double	random_double(void)
{
	static int	a;
	double		res;

	a = (a * 123456789123 + 123456) & 0x7fffffff;
	res = ((double)a / (double)0x80000000);
	return (res);
}
