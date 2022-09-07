/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:38 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/17 16:15:13 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Numbers 18 and 19 are equivalent to the keys 1 and 2 on a Mac keyboard.
They're set to change the isometric flag so that pressing them toggles
the projection of the image. Number 53 is the equivalent of the esc key.
It calls the function destroying the image window.
*/

static int	deal_key_esc(int key)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (key == 53)
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WIN_X, WIN_Y, "FDF");
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit(0);
	}
	return (0);
}

int	deal_key_1(int key, t_dot **matrix)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (key == 18)
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WIN_X, WIN_Y, "FDF");
		mlx_clear_window(mlx_ptr, win_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		draw(matrix);
	}
	deal_key_esc(key);
	return (0);
}

int	deal_key_2(int key, t_dot **matrix)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (key == 19)
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WIN_X, WIN_Y, "FDF");
		mlx_clear_window(mlx_ptr, win_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		draw2(matrix);
	}
	deal_key_1(key, matrix);
	deal_key_esc(key);
	return (0);
}
