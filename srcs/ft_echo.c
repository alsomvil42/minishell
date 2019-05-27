/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:28:48 by alsomvil          #+#    #+#             */
/*   Updated: 2018/09/19 14:28:16 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_two(t_tab *st_tab, t_env *st_env, int i, int j)
{
	if (search_and_affich_env(&st_tab->tab_word[i][j + 1],
				st_env->env, ft_strndup(st_tab->tab_word[i], j)) == 1)
		ft_printf("%s: Undefined variable.",
				&st_tab->tab_word[i][j + 1]);
}

void	ft_echo(t_tab *st_tab, t_env *st_env)
{
	int		i;
	int		j;

	i = 1;
	if (!st_tab->tab_word[i])
		ft_putchar('\n');
	while (st_tab->tab_word[i])
	{
		j = 0;
		while (st_tab->tab_word[i][j] != '$' && st_tab->tab_word[i][j] != '~'
				&& st_tab->tab_word[i][j])
			j++;
		if (st_tab->tab_word[i][j] == '$')
			ft_echo_two(st_tab, st_env, i, j);
		else if (st_tab->tab_word[i][j] == '~')
		{
			j = ft_strlen(st_tab->tab_word[i]);
			search_and_affich_env_t("HOME", st_env->env, st_tab->tab_word[i][1]
					? ft_strndup(&st_tab->tab_word[i][1], j) : NULL);
		}
		else
			ft_printf("%s", st_tab->tab_word[i]);
		st_tab->tab_word[++i] ? ft_putchar(' ') : ft_putchar('\n');
	}
}
