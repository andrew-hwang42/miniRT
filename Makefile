NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

SRCS_DIR = ./srcs/
SRCS_PARSE_DIR = ./srcs/parse/
SRCS_EXECUTE_DIR = ./srcs/execute/

FILES	= $(SRCS_DIR)main \
		$(SRCS_PARSE_DIR)init_scene_1 \
		$(SRCS_PARSE_DIR)init_scene_2 \
		$(SRCS_PARSE_DIR)parse_main \
		$(SRCS_PARSE_DIR)parse_map \
		$(SRCS_PARSE_DIR)parse_a \
		$(SRCS_PARSE_DIR)parse_c \
		$(SRCS_PARSE_DIR)parse_l \
		$(SRCS_PARSE_DIR)parse_obj_sp \
		$(SRCS_PARSE_DIR)parse_obj_pl \
		$(SRCS_PARSE_DIR)parse_obj_cy_1 \
		$(SRCS_PARSE_DIR)parse_obj_cy_2 \
		$(SRCS_PARSE_DIR)check_parse_err \
		$(SRCS_PARSE_DIR)check_parse_err_obj \
		$(SRCS_PARSE_DIR)init_scene_ori_1 \
		$(SRCS_PARSE_DIR)init_scene_ori_2 \
		$(SRCS_PARSE_DIR)utils_parse \
		$(SRCS_PARSE_DIR)utils_alloc_free \
		$(SRCS_EXECUTE_DIR)execute_main \
		$(SRCS_EXECUTE_DIR)set_camera_1 \
		$(SRCS_EXECUTE_DIR)set_camera_2 \
		$(SRCS_EXECUTE_DIR)init_obj \
		$(SRCS_EXECUTE_DIR)start_raytracing \
		$(SRCS_EXECUTE_DIR)set_ray \
		$(SRCS_EXECUTE_DIR)hit_sphere \
		$(SRCS_EXECUTE_DIR)hit_plane \
		$(SRCS_EXECUTE_DIR)hit_cylinder_1 \
		$(SRCS_EXECUTE_DIR)hit_cylinder_2 \
		$(SRCS_EXECUTE_DIR)apply_light \
		$(SRCS_EXECUTE_DIR)utils_vec1 \
		$(SRCS_EXECUTE_DIR)utils_vec2 \
		$(SRCS_EXECUTE_DIR)utils_color \
		$(SRCS_EXECUTE_DIR)utils_mlx \
		$(SRCS_EXECUTE_DIR)utils \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera_set_norm_vec \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera_set_scene_ori \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera_x_axis_obj \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera_y_axis_obj \
		$(SRCS_EXECUTE_DIR)move_rotate/rotate_camera_z_axis_obj \

INCS_DIR	= ./incs

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

$(MLX):
	chmod 775 $(MLX_DIR)/configure
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
