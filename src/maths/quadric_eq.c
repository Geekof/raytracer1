/*
** quadric_eq.c for raytracer1 in /home/arthur/delivery/raytracer1/src/maths/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun Feb 12 17:54:05 2017 Arthur Philippe
** Last update Wed Feb 15 19:27:15 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>

float	get_quadric_discriminant(sfVector3f abc)
{
  float	discriminant;

  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  return (discriminant);
}

sfVector3f	define_quadric_eq_vars(sfVector3f eye_pos,
				       sfVector3f dir_vector,
				       float radius)
{
  sfVector3f	abc;

  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.x += powf(dir_vector.z, 2);
  abc.y = (eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y);
  abc.y += eye_pos.z * dir_vector.z;
  abc.y *= 2;
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z += powf(eye_pos.z, 2);
  abc.z -= powf(radius, 2);
  return (abc);
}

float	solve_quadric_eq(float discriminant, float a, float b)
{
  float	sol;
  float	tmp;

  tmp = 0;
  if (!discriminant)
    {
      sol = -b;
      sol /= 2 * a;
      return (sol);
    }
  else if (discriminant > 0)
    {
      sol = -b + sqrtf(discriminant);
      sol /= 2 * a;
      tmp = -b - sqrtf(discriminant);
      tmp /= 2 * a;
      if (tmp > 0 && tmp < sol)
	return (tmp);
      return (sol);
    }
  return (-1);
}
