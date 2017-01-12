/*
** get_next_line_v2.c for get_next_line_v2.c in /home/james.clerc/CPE_2016/CPE_2016_getnextline
** 
** Made by james clerc
** Login   <james.clerc@epitech.net>
** 
** Started on  Thu Jan 12 15:40:43 2017 james clerc
** Last update Thu Jan 12 23:56:58 2017 james clerc
*/

#include "get_next_line.h"

void	condition_read(int fd, int *readd, int *i, char *save)
{
  if (*readd <= *i)
    {
      *readd = read(fd, save, READ_SIZE);
      *i = 0;
    }
}

void	add_charact(char *ret, char *save, int *i, int *comp)
{
  ret[*comp] = save[*i];
  *comp = *comp + 1;
  *i = *i + 1;
}

char	end_prog(char *ret, int readd, int *i, int comp)
{
  if (comp == 0 && readd == 0)
    return (0);
  else
    {
      *i = *i + 1;
      ret[comp] = '\0';
      return (1);
    }
}

char	*get_next_line(const int fd)
{
  static char	save[READ_SIZE + 2];
  static int	i = 1;
  static int	readd = 1;
  static int	comp = 0;
  char	*ret;
  int	size_of_malloc;

  if (fd == -1)
    return (NULL);
  size_of_malloc = 100000;
  comp = 0;
  ret = malloc(sizeof(char) * size_of_malloc);
  while (readd != 0  && save[i] != '\n')
    {
      condition_read(fd, &readd, &i, save);
      while (readd > i && save[i] != '\n')
	add_charact(ret, save, &i, &comp);
    }
  if (end_prog(ret, readd, &i, comp) == 0)
    return (NULL);
  else
    {
      my_putstr(ret);
      return (ret);
    }
}

