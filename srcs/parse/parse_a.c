/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:11 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:18:32 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_a_token(t_scene *scene, char ***s)
{
	if (!s[0])
		return (scene->ambient->err = ERR_MALLOC, 1);
	if (ft_strlen(s[0][0]) != 1)
		return (scene->ambient->err = ERR_IDENTIFIER,
			ft_free_3d(s), 1);
	if (!s[0][1] || token_count(s[0], 3))
		return (scene->ambient->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	return (0);
}

int	parse_a_lighting(t_scene *scene, char ***s)
{
	if (ft_atod(s[0][1]) == ERR_ATOD)
		return (scene->ambient->err = ERR_LIGHTING_VALUE,
			ft_free_3d(s), 1);
	if (!(0.0 <= ft_atod(s[0][1]) && ft_atod(s[0][1]) <= 1.0))
		return (scene->ambient->err = ERR_LIGHTING_VALUE,
			ft_free_3d(s), 1);
	scene->ambient->lighting = ft_atod(s[0][1]);
	return (0);
}

int	check_value_a_rgb(t_scene *scene, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
		return (scene->ambient->err = ERR_RGB_VALUE, 1);
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
		return (scene->ambient->err = ERR_RGB_VALUE, 1);
	return (0);
}

int	parse_a_rgb(t_scene *scene, char ***s)
{
	if (!s[1])
		return (scene->ambient->err = ERR_MALLOC,
			ft_free_3d(s), 1);
	if (token_count(s[1], 3) || check_comma(s[0][2]))
		return (scene->ambient->err = ERR_RGB_TOKEN,
			ft_free_3d(s), 1);
	if (check_value_a_rgb(scene, s[1]))
		return (ft_free_3d(s), 1);
	scene->ambient->rgb.r = ft_atoi(s[1][0]);
	scene->ambient->rgb.g = ft_atoi(s[1][1]);
	scene->ambient->rgb.b = ft_atoi(s[1][2]);
	return (0);
}

int	parse_a(t_scene *scene, char **line)
{
	char	***s;

	if (scene->ambient->check)
		return (err_msg("Map error: A: already exists"), 1);
	s = (char ***)ft_calloc(sizeof(char **), 3);
	if (!s)
		return (err_msg("Malloc error"), 1);
	s[0] = ft_split(*line, ' ');
	if (parse_a_token(scene, s))
		return (err_check_a(scene), 1);
	if (!s[0][1])
		return (scene->ambient->err = ERR_LINE_TOKEN,
			ft_free_3d(s), 1);
	s[1] = ft_split(s[0][2], ',');
	if (parse_a_lighting(scene, s) || parse_a_rgb(scene, s))
		return (err_check_a(scene), 1);
	ft_free_3d(s);
	scene->ambient->check++;
	return (0);
}
