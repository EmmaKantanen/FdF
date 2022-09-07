/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:38 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/18 14:07:30 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Adding the basic algorithm for making the image isometric.
*/

static void	set_param2(t_dot *a, t_dot *b)
{
	a->x *= SCALE * 1.2;
	a->y *= SCALE * 1.2;
	b->x *= SCALE * 1.2;
	b->y *= SCALE * 1.2;
	a->x += (SHIFT_X + 400);
	a->y += (SHIFT_Y - 500);
	b->x += (SHIFT_X + 400);
	b->y += (SHIFT_Y - 500);
	a->x = (a->x - a->y) * cos(1);
	a->y = (a->x + a->y) * sin(1) - a->z;
	b->x = (b->x - b->y) * cos(1);
	b->y = (b->x + b->y) * sin(1) - b->z;
}

static void	line2(t_dot a, t_dot b, void *mlx_ptr, void *win_ptr)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param2(&a, &b);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_inthigher(fmodule(step_x), fmodule(step_y));
	step_x = step_x / max;
	step_y = step_y / max;
	color = color_pick(a, b);
	while (((int)(a.x - b.x)) != '\0' || (((int)(a.y - b.y)) != '\0'))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, color);
		a.x = a.x + step_x;
		a.y = a.y + step_y;
	}
}

void	draw2(t_dot **matrix)
{
	int		y;
	int		x;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_X, WIN_Y, "FDF");
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line2(matrix[y][x], matrix[y + 1][x], mlx_ptr, win_ptr);
			if (!matrix[y][x].wordcount)
				line2(matrix[y][x], matrix[y][x + 1], mlx_ptr, win_ptr);
			if (matrix[y][x].wordcount)
				break ;
			x++;
		}
		y++;
	}
	mlx_key_hook(win_ptr, deal_key_2, matrix);
	mlx_loop(mlx_ptr);
}
