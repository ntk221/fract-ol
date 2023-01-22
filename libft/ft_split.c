/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:45:29 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/18 23:50:48 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip(const char *str, char c)
{
	const char	*s;

	s = str;
	while (*s != '\0' && *s == c)
		s++;
	return (s - str);
}

static size_t	read_word_len(char const *str, char c)
{
	size_t	word_len;

	word_len = 0;
	str += skip(str, c);
	while (*str != '\0')
	{
		if (*str != c)
		{
			str++;
			word_len++;
		}
		else
			break ;
	}
	return (word_len);
}

static size_t	count_words(char const *s, char c)
{
	size_t	num;

	if (!s[0])
		return (0);
	num = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			num++;
			while (*s == c)
				s++;
			continue ;
		}
		s++;
	}
	if (*(s - 1) != c)
		num++;
	return (num);
}

static char	**free_all(char **str_split, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str_split[j]);
		j++;
	}
	free(str_split);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	words_num;
	char	**res;

	if (str == NULL)
		return (NULL);
	words_num = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words_num)
	{
		j = 0;
		res[i] = (char *)malloc(sizeof(char) * (read_word_len(str, c) + 1));
		if (!res[i])
			return (free_all(res, i));
		str += skip(str, c);
		while (*str != '\0' && *str != c)
			res[i][j++] = *str++;
		res[i++][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}
