/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:02:24 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/21 00:27:39 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	mlx_init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr,
			WIN_W, WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H, "miniRT");
	if ((!mlx->win))
		return (1);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W,
			WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	if (!(mlx->img_ptr))
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!(mlx->addr))
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	mlx_exit(t_data *data)
{
	if (data->mlx->img_ptr)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img_ptr);
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	if (data->mlx->win)
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	if (data->mlx->mlx_ptr)
	{
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
	}
	free_obj(data->obj);
	free_scene(data->scene_ori);
	free_scene(data->scene);
	exit (0);
}

int	mlx_keys(int key, t_data *data)
{
	if (key == KEY_ESC)
		mlx_exit(data);
	check_key(key, data);
	return (0);
}
