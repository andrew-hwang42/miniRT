/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:01:06 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:01:07 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	rotate_cylinder_x_axis(t_data *data, int flag, int i, int key)
{
	double	rad;
	double	v_cos;
	double	v_sin;
	t_vec3	vec;

	rad = ROTATE_ANGLE * PI / 180;
	v_cos = cos(rad);
	v_sin = sqrt(1 - v_cos * v_cos);
	if (key == KEY_DOWN)
		v_sin *= -1;
	vec = data->scene->cylinder[i]->xyz_vec;
	data->scene->cylinder[i]->xyz_vec
		= vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + v_sin * vec.y + v_cos * vec.z);
	data->scene->cylinder[i]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
			vec3_mul_scalar(data->scene->cylinder[i]->xyz_vec, DELTA));
	vec = data->scene_ori->cylinder[i]->xyz_vec;
	data->scene_ori->cylinder[i]->xyz_vec
		= vec3(1 * vec.x + 0 * vec.y + 0 * vec.z,
			0 * vec.x + v_cos * vec.y + -1 * v_sin * vec.z,
			0 * vec.x + v_sin * vec.y + v_cos * vec.z);
	raytracing_main(data, flag);
}

void	rotate_cylinder_y_axis(t_data *data, int flag, int i, int key)
{
	double	rad;
	double	v_cos;
	double	v_sin;
	t_vec3	vec;

	rad = ROTATE_ANGLE * PI / 180;
	v_cos = cos(rad);
	v_sin = sqrt(1 - v_cos * v_cos);
	if (key == KEY_DOWN)
		v_sin *= -1;
	vec = data->scene->cylinder[i]->xyz_vec;
	data->scene->cylinder[i]->xyz_vec
		= vec3(v_cos * vec.x + 0 * vec.y + v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * v_sin * vec.x + 0 * vec.y + v_cos * vec.z);
	data->scene->cylinder[i]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
			vec3_mul_scalar(data->scene->cylinder[i]->xyz_vec, DELTA));
	vec = data->scene_ori->cylinder[i]->xyz_vec;
	data->scene_ori->cylinder[i]->xyz_vec
		= vec3(v_cos * vec.x + 0 * vec.y + v_sin * vec.z,
			0 * vec.x + 1 * vec.y + 0 * vec.z,
			-1 * v_sin * vec.x + 0 * vec.y + v_cos * vec.z);
	raytracing_main(data, flag);
}

void	rotate_cylinder_z_axis(t_data *data, int flag, int i, int key)
{
	double	rad;
	double	v_cos;
	double	v_sin;
	t_vec3	vec;

	rad = ROTATE_ANGLE * PI / 180;
	v_cos = cos(rad);
	v_sin = sqrt(1 - v_cos * v_cos);
	if (key == KEY_DOWN)
		v_sin *= -1;
	vec = data->scene->cylinder[i]->xyz_vec;
	data->scene->cylinder[i]->xyz_vec
		= vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
			v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
	data->scene->cylinder[i]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
			vec3_mul_scalar(data->scene->cylinder[i]->xyz_vec, DELTA));
	vec = data->scene_ori->cylinder[i]->xyz_vec;
	data->scene_ori->cylinder[i]->xyz_vec
		= vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
			v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
			0 * vec.x + 0 * vec.y + 1 * vec.z);
	raytracing_main(data, flag);
}

void	rotate_cylinder(int key, t_data *data, int i)
{
	if (data->axis == AXIS_X && (key == KEY_UP || key == KEY_DOWN))
		rotate_cylinder_x_axis(data, CY_ROTATE_X, i, key);
	if (data->axis == AXIS_Y && (key == KEY_UP || key == KEY_DOWN))
		rotate_cylinder_y_axis(data, CY_ROTATE_Y, i, key);
	if (data->axis == AXIS_Z && (key == KEY_UP || key == KEY_DOWN))
		rotate_cylinder_z_axis(data, CY_ROTATE_Z, i, key);
}
