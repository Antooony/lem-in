/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:20:23 by adenis            #+#    #+#             */
/*   Updated: 2017/03/27 21:40:40 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
# include "libft/libft.h"
# define LINE ((char *)lst->content)
# define LTMP (char **)&tmp->content
# define LLST (char **)&lst->content
# define START infos.start
# define BEGIN infos.begin
# define END infos.end

typedef	struct	s_room t_room;

struct			s_room
{
	char		*name;
	t_room		*next;
	t_room		**connexions;
	int			start;
	int			end;
	int			stop;
};


typedef struct	s_parse t_parse;

struct			s_parse
{
	t_room		*begin;
	t_room		*start;
	t_room		*end;
};

t_parse			infos;

int				check_ox(char *s);
void			display_lst(t_list	*lst);	
void			freelst(void *content, size_t content_size);
void			parsing(t_list *lst);
void			display_rooms(t_room *room);
t_room			*ft_newroom(void);
t_room			*fill_room(t_room *room, t_list *lst);


#endif