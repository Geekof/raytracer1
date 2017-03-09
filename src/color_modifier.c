/*
** color_modifier.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Mar  8 20:17:05 2017 Arthur Philippe
** Last update Thu Mar  9 12:27:14 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

sfVector3f	get_intersection(sfVector3f eye_pos,
				 sfVector3f dir_vector,
				 float k)
{
  sfVector3f		out;

  out.x = dir_vector.x * k + eye_pos.x;
  out.y = dir_vector.y * k + eye_pos.y;
  out.z = dir_vector.z * k + eye_pos.z;
  return (out);
}

static inline int	is_obj_lighten(t_object *list, t_env *env)
{
  float			k;

  k = -1;
  while (list)
    {
      k = obj_fctn_shunter(list, env);
      if (k > 0 && k < 1)
	return (0);
      list = list->next;
    }
  return (1);
}

void		color_modifier(t_env *env,
			       sfVector3f intersect_pt,
			       sfColor *color)
{
  sfVector3f	light_vector;
  sfVector3f	dir_v_save;
  sfVector3f	eye_save;
  int		lighten;

  dir_v_save = env->curr_dir_vector;
  eye_save = env->eye;
  env->eye = env->light;
  light_vector.x = env->light.x - intersect_pt.x;
  light_vector.y = env->light.y - intersect_pt.y;
  light_vector.z = env->light.z - intersect_pt.z;
  env->curr_dir_vector = light_vector;
  lighten = is_obj_lighten(env->list, env);
  env->curr_dir_vector = dir_v_save;
  env->eye = eye_save;
  if (!lighten)
    *color = sfBlack;
}
