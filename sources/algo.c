/*
** algo.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Oct 26 10:26:08 2013 thomas barroqueiro
** Last update Sat Oct 26 16:57:51 2013 thomas barroqueiro
*/

#include		"../includes/mariokart.h"

void			front(t_game *p)
{
  p->cd -= 1;
  if (p->cd == 0)
    p->algo = 0;
}

void			cone(t_game *p)
{
  int			i;
  int			check;

  check = 0;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) < p->largeur / 4)
    {
      move_left_to_right(p);
      check++;
    }
  i++;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) > (p->largeur - (p->largeur / 4)))
    {
      move_right_to_left(p);
      check++;
    }
  if (check == 0)
    p->algo = 0;
}

void			reverse_cone(t_game *p)
{
  int			i;
  int			check;

  check = 0;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) >= p->largeur / 4)
    {
      move_left_to_left(p);
      check++;
    }
  i++;
  while (p->map[i] != '%')
    i++;
  if ((i % p->largeur) <= (p->largeur - (p->largeur / 4)))
    {
      move_right_to_right(p);
      check++;
    }
  if (check == 0)
    p->algo = 0;
}

void			generate_algo(t_game *p)
{
  srand(time(0));
  p->algo = (random() % 5) + 1;
  p->cd = ((random() % 6) + 1) * 5;
}
