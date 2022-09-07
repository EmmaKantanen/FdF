/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:20:34 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/18 14:18:27 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "mlx.h"

# define SCALE 20
# define WIN_X 1400
# define WIN_Y 1000
# define SHIFT_X 100
# define SHIFT_Y 100

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			wordcount;
}				t_dot;

int		deal_key_2(int key, t_dot **matrix);
int		color_pick(t_dot a, t_dot b);
int		map_valid(char *line);
float	fmodule(float i);
void	draw(t_dot **matrix);
int		ft_wordcount(char const *s, char c);
void	draw2(t_dot **matrix);
int		main(int argc, char **argv);

#endif
