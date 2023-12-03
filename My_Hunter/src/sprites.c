/*
** EPITECH PROJECT, 2023
** test
** File description:
** sprites
*/

#include "../include/my.h"

void destroy_textures(global_t *global)
{
    my_putstr("\n>Textures : succefully destroyed\n");
    sfTexture_destroy(global->menu.back.texture);
    sfTexture_destroy(global->menu.start.texture);
    sfTexture_destroy(global->menu.satyr.texture);
    sfTexture_destroy(global->game.back.texture);
    sfTexture_destroy(global->game.sprite1.texture);
    sfTexture_destroy(global->game.sprite2.texture);
    sfTexture_destroy(global->game.sprite3.texture);
    sfTexture_destroy(global->game.sprite4.texture);
    sfTexture_destroy(global->over.back.texture);
    sfTexture_destroy(global->over.over.texture);
    sfTexture_destroy(global->over.restart.texture);
    sfTexture_destroy(global->over.stand1.texture);
}

void destroy_music(music_t *music)
{
    my_putstr("\n>Sounds : succefully destroyed\n");
    sfSound_destroy(music->sound_menu);
    sfSound_destroy(music->sound_game);
    sfSound_destroy(music->sound_over);
    sfSoundBuffer_destroy(music->buf_menu);
    sfSoundBuffer_destroy(music->buf_game);
    sfSoundBuffer_destroy(music->buf_over);
}

static sfIntRect create_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = rand() % 192 / 32 * 32;
    rect.width = 32;
    rect.height = 32;
    return rect;
}

void run(game_t *game)
{
    game->sprite1.pos.x += game->sprite1.velocity.x;
    game->sprite2.pos.x += game->sprite2.velocity.x;
    game->sprite3.pos.x += game->sprite3.velocity.x;
    game->sprite4.pos.x += game->sprite4.velocity.x;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left += offset;
}

void init_sprite(sprite_t *sprite)
{
    sfTexture *texture = sfTexture_createFromFile("asset/run.png", NULL);

    sprite->texture = texture;
    sprite->sprite = sfSprite_create();
    sprite->scale = (sfVector2f){6.0, 6.0};
    sprite->pos = (sfVector2f){-(rand() % 600), (rand() % 800) + 50};
    sprite->velocity = (sfVector2f){(rand() % 10 + 20), 0};
    sprite->rect = create_rect();
    sfSprite_setTexture(sprite->sprite, texture, sfTrue);
}
