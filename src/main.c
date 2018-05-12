/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include "bsq.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	bsq(av[1]);
	return (0);
}
