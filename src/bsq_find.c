/*
** EPITECH PROJECT, 2017
** bsq_find.c
** File description:
** find function
*/

#include "bsq.h"

int is_obstacle_col(map_t *map, int start, int size)
{
	int i = 0;

	while (i < size) {
		if (map->grid[start] == 'o' || map->grid[start] == '\0')
			return (1);
		start += map->nb_cols + 1;
		i += 1;
	}
	return (0);
}

int is_obstacle_line(map_t *map, int start, int size)
{
	int i = 0;

	while (i < size) {
		if (map->grid[start] == 'o'	\
		|| map->grid[start] == '\n'	\
		|| map->grid[start] == '\0')
			return (1);
		start += 1;
		i += 1;
	}
	return (0);
}

void is_max(map_t *map, int i, int size)
{
	if (map->size < size) {
		map->size = size;
		map->start = i;
	}
}

void is_square(map_t *map, int i)
{
	int size = 1;
	int y = 0;

	while (map->grid[i]) {
		if (is_obstacle_col(map, i + y, size)
		|| is_obstacle_line(map, i + (y * (map->nb_cols + 1)), size)) {
			is_max(map, i, size);
			return;
		}
		y += 1;
		size += 1;
	}
}

int bsq_find(map_t *map)
{
	int i = 0;

	while (map->grid[i] != '\0') {
		while (map->grid[i] == '\n' || map->grid[i] == 'o')
			i += 1;
		is_square(map, i);
		i += 1;
	}
	return (0);
}
