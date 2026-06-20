/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:02:20 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:02:21 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

double	vec3_length(t_vec3 v)
{
	double	res;

	res = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (res);
}

t_vec3	vec3_unit(t_vec3 v)
{
	t_vec3	res;

	res = vec3_mul_scalar(v, (1 / vec3_length(v)));
	return (res);
}
