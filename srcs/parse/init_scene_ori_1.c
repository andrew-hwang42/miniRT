/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_ori_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:14 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:18:27 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_scene_ori_a(t_scene *scene_ori, t_scene *scene)
{
	scene_ori->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	if (!(scene_ori->ambient))
		return (err_msg("Malloc error"),
			free(scene_ori), free_scene(scene),
			exit(1), 1);
	scene_ori->ambient->check = scene->ambient->check;
	scene_ori->ambient->err = scene->ambient->err;
	scene_ori->ambient->lighting = scene->ambient->lighting;
	scene_ori->ambient->rgb = scene->ambient->rgb;
	return (0);
}

int	init_scene_ori_c(t_scene *scene_ori, t_scene *scene)
{
	scene_ori->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	if (!(scene_ori->camera))
		return (err_msg("Malloc error"),
			free(scene_ori->ambient), free(scene_ori),
			free_scene(scene), exit(1), 1);
	scene_ori->camera->check = scene->camera->check;
	scene_ori->camera->err = scene->camera->err;
	scene_ori->camera->xyz_pos = scene->camera->xyz_pos;
	scene_ori->camera->xyz_vec = scene->camera->xyz_vec;
	scene_ori->camera->fov = scene->camera->fov;
	return (0);
}

int	init_scene_ori_l(t_scene *scene_ori, t_scene *scene)
{
	scene_ori->light = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(scene_ori->light))
		return (err_msg("Malloc error"),
			free(scene_ori->ambient), free(scene_ori->camera),
			free(scene_ori), free_scene(scene), exit(1), 1);
	scene_ori->light->check = scene->light->check;
	scene_ori->light->err = scene->light->err;
	scene_ori->light->xyz_pos = scene->light->xyz_pos;
	scene_ori->light->brightness = scene->light->brightness;
	scene_ori->light->rgb = scene->light->rgb;
	return (0);
}

void	init_scene_ori(t_scene *scene_ori, t_scene *scene)
{
	init_scene_ori_a(scene_ori, scene);
	init_scene_ori_c(scene_ori, scene);
	init_scene_ori_l(scene_ori, scene);
	init_scene_ori_sp(scene_ori, scene);
	init_scene_ori_pl(scene_ori, scene);
	init_scene_ori_cy(scene_ori, scene);
}
