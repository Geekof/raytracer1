/*
** raytrace_scene.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 22 18:45:40 2017 Arthur Philippe
** Last update Fri Mar  3 16:49:15 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int		raytrace(t_object *list, t_env *env, sfColor *color)
{
  float		last_k;
  float		k;
  sfColor	new_color;

  last_k = k = -1;
  *color = new_color = DEFAULT_COLOR;
  while (list)
    {
      k = obj_fctn_shunter(list, env, &new_color);
      if (k >= 0 && (last_k == -1 || last_k > k))
	{
	  *color = new_color;
	  last_k = k;
	}
      list = list->next;
    }
  return ((k >= 0) ? k : 0);
}

void	raytrace_scene(t_my_framebuffer *buffer, t_object *list, t_env *env)
{
  sfVector2i	sc_pos;
  sfColor	hit_color;

  sc_pos = (sfVector2i) {0, 0};
  while (sc_pos.y < buffer->height)
    {
      env->curr_dir_vector = calc_dir_vector(buffer->width, env->screen_size,
					     sc_pos);
      if (raytrace(list, env, &hit_color) >= 0)
	my_put_pixel(buffer, sc_pos.x, sc_pos.y, hit_color);
      sc_pos.y = (sc_pos.x < buffer->width) ? sc_pos.y : sc_pos.y + 1;
      sc_pos.x = (sc_pos.x < buffer->width) ? sc_pos.x + 1 : 0;
    }
}
