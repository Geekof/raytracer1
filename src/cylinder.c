/*
** cylinder.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Feb 24 15:24:47 2017 Arthur Philippe
** Last update Fri Feb 24 21:11:02 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>

float	solve_quadric_eq(float discriminant, float a, float b);

static inline sfVector3f	define_quadric_eq_vars(sfVector3f eye_pos,
						       sfVector3f dir_vector,
						       float radius)
{
  sfVector3f		abc;

  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.y = (eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y);
  abc.y *= 2;
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z -= powf(radius, 2);
  return (abc);
}

float	intersect_cylinder(sfVector3f eye_pos,
			   sfVector3f dir_vector,
			   float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quadric_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  sol = solve_quadric_eq(discriminant, abc.x, abc.y);
  return (sol);
}
