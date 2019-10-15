/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:50:20 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 12:58:44 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("%s", buff);
			free(buff);
		}
		printf("%s", buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEOF\n");
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("%s", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEOF\n");
		close(fd);
	}
	return (0);
}
