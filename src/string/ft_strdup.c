/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
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
 * Duplicates a given string and returns a 
 * pointer to the newly allocated string
 * 
 * @param s1 string to be duplicated
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	char	*string;

	string = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	return (string);
}
