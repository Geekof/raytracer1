/*
** intersect_plane.c for raytracer1 in /home/arthur/delivery/bsraytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb  9 13:20:41 2017 Arthur Philippe
** Last update Sat Feb 11 18:26:01 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "raytracer.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (!dir_vector.z)
    return (-1);
  k = -(eye_pos.z / dir_vector.z);
  if (k > 0)
    return (k);
  else
    return (-1);
}
