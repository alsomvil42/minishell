/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:07:37 by alsomvil          #+#    #+#             */
/*   Updated: 2018/09/19 14:44:53 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_forjoin(char *pwd, char *path)
{
	char	*test;
	char	*ret;

	test = ft_strjoin(pwd, "/");
	ret = ft_strjoin(test, path);
	free(test);
	return (ret);
}

int		search_and_affich_env_t(char *tab, char **env, char *rest)
{
	char	*temp;
	int		i;

	i = 0;
	while (env[i])
	{
		temp = ft_strndup(env[i], ft_strlen(tab));
		if (ft_strcmp(tab, temp) == 0 && env[i][ft_strlen(tab)] == '=')
		{
			ft_printf("%s", &env[i][ft_strlen(tab) + 1]);
			if (rest != NULL)
			{
				ft_printf("%s", rest);
				free(rest);
			}
			free(temp);
			return (0);
		}
		free(temp);
		i++;
	}
	if (rest)
		free(rest);
	return (1);
}

int		search_and_affich_env(char *tab, char **env, char *rest)
{
	char	*temp;
	int		i;

	i = 0;
	while (env[i])
	{
		temp = ft_strndup(env[i], ft_strlen(tab));
		if (ft_strcmp(tab, temp) == 0 && env[i][ft_strlen(tab)] == '=')
		{
			if (rest != NULL)
			{
				ft_printf("%s", rest);
				free(rest);
			}
			ft_printf("%s", &env[i][ft_strlen(tab) + 1]);
			free(temp);
			return (0);
		}
		free(temp);
		i++;
	}
	if (rest)
		free(rest);
	return (1);
}

char	*recup_path(char **env, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		temp = ft_strndup(env[i], ft_strlen(str));
		if (ft_strcmp(str, temp) == 0 && env[i][ft_strlen(str)] == '=')
		{
			free(temp);
			return (&env[i][ft_strlen(str) + 1]);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

void	modif_pwd(char **env, char *str)
{
	char		*temp;
	char		*buf;
	char		*fuck;
	struct stat	test;
	char		*tp;

	buf = NULL;
	fuck = getcwd(buf, SIZE_MAX);
	tp = ft_strjoin("/", str);
	temp = ft_strjoin(fuck, tp);
	if ((lstat(temp, &test) == 0) && S_ISLNK(test.st_mode))
		change_pwd(&env, temp);
	free(fuck);
	free(tp);
	free(temp);
}
