/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Initialise all game object
*/

#include "../include/my_runner.h"

void init_clock(clock_st *clock)
{
    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
}

void init_sprite(sprite *obj, char const *path)
{
    sfColor color = {255, 255, 255, obj->alpha};
    sfVector2u width_height = {0, 0};

    obj->t = sfTexture_createFromFile(path, NULL);
    obj->s = sfSprite_create();
    width_height = sfTexture_getSize(obj->t);
    obj->width = width_height.x;
    obj->height = width_height.y;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = obj->offset[1];
    obj->rect.height = obj->height;
    sfSprite_setPosition(obj->s, obj->pos);
    sfSprite_setTexture(obj->s, obj->t, sfTrue);
    sfSprite_setTextureRect(obj->s, obj->rect);
    sfSprite_setColor(obj->s, color);
}

void init_txt(txt_st *t, char const *path, char const *str)
{
    t->txt = sfText_create();
    t->font = sfFont_createFromFile(path);
    sfText_setString(t->txt, str);
    sfText_setFont(t->txt, t->font);
    sfText_setCharacterSize(t->txt, t->size);
    sfText_setPosition(t->txt, t->pos);
    sfText_setColor(t->txt, t->color);
}

void init_sfx(sfx_st *sfx_obj, char const *path)
{
    if (sfx_obj->type == MUSIC) {
        sfx_obj->music = sfMusic_createFromFile(path);
        sfMusic_setVolume(sfx_obj->music, sfx_obj->volume);
        sfMusic_setLoop(sfx_obj->music, sfTrue);
    } else if (sfx_obj->type == SOUND) {
        sfx_obj->buffer = sfSoundBuffer_createFromFile(path);
        sfx_obj->sound = sfSound_create();
        sfSound_setBuffer(sfx_obj->sound, sfx_obj->buffer);
        sfSound_setVolume(sfx_obj->sound, sfx_obj->volume);
    }
}
