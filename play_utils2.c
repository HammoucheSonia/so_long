/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 06:07:15 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 06:19:50 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_exit_j(t_map *t_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < t_map->nb_ligne)
	{
		while (t_map->t_map[i][j])
		{
			if (t_map->t_map[i][j] == 'E')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	pos_exit_i(t_map *t_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < t_map->nb_ligne)
	{
		while (t_map->t_map[i][j])
		{
			if (t_map->t_map[i][j] == 'E')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	se_deplacer_haut(t_si_on_joue *joue)
{
	int	i;
	int	j;

	i = joue->un_joueur->pos_i;
	j = joue->un_joueur->pos_j;
	if ((joue->t_map->t_map[i - 1][j] == 'E') && (nb_items(joue->t_map) == 0))
	{
		end(joue);
		exit(0);
	}
	if ((joue->t_map->t_map[i - 1][j] != '1'))
	{
		joue->t_map->t_map[i - 1][j] = 'P';
		if ((joue->pos_exit_i == i) && (joue->pos_exit_j == j))
			joue->t_map->t_map[i][j] = 'E';
		else
			joue->t_map->t_map[i][j] = '0';
		joue->un_joueur->pos_i = joue->un_joueur->pos_i - 1;
	}
}

void	se_deplacer_bas(t_si_on_joue *joue)
{
	int	i;
	int	j;

	i = joue->un_joueur->pos_i;
	j = joue->un_joueur->pos_j;
	if ((joue->t_map->t_map[i + 1][j] == 'E') && (nb_items(joue->t_map) == 0))
	{
		end(joue);
		exit(0);
	}
	if ((joue->t_map->t_map[i + 1][j] != '1'))
	{
		joue->t_map->t_map[i + 1][j] = 'P';
		if ((joue->pos_exit_i == i) && (joue->pos_exit_j == j))
			joue->t_map->t_map[i][j] = 'E';
		else
			joue->t_map->t_map[i][j] = '0';
		joue->un_joueur->pos_i = joue->un_joueur->pos_i + 1;
	}
}

void	se_deplacer_droite(t_si_on_joue *joue)
{
	int	i;
	int	j;

	i = joue->un_joueur->pos_i;
	j = joue->un_joueur->pos_j;
	if ((joue->t_map->t_map[i][j + 1] == 'E') && (nb_items(joue->t_map) == 0))
	{
		end(joue);
		exit(0);
	}
	if ((joue->t_map->t_map[i][j + 1] != '1'))
	{
		joue->t_map->t_map[i][j + 1] = 'P';
		if ((joue->pos_exit_i == i) && (joue->pos_exit_j == j))
			joue->t_map->t_map[i][j] = 'E';
		else
			joue->t_map->t_map[i][j] = '0';
		joue->un_joueur->pos_j = joue->un_joueur->pos_j + 1;
	}
}
