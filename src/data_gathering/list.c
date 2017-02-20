/*
** list.c for raytracer1 in /home/arthur/delivery/raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Feb 20 12:30:23 2017 Arthur Philippe
** Last update Mon Feb 20 21:09:37 2017 Arthur Philippe
*/

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_data.h"

t_object	*add_to_object_list(t_object *new_object, t_object *objects)
{
  t_object	*current_obj;

  current_obj = objects;
  if (!objects)
    return (new_object);
  while (current_obj->next)
    current_obj = current_obj->next;
  current_obj->next = new_object;
  return (objects);
}

t_object	*create_list_node()
{
  t_object	*obj;

  obj = malloc(sizeof(t_object));
  if (!obj)
    return (NULL);
  my_memset(obj, 0, sizeof(t_object));
  return (obj);
}

int		check_list_content(t_object *list)
{
  int		i;
  t_object	*current;

  i = 1;
  if (!list)
    return (-1);
  current = list;
  while (current->next)
    {
      acp_print("Object #%d is a %s.\n", i, get_object_type(current->type));
      current = current->next;
      i += 1;
    }
  acp_print("Object #%d is a %s.\n", i, get_object_type(current->type));
  acp_print("\nLoaded %d objects total.\n", i);
  return (i);
}
