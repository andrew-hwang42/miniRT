/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:09:42 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/22 00:51:45 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	key_select_mode_move_rotate_axis(int key, t_data *data)
{
	if (key == KEY_C)
		data->mode = MODE_CAMERA;
	if (key == KEY_L)
		data->mode = MODE_LIGHT;
	if (key == KEY_1)
		data->mode = MODE_SPHERE;
	if (key == KEY_2)
		data->mode = MODE_PLANE;
	if (key == KEY_3)
		data->mode = MODE_CYLINDER;
	if (key == KEY_M)
		data->move_rotate = MOVE;
	if (key == KEY_R)
		data->move_rotate = ROTATE;
	if (key == KEY_X)
		data->axis = AXIS_X;
	if (key == KEY_Y)
		data->axis = AXIS_Y;
	if (key == KEY_Z)
		data->axis = AXIS_Z;
}

void	key_obj_next(int key, t_data *data)
{
	if (key == KEY_F1)
	{
		if (data->sp == data->scene->n_sphere - 1)
			data->sp = 0;
		else
			data->sp++;
		raytracing_main(data, SP_NEXT);
	}
	if (key == KEY_F2)
	{
		if (data->pl == data->scene->n_plane - 1)
			data->pl = 0;
		else
			data->pl++;
		raytracing_main(data, PL_NEXT);
	}
	if (key == KEY_F3)
	{
		if (data->cy == data->scene->n_cylinder - 1)
			data->cy = 0;
		else
			data->cy++;
		raytracing_main(data, CY_NEXT);
	}
}

void	check_move_rotate(int key, t_data *data)
{
	if (data->mode == MODE_CAMERA && data->move_rotate == MOVE)
		move_camera(key, data);
	if (data->mode == MODE_CAMERA && data->move_rotate == ROTATE)
		rotate_camera(key, data);
	if (data->mode == MODE_LIGHT && data->move_rotate == MOVE)
		move_light(key, data);
	if (data->mode == MODE_SPHERE && data->move_rotate == MOVE)
		move_sphere(key, data, data->sp);
	if (data->mode == MODE_PLANE && data->move_rotate == MOVE)
		move_plane(key, data, data->pl);
	if (data->mode == MODE_PLANE && data->move_rotate == ROTATE)
		rotate_plane(key, data, data->pl);
	if (data->mode == MODE_CYLINDER && data->move_rotate == MOVE)
		move_cylinder(key, data, data->cy);
	if (data->mode == MODE_CYLINDER && data->move_rotate == ROTATE)
		rotate_cylinder(key, data, data->cy);
}

void	check_key(int key, t_data *data)
{
	key_select_mode_move_rotate_axis(key, data);
	if (key == KEY_F1 || key == KEY_F2 || key == KEY_F3)
		key_obj_next(key, data);
	if (key == KEY_Q)
	{
		data->mode = 0;
		data->move_rotate = 0;
		data->axis = 0;
		data->sp = 0;
		data->pl = 0;
		data->cy = 0;
		raytracing_main(data, 0);
	}
	if (data->mode != 0)
		check_move_rotate(key, data);
}
