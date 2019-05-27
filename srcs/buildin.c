/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 06:37:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/09/19 14:44:54 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_four(t_tab *st_tab, t_env *st_env, char *pwd, int i)
{
	char		*buf;
	char		*lol;
	int			ret;
	struct stat	temp;

	buf = NULL;
	ret = 0;
	lol = ft_forjoin(pwd, st_tab->tab_word[i]);
	if ((lstat(lol, &temp) == 0) && (access(st_tab->tab_word[i], R_OK) == -1))
	{
		ft_printf("Permission denied\n");
		free(pwd);
		free(lol);
		return ;
	}
	free(lol);
	if ((ret = chdir(st_tab->tab_word[i])) == 0)
	{
		free(pwd);
		pwd = getcwd(buf, SIZE_MAX);
		change_pwd(&st_env->env, pwd);
	}
	(ret == -1) ? ft_printf("cd: no such file or directory: %s\n",
			st_tab->tab_word[i]) : 0;
	free(pwd);
}

void	ft_cd_two(t_tab *st_tab, t_env *st_env, char *pwd)
{
	int			ret;
	int			i;
	char		*lol;
	struct stat	temp;

	i = st_tab->tab_word[2] ? 2 : 1;
	change_last_pwd(st_env->env, pwd);
	if (st_tab->tab_word[2] && st_tab->tab_word[1][0] == '-'
			&& st_tab->tab_word[1][1] == 'L')
	{
		lol = ft_forjoin(pwd, st_tab->tab_word[2]);
		if ((lstat(lol, &temp) == 0) && (access(st_tab->tab_word[2], R_OK) < 0))
		{
			ft_printf("Permission denied\n");
			free(lol);
			return ;
		}
		free(lol);
		if ((ret = chdir(st_tab->tab_word[2])) == 0)
			modif_pwd(st_env->env, st_tab->tab_word[2]);
		(ret == -1) ? ft_printf(ERR, st_tab->tab_word[2]) : 0;
		free(pwd);
	}
	else
		ft_cd_four(st_tab, st_env, pwd, i);
}

void	ft_cd_three(char *old_pwd, t_env *st_env, char *pwd)
{
	old_pwd = get_last_pwd(st_env->env);
	if (old_pwd == NULL)
	{
		ft_printf("Please set the OLDPWD\n");
		free(pwd);
		return ;
	}
	chdir(old_pwd);
	change_last_pwd(st_env->env, pwd);
	change_pwd(&st_env->env, old_pwd);
	free(old_pwd);
	free(pwd);
}

void	ft_cd_five(t_env *st_env, char *pwd)
{
	change_last_pwd(st_env->env, pwd);
	change_pwd(&st_env->env, "/Users/alsomvil/");
	chdir("/Users/alsomvil/");
	free(pwd);
}

void	ft_cd(t_env *st_env, t_tab *st_tab)
{
	char	*pwd;
	char	*old_pwd;
	char	*buf;

	buf = NULL;
	pwd = getcwd(buf, SIZE_MAX);
	if (!pwd)
	{
		chdir("/Users/alsomvil/");
		return ;
	}
	old_pwd = NULL;
	if (!st_tab->tab_word[1] || (ft_strcmp(st_tab->tab_word[1], "~") == 0))
		ft_cd_five(st_env, pwd);
	else if (st_tab->tab_word[1][0] == '$')
	{
		free(pwd);
		if ((pwd = recup_path(st_env->env, &st_tab->tab_word[1][1])) != NULL)
			chdir(recup_path(st_env->env, &st_tab->tab_word[1][1]));
		free(pwd);
	}
	else if (ft_strcmp(st_tab->tab_word[1], "-") == 0)
		ft_cd_three(old_pwd, st_env, pwd);
	else
		ft_cd_two(st_tab, st_env, pwd);
}
