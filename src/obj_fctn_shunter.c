/*
** obj_fctn_shunter.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 12:56:37 2017 Arthur Philippe
** Last update Thu Feb 23 15:04:53 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

static float		obj_fctn_sphere(t_object *object,
					t_env *env,
					sfColor *color)
{
  sfVector3f	new_eye;

  *color = sfRed;
  new_eye.x = env->eye.x - object->pos.x;
  new_eye.y = env->eye.y - object->pos.y;
  new_eye.z = env->eye.z - object->pos.z;
  return (intersect_sphere(new_eye, env->curr_dir_vector, object->size_a));
}

static float		obj_fctn_plane(t_object *object,
				       t_env *env,
				       sfColor *color)
{
  sfVector3f	new_eye;

  *color = sfBlue;
  new_eye.x = env->eye.x;
  new_eye.y = env->eye.y;
  new_eye.z = env->eye.z - object->pos.z;
  return (intersect_plane(new_eye, env->curr_dir_vector));
}

float	obj_fctn_shunter(t_object *object, t_env *env, sfColor *color)
{
  float		(*obj_intersect[5])(t_object *, t_env *, sfColor *);

  obj_intersect[1] = obj_fctn_sphere;
  obj_intersect[2] = obj_fctn_plane;
  if (object->type > 0 && object->type <= 2)
    return (obj_intersect[object->type](object, env, color));
  else
    return (-1);
}
