/*
** turn.c for  in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Oct 26 11:03:10 2013 thomas barroqueiro
** Last update Sat Oct 26 14:44:37 2013 thomas barroqueiro
*/

#include		"../includes/mariokart.h"

void			turn_right(t_game *p)
{
  int			i;
  int			j;
  int			check;

  check = 0;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  j = i + 1;
  while (p->map[j] != '%')
    j++;
  if ((i % p->largeur) < (p->largeur / 2))
    {
      move_left_to_right(p);
      check++;
    }
  if ((j % p->largeur) < (p->largeur - 2))
    {
      move_right_to_right(p);
      check++;
    }
  if (check == 0)
    p->algo = 0;
}

void			turn_left(t_game *p)
{
  int			i;
  int			check;

  check = 0;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) > 1)
    {
      move_left_to_left(p);
      check++;
    }
  i++;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) > (p->largeur / 2))
    {
      move_right_to_left(p);
      check++;
    }
  if (check == 0)
    p->algo = 0;
}
