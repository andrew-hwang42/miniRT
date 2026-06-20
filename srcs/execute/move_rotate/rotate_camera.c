#include "../incs/miniRT.h"

void	rotate_camera_x_axis(t_data *data, int flag,
				double v_cos, double v_sin)
{
	t_vec3	vec;
	t_vec3	pos;

	rotate_camera_x_axis_set_sp(data, v_cos, v_sin);
	rotate_camera_x_axis_set_pl(data, v_cos, v_sin);
	rotate_camera_x_axis_set_cy(data, v_cos, v_sin);
	rotate_camera_x_axis_set_l(data, v_cos, v_sin);
	vec = data->scene->camera->xyz_vec;
	data->scene->camera->xyz_vec
		= vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * -1 * v_sin * vec.z,
			0 * vec.x + -1 * v_sin * vec.y + v_cos * vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_scalar(data->scene->camera->xyz_vec, DELTA));
	rotate_camera_x_axis_set_norm_vec(data, v_cos, v_sin);
	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * -1 * v_sin * pos.z,
			0 * pos.x + -1 * v_sin * pos.y + v_cos * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
	raytracing_main(data, flag);
}

void	rotate_camera_y_axis(t_data *data, int flag,
				double v_cos, double v_sin)
{
	t_vec3	vec;
	t_vec3	pos;

	rotate_camera_y_axis_set_sp(data, v_cos, v_sin);
	rotate_camera_y_axis_set_pl(data, v_cos, v_sin);
	rotate_camera_y_axis_set_cy(data, v_cos, v_sin);
	rotate_camera_y_axis_set_l(data, v_cos, v_sin);
	vec = data->scene->camera->xyz_vec;
	data->scene->camera->xyz_vec
		= vec3(v_cos * vec.x + 0 * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * -1 * v_sin * vec.x + 0 * vec.y + v_cos * vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_scalar(data->scene->camera->xyz_vec, DELTA));
	rotate_camera_y_axis_set_norm_vec(data, v_cos, v_sin);
	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * -1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
	raytracing_main(data, flag);
}

void	rotate_camera_z_axis(t_data *data, int flag,
				double v_cos, double v_sin)
{
	t_vec3	vec;
	t_vec3	pos;

	rotate_camera_z_axis_set_sp(data, v_cos, v_sin);
	rotate_camera_z_axis_set_pl(data, v_cos, v_sin);
	rotate_camera_z_axis_set_cy(data, v_cos, v_sin);
	rotate_camera_z_axis_set_l(data, v_cos, v_sin);
	vec = data->scene->camera->xyz_vec;
	data->scene->camera->xyz_vec
		= vec3(v_cos * vec.x + -1 * -1 * v_sin * vec.y + 0 * vec.z,
			-1 * v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_scalar(data->scene->camera->xyz_vec, DELTA));
	rotate_camera_z_axis_set_norm_vec(data, v_cos, v_sin);
	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(v_cos * pos.x + -1 * -1 * v_sin * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
			0 * pos.x + 0 * pos.y + 1 * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
	raytracing_main(data, flag);
}

void	rotate_camera(int key, t_data *data)
{
	double	rad;
	double	v_cos;
	double	v_sin;

	rad = ROTATE_ANGLE * PI / 180;
	v_cos = cos(rad);
	v_sin = sqrt(1 - v_cos * v_cos);
	if (key == KEY_DOWN)
		v_sin *= -1;
	if (data->axis == AXIS_X && (key == KEY_UP || key == KEY_DOWN))
		rotate_camera_x_axis(data, C_ROTATE_X, v_cos, v_sin);
	if (data->axis == AXIS_Y && (key == KEY_UP || key == KEY_DOWN))
		rotate_camera_y_axis(data, C_ROTATE_Y, v_cos, v_sin);
	if (data->axis == AXIS_Z && (key == KEY_UP || key == KEY_DOWN))
		rotate_camera_z_axis(data, C_ROTATE_Z, v_cos, v_sin);
}
