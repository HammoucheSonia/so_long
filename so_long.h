/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 07:38:02 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/15 07:44:25 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

typedef struct s_vars			t_vars;
typedef struct s_map			t_map;
typedef struct s_parcing_t_map	t_parsing_map;
typedef struct s_data			t_data;
typedef struct s_player			t_play;
typedef struct s_si_on_joue		t_si_on_joue;

struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
};

struct s_map
{
	char	**t_map;
	int		nb_ligne;
};

struct s_parcing_t_map
{
	int	rectangle;
	int	murs;
	int	vides;
	int	exit_play_item;
};

struct s_data
{
	void	*murs;
	void	*vides;
	void	*img_collectable;
	void	*img_player;
	void	*img_maison;
	int		width;
	int		height;
};

struct s_player
{
	int	pos_i;
	int	pos_j;
	int	gauche;
	int	droite;
	int	montee;
	int	descente;
};

struct s_si_on_joue
{
	int		player_haut;
	int		player_droit;
	int		player_gauche;
	int		player_bas;
	int		pos_exit_i;
	int		pos_exit_j;
	t_play	*un_joueur;
	t_data	*img;
	t_map	*t_map;
	t_vars	*vars;
};

//fonctions GNL 
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *la_chaine, char *buff);
char			*ft_get_line(char *la_chaine);
char			*ft_new(char *la_chaine);
char			*lecture(int fd, char *la_chaine);
char			*get_next_line(int fd);
size_t			ft_strlen_get(char *s);

int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_ber(char *str);
int				ft_parcing(char *str);
int				ft_map(char *str, int n);
int				nb_ligne(char *str);
char			*ft_strdup(char *str);
t_map			*create_t_map(char *filname);
int				lignes_ok(char **t_map, int n);
int				est_un_mur_haut(char *str);
int				est_un_mur_bas(char *str);
int				entre_les_murs(char *str);
int				player_exit_item(char **t_map, int nb_ligne, int e, int p);
int				complete_t_map(char **t_map, int n);
int				create_parcing(t_map *t_map);
t_data			*create_t_data(t_vars *var);
void			affichage_t_map(t_vars *var, t_map *t_map, t_data *img);
t_play			*final_play(t_map *t_map, int i, int j);
t_play			*if_play(t_map *t_map);
void			ft_putnbr(int n);
t_si_on_joue	*init_staruct(t_map *t_map, t_data *img,
					t_play *joueur, t_vars *var);
int				nb_items(t_map *t_map);
int				pos_exit_j(t_map *t_map);
int				pos_exit_i(t_map *t_map);
void			ft_free_img(t_data *img, void *mlx_ptr);
void			ft_free_t_map(t_map *t_map);
void			end(t_si_on_joue *t_data);
void			se_deplacer_haut(t_si_on_joue *joue);
void			se_deplacer_bas(t_si_on_joue *joue);
void			se_deplacer_droite(t_si_on_joue *joue);
void			se_deplacer_gauche(t_si_on_joue *joue);
int				deal_key(int key, t_si_on_joue *joue);
void			ft_putstr(char *str);
int				ft_exit(t_si_on_joue *joue);
void			affichage(t_map *une_t_map);
void			verif_doc(char *str);

#endif
