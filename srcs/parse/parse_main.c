/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beamrane <beamrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:39:07 by beamrane          #+#    #+#             */
/*   Updated: 2026/06/21 20:18:41 by beamrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 3)
	{
		err_msg("File extention error");
		return (1);
	}
	if (!(str[len - 3] == '.'
			&& str[len - 2] == 'r'
			&& str[len - 1] == 't'))
	{
		err_msg("File extention error");
		return (1);
	}
	return (0);
}

void	parse_arg(t_scene *scene, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (!fd || fd < 0)
	{
		err_msg("File open error");
		free_scene(scene);
		exit(1);
	}
	if (check_extention(argv))
	{
		free_scene(scene);
		close(fd);
		exit(1);
	}
	close(fd);
}

int	parse_main(t_scene *scene, char **argv)
{
	parse_arg(scene, argv[1]);
	parse_map(scene, argv[1]);
	if (check_parse_error(scene))
	{
		free_scene(scene);
		exit(1);
	}
	return (0);
}
