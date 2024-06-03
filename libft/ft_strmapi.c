/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:40:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/29 15:40:23 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*index;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	index = (char *)malloc(sizeof(char) * len + 1);
	if (!index)
		return (0);
	while (i < len)
	{
		index[i] = f(i, s[i]);
		i++;
	}
	index[i] = '\0';
	return (index);
}
