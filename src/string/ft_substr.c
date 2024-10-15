/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Copies a part of a string based on a 
 * starting point and how many chars it 
 * needs to copy
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, uint32_t start, size_t len)
{
	char	*string;
	size_t	start_pos;
	size_t	src_len;

	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len || len == 0)
		return (ft_strdup(""));
	if (len > src_len - start)
		return (ft_strdup(s + start));
	string = ft_calloc((len + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	if (start + len > src_len)
		start_pos = src_len - start;
	else
		start_pos = len;
	ft_memcpy(string, s + start, start_pos);
	return (string);
}
