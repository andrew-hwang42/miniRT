#include "../incs/miniRT.h"

void	rotate_x_axis(t_data *data, double v_cos, double v_sin)
{
	rotate_camera_x_axis_set_sp(data, v_cos, v_sin);
	rotate_camera_x_axis_set_pl(data, v_cos, v_sin);
	rotate_camera_x_axis_set_cy(data, v_cos, v_sin);
	rotate_camera_x_axis_set_l(data, v_cos, v_sin);
	rotate_camera_x_axis_set_norm_vec(data, v_cos, v_sin);
}

void	camera_vec_zero_minusone_zero(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	pos;

	v_cos = cos(PI / 2);
	v_sin = sin(PI / 2);
	pos = data->scene->camera->xyz_pos;
	rotate_x_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + v_sin * pos.y + v_cos * pos.z);
}

void	camera_vec_zero_plusone_zero(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	pos;

	v_cos = cos(3 * PI / 2);
	v_sin = sin(3 * PI / 2);
	pos = data->scene->camera->xyz_pos;
	rotate_x_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + v_sin * pos.y + v_cos * pos.z);
}

void	camera_vec_zero_y_z(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	vec;
	t_vec3	pos;

	vec = data->scene->camera->xyz_vec;
	v_cos = cos(vec.y / sqrt(vec.y * vec.y + vec.z * vec.z));
	v_sin = sqrt(1 - v_cos * v_cos);
	if (vec.y < 0 && vec.z > 0)
		v_cos *= -1;
	if (vec.y > 0 && vec.z > 0)
	{
		v_cos *= -1;
		v_sin *= -1;
	}
	if (vec.y > 0 && vec.z < 0)
		v_sin *= -1;
	pos = data->scene->camera->xyz_pos;
	rotate_x_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + v_sin * pos.y + v_cos * pos.z);
}

void	camera_vec_x_zero_z(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	vec;
	t_vec3	pos;

	vec = data->scene->camera->xyz_vec;
	v_cos = cos(vec.z / sqrt(vec.x * vec.x + vec.z * vec.z));
	v_sin = sqrt(1 - v_cos * v_cos);
	if (vec.x > 0 && vec.z > 0)
		v_sin *= -1;
	if (vec.x < 0 && vec.z > 0)
	{
		v_cos *= -1;
		v_sin *= -1;
	}
	if (vec.x < 0 && vec.z < 0)
		v_sin *= -1;
	pos = data->scene->camera->xyz_pos;
	rotate_y_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
}
