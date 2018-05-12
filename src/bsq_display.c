/*
** EPITECH PROJECT, 2017
** bsq_display.c
** File description:
** display function
*/

#include "bsq.h"

void draw_col(map_t **map, int start, int size)
{
	int i = 0;

	while (i < size) {
		(*map)->grid[start] = 'x';
		start += (*map)->nb_cols + 1;
		i += 1;
	}
}

void draw_line(map_t **map, int start, int size)
{
	int i = 0;

	while (i < size) {
		(*map)->grid[start] = 'x';
		start += 1;
		i += 1;
	}
}

void bsq_draw(map_t **map)
{
	int i = 0;
	int x = (*map)->start;
	int y = (*map)->start;

	while (i < (*map)->size - 1) {
		draw_line(map, x, i);
		draw_col(map, y, i + 1);
		i += 1;
		y += 1;
		x += (*map)->nb_cols + 1;
	}
}

void bsq_display(map_t *map)
{
	int i = 0;

	while (map->grid[i])
		write(1, &(map->grid[i++]), 1);
}
