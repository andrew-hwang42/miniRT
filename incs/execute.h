/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:03:06 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/22 00:42:34 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "./miniRT.h"

/* execute_main.c */
void	init_data(t_data *data);
void	init_rt(t_scene *scene, t_rt *rt);
void	raytracing_main(t_data *data, int flag);
t_data	*get_data(t_data *new_data);
int		execute_main(t_scene *scene, t_scene *scene_ori, t_mlx *mlx);

/* set_camera_1.c */
void	rotate_y_axis(t_data *data, double v_cos, double v_sin);
void	camera_vec_zero_zero_plusone(t_data *data);
void	camera_vec_minusone_zero_zero(t_data *data);
void	camera_vec_plusone_zero_zero(t_data *data);
void	set_camera(t_data *data);

/* set_camera_2.c */
void	rotate_x_axis(t_data *data, double v_cos, double v_sin);
void	camera_vec_zero_minusone_zero(t_data *data);
void	camera_vec_zero_plusone_zero(t_data *data);
void	camera_vec_zero_y_z(t_data *data);
void	camera_vec_x_zero_z(t_data *data);

/* init_obj.c */
void	put_value_sp(t_scene *scene, t_obj **obj);
void	put_value_pl(t_scene *scene, t_obj **obj);
void	put_value_cy(t_scene *scene, t_obj **obj);
void	put_value_pl_dup(t_scene *scene, t_obj **obj, int n_obj);
t_obj	**init_obj(t_scene *scene);

/* start_raytracing */
int		hit_obj(t_data *data, t_hit *hit);
t_rgb3	trace(t_data *data, t_ray ray_set);
void	start_raytracing(t_data *data);

/* set_ray.c */
t_ray	ray_vec(t_vec3 point, t_vec3 direc);
t_ray	set_ray(t_data *data, double u, double v);

/* hit_sphere.c */
void	set_hit_point(t_data *data, t_hit *hit, double t);
void	set_hit_normal_direc(t_data *data, t_hit *hit);
int		is_sphere(t_data *data, double *t, int sp_i, double distance);
int		hit_sphere(t_data *data, t_hit *hit, int sp_i, double distance);
int		light_hit_sp(t_data *data, int sp_i, double distance);

/* hit_plane.c */
int		is_plane(t_data *data, double *t, int pl_i, double distance);
int		hit_plane(t_data *data, t_hit *hit, int pl_i, double distance);
int		light_hit_pl(t_data *data, int pl_i, double distance);

/* hit_cylinder_1.c */
void	norminette_is_cylinder_body(t_data *data,
			int cy_i, double *d, t_vec3 *cy_center);
double	is_cylinder_body(t_data *data, int cy_i, double distance);
t_vec3	calc_normal_vec_cylinder_body(t_data *data, t_hit *hit, int cy_i);
int		hit_cylinder(t_data *data, t_hit *hit, int cy_i, double distance);
int		light_hit_cy(t_data *data, int cy_i, double distance);

/* hit_cylinder_2.c */
void	is_cylinder_circle_1(t_data *data,
			int cy_i, t_vec3 *cy_center, t_vec3 *tc);
void	is_cylinder_circle_2(double *dot, double *t_circle);
void	is_cylinder_circle_3(t_data *data,
			double *t_circle, t_vec3 *hit_p);
int		check_circle_radius(t_data *data,
			int cy_i, t_vec3 hit_point, t_vec3 cy_center);
double	is_cylinder_circle(t_data *data, int cy_i, double distance);

/* apply_light.c */
int		check_light_hit_obj(t_data *data, double distance);
int		calculate_light(t_data *data, t_hit *hit,
			double *light_intensity, t_rgb3 *light_color);
t_rgb3	apply_light(t_data *data, t_hit *hit);

/* utils_vec1.c */
t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul_scalar(t_vec3 v, double rn);
double	vec3_dot_vec3(t_vec3 v1, t_vec3 v2);

/* utils_vec2.c */
double	vec3_length(t_vec3 v);
t_vec3	vec3_unit(t_vec3 v);

/* utils_color.c */
t_rgb3	rgb3(double r, double g, double b);
t_rgb3	color_add(t_rgb3 c1, t_rgb3 c2);
double	color_clamp(double c);
t_rgb3	color_average(t_rgb3 c);
int		color_convert_to_int(t_rgb3 rgb);

/* utils_mlx.c */
int		mlx_init_window(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_exit(void *param);
int		mlx_keys(int key, void *param);
int		mlx_close(void);

/* utils_mlx_key.c */
void	key_select_mode_move_rotate_axis(int key, t_data *data);
void	key_obj_next(int key, t_data *data);
void	check_move_rotate(int key, t_data *data);
void	check_key(int key, t_data *data);

/* utils.c */
void	free_obj(t_obj **obj);
double	random_double(void);
void	check_obj_flag(t_data *data, int flag);
void	print_obj_vec_info(t_data *data, t_scene *scene);
void	print_obj_info(t_data *data, t_scene *scene, int flag);

/* print_msg.c */
void	show_example(void);
void	show_guide(void);
void	print_obj_info(t_data *data, t_scene *scene, int flag);

#endif
