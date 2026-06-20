#include "../incs/miniRT.h"

void	init_data(t_data *data)
{
	data->rt = NULL;
	data->ray = NULL;
	data->hit = NULL;
	data->sp = 0;
	data->pl = 0;
	data->cy = 0;
	data->x_normal = vec3(1, 0, 0);
	data->y_normal = vec3(0, 1, 0);
	data->z_normal = vec3(0, 0, 1);
	data->mode = 0;
	data->move_rotate = 0;
	data->axis = 0;
}

void	init_rt(t_scene *scene, t_rt *rt)
{
	rt->focal_length = 1;
	rt->viewport_height
		= 2 * rt->focal_length * tan(scene->camera->fov * PI / 360);
	rt->viewport_width = rt->viewport_height * ASPECT_RATIO_W / ASPECT_RATIO_H;
	rt->vp_horizontal = vec3(rt->viewport_width, 0, 0);
	rt->vp_vertical
		= vec3(0, -1 * (rt->viewport_height), 0);
	rt->vp_low_left
		= vec3(-1 * (rt->vp_horizontal.x) / 2,
			-1 * (rt->vp_vertical.y) / 2, -1 * (rt->focal_length));
	rt->cam_xyz_pos = scene->camera->xyz_pos;
}

void	raytracing_main(t_data *data, int flag)
{
	t_rt	rt;

	if (data->obj)
		free_obj(data->obj);
	data->obj = init_obj(data->scene);
	data->rt = &rt;
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	init_rt(data->scene, data->rt);
	start_raytracing(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img_ptr, 0, 0);
	(void)flag;
	//show_guide();
	//print_scene_info(data, data->scene_ori, flag);
}

int	execute_main(t_scene *scene, t_scene *scene_ori, t_mlx *mlx)
{
	t_data	data;

	data.scene_ori = scene_ori;
	data.scene = scene;
	data.obj = NULL;
	data.mlx = mlx;
	data.n_obj = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	init_data(&data);
	if (mlx_init_window(mlx))
		return (err_msg("mlx init error"), free_scene(scene),
			free_scene(scene_ori), exit(1), 1);
	if (data.scene_ori->camera->xyz_vec.z != -1)
		set_camera(&data);
	raytracing_main(&data, 0);
	mlx_key_hook(mlx->win, mlx_keys, (void *)&data);
	mlx_hook(mlx->win, 17, 2, mlx_exit, (void *)&data);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
