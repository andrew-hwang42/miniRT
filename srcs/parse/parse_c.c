/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:10 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/22 07:11:35 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_c_token(t_scene *scene, char ***s)
{
	if (!s[0])
		return (scene->camera->err = ERR_MALLOC, 1);
	if (ft_strlen(s[0][0]) != 1)
		return (scene->camera->err = ERR_IDENTIFIER,
			ft_free_3d(s), 1);
	if (token_count(s[0], 4))
		return (scene->camera->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	return (0);
}

int	parse_c_xyz_pos(t_scene *scene, char ***s)
{
	if (!s[1])
		return (scene->camera->err = ERR_MALLOC,
			ft_free_3d(s), 1);
	if (token_count(s[1], 3) || check_comma(s[0][1]))
		return (scene->camera->err = ERR_XYZ_POS_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[1][0]) == ERR_ATOD
		|| ft_atod(s[1][1]) == ERR_ATOD
		|| ft_atod(s[1][2]) == ERR_ATOD)
		return (scene->camera->err = ERR_XYZ_POS_VALUE,
			ft_free_3d(s), 1);
	scene->camera->xyz_pos.x = ft_atod(s[1][0]);
	scene->camera->xyz_pos.y = ft_atod(s[1][1]);
	scene->camera->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	check_value_c_xyz_vec(t_scene *scene, char **xyz_vec)
{
	if (ft_atod(xyz_vec[0]) == ERR_ATOD || ft_atod(xyz_vec[1]) == ERR_ATOD
		|| ft_atod(xyz_vec[2]) == ERR_ATOD)
		return (scene->camera->err = ERR_XYZ_VEC_VALUE, 1);
	if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
			+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
			+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) == 1))
	{
		if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
				+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
				+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) > 1 - EPSILON))
			return (scene->camera->err = ERR_XYZ_VEC_VALUE, 1);
	}
	if (ft_atod(xyz_vec[0]) != 0
		&& ft_atod(xyz_vec[1]) != 0 && ft_atod(xyz_vec[2]) != 0)
		return (scene->camera->err = ERR_XYZ_VEC_VALUE, 1);
	return (0);
}

int	parse_c_xyz_vec_and_fov(t_scene *scene, char ***s)
{
	if (!s[2])
		return (scene->camera->err = ERR_MALLOC,
			ft_free_3d(s), 1);
	if (token_count(s[2], 3) || check_comma(s[0][2]))
		return (scene->camera->err = ERR_XYZ_VEC_TOKEN,
			ft_free_3d(s), 1);
	if (check_value_c_xyz_vec(scene, s[2]))
		return (ft_free_3d(s), 1);
	scene->camera->xyz_vec.x = ft_atod(s[2][0]);
	scene->camera->xyz_vec.y = ft_atod(s[2][1]);
	scene->camera->xyz_vec.z = ft_atod(s[2][2]);
	if (ft_atoi(s[0][3]) == ERR_ATOI)
		return (scene->camera->err = ERR_FOV_VALUE,
			ft_free_3d(s), 1);
	if (!(0 <= ft_atoi(s[0][3]) && ft_atoi(s[0][3]) <= 180))
		return (scene->camera->err = ERR_FOV_VALUE,
			ft_free_3d(s), 1);
	scene->camera->fov = ft_atoi(s[0][3]);
	return (0);
}

int	parse_c(t_scene *scene, char **line)
{
	char	***s;

	if (scene->camera->check)
		return (err_msg("Map error: C: already exists"), 1);
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
		return (err_msg("Malloc error"), 1);
	s[0] = ft_split(*line, ' ');
	if (parse_c_token(scene, s))
		return (err_check_c(scene), 1);
	if (!s[0][1])
		return (scene->camera->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][2], ',');
	if (parse_c_xyz_pos(scene, s)
		|| parse_c_xyz_vec_and_fov(scene, s))
		return (err_check_c(scene), 1);
	ft_free_3d(s);
	scene->camera->check++;
	return (0);
}
