/*
** my_put_nbr.c for   in /home/barroq_t//lib
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Fri Feb  8 09:34:04 2013 thomas barroqueiro
** Last update Fri Oct 25 23:48:09 2013 thomas barroqueiro
*/

#include	"../includes/mariokart.h"

int		my_getnbr(char *str)
{
  int	neg;
  int	num;
  int	i;

  num = 0;
  neg = 1;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	neg = neg * - 1;
      i++;
    }
  if (str[i] < '0' || str[i] > '9')
    return (0);
  while (str[i] >= '0' && str[i] <= '9')
    {
      num = num * 10 + (str[i] - 48);
      i++;
    }
  num = num * neg;
  if (my_strlen(str) > 10)
    return (0);
  return (num);
}

void		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return ;
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putstr("-");
      my_putnbr(-nb);
    }
  else
    {
      if (nb / 10 > 0)
	my_putnbr(nb / 10);
      my_putchar('0' + nb % 10);
    }
}
