/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:03:31 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/19 06:34:21 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	index -> content = content;
	index -> next = NULL;
	return (index);
}
