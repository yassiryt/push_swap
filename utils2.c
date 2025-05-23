/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:26:31 by yatanagh          #+#    #+#             */
/*   Updated: 2025/04/08 02:25:42 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	big_str(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	small_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*skip(char *s, char c)
{
	while (s && *s == c)
		s++;
	return (s);
}

static void	*ft_free(char **p, int count)
{
	while (count > 0)
	{
		count--;
		free(p[count]);
	}
	free (p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		len;
	int		j;
	int		i;
	int		k;

	j = big_str(s, c);
	i = 0;
	p = (char **)malloc(sizeof(char *) * (j + 1));
	if (!p || !s)
		return (NULL);
	while (i < j)
	{
		s = skip(s, c);
		len = small_str(s, c);
		p[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!p[i])
			return (ft_free(p, i));
		k = 0;
		while (k < len)
			p[i][k++] = *s++;
		p[i++][k] = '\0';
	}
	p[i] = NULL;
	return (p);
}
