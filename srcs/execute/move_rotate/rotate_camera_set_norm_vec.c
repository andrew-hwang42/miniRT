#include "../incs/miniRT.h"

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

void	rotate_camera_y_axis_set_norm_vec(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	vec;

	vec = data->x_normal;
	data->x_normal = vec3(v_cos * vec.x + 0 * vec.y + v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * v_sin * vec.x + 0 * vec.y + v_cos * vec.z);
	vec = data->y_normal;
	data->y_normal = vec3(v_cos * vec.x + 0 * vec.y + v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * v_sin * vec.x + 0 * vec.y + v_cos * vec.z);
	vec = data->z_normal;
	data->z_normal = vec3(v_cos * vec.x + 0 * vec.y + v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * vec.x + 0 * vec.y + v_cos * vec.z);
}

void	rotate_camera_z_axis_set_norm_vec(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	vec;

	vec = data->x_normal;
	data->x_normal = vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
			v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
	vec = data->y_normal;
	data->y_normal = vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
			v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
	vec = data->z_normal;
	data->z_normal = vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
			v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
}
