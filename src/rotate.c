/*
** rotate.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 19:51:13 2017 Arthur Philippe
** Last update Fri Feb 24 21:00:28 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

static inline sfVector3f	rotate_angle_converter(sfVector3f angles)
{
  angles.x = angles.x * (PI / 180);
  angles.y = angles.x * (PI / 180);
  angles.z = angles.x * (PI / 180);
  return (angles);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  angles = rotate_angle_converter(angles);
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
  angles = rotate_angle_converter(angles);
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
