#include "../incs/miniRT.h"

void	rotate_camera_x_axis_set_scene_ori(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;

	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(1 * pos.x + 0 * pos.y + 0 * pos.z,
			0 * pos.x + v_cos * pos.y + -1 * -1 * v_sin * pos.z,
			0 * pos.x + -1 * v_sin * pos.y + v_cos * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
}

void	rotate_camera_y_axis_set_scene_ori(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;

	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + -1 * v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * -1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
}

void	rotate_camera_z_axis_set_scene_ori(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;

	pos = data->scene_ori->camera->xyz_pos;
	data->scene_ori->camera->xyz_pos
		= vec3(v_cos * pos.x + -1 * -1 * v_sin * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
			0 * pos.x + 0 * pos.y + 1 * pos.z);
	data->scene_ori->camera->xyz_vec = data->scene->camera->xyz_vec;
}
