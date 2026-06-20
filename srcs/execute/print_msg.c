/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:05:23 by ahwang            #+#    #+#             */
/*   Updated: 2026/06/21 01:25:13 by ahwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	show_example(void)
{
	printf("The manipulation system follows a strict input order:\n");
	printf("    1. Select a mode (C/L/1/2/3)\n");
	printf("    2. Select an operation (M/R)\n");
	printf("    3. Select an axis (X/Y/Z)\n");
	printf("    4. Apply the transformation (UP/DOWN)\n\n");
	printf("Ex1) Rotate Camera in the negative direction (counterclockwise)");
	printf(" of the z-axis\n");
	printf("        Press C (Camera) → R (Rotate) → Z (z-axis) → DOWN (-)\n");
	printf("Ex2) Move Light in the positive direction of the y-axis\n");
	printf("        Press L (Light) → M (Move) → Y (y-axis) → UP (+)\n");
	printf("Ex3) Rotate 2rd cylinder in the positive direction (clockwise)");
	printf(" of the x-axis\n");
	printf("        Press 3 (Cylinder) → F3 (cy[0]->cy[1]) ");
	printf("→ F3 (cy[1]->cy[2]) → M (Move) → Y (x-axis) → UP (+)\n");
	printf("\n");
}

void	show_guide(void)
{
	printf("\n╔═══════════════════════╦═══════════════════════");
	printf("╦═══════════════════════╦═══════════════════════╗\n");
	printf("║         mode          ║       operation       ");
	printf("║         utils         ║       manipulate      ║\n");
	printf("╠══════╦════════════════╬══════╦════════════════");
	printf("╬══════╦════════════════╬══════╦════════════════╣\n");
	printf("║ C    ║ Camera         ║ M    ║ Move           ");
	printf("║ F1   ║ Next sphere    ║ UP   ║ + / clockwise  ║\n");
	printf("║ L    ║ Light          ║ R    ║ Rotate (%d°)   ", ROTATE_ANGLE);
	printf("║ F2   ║ Next plane     ║ DOWN ║ - / counter-   ║\n");
	printf("║ 1    ║ Sphere         ╠══════╬════════════════");
	printf("╣ F3   ║ Next cylinder  ║      ║      clockwise ║\n");
	printf("║ 2    ║ Plane          ║ X    ║ X-axis         ");
	printf("╠══════╬════════════════╬══════╬════════════════╣\n");
	printf("║ 3    ║ Cylinder       ║ Y    ║ Y-axis         ");
	printf("║ Q    ║ Reset all      ║ ESC  ║ Exit           ║\n");
	printf("║      ║                ║ Z    ║ Z-axis         ");
	printf("║      ║   selection    ║      ║                ║\n");
	printf("╚══════╩════════════════╩══════╩════════════════");
	printf("╩══════╩════════════════╩══════╩════════════════╝\n");
	show_example();
}

void	check_obj_flag(t_data *data, int flag)
{
	if (flag == SP_NEXT)
	{
		printf("║     ║   ║     camera    ║     light     ║");
		printf("   %ssphere[%d]%s   ║    plane[%d]   ║  cylinder[%d]  ║\n",
			CYAN, data->sp, BLACK, data->pl, data->cy);
	}
	else if (flag == PL_NEXT)
	{
		printf("║     ║   ║     camera    ║     light     ");
		printf("║   sphere[%d]   ║    %splane[%d]%s   ║  cylinder[%d]  ║\n",
			data->sp, CYAN, data->pl, BLACK, data->cy);
	}
	else if (flag == CY_NEXT)
	{
		printf("║     ║   ║     camera    ║     light     ");
		printf("║   sphere[%d]   ║    plane[%d]   ║  %scylinder[%d]%s  ║\n",
			data->sp, data->pl, CYAN, data->cy, BLACK);
	}
	else
	{
		printf("║     ║   ║     camera    ║     light     ");
		printf("║   sphere[%d]   ║    plane[%d]   ║  cylinder[%d]  ║\n",
			data->sp, data->pl, data->cy);
	}
}

void	print_obj_vec_info(t_data *data, t_scene *scene)
{
	printf("║     ║ x ║ %f\t  ║       -       ║       -       ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_vec.x,
		scene->plane[data->pl]->xyz_vec.x,
		scene->cylinder[data->cy]->xyz_vec.x);
	printf("║ vec ║ y ║ %f\t  ║       -       ║       -       ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_vec.y,
		scene->plane[data->pl]->xyz_vec.y,
		scene->cylinder[data->cy]->xyz_vec.y);
	printf("║     ║ z ║ %f\t  ║       -       ║       -       ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_vec.z,
		scene->plane[data->pl]->xyz_vec.z,
		scene->cylinder[data->cy]->xyz_vec.z);
	printf("╚═════╩═══╩═══════════════╩═══════════════");
	printf("╩═══════════════╩═══════════════╩═══════════════╝\n");
}

void	print_obj_info(t_data *data, t_scene *scene, int flag)
{
	printf("╔═════╦═══╦═══════════════╦═══════════════");
	printf("╦═══════════════╦═══════════════╦═══════════════╗\n");
	check_obj_flag(data, flag);
	printf("╠═════╬═══╬═══════════════╬═══════════════");
	printf("╬═══════════════╬═══════════════╬═══════════════╣\n");
	printf("║     ║ x ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_pos.x, scene->light->xyz_pos.x,
		scene->sphere[data->sp]->xyz_pos.x,
		scene->plane[data->pl]->xyz_pos.x,
		scene->cylinder[data->cy]->xyz_pos.x);
	printf("║ pos ║ y ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_pos.y, scene->light->xyz_pos.y,
		scene->sphere[data->sp]->xyz_pos.y,
		scene->plane[data->pl]->xyz_pos.y,
		scene->cylinder[data->cy]->xyz_pos.y);
	printf("║     ║ z ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║ %f\t  ║\n",
		scene->camera->xyz_pos.z, scene->light->xyz_pos.z,
		scene->sphere[data->sp]->xyz_pos.z,
		scene->plane[data->pl]->xyz_pos.z,
		scene->cylinder[data->cy]->xyz_pos.z);
	printf("╠═════╬═══╬═══════════════╬═══════════════");
	printf("╬═══════════════╬═══════════════╬═══════════════╣\n");
	print_obj_vec_info(data, scene);
}
