/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:17:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/11/05 12:33:01 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr_alst;

	ptr_alst = *alst;
	while (ptr_alst)
	{
		del(ptr_alst->content, ptr_alst->content_size);
		free(ptr_alst);
		ptr_alst = ptr_alst->next;
	}
	*alst = NULL;
}
