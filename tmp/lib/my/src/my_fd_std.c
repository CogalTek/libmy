/*
** my_fd_std.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 18:01:04 2017 Benjamin Viguier
** Last update Wed May 17 23:47:34 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "internal.h"

t_my_fd	*my_fdin;
t_my_fd	*my_fdout;
t_my_fd	*my_fderr;

LMY_CONSTRUCTOR static void	__libmy_init_stdfd(void)
{
  t_my_fd			*buffer;

  if ((buffer = malloc(sizeof(t_my_fd) * 3)) == NULL)
    return;
  my_memset(buffer, 0, sizeof(t_my_fd) * 3);
  my_fdin = buffer;
  my_fdout = buffer + 1;
  my_fderr = buffer + 2;
  my_fdin->fd = (S_IN);
  my_fdout->fd = (S_OUT);
  my_fderr->fd = (S_ERR);
  my_fdin->auto_flush = LMY_TRUE;
  my_fdout->auto_flush = LMY_TRUE;
  my_fderr->auto_flush = LMY_TRUE;
}

LMY_DESTRUCTOR static void	__libmy_close_stdfd(void)
{
  my_fflush(my_fdin);
  my_fflush(my_fdout);
  my_fflush(my_fderr);
  free(my_fdin);
}
