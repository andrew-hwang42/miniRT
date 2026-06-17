#include "../incs/miniRT.h"

void	put_value_sp(t_scene *scene, t_obj **obj)
{
	int	i;

	i = -1;
	while (++i < scene->n_sphere)
	{
		obj[i]->obj_type = SPHERE;
		obj[i]->xyz_pos = scene->sphere[i]->xyz_pos;
		obj[i]->diameter = scene->sphere[i]->diameter;
		obj[i]->height = 0;
		obj[i]->rgb = scene->sphere[i]->rgb;
	}
}

void	put_value_pl(t_scene *scene, t_obj **obj)
{
	int	i;

	i = -1;
	while (++i < scene->n_plane)
	{
		obj[scene->n_sphere + i]->obj_type = PLANE;
		obj[scene->n_sphere + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[scene->n_sphere + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[scene->n_sphere + i]->rgb = scene->plane[i]->rgb;
	}
}

void	put_value_cy(t_scene *scene, t_obj **obj)
{
	int	i;

	i = -1;
	while (++i < scene->n_cylinder)
	{
		obj[scene->n_sphere + scene->n_plane + i]->obj_type
			= CYLINDER;
		obj[scene->n_sphere + scene->n_plane + i]->xyz_pos
			= scene->cylinder[i]->xyz_pos;
		obj[scene->n_sphere + scene->n_plane + i]->xyz_vec
			= scene->cylinder[i]->xyz_vec;
		obj[scene->n_sphere + scene->n_plane + i]->diameter
			= scene->cylinder[i]->diameter;
		obj[scene->n_sphere + scene->n_plane + i]->height
			= scene->cylinder[i]->height;
		obj[scene->n_sphere + scene->n_plane + i]->rgb
			= scene->cylinder[i]->rgb;
	}
}

void	put_value_pl_dup(t_scene *scene, t_obj **obj, int n_obj)
{
	int	i;

	i = -1;
	while (++i < scene->n_plane)
	{
		obj[n_obj + i]->obj_type = PLANE;
		obj[n_obj + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[n_obj + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[n_obj + i]->rgb = scene->plane[i]->rgb;
		obj[n_obj + i]->xyz_pos = vec3_sub_vec3(scene->plane[i]->xyz_pos,
				vec3_mul_scalar(scene->plane[i]->xyz_vec, DELTA));
		obj[n_obj + i]->xyz_vec.x *= -1;
		obj[n_obj + i]->xyz_vec.y *= -1;
		obj[n_obj + i]->xyz_vec.z *= -1;
	}
}

t_obj	**init_obj(t_scene *scene)
{
	t_obj	**obj;
	int		n_obj;
	int		i;

	n_obj = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	obj = (t_obj **)ft_calloc(sizeof(t_obj *),
			n_obj + scene->n_plane + 1);
	if (!obj)
		return (err_msg("Malloc error"), free_scene(scene),
			exit (1), NULL);
	i = -1;
	while (++i < n_obj + scene->n_plane)
	{
		obj[i] = (t_obj *)ft_calloc(sizeof(t_obj), 2);
		if (!obj[i])
			return (err_msg("Malloc error\n"), free_obj(obj),
				free_scene(scene), exit(1), NULL);
	}
	put_value_sp(scene, obj);
	put_value_pl(scene, obj);
	put_value_cy(scene, obj);
	put_value_pl_dup(scene, obj, n_obj);
	return (obj);
}
