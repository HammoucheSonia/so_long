/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:53:01 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 06:03:59 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_img(t_data *img, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, img->murs);
	mlx_destroy_image(mlx_ptr, img->vides);
	mlx_destroy_image(mlx_ptr, img->img_maison);
	mlx_destroy_image(mlx_ptr, img->img_player);
	mlx_destroy_image(mlx_ptr, img->img_collectable);
	free(img);
}

void	ft_free_t_map(t_map *t_map)
{
	int	i;
	int	n;

	i = 0;
	n = t_map->nb_ligne;
	while (i < n)
	{
		free(t_map->t_map[i]);
		i++;
	}
	free(t_map->t_map);
	t_map->t_map = NULL;
	free(t_map);
}

void	end(t_si_on_joue *t_data)
{
	mlx_destroy_window(t_data->vars->mlx_ptr, t_data->vars->win_ptr);
	ft_free_img(t_data->img, t_data->vars->mlx_ptr);
	if (t_data->vars->mlx_ptr)
	{
		mlx_destroy_display((*t_data->vars).mlx_ptr);
		free((*t_data->vars).mlx_ptr);
	}
	free(t_data->un_joueur);
	free(t_data->vars);
	ft_free_t_map(t_data->t_map);
	free(t_data);
}

void	se_deplacer_gauche(t_si_on_joue *joue)
{
	int	i;
	int	j;

	i = joue->un_joueur->pos_i;
	j = joue->un_joueur->pos_j;
	if ((joue->t_map->t_map[i][j - 1] == 'E') && (nb_items(joue->t_map) == 0))
	{
		end(joue);
		exit(0);
	}
	if ((joue->t_map->t_map[i][j - 1] != '1'))
	{
		joue->t_map->t_map[i][j - 1] = 'P';
		if ((joue->pos_exit_i == i) && (joue->pos_exit_j == j))
			joue->t_map->t_map[i][j] = 'E';
		else
			joue->t_map->t_map[i][j] = '0';
		joue->un_joueur->pos_j = joue->un_joueur->pos_j - 1;
	}
}

int	deal_key(int key, t_si_on_joue *joue)
{
	static int	retour = 0;

	if (key == 65307)
		ft_exit(joue);
	if (key == 119 || key == 115 || key == 100 || key == 97)
	{
		if (key == 119)
			se_deplacer_haut(joue);
		if (key == 115)
			se_deplacer_bas(joue);
		if (key == 100)
			se_deplacer_droite(joue);
		if (key == 97)
			se_deplacer_gauche(joue);
		affichage_t_map(joue->vars, joue->t_map, joue->img);
		retour++;
		ft_putnbr(retour);
		ft_putchar('\n');
	}
	return (0);
}
