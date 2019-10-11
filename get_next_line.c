/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/11 16:58:28 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
		+ 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char		*sstr[255];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (ERROR);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ret < 0)
			return (ERROR);
		buf[ret] = '\0';
		if (ft_is_in_stri('\n', tmp))
			return (SUCCESS);
	}
	return (FINISH);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ERROR);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	if (close(fd) == -1)
		return (ERROR);
}
