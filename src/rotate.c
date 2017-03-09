/*
** rotate.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 23 19:51:13 2017 Arthur Philippe
** Last update Thu Mar  9 13:03:33 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "math.h"
#include "raytracer.h"

static inline sfVector3f	rotate_angle_converter(sfVector3f angles)
{
  angles.x = angles.x * (PI / 180);
  angles.y = angles.y * (PI / 180);
  angles.z = angles.z * (PI / 180);
  return (angles);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = rotate_angle_converter(angles);
  tmp.x = X_TRANSLATE_X;
  tmp.y = Y_TRANSLATE_X;
  tmp.z = Z_TRANSLATE_X;
  to_rotate = tmp;
  tmp.x = X_TRANSLATE_Y;
  tmp.y = Y_TRANSLATE_Y;
  tmp.z = Z_TRANSLATE_Y;
  to_rotate = tmp;
  tmp.x = X_TRANSLATE_Z;
  tmp.y = Y_TRANSLATE_Z;
  tmp.z = Z_TRANSLATE_Z;
  to_rotate = tmp;
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = rotate_angle_converter(angles);
  tmp.x = X_TRANSLATE_Z;
  tmp.y = Y_TRANSLATE_Z;
  tmp.z = Z_TRANSLATE_Z;
  to_rotate = tmp;
  tmp.x = X_TRANSLATE_Y;
  tmp.y = Y_TRANSLATE_Y;
  tmp.z = Z_TRANSLATE_Y;
  to_rotate = tmp;
  tmp.x = X_TRANSLATE_X;
  tmp.y = Y_TRANSLATE_X;
  tmp.z = Z_TRANSLATE_X;
  to_rotate = tmp;
  return (to_rotate);
}
