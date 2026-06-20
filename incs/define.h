/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:03:08 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/21 00:33:32 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* color */
# define YELLOW				"\x1b[33m"
# define BLACK				"\x1b[0m"
# define RED				"\x1b[31m"
# define CYAN				"\x1b[36m"
# define BLUE				"\x1b[34m"

/* parse */
# define ERR_ATOI			-9999
# define ERR_ATOD			-9999.0
# define ERR_MALLOC			1
# define ERR_IDENTIFIER			2
# define ERR_LINE_TOKEN			3
# define ERR_LIGHTING_VALUE		4
# define ERR_FOV_VALUE			5
# define ERR_BRIGHTNESS_VALUE		6
# define ERR_DIAMETER_VALUE		7
# define ERR_HEIGHT_VALUE		8
# define ERR_RGB_TOKEN			9
# define ERR_RGB_VALUE			10
# define ERR_XYZ_POS_TOKEN		11
# define ERR_XYZ_POS_VALUE		12
# define ERR_XYZ_VEC_TOKEN		13
# define ERR_XYZ_VEC_VALUE		14

/* execute */
# define SPHERE				1
# define PLANE				2
# define CYLINDER			3

# define PI				3.14159265359
# define NUM_SAMPLE			2

# define FRONT				1
# define BACK				2

# define TOP				0
# define BOTTOM				1

/* mlx */
# define ASPECT_RATIO_W			16
# define ASPECT_RATIO_H			9
# define WIN_W				800

# define ROTATE_ANGLE			30
# define CAMERA_MOVE			1
# define LIGHT_MOVE			1
# define OBJECT_MOVE			0.5
# define ZOOM				10

/* translating roatating flag */
# define MODE_CAMERA			1
# define MODE_LIGHT			2
# define MODE_SPHERE			3
# define MODE_PLANE			4
# define MODE_CYLINDER			5

# define MOVE				1
# define ROTATE				2

# define AXIS_X				1
# define AXIS_Y				2
# define AXIS_Z				3

# define C_MOVE_X_MINUS			1
# define C_MOVE_X_PLUS			2
# define C_MOVE_Y_MINUS			3
# define C_MOVE_Y_PLUS			4
# define C_MOVE_Z_MINUS			5
# define C_MOVE_Z_PLUS			6
# define C_ROTATE_X			7
# define C_ROTATE_Y			8
# define C_ROTATE_Z			9

# define L_MOVE_X_MINUS			10
# define L_MOVE_X_PLUS			11
# define L_MOVE_Y_MINUS			12
# define L_MOVE_Y_PLUS			13
# define L_MOVE_Z_MINUS			14
# define L_MOVE_Z_PLUS			15

# define SP_MOVE_X_MINUS		16
# define SP_MOVE_X_PLUS			17
# define SP_MOVE_Y_MINUS		18
# define SP_MOVE_Y_PLUS			19
# define SP_MOVE_Z_MINUS		20
# define SP_MOVE_Z_PLUS			21
# define SP_NEXT			22

# define PL_MOVE_X_MINUS		23
# define PL_MOVE_X_PLUS			24
# define PL_MOVE_Y_MINUS		25
# define PL_MOVE_Y_PLUS			26
# define PL_MOVE_Z_MINUS		27
# define PL_MOVE_Z_PLUS			28
# define PL_ROTATE_X			29
# define PL_ROTATE_Y			30
# define PL_ROTATE_Z			31
# define PL_NEXT			32

# define CY_MOVE_X_MINUS		33
# define CY_MOVE_X_PLUS			34
# define CY_MOVE_Y_MINUS		35
# define CY_MOVE_Y_PLUS			36
# define CY_MOVE_Z_MINUS		37
# define CY_MOVE_Z_PLUS			38
# define CY_ROTATE_X			39
# define CY_ROTATE_Y			40
# define CY_ROTATE_Z			41
# define CY_NEXT			42

/* linux keycode */
# define KEY_ESC			0xFF1B
# define KEY_UP				0xFF52
# define KEY_DOWN			0xFF54
# define KEY_X				0x78
# define KEY_Y				0x79
# define KEY_Z				0x7A

# define KEY_C				0x63
# define KEY_L				0x6C
# define KEY_M				0x6D
# define KEY_R				0x72
# define KEY_1				0x31
# define KEY_2				0x32
# define KEY_3				0x33
# define KEY_F1				0xFFBE
# define KEY_F2				0xFFBF
# define KEY_F3				0xFFC0
# define KEY_Q				0x71

# include "./miniRT.h"

#endif
