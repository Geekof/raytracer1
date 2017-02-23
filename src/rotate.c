/*
** rotate.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 19:51:13 2017 Arthur Philippe
** Last update Thu Feb 23 21:13:57 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate.x = X_TRANSLATE_X;
  to_rotate.y = Y_TRANSLATE_X;
  to_rotate.z = Z_TRANSLATE_X;
  to_rotate.x = X_TRANSLATE_Y;
  to_rotate.y = Y_TRANSLATE_Y;
  to_rotate.z = Z_TRANSLATE_Y;
  to_rotate.x = X_TRANSLATE_Z;
  to_rotate.y = Y_TRANSLATE_Z;
  to_rotate.z = Z_TRANSLATE_Z;
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate.x = X_TRANSLATE_Z;
  to_rotate.y = Y_TRANSLATE_Z;
  to_rotate.z = Z_TRANSLATE_Z;
  to_rotate.x = X_TRANSLATE_Y;
  to_rotate.y = Y_TRANSLATE_Y;
  to_rotate.z = Z_TRANSLATE_Y;
  to_rotate.x = X_TRANSLATE_X;
  to_rotate.y = Y_TRANSLATE_X;
  to_rotate.z = Z_TRANSLATE_X;
  return (to_rotate);
}
