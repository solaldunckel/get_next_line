/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/14 18:39:00 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char		*s[256];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	if (!s[fd])
		if (!(s[fd] = malloc(sizeof(char *))))
			return (ERROR);
	while ((is_in_s('\n', s[fd])) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(s[fd], buf);
		free(tmp);
	}
	*line = ft_substr(s[fd], 0, ft_strclen(s[fd]) + 1);
	if (is_in_s('\n', s[fd]) >= 0)
	{
		s[fd] = ft_substr(s[fd], is_in_s('\n', s[fd]) + 1, ft_strlen(s[fd]));
		return (SUCCESS);
	}
	return (FINISH);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	(void)argc;
	
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ERROR);
	while (get_next_line(fd, &line))
	{
		printf("%s",line);
		i++;
	}
	if (close(fd) == -1)
		return (ERROR);
}
