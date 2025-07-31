/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:40:28 by juan-jof          #+#    #+#             */
/*   Updated: 2025/07/31 02:47:03 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_separator(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i]))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !ft_is_separator(str[i]))
				i++;
		}
	}
	return count;
}

int	word_len(char *str)
{
	int i = 0;
	
	while (str[i] && !ft_is_separator(str[i]))
		i++;
	return (i);
}

 char	*copy_word(char *str)
{	
	int i = 0;
	int len;
	char *word;
	
	len = word_len(str);
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return NULL;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *str)
{
	int i = 0;
	char **split;
	
	split = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!split)
		return NULL;
	while (*str)
	{
		while (*str && ft_is_separator(*str))
			str++;
		if (*str)
		{	
			split[i] = copy_word(str);
			i++;
			while (*str && !ft_is_separator(*str))
				str++;
		}
	}
	split[i] = NULL;
	return (split);
}

