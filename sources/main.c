/*
** main.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Fri Oct 25 22:16:53 2013 thomas barroqueiro
** Last update Sat Oct 26 14:45:05 2013 thomas barroqueiro
*/

#include		<time.h>
#include		"../includes/mariokart.h"

static	int		check_arg(int ac, char **av)
{
  if (ac != 3)
    {
      my_putstr_err("Wrong arguments.\n");
      return (-1);
    }
  if (my_getnbr(av[1]) < 10 || my_getnbr(av[2]) < 10)
    {
      my_putstr("The map is too little (10 10 at least).\n");
      return (-1);
    }
  return (0);
}

static	void		init_var(t_game *p, char *av1, char *av2)
{
  p->score = 0;
  p->hauteur = my_getnbr(av1);
  p->largeur = my_getnbr(av2);
  p->map = create_map(p);
  p->wheel = (my_strlen(p->map) - (p->largeur * 2)) - (p->largeur / 2) - 1;
  kart(p);
  wall(p);
  p->bonus = 0;
  p->algo = 0;
  p->cd = 0;
  p->obstacle_cd = 6;
  p->bonus_cd = 4;
}

static	void		drive(t_game *p)
{
  char			*buffer;

  buffer = xmalloc(sizeof(*buffer) * 5);
  if (p->algo == 0)
    generate_algo(p);
  xread(1, buffer, 4);
  if (buffer[2] == 'D')
    p->wheel -= 1;
  else if (buffer[2] == 'C')
    p->wheel += 1;
  clearscreen();
  goin(p);
}

int			main(int ac, char **av)
{
  struct termios	t;
  t_game		p;
  time_t		ti;

  if (check_arg(ac, av) == -1)
    return (-1);
  ti = time(0);
  init_var(&p, av[1], av[2]);
  raw_mode(&t);
  while (42)
    {
      drive(&p);
      p.score = (1 + ((time(0) - ti) * 0.2) + p.bonus);
      aff_func(&p);
      usleep(200000);
    }
  unraw_mode(&t);
  free(p.map);
  return (0);
}
