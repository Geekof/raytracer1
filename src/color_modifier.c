/*
** color_modifier.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Mar  8 20:17:05 2017 Arthur Philippe
** Last update Tue Mar 14 09:40:28 2017 Arthur Philippe
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
      if (k > 0.0001 && k < 1)
	return (0);
      list = list->next;
    }
  return (1);
}

void	set_light_and_normal(sfVector3f *light,
			     sfVector3f *normal,
			     t_env *env,
			     t_object *obj)
{
  sfVector3f	intersect_pt;

  intersect_pt = translate_inv(env->last_intersect, obj->pos);
  *light = rotate_zyx(*light, obj->rot);
  intersect_pt = rotate_zyx(intersect_pt, obj->rot);
  if (obj->type == 1)
    *normal = get_normal_sphere(intersect_pt);
  else if (obj->type == 2)
    *normal = get_normal_plane(1);
  else if (obj->type == 3)
    *normal = get_normal_cylinder(intersect_pt);
  else if (obj->type == 4)
    *normal = get_normal_cone(intersect_pt, obj->size_a);
  *normal = rotate_zyx(*normal, obj->rot);
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

  light_vector.x = env->light.x - env->last_intersect.x;
  light_vector.y = env->light.y - env->last_intersect.y;
  light_vector.z = env->light.z - env->last_intersect.z;
  dir_v_save = env->curr_dir_vector;
  eye_save = env->eye;
  env->curr_dir_vector = light_vector;
  env->eye = intersect_pt;
  // lighten = is_obj_lighten(env->list, env);
  set_light_and_normal(&light_vector, &normal, env, obj);
  if (lighten || 1)
    {
      coef = get_light_coef(light_vector, normal);
      coef += (coef < 0.9) ? 0.1 : (coef > 0.9 && coef < 1) ? 1 - coef : 0;
      color->a *= coef;
    }
  else if (!lighten)
    color->a *= 0.1;
  env->curr_dir_vector = dir_v_save;
  env->eye = eye_save;
}
