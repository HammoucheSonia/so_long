/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:29:02 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 04:39:24 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_play	*final_play(t_map *t_map, int i, int j)
{
	t_play	*joueur;

	joueur = malloc(sizeof(t_play));
	joueur->pos_i = i;
	joueur->pos_j = j;
	joueur->droite = 0;
	joueur->gauche = 0;
	joueur->montee = 0;
	joueur->descente = 0;
	if (t_map->t_map[i][j + 1] == '0' || t_map->t_map[i][j + 1] == 'C')
		joueur->droite = 1;
	if (t_map->t_map[i][j - 1] == '0' || t_map->t_map[i][j + 1] == 'C')
		joueur->gauche = 1;
	if (t_map->t_map[i + 1][j] == '0' || t_map->t_map[i][j + 1] == 'C')
		joueur->montee = 1;
	if (t_map->t_map[i - 1][j] == '0' || t_map->t_map[i][j + 1] == 'C')
		joueur->descente = 1;
	return (joueur);
}

t_play	*if_play(t_map *t_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t_map->t_map[i][j])
	{
		while (t_map->t_map[i][j])
		{
			if (t_map->t_map[i][j] == 'P')
				return (final_play(t_map, i, j));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

t_si_on_joue	*init_staruct(t_map *t_map, t_data *img, t_play *joueur,
		t_vars *var)
{
	t_si_on_joue	*joue;

	joue = malloc(sizeof(t_si_on_joue));
	joue->player_droit = 0;
	joue->player_bas = 0;
	joue->player_gauche = 0;
	joue->player_haut = 0;
	joue->t_map = t_map;
	joue->img = img;
	joue->un_joueur = joueur;
	joue->vars = var;
	joue->pos_exit_i = pos_exit_i(t_map);
	joue->pos_exit_j = pos_exit_j(t_map);
	return (joue);
}

int	nb_items(t_map *t_map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < (t_map->nb_ligne - 1))
	{
		while (t_map->t_map[i][j])
		{
			if (t_map->t_map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	return (c);
}
