/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:20:23 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 06:47:37 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# define LINE ((char *)lst->content)
# define LTMP (char **)&tmp->content
# define LLST (char **)&lst->content
# define PATH g_infos.path
# define START g_infos.start
# define FIRST g_infos.first
# define END g_infos.end
# define ANTS g_infos.ants
# define LINK room1->links
# define BEGIN g_infos.begin
# define FINISH g_infos.finish
# define TMP g_infos.tmp

typedef	struct s_room	t_room;

struct			s_room
{
	char		*name;
	t_room		*next;
	t_list		*links;
	int			start;
	int			end;
	int			stop;
	int			track;
};

typedef struct s_path	t_path;

struct			s_path
{
	void		*content;
	size_t		*content_size;
	int			ant;
	t_path		*next;
	t_path		*start;
};

typedef struct s_parse	t_parse;

struct			s_parse
{
	t_path		*path;
	int			ants;
	t_path		*begin;
	t_path		*finish;
	t_path		*tmp;
	t_room		*first;
	t_room		*start;
	t_room		*end;
};

t_parse			g_infos;

int				still_ox(t_list *lst);
int				islimit(char *s);
int				iscomment(char *s);
int				isvalid(char *s);
int				isox(char *s);
int				isroom(char *s);
int				islink(char *s);
int				islinked(t_room *room1, t_room *room2);

void			get_links(char *s);
t_room			*get_room(char *s);
void			get_limits(t_room *room, t_list *lst);

void			check_up(void);
void			parsing(t_list *lst);

void			display_lst(t_list	*lst);
void			display_rooms(t_room *room);

void			init_infos(void);
void			del(void *content, size_t size);
void			freelst(void *content, size_t content_size);
void			leave(void);

void			resolution(void);
int				get_path(t_room *room1);
// void			set_link(t_room *room1, t_room *room2);
void			link_rooms(t_room *room1, t_room *room2);
t_room			*ft_newroom(void);
t_room			*fill_room(t_room *room, t_list *lst);

#endif
