/*
** func.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Fri Oct 25 22:32:54 2013 thomas barroqueiro
** Last update Fri Oct 25 22:44:47 2013 thomas barroqueiro
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"../includes/mariokart.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

void			my_putstr_err(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return ;
}

void			my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    {
      my_putstr_err("write failed\n");
      return ;
    }
}
