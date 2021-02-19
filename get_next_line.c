/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:26:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/02/19 13:12:02 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		c[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, c, 0) < 0)
		return (-1);
	tmp = ft_fillrest(tmp);
	while (!(ft_isline(tmp)))
	{
		if (!(ret = read(fd, c, BUFFER_SIZE)))
			break ;
		c[ret] = '\0';
		if (!(tmp = ft_filltmp(c, tmp)))
			return (-1);
	}
	if (!(*line = ft_strdup(tmp)))
		return (-1);
	if (ret == 0)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	else
		return (1);
}
