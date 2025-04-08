/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:27:18 by yatanagh          #+#    #+#             */
/*   Updated: 2025/04/08 00:49:18 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s2)
		s2 = "";
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	if (s1)
		while (s1[++i])
			p[i] = s1[i];
	else
		i = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	if (s1)
		free(s1);
	return (p);
}

void	qu(int c)
{
	if (c < 2)
		exit(0);
}

void	quit(t_stab *va, int c, char **v)
{
	if (va)
	{
		if (va->tab_a)
			free(va->tab_a);
		if (va->tab_b)
			free(va->tab_b);
	}
	if (v)
		free_string_array(v);
	if (c == 1 || c == 5)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	else
		exit(0);
}

void	nor(t_stab *var)
{
	indexing(var);
	push_sorted_to_b(var);
	push_sorted_to_a(var);
}
