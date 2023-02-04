/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:34:59 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 09:37:49 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	others(char **t_map, int nb_ligne)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (i < (nb_ligne - 1))
	{
		n = ft_strlen(t_map[i]);
		while (j < (n - 1))
		{
			if (!((t_map[i][j] == 'E') || (t_map[i][j] == 'P')
				|| (t_map[i][j] == 'C') || (t_map[i][j] == '1')
				|| (t_map[i][j] == '0')))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	player_exit_item(char **t_map, int nb_ligne, int e, int p)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < (nb_ligne - 1))
	{
		while (t_map[i][j])
		{
			if (t_map[i][j] == 'E')
				e++;
			if (t_map[i][j] == 'P')
				p++;
			if (t_map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if ((e == 1) && (c >= 1) && (p == 1) && (others(t_map, nb_ligne) == 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*tab;

	if (argc != 2 || ft_ber(argv[1]) == 0)
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	verif_doc(argv[1]);
	tab = create_t_map(argv[1]);
	if (create_parcing(tab) == 0)
	{
		ft_putstr("Erreur\n");
		ft_free_t_map(tab);
		return (0);
	}
	affichage(tab);
	return (0);
}
