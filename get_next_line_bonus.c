/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:26:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/02/19 13:14:29 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*tmp[1024];
	char		c[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, c, 0) < 0)
		return (-1);
	tmp[fd] = ft_fillrest(tmp[fd]);
	while (!(ft_isline(tmp[fd])))
	{
		if (!(ret = read(fd, c, BUFFER_SIZE)))
			break ;
		c[ret] = '\0';
		tmp[fd] = ft_filltmp(c, tmp[fd]);
	}
	if (!(*line = ft_strdup(tmp[fd])))
		return (-1);
	if (ret == 0)
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (0);
	}
	else
		return (1);
}
