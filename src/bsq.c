/*
** EPITECH PROJECT, 2017
** bsq.c
** File description:
** bsq function
*/

#include "bsq.h"

void display_error(char *path, int num)
{
	if (num == 1)
		my_putstr("Cannot open the file : '");
	if (num == 2)
		my_putstr("Cannot read the file : '");
	if (num == 2)
		my_putstr("Cannot close the file : '");
	my_putstr(path);
	my_putstr("'\n");
	exit(84);
}

void bsq(char *path)
{
	map_t *map = init_map(path);

	bsq_find(map);
	bsq_draw(&map);
	bsq_display(map);
	free(map->grid);
	free(map);
}
