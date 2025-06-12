/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:59:31 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 21:22:26 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}

// int	main(void)
// {
// 	const char	*s1 = NULL;
// 	const char	*s2 = " The suffix string.";
// 	char		*result;

// 	result = ft_strjoin(s1, s2);
// 	if (result)
// 	{
// 		printf("Joined String: %s\n", result);
// 		// "The prefix string. The suffix string."
// 		free(result); // メモリを解放
// 	}
// 	return (0);
// }
