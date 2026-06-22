/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:03:05 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/22 05:34:21 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "./struct.h"
# include "./define.h"
# include "./execute.h"
# include "./move_rotate.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define EPSILON	1e-4
# define DELTA		1e-10

/* main.c */
void	err_msg(char *str);
int		main(int argc, char **argv);

/* init_scene_1.c */
int		init_scene_a(t_scene *scene);
int		init_scene_c(t_scene *scene);
int		init_scene_l(t_scene *scene);
void	init_scene(t_scene *scene);

/* init_scene_2.c */
int		init_scene_sp(t_scene *scene, int i);
int		init_scene_pl(t_scene *scene, int i);
int		init_scene_cy(t_scene *scene, int i);

/* parse_main.c */
int		check_extention(char *str);
void	parse_arg(t_scene *scene, char *argv);
int		parse_main(t_scene *scene, char **argv);

/* parse_map.c */
void	read_all_finish_gnl(t_scene *scene, char **line,
			int fd, int err);
char	**check_line(char **line);
int		check_id(t_scene *scene, char **line);
void	parse_map(t_scene *scene, char *argv);

/* parse_a.c */
int		parse_a_token(t_scene *scene, char ***s);
int		parse_a_lighting(t_scene *scene, char ***s);
int		check_value_a_rgb(t_scene *scene, char **rgb);
int		parse_a_rgb(t_scene *scene, char ***s);
int		parse_a(t_scene *scene, char **line);

/* parse_c.c */
int		parse_c_token(t_scene *scene, char ***s);
int		parse_c_xyz_pos(t_scene *scene, char ***s);
int		check_value_c_xyz_vec(t_scene *scene, char **xyz_vec);
int		parse_c_xyz_vec_and_fov(t_scene *scene, char ***s);
int		parse_c(t_scene *scene, char **line);

/* parse_l.c */
int		parse_l_token(t_scene *scene, char ***s);
int		parse_l_xyz_pos(t_scene *scene, char ***s);
int		parse_l_brightness(t_scene *scene, char ***s);
int		parse_l(t_scene *scene, char **line);

/* parse_obj_sp.c */
int		parse_sp_token(t_scene *scene, int i, char ***s);
int		parse_sp_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_sp_diameter(t_scene *scene, int i, char ***s);
int		parse_sp_rgb(t_scene *scene, int i, char ***s);
int		parse_sp(t_scene *scene, char **line);

/* parse_obj_pl.c */
int		parse_pl_token(t_scene *scene, int i, char ***s);
int		parse_pl_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_pl_xyz_vec(t_scene *scene, int i, char ***s);
int		parse_pl_rgb(t_scene *scene, int i, char ***s);
int		parse_pl(t_scene *scene, char **line);

/* parse_obj_cy_1.c */
int		parse_cy_token(t_scene *scene, int i, char ***s);
int		parse_cy(t_scene *scene, char **line);

/* parse_obj_cy_2.c */
int		parse_cy_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_cy_diameter_and_height(t_scene *scene, int i, char ***s);
int		parse_cy_xyz_vec(t_scene *scene, int i, char ***s);
int		parse_cy_rgb(t_scene *scene, int i, char ***s);

/* check_parse_err.c */
void	err_check_a(t_scene *scene);
void	err_check_c(t_scene *scene);
void	err_check_l(t_scene *scene);
int		check_parse_error(t_scene *scene);

/* check_parse_err_obj.c */
void	map_err(int i, char *id, char *str);
void	err_check_sp(t_scene *scene, int i);
void	err_check_pl(t_scene *scene, int i);
void	err_check_cy(t_scene *scene, int i);

/* init_scene_ori_1.c */
int		init_scene_ori_a(t_scene *scene_ori, t_scene *scene);
int		init_scene_ori_c(t_scene *scene_ori, t_scene *scene);
int		init_scene_ori_l(t_scene *scene_ori, t_scene *scene);
void	init_scene_ori(t_scene *scene_ori, t_scene *scene);

/* init_scene_ori_2.c */
int		init_scene_ori_sp(t_scene *scene_ori, t_scene *scene);
int		init_scene_ori_pl(t_scene *scene_ori, t_scene *scene);
void	put_value_scene_ori_cy(t_scene *scene_ori, t_scene *scene);
int		init_scene_ori_cy(t_scene *scene_ori, t_scene *scene);

/* utils_parse.c */
int		token_count(char **token, int cnt);
int		check_comma(char *str);

/* utils_alloc_free.c */
void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len);
void	ft_free_2d(char **str);
void	ft_free_3d(char ***str);
void	free_scene(t_scene *scene);

#endif
