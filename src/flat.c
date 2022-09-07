/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:38 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/18 16:31:33 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This is part of the basic Bresenham algorithm, dealing with positive and
negative half-planes.
*/

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

/*
This function acts as a port for parameter multipliers, i.e. scale and
marginals (shifts), later the isometric view.
*/

static void	set_param(t_dot *a, t_dot *b)
{
	a->x *= SCALE;
	a->y *= SCALE;
	b->x *= SCALE;
	b->y *= SCALE;
	a->x += SHIFT_X;
	a->y += SHIFT_Y;
	b->x += SHIFT_X;
	b->y += SHIFT_Y;
}

/*
This is the basic Bresenham's algorithm.
The line is handled by iterating the longer/wider component we'll find by using
ft_inthigher (and finding out if the value is positive/negative). To put it
simply, we are in a way finding the average value of the line.
At last we need to prevent the accumulating of the error maginal, otherwise
the line will distort.
*/

static void	line(t_dot a, t_dot b, void *mlx_ptr, void *win_ptr)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b);
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

/*
The connections of the matrix are created here. The wordcount is used to
prevent the program connecting the last values to the following rows.
*/

void	draw(t_dot **matrix)
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
				line(matrix[y][x], matrix[y + 1][x], mlx_ptr, win_ptr);
			if (!matrix[y][x].wordcount)
				line(matrix[y][x], matrix[y][x + 1], mlx_ptr, win_ptr);
			if (matrix[y][x].wordcount)
				break ;
			x++;
		}
		y++;
	}
	mlx_key_hook(win_ptr, deal_key_2, matrix);
	mlx_loop(mlx_ptr);
}
