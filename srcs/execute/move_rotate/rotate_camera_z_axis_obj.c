/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera_z_axis_obj.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:01:13 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:01:14 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	rotate_camera_z_axis_set_sp(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;
	int		i;

	i = -1;
	while (++i < data->scene->n_sphere)
	{
		pos = data->scene->sphere[i]->xyz_pos;
		data->scene->sphere[i]->xyz_pos
			= vec3(v_cos * pos.x + -1 * v_sin * pos.y + 0 * pos.z,
				v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
				0 * v_sin * pos.x + 0 * pos.y + 1 * pos.z);
	}
}

void	rotate_camera_z_axis_set_pl(t_data *data,
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
			= vec3(v_cos * pos.x + -1 * v_sin * pos.y + 0 * pos.z,
				v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
				0 * pos.x + 0 * pos.y + 1 * pos.z);
		vec = data->scene->plane[i]->xyz_vec;
		data->scene->plane[i]->xyz_vec
			= vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
				v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
				0 * vec.x + 0 * vec.y + 1 * vec.z);
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_scalar(data->scene->plane[i]->xyz_vec, DELTA));
	}
}

void	rotate_camera_z_axis_set_cy(t_data *data,
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
			= vec3(v_cos * pos.x + -1 * v_sin * pos.y + 0 * pos.z,
				v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
				0 * pos.x + 0 * pos.y + 1 * pos.z);
		vec = data->scene->cylinder[i]->xyz_vec;
		data->scene->cylinder[i]->xyz_vec
			= vec3(v_cos * vec.x + -1 * v_sin * vec.y + 0 * vec.z,
				v_sin * vec.x + v_cos * vec.y + 0 * vec.z,
				0 * vec.x + 0 * vec.y + 1 * vec.z);
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_scalar(data->scene->cylinder[i]->xyz_vec, DELTA));
	}
}

void	rotate_camera_z_axis_set_l(t_data *data,
				double v_cos, double v_sin)
{
	t_vec3	pos;

	pos = data->scene->light->xyz_pos;
	data->scene->light->xyz_pos
		= vec3(v_cos * pos.x + -1 * v_sin * pos.y + 0 * pos.z,
			v_sin * pos.x + v_cos * pos.y + 0 * pos.z,
			0 * pos.x + 0 * pos.y + 1 * pos.z);
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
