/*
** color_modifier.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Mar  8 20:17:05 2017 Arthur Philippe
** Last update Mon Mar 13 12:38:40 2017 Arthur Philippe
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

void	lower_color(sfColor *color)
{
  while (color->r > 50 || color->g > 50 || color->b > 50)
    {
      color->r -= (color->r) ? 1 : 0;
      color->g -= (color->g) ? 1 : 0;
      color->b -= (color->b) ? 1 : 0;
    }
}

static inline int	is_obj_lighten(t_object *list, t_env *env)
{
  float			k;

  k = -1;
  while (list)
    {
      k = obj_fctn_shunter(list, env);
      if (k > 0.001 && k < 1)
	return (0);
      list = list->next;
    }
  return (1);
}

void		color_modifier(t_env *env,
			       t_object *obj,
			       sfVector3f intersect_pt,
			       sfColor *color)
{
  sfVector3f	light_vector;
  sfVector3f	dir_v_save;
  sfVector3f	eye_save;
  sfVector3f	normal;
  int		lighten;
  float		coef;

  dir_v_save = env->curr_dir_vector;
  eye_save = env->eye;
  env->eye = intersect_pt;
  normal = env->last_normal;
  light_vector.x = env->light.x - intersect_pt.x;
  light_vector.y = env->light.y - intersect_pt.y;
  light_vector.z = env->light.z - intersect_pt.z;
  env->curr_dir_vector = light_vector;
  lighten = is_obj_lighten(env->list, env);
  env->curr_dir_vector = dir_v_save;
  env->eye = eye_save;
  // printf("type %d ", env->last_obj);
  if (lighten)
    {
      coef = get_light_coef(rotate_zyx(light_vector, obj->rot), normal);
      coef += (coef < 1) ? 0.1 : 0;
      color->a *= coef;
    }
  else if (!lighten)
    color->a *= 0.1;
}
