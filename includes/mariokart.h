/*
** mariokart.h for   in /home/barroq_t//Rush/mariokart/includes
** 
** Made by thomas barroqueiro
** Login   <barroq_t@epitech.net>
** 
** Started on  Fri Oct 25 22:14:17 2013 thomas barroqueiro
** Last update Sat Oct 26 14:44:21 2013 thomas barroqueiro
*/

#ifndef			MARIOKART_H_
# define		MARIOKART_H_

#include		<stdlib.h>
#include		<termios.h>

typedef	struct		s_game	t_game;

struct			s_game
{
  char			*map;
  int			score;
  int			hauteur;
  int			largeur;
  int			bonus;
  int			wheel;
  int			algo;
  int			cd;
  int			obstacle_cd;
  int			bonus_cd;
};

/* move_wall.c */
void			move_left_to_left(t_game *p);
void			move_left_to_right(t_game *p);
void			move_right_to_left(t_game *p);
void			move_right_to_right(t_game *p);
void			move_wall(t_game *p);

/* display.c */
void			aff_func(t_game *p);
void			clearscreen();

/* create.c */
char			*create_map(t_game *p);
void			kart(t_game *p);
void			wall(t_game *p);

/* nbr.c */
int			my_getnbr(char *str);
void			my_putchar(char c);
void			my_putnbr(int nb);

/* raw.c */
void			raw_mode(struct termios *t);
void			unraw_mode(struct termios *t);

/* algo.c */
void			generate_algo(t_game *p);

/* turn.c */
void			turn_right(t_game *p);
void			turn_left(t_game *p);

/* obstacles_and_bonus.c */
void			obstacle(t_game *p, int count);
void			bonus(t_game *p);

/* func.c */
int			my_strlen(char *str);
void			my_putstr_err(char *str);
void			my_putstr(char *str);

/* xfunc.c */
void			*xmalloc(size_t i);
int			xread(int fd, char *str, int i);

#endif			/* !MARIOKART_H_ */
