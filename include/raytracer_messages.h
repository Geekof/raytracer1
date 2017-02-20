/*
** raytracer_messages.h for raytracer1 in /home/arthur/delivery/raytracer1/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 16 16:35:31 2017 Arthur Philippe
** Last update Mon Feb 20 21:43:39 2017 Arthur Philippe
*/

#ifndef RAYTRACER_MESSAGES_H_
# define RAYTRACER_MESSAGES_H_

# define MSG_FD_ERROR		"File related error: "
# define MSG_FC_ERROR		"File content error: "
# define MSG_MISSING_FILE	"No such file or directory\n"
# define MSG_PERMISSION		"Permission denied\n"
# define MSG_IS_DIR		"Is a directory\n"
# define MSG_UNKNOWN		"Unexpected error\n"
# define MSG_TOO_FEW_ARG	"raytracer: too few arguments\n"

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RST		"\x1b[0m"
# define BOLD		"\033[1m"

# define TYPE_SPHERE		"sphere"
# define TYPE_PLANE		"plane"
# define TYPE_CYLINDER		"cylinder"
# define TYPE_CONE		"cone"
# define TYPE_UNK		"potato"

#endif /* !RAYTRACER_MESSAGES_H_ */