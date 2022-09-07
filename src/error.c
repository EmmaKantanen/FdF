/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:19:38 by ekantane          #+#    #+#             */
/*   Updated: 2022/05/18 14:18:03 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
The valid maps can only have positive numbers, negative numbers and spaces.
For example hex codes in the maps themselves aren't allowed.
*/

int	map_valid(char *line)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (((line[x] < '0' || line[x] > '9') && line[x] != ' ' && line[x] \
		!= '-') || \
		(line[x] == '-' && (line[x + 1] < '1' || line[x + 1] > '9')) || \
		(line[x] != ' ' && line[x + 1] == '-'))
		{
			ft_putstr("not a valid map\n");
			free(line);
			exit (1);
		}
	x++;
	}
	return (0);
}
