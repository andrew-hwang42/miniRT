/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:02:42 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:02:42 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	set_hit_point(t_data *data, t_hit *hit, double t)
{
	hit->t = t;
	hit->hit_point = vec3_add_vec3(data->ray->point,
			vec3_mul_scalar(data->ray->direc, t));
}

void	set_hit_normal_direc(t_data *data, t_hit *hit)
{
	if (vec3_dot_vec3(data->ray->direc, hit->normal_vec) >= 0)
	{
		hit->front = BACK;
		hit->normal_vec = vec3_mul_scalar(hit->normal_vec, -1);
	}
	hit->front = FRONT;
}

int	is_sphere(t_data *data, double *t, int sp_i, double distance)
{
	t_vec3	rc;
	double	a;
	double	b;
	double	c;

	rc = vec3_sub_vec3(data->obj[sp_i]->xyz_pos, data->ray->point);
	a = vec3_dot_vec3(data->ray->direc, data->ray->direc);
	b = -1 * vec3_dot_vec3(rc, data->ray->direc);
	c = vec3_dot_vec3(rc, rc)
		- (((data->obj[sp_i]->diameter) / 2)
			* ((data->obj[sp_i]->diameter) / 2));
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < EPSILON || distance < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < EPSILON || distance < *t)
			return (1);
	}
	return (0);
}

int	hit_sphere(t_data *data, t_hit *hit, int sp_i, double distance)
{
	double	t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (is_sphere(data, &t, sp_i, distance))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
				data->obj[sp_i]->xyz_pos));
	set_hit_normal_direc(data, hit);
	hit->color = data->obj[sp_i]->rgb;
	return (0);
}

int	light_hit_sp(t_data *data, int sp_i, double distance)
{
	double		t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (is_sphere(data, &t, sp_i, distance))
		return (1);
	return (0);
}
