/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:18:19 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/05/12 17:11:50 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j])
				j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *haystack = "The quick brown fox jumps over the lazy dog";
    const char *needle1 = "brown";
    const char *needle2 = "xyz";
    char *result;

    // Find substring "brown" in haystack
    result = ft_strnstr(haystack, needle1, strlen(haystack));
    if (result != NULL) {
        printf("'%s' found in haystack: '%s'\n", needle1, result);
    } else {
        printf("'%s' not found in haystack\n", needle1);
    }

    // Find substring "xyz" in haystack
    result = ft_strnstr(haystack, needle2, strlen(haystack));
    if (result != NULL) {
        printf("'%s' found in haystack: '%s'\n", needle2, result);
    } else {
        printf("'%s' not found in haystack\n", needle2);
    }

    // Find empty substring in haystack
    result = ft_strnstr(haystack, "", strlen(haystack));
    if (result != NULL) {
        printf("Empty substring found in haystack: '%s'\n", result);
    } else {
        printf("Empty substring not found in haystack\n");
    }

    return 0;
}
*/
