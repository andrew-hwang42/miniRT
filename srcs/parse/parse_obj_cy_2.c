/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_cy_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:03 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 19:59:39 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_cy_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
		return (scene->cylinder[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[1], 3) || check_comma(s[0][1]))
		return (scene->cylinder[i]->err = ERR_XYZ_POS_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[1][0]) == ERR_ATOD
		|| ft_atod(s[1][1]) == ERR_ATOD
		|| ft_atod(s[1][2]) == ERR_ATOD)
		return (scene->cylinder[i]->err = ERR_XYZ_POS_VALUE,
			ft_free_3d(s), 1);
	scene->cylinder[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->cylinder[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->cylinder[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_cy_diameter_and_height(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][3]) == ERR_ATOD)
		return (scene->cylinder[i]->err = ERR_DIAMETER_VALUE,
			ft_free_3d(s), 1);
	if (ft_atod(s[0][3]) <= 0)
		return (scene->cylinder[i]->err = ERR_DIAMETER_VALUE,
			ft_free_3d(s), 1);
	scene->cylinder[i]->diameter = ft_atod(s[0][3]);
	if (ft_atod(s[0][4]) == ERR_ATOD)
		return (scene->cylinder[i]->err = ERR_HEIGHT_VALUE,
			ft_free_3d(s), 1);
	if (ft_atod(s[0][4]) <= 0)
		return (scene->cylinder[i]->err = ERR_HEIGHT_VALUE,
			ft_free_3d(s), 1);
	scene->cylinder[i]->height = ft_atod(s[0][4]);
	return (0);
}

int	parse_cy_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
		return (scene->cylinder[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[2], 3) || check_comma(s[0][2]))
		return (scene->cylinder[i]->err = ERR_XYZ_VEC_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[2][0]) == ERR_ATOD || ft_atod(s[2][1]) == ERR_ATOD
		|| ft_atod(s[2][2]) == ERR_ATOD)
		return (scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE,
			ft_free_3d(s), 1);
	if (!(ft_atod(s[2][0]) * ft_atod(s[2][0])
			+ ft_atod(s[2][1]) * ft_atod(s[2][1])
			+ ft_atod(s[2][2]) * ft_atod(s[2][2]) == 1))
	{
		if (!(ft_atod(s[2][0]) * ft_atod(s[2][0])
				+ ft_atod(s[2][1]) * ft_atod(s[2][1])
				+ ft_atod(s[2][2]) * ft_atod(s[2][2])
				> 1 - EPSILON))
			return (scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE,
				ft_free_3d(s), 1);
	}
	scene->cylinder[i]->xyz_vec.x = ft_atod(s[2][0]);
	scene->cylinder[i]->xyz_vec.y = ft_atod(s[2][1]);
	scene->cylinder[i]->xyz_vec.z = ft_atod(s[2][2]);
	return (0);
}

int	parse_cy_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[3])
		return (scene->cylinder[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[3], 3) || check_comma(s[0][5]))
		return (scene->cylinder[i]->err = ERR_RGB_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atoi(s[3][0]) == ERR_ATOI
		|| ft_atoi(s[3][1]) == ERR_ATOI
		|| ft_atoi(s[3][2]) == ERR_ATOI)
		return (scene->cylinder[i]->err = ERR_RGB_VALUE,
			ft_free_3d(s), 1);
	if (!(0 <= ft_atoi(s[3][0]) && ft_atoi(s[3][0]) <= 255)
		|| !(0 <= ft_atoi(s[3][1]) && ft_atoi(s[3][1]) <= 255)
		|| !(0 <= ft_atoi(s[3][2]) && ft_atoi(s[3][2]) <= 255))
		return (scene->cylinder[i]->err = ERR_RGB_VALUE,
			ft_free_3d(s), 1);
	scene->cylinder[i]->rgb.r = ft_atoi(s[3][0]);
	scene->cylinder[i]->rgb.g = ft_atoi(s[3][1]);
	scene->cylinder[i]->rgb.b = ft_atoi(s[3][2]);
	return (0);
}
