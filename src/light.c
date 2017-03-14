/*
** light.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Mar  7 12:15:12 2017 Arthur Philippe
** Last update Tue Mar 14 09:42:25 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"

static inline float	get_norm(sfVector3f in)
{
  float			norm;

  norm = sqrtf((in.x * in.x) + (in.y * in.y) + (in.z * in.z));
  return (norm);
}

static inline void	normalize_vectors(sfVector3f *st, sfVector3f *nd,
					  float	st_norm, float nd_norm)
{
  st->x = st->x / st_norm;
  st->y = st->y / st_norm;
  st->z = st->z / st_norm;
  nd->x = nd->x / nd_norm;
  nd->y = nd->y / nd_norm;
  nd->z = nd->z / nd_norm;
}

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	dot;
  float	l_norm;
  float	n_norm;
  float norms;
  float result;

  l_norm = get_norm(light_vector);
  n_norm = get_norm(normal_vector);
  norms = l_norm * n_norm;
  if (!norms)
    return (0);
  dot = light_vector.x * normal_vector.x + light_vector.y * normal_vector.y;
  dot += normal_vector.z * light_vector.z;
  result = dot / norms;
  if (result < 0)
    return (0);
  if (result > 1)
    return (1);
  return (result);
}

float	get_light_coef_bis(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	cos_a;

  cos_a = normal_vector.x * light_vector.x;
  cos_a += normal_vector.y * light_vector.y;
  cos_a += normal_vector.z * light_vector.z;
  if (cos_a < 0)
    return (0);
  else
    return (cos_a);
}
