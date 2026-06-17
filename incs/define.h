#ifndef DEFINE_H
# define DEFINE_H

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
# define KEY_UP				0xFF52
# define KEY_DOWN			0xFF54
# define KEY_ESC			0xFF1B
# define KEY_1				0x31
# define KEY_2				0x32
# define KEY_3				0x33
# define KEY_4				0x34
# define KEY_5				0x35
# define KEY_6				0x36
# define KEY_7				0x37
# define KEY_8				0x38
# define KEY_9				0x39
# define KEY_Q				0x71
# define KEY_W				0x77
# define KEY_E				0x65
# define KEY_R				0x72
# define KEY_T				0x74
# define KEY_Y				0x79
# define KEY_U				0x75
# define KEY_I				0x69
# define KEY_O				0x6F
# define KEY_A				0x61
# define KEY_S				0x73
# define KEY_D				0x64
# define KEY_F				0x66
# define KEY_G				0x67
# define KEY_H				0x68
# define KEY_J				0x6A
# define KEY_K				0x6B
# define KEY_L				0x6C
# define KEY_Z				0x7A
# define KEY_X				0x78
# define KEY_C				0x63
# define KEY_V				0x76
# define KEY_B				0x62
# define KEY_N				0x6E
# define KEY_POINT			0x2E
# define KEY_SLASH			0x2F
# define KEY_SEMICOLON			0x3B
# define KEY_SINGLE_QUOTE		0x27
# define KEY_SQUARE_BRACKET_LEFT	0x5B
# define KEY_SQUARE_BRACKET_RIGHT	0x5D

# define KEY_F1				0xFFBE
# define KEY_F2				0xFFBF
# define KEY_F3				0xFFC0

# include "./miniRT.h"

#endif
