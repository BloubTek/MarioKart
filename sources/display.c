/*
** display.c for   in /home/barroq_t//Rush/mariokart/sources
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Sat Oct 26 00:53:16 2013 thomas barroqueiro
** Last update Sat Oct 26 11:35:23 2013 thomas barroqueiro
*/

#include		<term.h>
#include		<curses.h>
#include		"../includes/mariokart.h"

void			clearscreen()
{
  char		*str;

  tgetent(NULL, "xterm");
  str = tgetstr("cl", 0);
  my_putstr(str);
}

void			game_over(t_game *p)
{
  my_putstr("Game Over.\nScore : ");
  my_putnbr(p->score);
  my_putchar('\n');
  exit(1);
}

void			aff_func(t_game *p)
{
  int			i;

  i = 0;
  my_putstr("\nScore : ");
  my_putnbr(p->score);
  my_putchar('\n');
  while (p->map[i])
    {
      my_putchar(p->map[i]);
      if (i % p->largeur == p->largeur - 1)
	my_putchar('\n');
      i++;
    }
}
