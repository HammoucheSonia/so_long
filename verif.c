/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:26:41 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 05:31:58 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lignes_ok(char **t_map, int n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(t_map[n - 1]);
	while (i < (n - 1))
	{
		if (len != ft_strlen(t_map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	est_un_mur_haut(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(str);
	while (i < (n - 1))
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	est_un_mur_bas(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(str);
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	entre_les_murs(char *str)
{
	if (str[0] == '1' && str[ft_strlen(str) - 2] == '1')
		return (1);
	return (0);
}
