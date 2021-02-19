/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:29:38 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/02/18 13:16:00 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_filltmp(char *c, char *tmp)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = 0;
	if (!(new = malloc(sizeof(char) * (ft_strlen(c) + ft_strlen(tmp) + 1))))
		return (NULL);
	if (tmp)
	{
		while (tmp[i])
			new[j++] = tmp[i++];
		i = 0;
	}
	while (c[i])
		new[j++] = c[i++];
	new[j] = '\0';
	if (tmp)
		free(tmp);
	return (new);
}

char	*ft_fillrest(char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tmp)
		return (NULL);
	if (!(ft_isline(tmp)))
	{
		tmp[i] = '\0';
		return (tmp);
	}
	while (tmp && tmp[j] && tmp[j] != '\n')
		j++;
	j++;
	while (tmp && tmp[j])
	{
		tmp[i] = tmp[j];
		i++;
		j++;
	}
	if (tmp)
		tmp[i] = '\0';
	return (tmp);
}

char	*ft_strdup(char *tmp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	while (tmp && tmp[i] && tmp[i] != '\n')
		i++;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (tmp && tmp[i] && tmp[i] != '\n')
		new[j++] = tmp[i++];
	new[j] = '\0';
	return (new);
}

int		ft_isline(char *tmp)
{
	int i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
