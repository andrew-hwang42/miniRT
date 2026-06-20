#include "../incs/miniRT.h"

void	move_light_x_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->x_normal, LIGHT_MOVE));
		flag = L_MOVE_X_PLUS;
		data->scene_ori->light->xyz_pos.x += LIGHT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->x_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_X_MINUS;
		data->scene_ori->light->xyz_pos.x -= LIGHT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_light_y_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->y_normal, LIGHT_MOVE));
		flag = L_MOVE_Y_PLUS;
		data->scene_ori->light->xyz_pos.y += LIGHT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->y_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Y_MINUS;
		data->scene_ori->light->xyz_pos.y -= LIGHT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_light_z_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->z_normal, LIGHT_MOVE));
		flag = L_MOVE_Z_PLUS;
		data->scene_ori->light->xyz_pos.z += LIGHT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_scalar(data->z_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Z_MINUS;
		data->scene_ori->light->xyz_pos.z -= LIGHT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_light(int key, t_data *data)
{
	if (data->axis == AXIS_X)
		move_light_x_axis(key, data);
	if (data->axis == AXIS_Y)
		move_light_y_axis(key, data);
	if (data->axis == AXIS_Z)
		move_light_z_axis(key, data);
}
