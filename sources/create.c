/*
** create.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Oct 26 00:52:07 2013 thomas barroqueiro
** Last update Sat Oct 26 14:29:11 2013 thomas barroqueiro
*/

#include		"../includes/mariokart.h"

char			*create_map(t_game *p)
{
  char			*map;
  int			i;

  i = 0;
  map = xmalloc(sizeof(*map) * (p->hauteur * p->largeur) + 1);
  while (i < p->largeur)
    map[i++] = '#';
  while (i < (p->largeur * p->hauteur) - p->largeur)
    {
      if ((i % p->largeur) == 0 || (i % p->largeur) == p->largeur - 1)
	map[i] = '#';
      else
	map[i] = ' ';
      i++;
    }
  while (i < p->largeur * p->hauteur)
    map[i++] = '#';
  map[i] = '\0';
  return (map);
}

void			kart(t_game *p)
{
  int			i;

  i = p->largeur + 1;
  while (i < (2 * p->largeur) - 1)
    {
      if (p->map[i] == '#' || (p->map[i] >= 'A' && p->map[i] <= 'D'))
	p->map[i] = ' ';
      i++;
    }
  if (p->map[p->wheel] == '%' || p->map[p->wheel + 2] == '%'
      || p->map[p->wheel] == '#' || p->map[p->wheel + 2] == '#')
    game_over(p);
  if ((p->map[p->wheel] >= 'A' && p->map[p->wheel] <= 'D')
      || (p->map[p->wheel + 2] >= 'A' && p->map[p->wheel + 2] <= 'D')
      || (p->map[p->wheel + 1] >= 'A' && p->map[p->wheel + 1] <= 'D'))
    p->bonus += 20;
  p->map[p->wheel] = 'o';
  p->map[p->wheel + 1] = 'A';
  p->map[p->wheel + 2] = 'o';
  p->map[p->wheel + p->largeur] = 'o';
  p->map[(p->wheel + p->largeur) + 1] = 'M';
  p->map[(p->wheel + p->largeur) + 2] = 'o';
}

void			wall(t_game *p)
{
  int			pos;

  pos = p->largeur;
  while (pos < (my_strlen(p->map) - p->largeur))
    {
      if (pos % p->largeur == 3 || pos % p->largeur == p->largeur - 3)
	p->map[pos] = '%';
      pos++;
    }
}

void			change_cases(t_game *p)
{
  int			i;

  i = 2 * p->largeur;
  while (p->map[i])
    {
      if (p->map[i] == 'A')
	p->map[i] = 'B';
      else if (p->map[i] == 'B')
	p->map[i] = 'C';
      else if (p->map[i] == 'C')
	p->map[i] = 'D';
      else if (p->map[i] == 'D')
	p->map[i] = 'A';
      i++;
    }
}

void			goin(t_game *p)
{
  char			*new_map;
  int			i;
  int			j;

  i = 0;
  j = p->largeur;
  new_map = xmalloc(sizeof(*new_map) * (p->largeur * p->hauteur));
  while (i < (p->largeur * 2))
    new_map[i] = p->map[i++];
  while (i < (p->largeur * p->hauteur) - p->largeur)
    {
      if (p->map[i] == 'o')
	p->map[i] = ' ';
      else
	new_map[i++] = p->map[j++];
    }
  while (i < (p->largeur * p->hauteur))
    new_map[i++] = '#';
  free(p->map);
  p->map = new_map;
  change_cases(p);
  kart(p);
  obstacle(p, 0);
  bonus(p);
  move_wall(p);
}
