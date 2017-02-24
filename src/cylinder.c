/*
** cylinder.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Feb 24 15:24:47 2017 Arthur Philippe
** Last update Fri Feb 24 15:52:08 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>

static sfVector3f	define_quadric_eq_vars(sfVector3f eye_pos,
					       sfVector3f dir_vector,
					       float radius)
{
  sfVector3f	abc;

  abc.x = powf(dir_vector.y, 2) + powf(dir_vector.z, 2);
  abc.y = (dir_vector.y * eye_pos.y) + (dir_vector.z * eye_pos.z);
  abc.y *= 2;
  abc.z = powf(eye_pos.y, 2) + powf(eye_pos.z, 2) - powf(radius, 2);
  return (abc);
}

float	intersect_cylinder(sfVector3f eye_pos,
			   sfVector3f dir_vector,
			   float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		k;

  abc = define_quadric_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  k = solve_quadric_eq(discriminant, abc.x, abc.y);
  return (k);
}
