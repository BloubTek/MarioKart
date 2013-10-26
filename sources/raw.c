/*
** raw.c for   in /home/barroq_t//Rush/mariokart
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Fri Oct 25 23:04:02 2013 thomas barroqueiro
** Last update Sat Oct 26 15:28:01 2013 thomas barroqueiro
*/

#include		"../includes/mariokart.h"

void			raw_mode(struct termios *t)
{
  if (tcgetattr(0, t) == -1)
    return ;
  t->c_lflag &= ~ECHO;
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, t) == -1)
    {
      my_putstr_err("tcsetattr failed\n");
      return ;
    }
}

void			unraw_mode(struct termios *t)
{
  t->c_lflag &= ICANON;
  if (tcsetattr(0, 0, t) == -1)
    {
      my_putstr_err("tcsetattr failed\n");
      return ;
    }
}
