/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoehlers <eoehlers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by eoehlers          #+#    #+#             */
/*   Updated: 2024/10/11 12:33:59 by eoehlers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *h, const char *n, size_t len)
{
    size_t n_len;

    if (*n == '\0')
        return ((char *)h);

    n_len = ft_strlen(n);

    while (*h && len >= n_len)
    {
        if (ft_strncmp(h, n, n_len) == 0)
            return ((char *)h);
        
        h++;
        len--;
    }

    return (NULL);
}

