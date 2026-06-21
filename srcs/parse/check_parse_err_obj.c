/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_err_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:21 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:18:21 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	map_err(int i, char *id, char *str)
{
	printf("Error\n");
	printf("Map error: ");
	if ((i % 10) == 1)
		printf("%dst ", i);
	else if ((i % 10) == 2)
		printf("%dnd ", i);
	else if ((i % 10) == 3)
		printf("%drd ", i);
	else
		printf("%dth ", i);
	printf("%s: %s\n", id, str);
}

void	err_check_sp(t_scene *scene, int i)
{
	if (scene->sphere[i]->err)
	{
		if (scene->sphere[i]->err == ERR_MALLOC)
			map_err(i + 1, "sp", "malloc error");
		else if (scene->sphere[i]->err == ERR_IDENTIFIER)
			map_err(i + 1, "sp", "identifier error");
		else if (scene->sphere[i]->err == ERR_LINE_TOKEN)
			map_err(i + 1, "sp", "line token error");
		else if (scene->sphere[i]->err == ERR_XYZ_POS_TOKEN)
			map_err(i + 1, "sp", "xyz position token error");
		else if (scene->sphere[i]->err == ERR_XYZ_POS_VALUE)
			map_err(i + 1, "sp", "xyz position value error");
		else if (scene->sphere[i]->err == ERR_DIAMETER_VALUE)
			map_err(i + 1, "sp", "diameter value error");
		else if (scene->sphere[i]->err == ERR_RGB_TOKEN)
			map_err(i + 1, "sp", "rbg token error");
		else if (scene->sphere[i]->err == ERR_RGB_VALUE)
			map_err(i + 1, "sp", "rgb value error");
	}
}

void	err_check_pl(t_scene *scene, int i)
{
	if (scene->plane[i]->err)
	{
		if (scene->plane[i]->err == ERR_MALLOC)
			map_err(i + 1, "pl", "malloc error");
		else if (scene->plane[i]->err == ERR_IDENTIFIER)
			map_err(i + 1, "pl", "identifier error");
		else if (scene->plane[i]->err == ERR_LINE_TOKEN)
			map_err(i + 1, "pl", "line token error");
		else if (scene->plane[i]->err == ERR_XYZ_POS_TOKEN)
			map_err(i + 1, "pl", "xyz position token error");
		else if (scene->plane[i]->err == ERR_XYZ_POS_VALUE)
			map_err(i + 1, "pl", "xyz position value error");
		else if (scene->plane[i]->err == ERR_XYZ_VEC_TOKEN)
			map_err(i + 1, "pl", "xyz normalized vector token error");
		else if (scene->plane[i]->err == ERR_XYZ_VEC_VALUE)
			map_err(i + 1, "pl", "xyz normalized vector value error");
		else if (scene->plane[i]->err == ERR_RGB_TOKEN)
			map_err(i + 1, "pl", "rbg token error");
		else if (scene->plane[i]->err == ERR_RGB_VALUE)
			map_err(i + 1, "pl", "rgb value error");
	}
}

void	err_check_cy(t_scene *scene, int i)
{
	if (scene->cylinder[i]->err)
	{
		if (scene->cylinder[i]->err == ERR_MALLOC)
			map_err(i + 1, "cy", "malloc error");
		else if (scene->cylinder[i]->err == ERR_IDENTIFIER)
			map_err(i + 1, "cy", "identifier error");
		else if (scene->cylinder[i]->err == ERR_LINE_TOKEN)
			map_err(i + 1, "cy", "line token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_POS_TOKEN)
			map_err(i + 1, "cy", "xyz position token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_POS_VALUE)
			map_err(i + 1, "cy", "xyz position value error");
		else if (scene->cylinder[i]->err == ERR_XYZ_VEC_TOKEN)
			map_err(i + 1, "cy", "xyz normalized vector token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_VEC_VALUE)
			map_err(i + 1, "cy", "xyz normalized vector value error");
		else if (scene->cylinder[i]->err == ERR_DIAMETER_VALUE)
			map_err(i + 1, "cy", "diameter value error");
		else if (scene->cylinder[i]->err == ERR_HEIGHT_VALUE)
			map_err(i + 1, "cy", "height value error");
		else if (scene->cylinder[i]->err == ERR_RGB_TOKEN)
			map_err(i + 1, "cy", "rbg token error");
		else if (scene->cylinder[i]->err == ERR_RGB_VALUE)
			map_err(i + 1, "cy", "rgb value error");
	}
}
