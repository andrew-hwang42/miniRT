/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:03:04 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/20 22:03:05 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_ROTATE_H
# define MOVE_ROTATE_H

# include "./miniRT.h"

/* move_camera.c */
void	move_camera_x_axis(int key, t_data *data);
void	move_camera_y_axis(int key, t_data *data);
void	move_camera_z_axis(int key, t_data *data);
void	move_camera(int key, t_data *data);

/* rotate_camera.c */
void	rotate_camera_x_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera_y_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera_z_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera(int key, t_data *data);

/* rotate_camera_x_axis_obj.c */
void	rotate_camera_x_axis_set_sp(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_pl(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_cy(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_l(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);

/* rotate_camera_y_axis_obj.c */
void	rotate_camera_y_axis_set_sp(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_pl(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_cy(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_l(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);

/* rotate_camera_z_axis_obj.c */
void	rotate_camera_z_axis_set_sp(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_pl(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_cy(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_l(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);

/* move_light.c */
void	move_light_x_axis(int key, t_data *data);
void	move_light_y_axis(int key, t_data *data);
void	move_light_z_axis(int key, t_data *data);
void	move_light(int key, t_data *data);

/* move_sphere.c */
void	move_sphere_x_axis(int key, t_data *data, int i);
void	move_sphere_y_axis(int key, t_data *data, int i);
void	move_sphere_z_axis(int key, t_data *data, int i);
void	move_sphere(int key, t_data *data, int i);

/* move_plane.c */
void	move_plane_x_axis(int key, t_data *data, int i);
void	move_plane_y_axis(int key, t_data *data, int i);
void	move_plane_z_axis(int key, t_data *data, int i);
void	move_plane(int key, t_data *data, int i);

/* rotate_plane.c */
void	rotate_plane_x_axis(t_data *data, int flag, int i, int key);
void	rotate_plane_y_axis(t_data *data, int flag, int i, int key);
void	rotate_plane_z_axis(t_data *data, int flag, int i, int key);
void	rotate_plane(int key, t_data *data, int i);

/* move_cylinder.c */
void	move_cylinder_x_axis(int key, t_data *data, int i);
void	move_cylinder_y_axis(int key, t_data *data, int i);
void	move_cylinder_z_axis(int key, t_data *data, int i);
void	move_cylinder(int key, t_data *data, int i);

/* rotate_cylinder.c */
void	rotate_cylinder_x_axis(t_data *data, int flag, int i, int key);
void	rotate_cylinder_y_axis(t_data *data, int flag, int i, int key);
void	rotate_cylinder_z_axis(t_data *data, int flag, int i, int key);
void	rotate_cylinder(int key, t_data *data, int i);

#endif
