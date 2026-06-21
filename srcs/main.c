/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:38:42 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 19:59:39 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	err_msg(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

int	minirt_start(char **argv)
{
	t_scene	*scene;
	t_scene	*scene_ori;
	t_mlx	mlx;

	scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	if (!scene)
	{
		err_msg("Malloc error");
		exit(1);
	}
	init_scene(scene);
	parse_main(scene, argv);
	scene_ori = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	init_scene_ori(scene_ori, scene);
	if (!scene_ori)
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	execute_main(scene, scene_ori, &mlx);
	free_scene(scene);
	free_scene(scene_ori);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		err_msg("Argument error");
		exit(1);
	}
	else
		minirt_start(argv);
	return (0);
}
