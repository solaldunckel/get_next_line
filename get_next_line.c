/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 12:50:13 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	*line = ft_substr(s[fd], 0, ft_strlen_gnl(s[fd]) + 1);
	if (is_in_s('\n', s[fd]) >= 0)
		s[fd] = ft_substr(s[fd], is_in_s('\n', s[fd]) + 1, ft_strlen(s[fd]));
	else if (ft_strlen_gnl(s[fd]) > 0)
		s[fd] = ft_substr(s[fd], is_in_s('\0', s[fd]) + 1, ft_strlen(s[fd]));
	else
		return (FINISH);
	return (SUCCESS);
}
