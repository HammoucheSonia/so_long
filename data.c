/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 06:23:57 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 09:37:36 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*create_t_data(t_vars *var)
{
	t_data	*image;

	image = malloc(sizeof(t_data));
	image->height = 2;
	image->height = 2;
	image->murs = mlx_xpm_file_to_image(var->mlx_ptr,
			"./wall.xpm", &image->width, &image->height);
	image->vides = mlx_xpm_file_to_image(var->mlx_ptr,
			"./background.xpm", &image->width, &image->height);
	image->img_collectable = mlx_xpm_file_to_image(var->mlx_ptr,
			"./collectable.xpm", &image->width, &image->height);
	image->img_player = mlx_xpm_file_to_image(var->mlx_ptr,
			"./player.xpm", &image->width, &image->height);
	image->img_maison = mlx_xpm_file_to_image(var->mlx_ptr,
			"./maison.xpm", &image->width, &image->height);
	return (image);
}

static void	affiche_utils(t_vars *var, t_data *img, char c, int *tab)
{
	if (c == 'P')
		mlx_put_image_to_window(var->mlx_ptr,
			var->win_ptr, img->img_player, tab[1] * 25, tab[0] * 25);
	if (c == 'C')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			img->img_collectable, tab[1] * 25, tab[0] * 25);
	if (c == 'E')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			img->img_maison, tab[1] * 25, tab[0] * 25);
	if (c == '1')
		mlx_put_image_to_window(var->mlx_ptr,
			var->win_ptr, img->murs, tab[1] * 25, tab[0] * 25);
	if (c == '0')
		mlx_put_image_to_window(var->mlx_ptr,
			var->win_ptr, img->vides, tab[1] * 25, tab[0] * 25);
	return ;
}

void	affichage_t_map(t_vars *var, t_map *t_map, t_data *img)
{
	int	i;
	int	j;
	int	tab[2];

	i = 0;
	j = 0;
	while (i < t_map->nb_ligne)
	{
		while (t_map->t_map[i][j])
		{
			if (t_map->t_map[i][j] == 'P' || t_map->t_map[i][j] == 'C'
				|| t_map->t_map[i][j] == 'E' || t_map->t_map[i][j] == '0'
				|| t_map->t_map[i][j] == '1' )
			{
				tab[0] = i;
				tab[1] = j;
				affiche_utils(var, img, t_map->t_map[i][j], tab);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
