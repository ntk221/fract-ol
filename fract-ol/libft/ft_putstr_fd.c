/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:48:45 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/15 11:37:55 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	if (*str == '\0')
		return ;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}
