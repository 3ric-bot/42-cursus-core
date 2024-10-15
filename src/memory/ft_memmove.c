/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d < s)
		ft_memcpy(d, s, len);
	else
	{
		s = src + (len - 1);
		d = dest + (len - 1);
		while (len > 0)
		{
			*d = *s;
			d--;
			s--;
			len--;
		}
	}
	return (dest);
}
