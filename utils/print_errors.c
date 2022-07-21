/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:06:46 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/03 20:39:16 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	print_errors(int e)
{
	if (e == 0)
		printf("Error: failed to find .cub file\n");
	else if (e == 1)
		printf("Error: failed to read .cub file\n");
	else if (e == 2)
		printf("Error: failed to parse rgb colors\n");
	else if (e == 3)
		printf("Error: failed to allocate memory\n");
	else if (e == 4)
		printf("Error: failed to parse texture paths\n");
	else if (e == 5)
		printf("Error: failed to parse the map\n");
	else if (e == 6)
		printf("Error: your map content doesn\'t respect the map rules\n");
	else if (e == 7)
		printf("Error: your map must be surrounded by walls\n");
	else if (e == 8)
		printf("Error: your player is duplicated inside your map\n");
	else if (e == 9)
		printf("Error: cannot find player inside your map\n");
}
