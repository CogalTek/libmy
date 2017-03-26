/*
** my_memgrb_ext.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat Mar 25 17:39:06 2017 Benjamin Viguier
** Last update Sun Mar 26 16:43:30 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "hash_table.h"

size_t		mg_sizeof(void *ptr)
{
  size_t	*size_ptr;

  size_ptr = ptr;
  size_ptr--;
  return (*size_ptr);
}

void		*mg_realloc(t_memgrb *memg, void *old, size_t newsize)
{
  size_t	oldsize;
  void		*new;

  oldsize = mg_sizeof(old);
  if ((new = mg_malloc(memg, newsize)) == NULL)
    return (NULL);
  my_memcpy(new, old, MIN(newsize, oldsize));
  mg_free(memg, old);
  return (new);
}

t_memgrb		*mg_get_maingrb(void)
{
  static t_memgrb	grb;
  static int		is_init;

  if (!is_init)
    {
      if (init_allowed_ht((t_ht*) &grb, 2048, &jenkins_hash_ptr) < 0)
	return (NULL);
      is_init = 1;
    }
  return (&grb);
}

void		mg_clear(t_memgrb *memg)
{
  t_clist_elm	*elm;
  
  while	(memg->len)
    {
      if (memg->buffer[--(memg->len)].value)
	{
	  if (memg->buffer[memg->len].islist)
	    {
	      elm = memg->buffer[memg->len].value;
	      while (elm)
		{
		  elm->ptr -= sizeof(size_t);
		  free(elm->ptr);
		  if ((elm = CLIST_NEXT(memg->buffer[memg->len].value, elm)))
		    free(elm->prev);
		}
	    }
	  else
	    free(memg->buffer[memg->len].value - sizeof(size_t));
	}
    }
  free(memg->buffer);
  free(memg);
}