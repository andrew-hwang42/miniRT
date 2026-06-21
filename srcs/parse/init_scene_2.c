/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:16 by  beamrane         #+#    #+#             */
/*   Updated: 2026/06/21 18:47:28 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_scene_sp(t_scene *scene, int i)
{
	if (i == 0)
		scene->sphere = (t_sphere **)ft_calloc(sizeof(t_sphere *), 2);
	if (i > 0)
		scene->sphere = (t_sphere **)ft_realloc(scene->sphere,
				sizeof(t_sphere *) * (i + 1), sizeof(t_sphere *) * (i + 2));
	if (!(scene->sphere))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	scene->sphere[i] = (t_sphere *)ft_calloc(sizeof(t_sphere), 2);
	if (!(scene->sphere[i]))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	return (0);
}

int	init_scene_pl(t_scene *scene, int i)
{
	if (i == 0)
		scene->plane = (t_plane **)ft_calloc(sizeof(t_plane *), 2);
	if (i > 0)
		scene->plane = (t_plane **)ft_realloc(scene->plane,
				sizeof(t_plane *) * (i + 1), sizeof(t_plane *) * (i + 2));
	if (!(scene->plane))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	scene->plane[i] = (t_plane *)ft_calloc(sizeof(t_plane), 2);
	if (!(scene->plane[i]))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	return (0);
}

int	init_scene_cy(t_scene *scene, int i)
{
	if (i == 0)
		scene->cylinder = (t_cylinder **)ft_calloc(sizeof(t_cylinder *), 2);
	if (i > 0)
		scene->cylinder = (t_cylinder **)ft_realloc(scene->cylinder,
				sizeof(t_cylinder *) * (i + 1), sizeof(t_cylinder *) * (i + 2));
	if (!(scene->cylinder))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	scene->cylinder[i] = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 2);
	if (!(scene->cylinder[i]))
		return (err_msg("Malloc error"),
			free_scene(scene), exit(1), 1);
	return (0);
}
