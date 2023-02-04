/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:25:27 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 04:25:43 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*ft_get_line(char *la_chaine)
{
	int		i;
	char	*str;

	i = 0;
	if (!la_chaine[i])
		return (NULL);
	while (la_chaine[i] && la_chaine[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (la_chaine[i] && la_chaine[i] != '\n')
	{
		str[i] = la_chaine[i];
		i++;
	}
	if (la_chaine[i] == '\n')
	{
		str[i] = la_chaine[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new(char *la_chaine)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (la_chaine[i] && la_chaine[i] != '\n')
		i++;
	if (!la_chaine[i])
	{
		free(la_chaine);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_get(la_chaine) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (la_chaine[i])
		str[j++] = la_chaine[i++];
	str[j] = '\0';
	free(la_chaine);
	return (str);
}

char	*lecture(int fd, char *la_chaine)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(la_chaine, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		la_chaine = ft_strjoin(la_chaine, buff);
	}
	free(buff);
	return (la_chaine);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*la_chaine;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	la_chaine = lecture(fd, la_chaine);
	if (!la_chaine)
		return (NULL);
	line = ft_get_line(la_chaine);
	la_chaine = ft_new(la_chaine);
	return (line);
}
