#include "../incs/miniRT.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3	vec3_add_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec3	vec3_sub_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec3	vec3_mul_scalar(t_vec3 v, double n)
{
	t_vec3	res;

	res.x = v.x * n;
	res.y = v.y * n;
	res.z = v.z * n;
	return (res);
}

double	vec3_dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}
