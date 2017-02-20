/*
** objects_creation.c for raytracer1 in /home/arthur/delivery/raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Feb 18 11:24:50 2017 Arthur Philippe
** Last update Mon Feb 20 21:04:21 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	resolve_object_type(char *str)
{
  if (match(str, OBJ_SPHERE))
    return (1);
  else if (match(str, OBJ_PLANE))
    return (2);
  else if (match(str, OBJ_CYLINDER))
    return (3);
  else if (match(str, OBJ_CONE))
    return (4);
  return (0);
}

char	*get_object_type(int type)
{
  if (type == 1)
    return (TYPE_SPHERE);
  else if (type == 2)
    return (TYPE_PLANE);
  else if (type == 3)
    return (TYPE_CYLINDER);
  else if (type == 4)
    return (TYPE_CONE);
  else
    return (TYPE_UNK);
}

t_object	*create_object(char *buffer, int *idx)
{
  t_object	*new_object;

  if (!(new_object = create_list_node()))
    return (NULL);
  new_object->next = NULL;
  while (buffer[*idx])
    {
      if (buffer[*idx] == 'A')
	new_object->size_a = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'B')
	new_object->size_b = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'X')
  	new_object->pos.x = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'Y')
	new_object->pos.y = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'Z')
	new_object->pos.z = my_getnbr(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'T')
	new_object->type = resolve_object_type(&buffer[*idx + 2]);
      else if (buffer[*idx] == 'E')
	break;
      while (buffer[*idx] && buffer[(*idx)++] != '\n');
    }
  return (new_object);
}
