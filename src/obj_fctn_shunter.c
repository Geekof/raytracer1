/*
** obj_fctn_shunter.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 12:56:37 2017 Arthur Philippe
** Last update Tue Mar 14 13:52:54 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

sfVector3f	get_intersection(sfVector3f eye_pos,
				 sfVector3f dir_vector,
				 float k);

inline static float	obj_fctn_sphere(t_object *object,
					t_env *env)
{
  sfVector3f		new_eye;
  float			k;

  new_eye.x = env->eye.x - object->pos.x;
  new_eye.y = env->eye.y - object->pos.y;
  new_eye.z = env->eye.z - object->pos.z;
  k = intersect_sphere(new_eye, env->curr_dir_vector, object->size_a);
  // if (k != -1)
  //   {
  //     env->last_obj = 1;
  //     env->last_intersect = get_intersection(env->eye, env->curr_dir_vector, k);
  //     env->last_normal = get_normal_sphere(env->last_intersect);
  //   }
  return (k);
}

inline static float	obj_fctn_plane(t_object *object,
				       t_env *env)
{
  sfVector3f		new_eye;
  sfVector3f		new_dir_v;
  float			k;

  new_eye.x = env->eye.x;
  new_eye.y = env->eye.y;
  new_eye.z = env->eye.z - object->pos.z;
  new_eye = rotate_zyx(new_eye, object->rot);
  new_dir_v = rotate_zyx(env->curr_dir_vector, object->rot);
  k = intersect_plane(new_eye, new_dir_v);
  // if (k != -1)
  //   {
  //     env->last_obj = 2;
  //     env->last_intersect = get_intersection(env->eye, env->curr_dir_vector, k);
  //     env->last_normal = get_normal_plane(1);
  //   }
  return (k);
}

inline static float	obj_fctn_cylinder(t_object *object,
					  t_env *env)
{
  sfVector3f		new_eye;
  sfVector3f		new_dir_v;
  float			k;

  new_eye.x = env->eye.x - object->pos.x;
  new_eye.y = env->eye.y - object->pos.y;
  new_eye.z = env->eye.z - object->pos.z;
  new_eye = rotate_zyx(new_eye, object->rot);
  new_dir_v = rotate_zyx(env->curr_dir_vector, object->rot);
  k = intersect_cylinder(new_eye, new_dir_v, object->size_a);
  // if (k != -1)
  //   {
  //     env->last_obj = 3;
  //     env->last_intersect = get_intersection(env->eye, env->curr_dir_vector, k);
  //     env->last_normal = get_normal_cylinder(env->last_intersect);
  //   }
  return (k);
}

inline static float	obj_fctn_cone(t_object *object,
				      t_env *env)
{
  sfVector3f		new_eye;
  sfVector3f		new_dir_v;
  float			k;

  new_eye.x = env->eye.x - object->pos.x;
  new_eye.y = env->eye.y - object->pos.y;
  new_eye.z = env->eye.z - object->pos.z;
  new_eye = rotate_zyx(new_eye, object->rot);
  new_dir_v = rotate_zyx(env->curr_dir_vector, object->rot);
  k = intersect_cone(new_eye, new_dir_v, object->size_a);
  // if (k != -1)
  //   {
  //     env->last_obj = 4;
  //     env->last_intersect = get_intersection(env->eye, env->curr_dir_vector, k);
  //     env->last_normal = get_normal_cone(env->last_intersect, object->size_a);
  //   }
  return (k);

}

float			obj_fctn_shunter(t_object *object, t_env *env)
{
  static float		(*obj_intersect[5])(t_object *, t_env *);

  obj_intersect[1] = obj_fctn_sphere;
  obj_intersect[2] = obj_fctn_plane;
  obj_intersect[3] = obj_fctn_cylinder;
  obj_intersect[4] = obj_fctn_cone;
  if (object->type > 0 && object->type <= 4)
    return (obj_intersect[object->type](object, env));
  else
    return (-1);
}
