/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:38 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/18 14:32:53 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
First we allocate memory for the grid matrix and return it with the dot values.

Below here we use the variables in the struct to set the exact values.
The "wordcount" variable moves alongside the others while all its values will
be set to 0, except the value before null. Like this we can be sure the maps
won't have weird glitches caused by uneven rows.

*/

static int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	map_valid(line);
	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].wordcount = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].wordcount = 1;
	if (matrix_of_dots[0][x].wordcount != matrix_of_dots[y][x].wordcount)
	{
		ft_putstr("not a valid map\n");
		exit (1);
	}
	return (x);
}

static t_dot	**memory_allocate(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = ft_wordcount(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

static t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
	{
		ft_putstr("file does not exist\n");
		exit (1);
	}
	matrix_of_dots = memory_allocate(file_name);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_dots_from_line(line, matrix_of_dots, y++);
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	int		y;

	y = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf map.fdf\n");
		exit (1);
	}
	matrix = read_map(argv[1]);
	if (!matrix[y])
	{
		ft_putstr("not a valid map\n");
		exit (1);
	}
	draw(matrix);
}
