/*
** raytracer.c for raytracer.c in /home/arthur/delivery/bsraytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Feb  7 10:44:55 2017 Arthur Philippe
** Last update Fri Feb 24 20:51:39 2017 Arthur Philippe
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# define EXIT_SUCCESS	0
# define EXIT_FAIL	84
# define EXIT_ARG_COUNT	84
# define BUFFER_SIZE	10000
# define SC_W		1280
# define SC_H		720
# define WINDOW_NAME	"Raytracer"
# define FILE_NAME	"objects.tracr"
# define OBJ_START	"OBJECT*"
# define OBJ_END	"END_OBJECT*"
# define OBJ_SPHERE	"SPHERE*"
# define OBJ_PLANE	"PLANE*"
# define OBJ_CYLINDER	"CYLINDER*"
# define OBJ_CONE	"CONE*"
# define PI		3.14159265359
# define XA		angles.x
# define YA		angles.y
# define ZA		angles.z
# define DEFAULT_COLOR	sfBlack
# define X_TRANSLATE_X	(to_rotate.x)
# define Y_TRANSLATE_X	((to_rotate.y * cosf(XA)) + (to_rotate.z * -sinf(XA)))
# define Z_TRANSLATE_X	((to_rotate.y * sinf(XA)) + (to_rotate.z * cosf(XA)))
# define X_TRANSLATE_Y	((to_rotate.x * cosf(YA)) + (to_rotate.z * sinf(YA)))
# define Y_TRANSLATE_Y	((to_rotate.y))
# define Z_TRANSLATE_Y	((to_rotate.x * -sinf(YA)) + (to_rotate.z * cosf(YA)))
# define X_TRANSLATE_Z	((to_rotate.x * cosf(ZA)) + (to_rotate.y * -sinf(ZA)))
# define Y_TRANSLATE_Z	((to_rotate.x * sinf(ZA)) + (to_rotate.y * cosf(ZA)))
# define Z_TRANSLATE_Z	(to_rotate.z)


typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_window
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*tex;
  t_my_framebuffer	*buffer;
}			t_my_window;

typedef struct		s_object
{
  int			type;
  float			size_a;
  float			size_b;
  sfVector3f		pos;
  sfVector3f		rot;
  struct s_object	*next;
}			t_object;

typedef struct		s_env
{
  sfVector3f		eye;
  sfVector3f		curr_dir_vector;
  sfVector2i		screen_size;
}			t_env;
/*
** Mandatory
*/
void		my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector3f	calc_dir_vector(float, sfVector2i, sfVector2i);
float		intersect_sphere(sfVector3f, sfVector3f, float radius);
float		intersect_plane(sfVector3f, sfVector3f);
float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector,
				   float radius);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);

/*
** window related implements.
*/
int			open_window(t_my_window *, t_object *, t_env *);
sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
void			wf_window_destroy(t_my_window *);
void			wf_refresh_window(t_my_window *,
					  t_env *,
					  int *);
void			reset_pixels(t_my_framebuffer *buffer);
/*
** Render
*/
void	raytrace_scene(t_my_framebuffer *buffer, t_object *list, t_env *env);
int	raytracer(t_object *list, t_env *env, sfColor *color);
float	obj_fctn_shunter(t_object *object, t_env *env, sfColor *);
/*
** Math
*/
float		get_quadric_discriminant(sfVector3f);
sfVector3f	define_quadric_eq_vars(sfVector3f eye_pos,
				       sfVector3f dir_vector,
				       float radius);
float		solve_quadric_eq(float discriminant, float a, float b);
/*
** Data obliteration - for your destructive needs.
*/
void	window_destroy(t_my_window *);
void	destroy_objects(t_object *);

int		acp_putstr(int fd, char *str);
void		*my_memset(void *str, int c, int size);
int		my_getnbr(char *);
#endif /* !RAYTRACER_H_ */
