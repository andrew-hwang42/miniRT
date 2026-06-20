/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:02:35 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:02:36 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	rotate_y_axis(t_data *data, double v_cos, double v_sin)
{
	rotate_camera_y_axis_set_sp(data, v_cos, v_sin);
	rotate_camera_y_axis_set_pl(data, v_cos, v_sin);
	rotate_camera_y_axis_set_cy(data, v_cos, v_sin);
	rotate_camera_y_axis_set_l(data, v_cos, v_sin);
	rotate_camera_y_axis_set_norm_vec(data, v_cos, v_sin);
}

void	camera_vec_zero_zero_plusone(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	pos;

	v_cos = cos(PI);
	v_sin = sin(PI);
	pos = data->scene->camera->xyz_pos;
	rotate_y_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
}

void	camera_vec_minusone_zero_zero(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	pos;

	v_cos = cos(3 * PI / 2);
	v_sin = sin(3 * PI / 2);
	pos = data->scene->camera->xyz_pos;
	rotate_y_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
}

void	camera_vec_plusone_zero_zero(t_data *data)
{
	double	v_cos;
	double	v_sin;
	t_vec3	pos;

	v_cos = cos(PI / 2);
	v_sin = sin(PI / 2);
	pos = data->scene->camera->xyz_pos;
	rotate_y_axis(data, v_cos, v_sin);
	data->scene->camera->xyz_pos
		= vec3(v_cos * pos.x + 0 * pos.y + v_sin * pos.z,
			0 * pos.x + 1 * pos.y + 0 * pos.z,
			-1 * v_sin * pos.x + 0 * pos.y + v_cos * pos.z);
}

void	set_camera(t_data *data)
{
	t_vec3	cam_vec;

	cam_vec = data->scene_ori->camera->xyz_vec;
	if (cam_vec.x == 0 && cam_vec.y == 0 && cam_vec.z == 1)
		camera_vec_zero_zero_plusone(data);
	if (cam_vec.x == -1 && cam_vec.y == 0 && cam_vec.z == 0)
		camera_vec_minusone_zero_zero(data);
	if (cam_vec.x == 1 && cam_vec.y == 0 && cam_vec.z == 0)
		camera_vec_plusone_zero_zero(data);
	if (cam_vec.x == 0 && cam_vec.y == -1 && cam_vec.z == 0)
		camera_vec_zero_minusone_zero(data);
	if (cam_vec.x == 0 && cam_vec.y == 1 && cam_vec.z == 0)
		camera_vec_zero_plusone_zero(data);
	if (cam_vec.x == 0 && cam_vec.y != 0 && cam_vec.z != 0)
		camera_vec_zero_y_z(data);
	if (cam_vec.x != 0 && cam_vec.y == 0 && cam_vec.z != 0)
		camera_vec_x_zero_z(data);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_scalar(data->scene->camera->xyz_vec, DELTA));
}
