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

void	check_key_object(int key, t_data *data)
{
	if (key == KEY_1)
		data->mode = MODE_SPHERE;
	if (key == KEY_2)
		data->mode = MODE_PLANE;
	if (key == KEY_3)
		data->mode = MODE_CYLINDER;
	if (key == KEY_M)
		data->move_rotate = MOVE;
	if (key == KEY_R)
		data->move_rotate = ROTATE;
	if (key == KEY_X)
		data->axis = AXIS_X;
	if (key == KEY_Y)
		data->axis = AXIS_Y;
	if (key == KEY_Z)
		data->axis = AXIS_Z;
	if (key == KEY_Q)
	{
		data->mode = 0;
		data->move_rotate = 0;
		data->axis = 0;
	}
}

int	mlx_keys(int key, t_data *data)
{
	if (key == KEY_ESC)
		mlx_exit(data);
	if (key == KEY_C)
		data->mode = MODE_CAMERA;
	if (key == KEY_L)
		data->mode = MODE_LIGHT;
	check_key_object(key, data);
	if (data->mode == MODE_CAMERA && data->move_rotate == MOVE)
		move_camera(key, data);
	if (data->mode == MODE_CAMERA && data->move_rotate == ROTATE)
		rotate_camera(key, data);
	if (data->mode == MODE_LIGHT)
		move_light(key, data);
	if (data->mode == MODE_SPHERE)
		move_sphere(key, data, data->sp);
	if (data->mode == MODE_PLANE && data->move_rotate == MOVE)
		move_plane(key, data, data->pl);
	if (data->mode == MODE_PLANE && data->move_rotate == ROTATE)
		rotate_plane(key, data, data->pl);
	if (data->mode == MODE_CYLINDER && data->move_rotate == MOVE)
		move_cylinder(key, data, data->cy);
	if (data->mode == MODE_CYLINDER && data->move_rotate == ROTATE)
		rotate_cylinder(key, data, data->cy);
	return (0);
}
