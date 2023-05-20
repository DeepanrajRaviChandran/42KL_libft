/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:50:03 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/05/18 00:04:26 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num_str;

	len = num_len(n);
	num_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	if (n < 0)
	{
		num_str[0] = '-';
		n = -n;
	}
	while (len > 0 && num_str[len - 1] != '-')
	{
		num_str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (num_str);
}
/*
#include <stdio.h>

// Paste the ft_itoa() implementation here

int main() {
    int test_cases[] = {0, 123, -456, 7890, -12345};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int num = test_cases[i];
        char* str = ft_itoa(num);
        if (str != NULL) {
            printf("Integer: %d\n", num);
            printf("String: %s\n", str);
            free(str);
        } else {
            printf("Memory allocation failed for num = %d\n", num);
        }
        printf("------------------------------\n");
    }

    return 0;
}
*/
