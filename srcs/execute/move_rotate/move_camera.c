/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:01:30 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:01:31 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	move_camera_x_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(CAMERA_MOVE, 0, 0));
		flag = C_MOVE_X_PLUS;
		data->scene_ori->camera->xyz_pos.x += CAMERA_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(-1 * CAMERA_MOVE, 0, 0));
		flag = C_MOVE_X_MINUS;
		data->scene_ori->camera->xyz_pos.x -= CAMERA_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_camera_y_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, CAMERA_MOVE, 0));
		flag = C_MOVE_Y_PLUS;
		data->scene_ori->camera->xyz_pos.y += CAMERA_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, -1 * CAMERA_MOVE, 0));
		flag = C_MOVE_Y_MINUS;
		data->scene_ori->camera->xyz_pos.y -= CAMERA_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_camera_z_axis(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, CAMERA_MOVE));
		flag = C_MOVE_Z_PLUS;
		data->scene_ori->camera->xyz_pos.z += CAMERA_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, -1 * CAMERA_MOVE));
		flag = C_MOVE_Z_MINUS;
		data->scene_ori->camera->xyz_pos.z -= CAMERA_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_camera(int key, t_data *data)
{
	if (data->axis == AXIS_X)
		move_camera_x_axis(key, data);
	if (data->axis == AXIS_Y)
		move_camera_y_axis(key, data);
	if (data->axis == AXIS_Z)
		move_camera_z_axis(key, data);
}
