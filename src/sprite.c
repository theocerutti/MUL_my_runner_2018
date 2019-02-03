/*
** EPITECH PROJECT, 2018
** Handle sprite
** File description:
** Handle sprite
*/

#include "../include/my_runner.h"

void anim_sprite(sprite *s)
{
    s->rect.left += s->offset[0];
    if (s->rect.left > s->width - s->offset[1])
        s->rect.left = 0;
    sfSprite_setTextureRect(s->s, s->rect);
}

void anim_sprite_list(l_list list)
{
    while (list != NULL) {
        anim_sprite(&list->obj);
        list = list->next;
    }
}
