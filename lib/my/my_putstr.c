/*
** EPITECH PROJECT, 2020
** My Put Str
** File description:
** Print a String
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr(char *c)
{
    write(1, c, my_strlen(c));
}
