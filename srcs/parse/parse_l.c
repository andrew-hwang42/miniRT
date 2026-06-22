/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:09 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/22 07:11:33 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_l_token(t_scene *scene, char ***s)
{
	if (!s[0])
		return (scene->light->err = ERR_MALLOC, 1);
	if (ft_strlen(s[0][0]) != 1)
		return (scene->light->err = ERR_IDENTIFIER,
			ft_free_3d(s), 1);
	if (token_count(s[0], 3))
	{
		return (scene->light->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
		printf("here\n");
	}
	return (0);
}

int	parse_l_xyz_pos(t_scene *scene, char ***s)
{
	if (!s[1])
		return (scene->light->err = ERR_MALLOC,
			ft_free_3d(s), 1);
	if (token_count(s[1], 3) || check_comma(s[0][1]))
		return (scene->light->err = ERR_XYZ_POS_TOKEN,
			ft_free_3d(s), 1);
	if (ft_atod(s[1][0]) == ERR_ATOD
		|| ft_atod(s[1][1]) == ERR_ATOD
		|| ft_atod(s[1][2]) == ERR_ATOD)
		return (scene->light->err = ERR_XYZ_POS_VALUE,
			ft_free_3d(s), 1);
	scene->light->xyz_pos.x = ft_atod(s[1][0]);
	scene->light->xyz_pos.y = ft_atod(s[1][1]);
	scene->light->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_l_brightness(t_scene *scene, char ***s)
{
	if (ft_atod(s[0][2]) == ERR_ATOD)
		return (scene->light->err = ERR_BRIGHTNESS_VALUE,
			ft_free_3d(s), 1);
	if (!(0.0 <= ft_atod(s[0][2]) && ft_atod(s[0][2]) <= 1.0))
		return (scene->light->err = ERR_BRIGHTNESS_VALUE,
			ft_free_3d(s), 1);
	scene->light->brightness = ft_atod(s[0][2]);
	return (0);
}

int	parse_l(t_scene *scene, char **line)
{
	char	***s;

	if (scene->light->check)
		return (err_msg("Map error: L: already exists"), 1);
	s = (char ***)ft_calloc(sizeof(char **), 3);
	if (!s)
		return (err_msg("Malloc error"), 1);
	s[0] = ft_split(*line, ' ');
	if (parse_l_token(scene, s))
		return (err_check_l(scene), 1);
	if (!s[0][1])
		return (scene->light->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	s[1] = ft_split(s[0][1], ',');
	if (parse_l_xyz_pos(scene, s) || parse_l_brightness(scene, s))
		return (err_check_l(scene), 1);
	ft_free_3d(s);
	scene->light->rgb.r = 255;
	scene->light->rgb.g = 255;
	scene->light->rgb.b = 255;
	scene->light->check++;
	return (0);
}
