/*
** obstacles_and_bonus.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Oct 26 14:28:29 2013 thomas barroqueiro
** Last update Sat Oct 26 14:30:52 2013 thomas barroqueiro
*/

#include		"../includes/mariokart.h"

void			obstacle(t_game *p, int count)
{
  int			i;
  int			pos;

  srand(p->hauteur + p->largeur + p->score);
  if ((random() % 3) == 2)
    p->obstacle_cd -= 1;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  i++;
  while (p->map[i] != '%')
    {
      i++;
      count++;
    }
  pos = i - (random() % count); 
  if (p->obstacle_cd == 0 && count > 3)
    {
      if (p->map[pos] == ' ')
	p->map[pos] = '#';
      if (p->map[pos - 1] == ' ')
	p->map[pos - 1] = '#';
      p->obstacle_cd = 6;
    }
}

void			bonus(t_game *p)
{
  int			i;
  int			pos;
  int			count;

  if ((random() % 3) == 2)
    p->bonus_cd -= 1;
  count = 0;
  i = p->largeur;
  while (p->map[i] != '%')
    i++;
  i++;
  while (p->map[i] != '%')
    {
      i++;
      count++;
    }
  pos = i - (random() % count); 
  if (p->bonus_cd == 0 && count > 3)
    {
      if (p->map[pos] == ' ')
	p->map[pos] = 'A';
      p->bonus_cd = 12;
    }
}
