#include "../incs/miniRT.h"

int	hit_obj(t_data *data, t_hit *hit)
{
	int		i;
	int		hit_flag;
	double	distance;

	i = 0;
	hit_flag = 0;
	distance = INFINITY;
	while (i < data->n_obj + data->scene->n_plane)
	{
		if (!(hit_sphere(data, hit, i, distance))
			|| !(hit_plane(data, hit, i, distance))
			|| !(hit_cylinder(data, hit, i, distance)))
		{
			hit_flag = 1;
			distance = hit->t;
		}
		i++;
	}
	return (hit_flag);
}

t_rgb3	trace(t_data *data, t_ray ray_set)
{
	t_hit	hit;
	t_rgb3	ambient;
	t_rgb3	light;

	data->ray = &ray_set;
	if (hit_obj(data, &hit))
	{
		ambient.r = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.r) * hit.color.r * 0.001;
		ambient.g = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.g) * hit.color.g * 0.001;
		ambient.b = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.b) * hit.color.b * 0.001;
		light = apply_light(data, &hit);
		return (color_add(ambient, light));
	}
	return (rgb3(0, 0, 0));
}

void	start_raytracing(t_data *data)
{
	int		i;
	int		j;
	int		s;
	t_rgb3	color;

	j = (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	printf("Rendering...");
	while (0 <= --j)
	{
		printf("Rendering... %d %%\n",
			((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - j) * 100
			/ (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H));
		i = -1;
		while (++i <= WIN_W - 1)
		{
			color = rgb3(0, 0, 0);
			s = -1;
			while (++s < NUM_SAMPLE)
				color = color_add(color,
						trace(data, set_ray(data, i, j)));
			color = color_average(color);
			my_mlx_pixel_put(data->mlx, i, j, color_convert_to_int(color));
		}
	}
	printf("Done\n");
}
