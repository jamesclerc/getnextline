/*
** get_next_line_v2.c for get_next_line_v2.c in /home/james.clerc/CPE_2016/CPE_2016_getnextline
** 
** Made by james clerc
** Login   <james.clerc@epitech.net>
** 
** Started on  Thu Jan 12 15:40:43 2017 james clerc
** Last update Sat Jan 14 16:57:44 2017 james clerc
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	condition_read(int fd, int *readd, int *taille, char *save)
{
  if (*readd <= *taille)
    {
      *readd = read(fd, save, READ_SIZE);
      *taille = 0;
    }
}

void	add_charact(char *ret, char *save, int *taille, int *comp)
{
  ret[*comp] = save[*taille];
  *comp = *comp + 1;
  *taille = *taille + 1;
}

char	end_prog(char *ret, int readd, int *taille, int comp)
{
  if (comp == 0 && readd == 0)
    return (0);
  else
    {
      *taille = *taille + 1;
      ret[comp] = '\0';
      return (1);
    }
}

char	*get_next_line(const int fd)
{
  static char	save[READ_SIZE + 2];
  static int	taille = 1;
  static int	readd = 1;
  static int	comp = 0;
  char	*ret;
  int	size_of_malloc;

  if (fd == -1 || READ_SIZE <= 0)
    return (NULL);
  size_of_malloc = 100000;
  comp = 0;
  ret = malloc(sizeof(char) * size_of_malloc);
  if (ret == NULL)
    return (NULL);
  while (readd != 0  && save[taille] != '\n')
    {
      condition_read(fd, &readd, &taille, save);
      while (readd > taille && save[taille] != '\n')
	add_charact(ret, save, &taille, &comp);
    }
  if (end_prog(ret, readd, &taille, comp) == 0)
    return (NULL);
  else
    return (ret);
}
