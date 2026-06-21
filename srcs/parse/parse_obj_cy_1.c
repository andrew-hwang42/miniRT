/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_cy_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:05 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:20:20 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_cy_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
		return (scene->cylinder[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	if (ft_strlen(s[0][0]) != 2)
		return (scene->cylinder[i]->err = ERR_IDENTIFIER,
			ft_free_3d(s), 1);
	if (token_count(s[0], 6))
		return (scene->cylinder[i]->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	return (0);
}

int	parse_cy(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_cylinder;
	if (i > 0)
		init_scene_cy(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 5);
	if (!s)
		return (err_msg("Malloc error"), 1);
	s[0] = ft_split(*line, ' ');
	if (parse_cy_token(scene, i, s))
		return (err_check_cy(scene, i), 1);
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][2], ',');
	s[3] = ft_split(s[0][5], ',');
	if (parse_cy_xyz_pos(scene, i, s)
		|| parse_cy_xyz_vec(scene, i, s)
		|| parse_cy_diameter_and_height(scene, i, s)
		|| parse_cy_rgb(scene, i, s))
		return (err_check_cy(scene, i), 1);
	ft_free_3d(s);
	scene->n_cylinder++;
	return (0);
}
