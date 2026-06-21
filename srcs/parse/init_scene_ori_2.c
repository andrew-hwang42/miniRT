/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_ori_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:12 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:18:28 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_scene_ori_sp(t_scene *scene_ori, t_scene *scene)
{
	int	i;

	i = -1;
	scene_ori->sphere = (t_sphere **)ft_calloc(sizeof(t_sphere *),
			scene->n_sphere + 1);
	if (!(scene_ori->sphere))
		return (err_msg("Malloc error"), free_scene(scene_ori),
			free_scene(scene), exit(1), 1);
	while (++i < scene->n_sphere)
	{
		scene_ori->sphere[i] = (t_sphere *)ft_calloc(sizeof(t_sphere), 2);
		if (!(scene_ori->sphere[i]))
			return (err_msg("Malloc error"), free_scene(scene_ori),
				free_scene(scene), exit(1), 1);
	}
	i = -1;
	while (++i < scene->n_sphere)
	{
		scene_ori->sphere[i]->err = scene->sphere[i]->err;
		scene_ori->sphere[i]->xyz_pos = scene->sphere[i]->xyz_pos;
		scene_ori->sphere[i]->diameter = scene->sphere[i]->diameter;
		scene_ori->sphere[i]->rgb = scene->sphere[i]->rgb;
	}
	return (0);
}

int	init_scene_ori_pl(t_scene *scene_ori, t_scene *scene)
{
	int	i;

	i = -1;
	scene_ori->plane = (t_plane **)ft_calloc(sizeof(t_plane *),
			scene->n_plane + 1);
	if (!(scene_ori->plane))
		return (err_msg("Malloc error"), free_scene(scene_ori),
			free_scene(scene), exit(1), 1);
	while (++i < scene->n_plane)
	{
		scene_ori->plane[i] = (t_plane *)ft_calloc(sizeof(t_plane), 2);
		if (!(scene_ori->plane[i]))
			return (err_msg("Malloc error"), free_scene(scene_ori),
				free_scene(scene), exit(1), 1);
	}
	i = -1;
	while (++i < scene->n_plane)
	{
		scene_ori->plane[i]->err = scene->plane[i]->err;
		scene_ori->plane[i]->xyz_pos = scene->plane[i]->xyz_pos;
		scene_ori->plane[i]->xyz_vec = scene->plane[i]->xyz_vec;
		scene_ori->plane[i]->rgb = scene->plane[i]->rgb;
	}
	return (0);
}

void	put_value_scene_ori_cy(t_scene *scene_ori, t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->n_cylinder)
	{
		scene_ori->cylinder[i]->err = scene->cylinder[i]->err;
		scene_ori->cylinder[i]->xyz_pos = scene->cylinder[i]->xyz_pos;
		scene_ori->cylinder[i]->xyz_vec = scene->cylinder[i]->xyz_vec;
		scene_ori->cylinder[i]->diameter = scene->cylinder[i]->diameter;
		scene_ori->cylinder[i]->height = scene->cylinder[i]->height;
		scene_ori->cylinder[i]->rgb = scene->cylinder[i]->rgb;
	}
}

int	init_scene_ori_cy(t_scene *scene_ori, t_scene *scene)
{
	int	i;

	i = -1;
	scene_ori->cylinder = (t_cylinder **)ft_calloc(sizeof(t_cylinder *),
			scene->n_cylinder + 1);
	if (!(scene_ori->cylinder))
		return (err_msg("Malloc error"), free_scene(scene_ori),
			free_scene(scene), exit(1), 1);
	while (++i < scene->n_cylinder)
	{
		scene_ori->cylinder[i]
			= (t_cylinder *)ft_calloc(sizeof(t_cylinder), 2);
		if (!(scene_ori->cylinder[i]))
			return (err_msg("Malloc error"), free_scene(scene_ori),
				free_scene(scene), exit(1), 1);
	}
	put_value_scene_ori_cy(scene_ori, scene);
	return (0);
}
