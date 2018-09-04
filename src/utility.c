/*
** EPITECH PROJECT, 2018
** strace.h
** File description:
** utility.c
*/

#include <stdlib.h>

int count_env(char **env)
{
	int count = 0;

	while (env[count] != NULL)
		count += 1;
	return (count);
}
