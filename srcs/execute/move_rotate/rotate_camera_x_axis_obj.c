#include "../incs/miniRT.h"

void	rotate_camera_x_axis_set_sp(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;
	int		i;

	i = -1;
	while (++i < data->scene->n_sphere)
	{
		pos = data->scene->sphere[i]->xyz_pos;
		data->scene->sphere[i]->xyz_pos
			= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
				0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
				0 * pos.x + v_sin * pos.y + v_cos * pos.z);
	}
}

void	rotate_camera_x_axis_set_pl(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;
	t_vec3	vec;
	int		i;

	i = -1;
	while (++i < data->scene->n_plane)
	{
		pos = data->scene->plane[i]->xyz_pos;
		data->scene->plane[i]->xyz_pos
			= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
				0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
				0 * pos.x + v_sin * pos.y + v_cos * pos.z);
		vec = data->scene->plane[i]->xyz_vec;
		data->scene->plane[i]->xyz_vec
			= vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
				0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
				0 * vec.x + v_sin * vec.y + v_cos * vec.z);
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_scalar(data->scene->plane[i]->xyz_vec, DELTA));
	}
}

void	rotate_camera_x_axis_set_cy(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;
	t_vec3	vec;
	int		i;

	i = -1;
	while (++i < data->scene->n_cylinder)
	{
		pos = data->scene->cylinder[i]->xyz_pos;
		data->scene->cylinder[i]->xyz_pos
			= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
				0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
				0 * pos.x + v_sin * pos.y + v_cos * pos.z);
		vec = data->scene->cylinder[i]->xyz_vec;
		data->scene->cylinder[i]->xyz_vec
			= vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
				0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
				0 * vec.x + v_sin * vec.y + v_cos * vec.z);
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_scalar(data->scene->cylinder[i]->xyz_vec, DELTA));
	}
}

void	rotate_camera_x_axis_set_l(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;

	pos = data->scene->light->xyz_pos;
	data->scene->light->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + v_sin * pos.y + v_cos * pos.z);
}

void	rotate_camera_x_axis_set_norm_vec(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	vec;

	vec = data->x_normal;
	data->x_normal = vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + v_sin * vec.y + v_cos * vec.z);
	vec = data->y_normal;
	data->y_normal = vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + v_sin * vec.y + v_cos * vec.z);
	vec = data->z_normal;
	data->z_normal = vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + v_sin * vec.y + v_cos * vec.z);
}
