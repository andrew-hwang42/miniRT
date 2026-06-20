/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:01:20 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 23:57:11 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	move_sphere_x_axis(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->x_normal, OBJECT_MOVE));
		flag = SP_MOVE_X_PLUS;
		data->scene_ori->sphere[i]->xyz_pos.x += OBJECT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->x_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_X_MINUS;
		data->scene_ori->sphere[i]->xyz_pos.x -= OBJECT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_sphere_y_axis(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->y_normal, OBJECT_MOVE));
		flag = SP_MOVE_Y_PLUS;
		data->scene_ori->sphere[i]->xyz_pos.y += OBJECT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->y_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_Y_MINUS;
		data->scene_ori->sphere[i]->xyz_pos.y -= OBJECT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_sphere_z_axis(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->z_normal, OBJECT_MOVE));
		flag = SP_MOVE_Z_PLUS;
		data->scene_ori->sphere[i]->xyz_pos.z += OBJECT_MOVE;
		raytracing_main(data, flag);
	}
	if (key == KEY_DOWN)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_scalar(data->z_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_Z_MINUS;
		data->scene_ori->sphere[i]->xyz_pos.z -= OBJECT_MOVE;
		raytracing_main(data, flag);
	}
}

void	move_sphere(int key, t_data *data, int i)
{
	if (data->axis == AXIS_X)
		move_sphere_x_axis(key, data, i);
	if (data->axis == AXIS_Y)
		move_sphere_y_axis(key, data, i);
	if (data->axis == AXIS_Z)
		move_sphere_z_axis(key, data, i);
}
