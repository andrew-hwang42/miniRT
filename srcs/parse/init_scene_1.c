/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:17 by  beamrane         #+#    #+#             */
/*   Updated: 2026/06/21 18:47:25 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_scene_a(t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	if (!(scene->ambient))
		return (err_msg("Malloc error"),
			free(scene), exit(1), 1);
	return (0);
}

int	init_scene_c(t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	if (!(scene->camera))
		return (err_msg("Malloc error"),
			free(scene->ambient), free(scene),
			exit(1), 1);
	return (0);
}

int	init_scene_l(t_scene *scene)
{
	scene->light = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(scene->light))
		return (err_msg("Malloc error"),
			free(scene->ambient), free(scene->camera),
			free(scene), exit(1), 1);
	return (0);
}

void	init_scene(t_scene *scene)
{
	init_scene_a(scene);
	init_scene_c(scene);
	init_scene_l(scene);
	init_scene_sp(scene, 0);
	init_scene_pl(scene, 0);
	init_scene_cy(scene, 0);
}
