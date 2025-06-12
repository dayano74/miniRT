/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:36 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 21:14:17 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_count(char const *str, char c)
{
	int	word_count;
	int	i;
	int	flag;

	if (str == NULL)
		return (0);
	word_count = 0;
	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && flag)
		{
			word_count++;
			flag = 0;
		}
		if (str[i] != c)
			flag = 1;
		i++;
	}
	if (flag)
		word_count++;
	return (word_count);
}

static int	ft_strlen_alp(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static char	*ft_strdup_alp(char const *src, int num)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((num + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_all_free(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		split_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split_count = ft_split_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (split_count + 1));
	if (strs == NULL)
		return (NULL);
	while (i < split_count)
	{
		while (s[j] == c)
			j++;
		strs[i] = ft_strdup_alp(&s[j], ft_strlen_alp(&s[j], c));
		if (strs[i++] == NULL)
		{
			ft_all_free(strs, i - 1);
			return (NULL);
		}
		j += ft_strlen_alp(&s[j], c);
	}
	strs[i] = NULL;
	return (strs);
}

// int	main(void)
// {
// 	char	**result;

// 	// const char	*s = "Hello,World,This,Is,A,Test";
// 	result = ft_split("  tripouille  42  ", ' ');
// 	for (int i = 0; result[i] != NULL; i++)
// 	{
// 		printf("Split[%d]: %s\n", i, result[i]);
// 		free(result[i]); // 各要素のメモリを解放
// 	}
// 	free(result); // 配列自体のメモリを解放
// 	return (0);
// }
