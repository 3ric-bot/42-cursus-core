/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (len > 0)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		len--;
	}
	return (dest);
}
