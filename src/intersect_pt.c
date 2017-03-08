/*
** intersect_pt.c for raytracer in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Mar  8 20:17:05 2017 Arthur Philippe
** Last update Wed Mar  8 20:31:10 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

inline sfVector3f	get_intersection(sfVector3f eye_pos,
					 sfVector3f dir_vector,
					 float k)
{
  sfVector3f		out;

  out.x = dir_vector.x * k + eye_pos.x;
  out.y = dir_vector.y * k + eye_pos.y;
  out.z = dir_vector.z * k + eye_pos.z;
  return (out);
}
