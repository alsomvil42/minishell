/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:22:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/09/19 14:44:51 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <fcntl.h>
# define ERR "cd: no such file or directory: %s\n"

typedef struct	s_tab
{
	char	**tab_word;
	char	**tab_path;
}				t_tab;

typedef struct	s_env
{
	char	**env;
}				t_env;

void			verif_main(int argc, char **argv);
char			*ft_forjoin(char *pwd, char *path);
int				search_and_affich_env_t(char *tab, char **env, char *rest);
int				ft_strcmp(const char *s1, const char *s2);
int				nb_env(char **env);
int				check_is_env(char *str);
void			forfree(char **tab);
int				verif_char(char *line);
int				search_and_affich_env(char *tab, char **env, char *temp);
char			*recup_path(char **env, char *str);
void			modif_pwd(char **env, char *str);
int				get_next_line(const int fd, char **line);
char			**ft_split_whitespaces(char *str);
char			**ft_strsplit(char const *s, char c);
void			set_env(t_env *st_env, char **env);
void			ft_unsetenv(t_env *st_env, t_tab *st_tab);
void			affich_env(t_env *st_env, t_tab *st_tab);
char			*get_pwd(char **env);
void			change_pwd(char ***env, char *pwd);
void			change_last_pwd(char **env, char *pwd);
char			*get_last_pwd(char **env);
void			ft_echo(t_tab *st_tab, t_env *st_env);
void			ft_cd(t_env *st_env, t_tab *st_tab);
void			ft_setenv(t_env *st_env, t_tab *st_tab);
void			realize_built(t_tab *st_tab, t_env *st_env);
int				check_is_builtins(t_tab *st_tab);
int				existe_env(char **env, char *str);
void			modif_env(char **env, char *str);
char			**duplicate_tab(char ***tab);
char			**duplicate_tab_two(char ***tab, int j);
char			**duplicate_env(char **tab);
void			create_env(char ***env, char *str);
void			delete_env(char ***env, char *str);
void			freetab(char **tab);

#endif
