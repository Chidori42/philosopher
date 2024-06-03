/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:19:23 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/22 10:29:18 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*str;
	size_t	front;
	size_t	rear;

	str = 0;
	if (!s1 || !set)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
		rear--;
	str = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (str)
		ft_strlcpy(str, &s1[front], rear - front + 1);
	return (str);
}
