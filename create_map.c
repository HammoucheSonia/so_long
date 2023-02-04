/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:28:51 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 04:05:11 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_ligne(char *str)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

t_map	*create_t_map(char *filname)
{
	int		n;
	int		i;
	t_map	*t_map;
	int		fd;
	char	**tab;

	i = 0;
	n = nb_ligne(filname);
	t_map = malloc(sizeof(t_map));
	fd = open(filname, O_RDONLY);
	tab = malloc(sizeof(char *) * (n));
	while (i <= (n - 1))
	{
		tab[i] = (get_next_line(fd));
		i++;
	}
	close(fd);
	t_map->nb_ligne = nb_ligne(filname);
	t_map->t_map = tab;
	return (t_map);
}

int	complete_t_map(char **t_map, int n)
{
	int	i;

	i = 0;
	if ((est_un_mur_haut(t_map[i]) == 0) || (est_un_mur_bas(t_map[n - 1]) == 0))
		return (0);
	while (i < (n - 1))
	{
		if (entre_les_murs(t_map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	create_parcing(t_map *t_map)
{
	t_parsing_map	*parcing;
	int				e;
	int				p;

	e = 0;
	p = 0;
	parcing = malloc(sizeof(t_parsing_map));
	if ((lignes_ok(t_map->t_map, t_map->nb_ligne) == 1)
		&& (complete_t_map(t_map->t_map, t_map->nb_ligne) == 1)
		&& (player_exit_item(t_map->t_map, t_map->nb_ligne, e, p) == 1))
	{
		free(parcing);
		return (1);
	}
	free(parcing);
	return (0);
}
