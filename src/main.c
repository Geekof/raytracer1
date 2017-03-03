/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Fri Mar  3 16:51:50 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	window_loop(t_my_window *);
int	raytracer_launcher();

int	main(int ac, char **av)
{
  int	status;

  status = 0;
  if (ac < 2)
    {
      acp_putstr(STDERR_FILENO, MSG_TOO_FEW_ARG);
      status = 84;
    }
  else
    status = raytracer_launcher(av[1]);
  if (status)
    acp_print(MSG_INTERUPTED, BOLD, RED, RST);
  else
    acp_print(MSG_QUIT);
  return (status);
}

int	raytracer_launcher(char *file_name)
{
  t_my_window	w;
  t_env		env;
  t_object	*list;

  list = get_objects_from_file(file_name);
  if (!list)
    return (84);
  env.eye = (sfVector3f) {-400, 0, 0};
  open_window(&w, list, &env);
  while (window_loop(&w));
  destroy_objects(list);
  window_destroy(&w);
  return (0);
}

int	window_loop(t_my_window *w)
{
  sfEvent	event;

  while (sfRenderWindow_waitEvent(w->window, &event))
    {
      if (event.type == sfEvtClosed
	  || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
	{
	  sfRenderWindow_close(w->window);
	  return (0);
	}
    }
  return (1);
}
