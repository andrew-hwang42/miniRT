/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:38:42 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/22 04:57:13 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	err_msg(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_scene	*scene_ori;
	t_mlx	mlx;

	if (argc != 2 || !argv[1])
		return (err_msg("Argument error"), exit(1), 1);
	scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	if (!scene)
		return (err_msg("Malloc error"), exit(1), 1);
	init_scene(scene);
	parse_main(scene, argv);
	scene_ori = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	init_scene_ori(scene_ori, scene);
	if (!scene_ori)
		return (err_msg("Malloc error"), free_scene(scene),
			exit(1), 1);
	execute_main(scene, scene_ori, &mlx);
	free_scene(scene);
	free_scene(scene_ori);
	return (0);
}
