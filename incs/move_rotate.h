#ifndef MOVE_ROTATE_H
# define MOVE_ROTATE_H

# include "./miniRT.h"

/* rotate_camera.c */
void	rotate_camera_x_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera_y_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera_z_axis(t_data *data, int flag,
			double v_cos, double v_sin);
void	rotate_camera(int key, t_data *data);

/* rotate_camera_set_norm_vec.c */
void	rotate_camera_x_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_norm_vec(t_data *data,
			double v_cos, double v_sin);

/* rotate_camera_set_scene_ori.c */
void	rotate_camera_x_axis_set_scene_ori(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_y_axis_set_scene_ori(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_scene_ori(t_data *data,
			double v_cos, double v_sin);

/* rotate_camera_x_axis_obj.c */
void	rotate_camera_x_axis_set_sp(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_pl(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_cy(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_x_axis_set_l(t_data *data,
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

/* rotate_camera_z_axis_obj.c */
void	rotate_camera_z_axis_set_sp(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_pl(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_cy(t_data *data,
			double v_cos, double v_sin);
void	rotate_camera_z_axis_set_l(t_data *data,
			double v_cos, double v_sin);

#endif
