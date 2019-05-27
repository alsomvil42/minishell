/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:51:20 by alsomvil          #+#    #+#             */
/*   Updated: 2018/09/19 12:31:12 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_is_builtins(t_tab *st_tab)
{
	if (ft_strcmp(st_tab->tab_word[0], "echo") == 0 ||
			ft_strcmp(st_tab->tab_word[0], "cd") == 0 ||
			ft_strcmp(st_tab->tab_word[0], "setenv") == 0 ||
			ft_strcmp(st_tab->tab_word[0], "unsetenv") == 0 ||
			ft_strcmp(st_tab->tab_word[0], "env") == 0)
		return (1);
	return (0);
}

void	realize_built(t_tab *st_tab, t_env *st_env)
{
	char	*buf;

	buf = NULL;
	if (ft_strcmp(st_tab->tab_word[0], "env") == 0)
		affich_env(st_env, st_tab);
	else if (ft_strcmp(st_tab->tab_word[0], "echo") == 0)
		ft_echo(st_tab, st_env);
	else if (ft_strcmp(st_tab->tab_word[0], "cd") == 0)
		ft_cd(st_env, st_tab);
	else if (ft_strcmp(st_tab->tab_word[0], "setenv") == 0)
		ft_setenv(st_env, st_tab);
	else if (ft_strcmp(st_tab->tab_word[0], "unsetenv") == 0)
		ft_unsetenv(st_env, st_tab);
}

void	verif_main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_printf("%s: No such file or directory.\n", argv[1]);
		exit(0);
	}
}

void	ft_unsetenv(t_env *st_env, t_tab *st_tab)
{
	if (!st_tab->tab_word[1])
		return ;
	else if (ft_strcmp(st_tab->tab_word[1], "*") == 0)
		freetab(st_env->env);
	else
		delete_env(&st_env->env, st_tab->tab_word[1]);
}

void	ft_setenv(t_env *st_env, t_tab *st_tab)
{
	if (!st_tab->tab_word[1])
		return ;
	else
	{
		if ((existe_env(st_env->env, st_tab->tab_word[1]) == 1))
			modif_env(st_env->env, st_tab->tab_word[1]);
		else if ((existe_env(st_env->env, st_tab->tab_word[1]) == 0))
			create_env(&st_env->env, st_tab->tab_word[1]);
		else
			return ;
	}
}
