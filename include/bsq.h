/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** bsq header
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_map
{
	char *grid;
	int start;
	int size;
	int nb_lines;
	int nb_cols;
} map_t;

void bsq(char *);

// Display //
void display_error(char *, int);
void bsq_display(map_t *);
void bsq_draw(map_t **);

// Init //
map_t *init_map(char *);

// Find max square //
int bsq_find(map_t *);

// SRC //
int my_putchar(char);
void my_putstr(char *);
int my_strlen(char *);
int my_atoi(char *);

#define BUFF_SIZE 900000000

#endif /* BSQ_H_ */
