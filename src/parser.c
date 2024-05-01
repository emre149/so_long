/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/05/01 20:27:25 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	c_interpretor(char c)
{
	if (c == '1')
	{
		ft_printf("1");
	}
	else if (c == '0')
	{
		ft_printf("0");
	}
	else if (c == 'P')
	{
		ft_printf("P");
	}
	else if (c == 'C')
	{
		ft_printf("C");
	}
	else if (c == 'E')
	{
		ft_printf("E");
	}
	return (0);
}

void	line_parsing(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		c_interpretor(line[i]);
		i++;
	}
	ft_printf("\n");
}

void	read_and_process(const char *filename)
{
    char *line;
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
	{
        perror("Erreur d'ouverture du fichier");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
	{
        line_parsing(line);
        free(line);
    }

    close(fd);
}

int	main()
{
	read_and_process("../maps/classic.ber");
	return (0);
}