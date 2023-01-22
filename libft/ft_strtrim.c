/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:41:07 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/11 21:21:08 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	str_len;
	size_t	new_len;
	char	*new;

	if (str == NULL || set == NULL)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	str_len = ft_strlen(str);
	new_len = str_len;
	while (new_len && ft_strchr(set, str[new_len]))
		new_len--;
	new = ft_substr((char *)str, 0, new_len + 1);
	return (new);
}
