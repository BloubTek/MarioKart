/*
** xmalloc.c for   in /home/barroq_t/Rush/Rush1
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Dec  1 11:10:15 2012 thomas barroqueiro
** Last update Sat Oct 26 11:43:32 2013 thomas barroqueiro
*/

#include	"../includes/mariokart.h"

void		*xmalloc(size_t i)
{
  void		*rtrn;

  if ((rtrn = malloc(i)) == NULL)
    exit(1);
  return (rtrn);
}

int		xread(int fd, char *str, int i)
{
  int		rd;

  if ((rd = read(fd, str, i)) == -1)
    exit(1);
  return (rd);
}
