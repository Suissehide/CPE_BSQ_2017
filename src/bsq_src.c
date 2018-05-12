/*
** EPITECH PROJECT, 2017
** my_sokoban.c
** File description:
** my_sokoban function
*/

#include "bsq.h"

int my_atoi(char *str)
{
	int i = 0;
	int ret = 0;

	while (str[i]) {
		ret = (10 * ret) + str[i] - '0';
		i += 1;
	}
	return (ret);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i += 1;
	return (i);
}

void    my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i += 1;
	}
}

int     my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
