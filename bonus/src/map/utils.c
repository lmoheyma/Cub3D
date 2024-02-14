/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:07:25 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/12 21:03:04 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_spaces(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

void	skip_spaces(char *str, int *i)
{
	while (is_spaces(str[*i]))
		*i += 1;
}

int	empty_line(char *s)
{
	int	i;

	i = 0;
	skip_spaces(s, &i);
	if (s[i])
		return (0);
	return (1);
}

void	skip_empty_lines(char **str, int *i)
{
	while (empty_line(str[*i]) && str[*i])
		*i += 1;
}

char	*ft_strdup_space(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && !is_spaces(s[i]))
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && !is_spaces(s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
