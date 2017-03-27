/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:20:47 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 14:12:51 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_return(char **line, char **str, int ret)
{
	if (ret == 0 && !*str[0])
	{
		*line = ft_strnew(0);
		return (0);
	}
	if (ft_strchr(*str, '\n'))
	{
		if (ft_strchr(*str, '\n') - *str == 0)
			*line = ft_strnew(0);
		else
			*line = ft_strsub(*str, 0, ft_strchr(*str, '\n') - *str);
		*str = ft_strchr(*str, '\n') + 1;
	}
	else
	{
		*line = ft_strdup(*str);
		*str = ft_strnew(0);
	}
	return (1);
}

static int		get_input(int fd, char **s, char **line)
{
	char	*buff;
	int		ret;
	char	*str;

	ret = BUFF_SIZE;
	if (*s)
		str = ft_strdup(*s);
	else
		str = ft_strnew(0);
	while ((ret == BUFF_SIZE) && str && !ft_strchr(str, '\n'))
	{
		if (!(buff = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[ret] = '\0';
		str = ft_strjoinfree(str, buff);
	}
	*s = ft_strdup(str);
	if (str)
		ft_strdel(&str);
	return (ft_return(line, s, ret));
}

static t_list	*ft_check_fd(t_list *lst, int fd)
{
	if (lst->start)
		lst = lst->start;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static t_list	*ft_getfd(t_list *lst, int fd)
{
	t_list	*tmp;

	if (!lst)
	{
		if (!(lst = ft_lstnew(NULL, 0)))
			return (NULL);
		lst->fd = fd;
	}
	if (!ft_check_fd(lst, fd))
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			return (NULL);
		tmp->fd = fd;
		ft_lstadd_end(lst, tmp);
	}
	return (ft_check_fd(lst, fd));
}

int				get_next_line(const int fd, char **line)
{
	static t_list *lst;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
	{
		if (line)
			*line = ft_strnew(0);
		return (-1);
	}
	if (!(lst = ft_getfd(lst, fd)))
	{
		*line = ft_strnew(0);
		return (-1);
	}
	return (get_input(fd, (char **)&lst->content, line));
}
