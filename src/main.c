/*
** main.c for raytracer1 in /home/arthur/delivery/raytracer1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Feb 15 19:36:12 2017 Arthur Philippe
** Last update Mon Feb 20 21:44:31 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	window_loop(t_my_window *, t_env *);
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
    acp_print("%sraytracer: %serror:%s something went wrong\n", BOLD, RED, RST);
  acp_print("run terminated.\n");
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
  open_window(&w, &env);
  while (window_loop(&w, &env));
  destroy_objects(list);
  window_destroy(&w);
  return (0);
}

int	window_loop(t_my_window *w, t_env *env)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(w->window, &event))
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
