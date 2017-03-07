/*
** light.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Mar  7 12:15:12 2017 Arthur Philippe
** Last update Tue Mar  7 15:21:17 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "raytracer.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
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
