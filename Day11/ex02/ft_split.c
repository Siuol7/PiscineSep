/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:44:11 by caonguye          #+#    #+#             */
/*   Updated: 2024/09/22 20:36:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find[0])
		return (src);
	if (!src[0])
		return (0);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == to_find[j] && src[i + j])
		{
			if (!to_find[j + 1])
				return (&src[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *start, char *end)
{
	char	*res;
	char	*temp;
	char	*org;
	int		len;

	len = 0;
	temp = start;
	while (temp++ < end)
		len++;
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	org = res;
	while (start < end)
		*res++ = *start++;
	*res = '\0';
	return (org);
}

void	splitting(char **final, char *str, char *charset, int seplen)
{
	char	*temp;
	char	**sub;
	char	*check;

	temp = str;
	sub = final;
	temp = ft_strstr(temp, charset);
	while (temp)
	{
		check = ft_strdup(str, temp);
		if (check[0] != '\0')
			*sub++ = check;
		temp += seplen;
		str = temp;
		temp = ft_strstr(temp, charset);
	}
	if (*str != '\0')
	{
		*sub = ft_strdup(str, str + ft_strlen(str));
		sub++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		seplen;
	int		sepcnt;
	char	*temp;
	char	**final;

	sepcnt = 0;
	seplen = ft_strlen(charset);
	temp = ft_strstr(str, charset);
	while (temp)
	{
		temp += seplen;
		sepcnt++;
		temp = ft_strstr(temp, charset);
	}
	final = (char **) malloc ((sepcnt + 2) * sizeof(char *));
	splitting(final, str, charset, seplen);
	return (final);
}
