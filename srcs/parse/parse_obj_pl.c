/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:02 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/22 07:11:22 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_pl_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
		return (scene->plane[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (ft_strlen(s[0][0]) != 2)
		return (scene->plane[i]->err = ERR_IDENTIFIER,
			ft_free_3d(s), 1);
	if (token_count(s[0], 4))
		return (scene->plane[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	return (0);
}

int	parse_pl_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
		return (scene->plane[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[1], 3) || check_comma(s[0][1]))
		return (scene->plane[i]->err = ERR_XYZ_POS_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[1][0]) == ERR_ATOD
		|| ft_atod(s[1][1]) == ERR_ATOD
		|| ft_atod(s[1][2]) == ERR_ATOD)
		return (scene->plane[i]->err = ERR_XYZ_POS_VALUE,
			ft_free_3d(s), 1);
	scene->plane[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->plane[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->plane[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_pl_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
		return (scene->plane[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[2], 3) || check_comma(s[0][2]))
		return (scene->plane[i]->err = ERR_XYZ_VEC_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[2][0]) == ERR_ATOD || ft_atod(s[2][1]) == ERR_ATOD
		|| ft_atod(s[2][2]) == ERR_ATOD)
		return (scene->plane[i]->err = ERR_XYZ_VEC_VALUE,
			ft_free_3d(s), 1);
	if (!(ft_atod(s[2][0]) * ft_atod(s[2][0])
			+ ft_atod(s[2][1]) * ft_atod(s[2][1])
			+ ft_atod(s[2][2]) * ft_atod(s[2][2]) == 1))
	{
		if (!(ft_atod(s[2][0]) * ft_atod(s[2][0])
				+ ft_atod(s[2][1]) * ft_atod(s[2][1])
				+ ft_atod(s[2][2]) * ft_atod(s[2][2])
				> 1 - EPSILON))
			return (scene->plane[i]->err = ERR_XYZ_VEC_VALUE,
				ft_free_3d(s), 1);
	}
	scene->plane[i]->xyz_vec.x = ft_atod(s[2][0]);
	scene->plane[i]->xyz_vec.y = ft_atod(s[2][1]);
	scene->plane[i]->xyz_vec.z = ft_atod(s[2][2]);
	return (0);
}

int	parse_pl_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[3])
		return (scene->plane[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (token_count(s[3], 3) || check_comma(s[0][3]))
		return (scene->plane[i]->err = ERR_RGB_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atoi(s[3][0]) == ERR_ATOI
		|| ft_atoi(s[3][1]) == ERR_ATOI
		|| ft_atoi(s[3][2]) == ERR_ATOI)
		return (scene->plane[i]->err = ERR_RGB_VALUE,
			ft_free_3d(s), 1);
	if (!(0 <= ft_atoi(s[3][0]) && ft_atoi(s[3][0]) <= 255)
		|| !(0 <= ft_atoi(s[3][1]) && ft_atoi(s[3][1]) <= 255)
		|| !(0 <= ft_atoi(s[3][2]) && ft_atoi(s[3][2]) <= 255))
		return (scene->plane[i]->err = ERR_RGB_VALUE,
			ft_free_3d(s), 1);
	scene->plane[i]->rgb.r = ft_atoi(s[3][0]);
	scene->plane[i]->rgb.g = ft_atoi(s[3][1]);
	scene->plane[i]->rgb.b = ft_atoi(s[3][2]);
	return (0);
}

int	parse_pl(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_plane;
	if (i > 0)
		init_scene_pl(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 5);
	if (!s)
		return (err_msg("Malloc error"), 1);
	s[0] = ft_split(*line, ' ');
	if (parse_pl_token(scene, i, s))
		return (err_check_pl(scene, i), 1);
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][2], ',');
	s[3] = ft_split(s[0][3], ',');
	if (parse_pl_xyz_pos(scene, i, s)
		|| parse_pl_xyz_vec(scene, i, s)
		|| parse_pl_rgb(scene, i, s))
		return (err_check_pl(scene, i), 1);
	ft_free_3d(s);
	scene->n_plane++;
	return (0);
}
