/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:42:08 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 05:06:04 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>

int	ft_ber(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n <= 4)
		return (0);
	if (str[n - 1] == 'r' && str[n - 2] == 'e'
		&& str[n - 3] == 'b' && str[n - 4] == '.')
		return (1);
	return (0);
}

int	ft_exit(t_si_on_joue *joue)
{
	ft_putstr("you give up\n");
	end(joue);
	exit(EXIT_SUCCESS);
}

static	int	game(t_si_on_joue *joue)
{
	affichage_t_map(joue->vars, joue->t_map, joue->img);
	mlx_hook(joue->vars->win_ptr, 17, (1L << 17), ft_exit, joue);
	mlx_hook(joue->vars->win_ptr, KeyPress, KeyPressMask, deal_key, joue);
	return (0);
}

void	verif_doc(char *str)
{
	int		fd;
	char	buffer[2];
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Erreur in file\n");
		exit(0);
	}
	ret = read(fd, &buffer, 1);
	if (ret < 0)
	{
		ft_putstr("Erreur in file \n");
		exit(0);
	}
	return ;
}

void	affichage(t_map *une_t_map)
{
	t_si_on_joue	*joue;
	t_vars			*var;
	void			*mlx_ptr;
	void			*win_ptr;
	t_data			*img;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return ;
	win_ptr = mlx_new_window(mlx_ptr, (ft_strlen(une_t_map->t_map[0]) - 1) * 25,
			(une_t_map->nb_ligne) * 25, "So_long");
	var = malloc(sizeof(t_vars));
	var->mlx_ptr = mlx_ptr;
	var->win_ptr = win_ptr;
	img = create_t_data(var);
	joue = init_staruct(une_t_map, img, if_play(une_t_map), var);
	game(joue);
	mlx_loop(mlx_ptr);
}
