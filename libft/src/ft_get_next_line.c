/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:24:29 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/02 18:26:06 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_len(char *sample)
{
	size_t	i;

	i = 0;
	while (sample[i] != '\n' && sample[i])
		i++;
	return (i);
}

static int		ft_ret(char **temp, char **sample, char **line, int ret)
{
	size_t	len;

	len = ft_len(*sample);
	*line = ft_strsub(*sample, 0, len);
	if (ret == 0 && ft_strlen(*sample) == 0)
		return (0);
	*temp = ft_strsub(*sample, len + 1, ft_strlen(*sample) - len);
	free(*sample);
	*sample = ft_strsub(*temp, 0, ft_strlen(*temp));
	free(*temp);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	char		*temp;
	static char *sample = "";

	while (ft_strchr(sample, '\n') == NULL)
	{
		buf = ft_strnew(BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		temp = ft_strjoin(sample, buf);
		free(buf);
		if (ft_strcmp(sample, "") != 0)
			free(sample);
		sample = ft_strsub(temp, 0, ft_strlen(temp));
		free(temp);
		if (ret < BUFF_SIZE)
			return (ft_ret(&temp, &sample, line, ret));
	}
	return (ft_ret(&temp, &sample, line, ret));
}
