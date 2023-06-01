/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:32:25 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/01 12:36:15 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"

// int     main(void)
// {
//     int     fd;
//     char    *line;

//     fd = open("/mnt/nfs/homes/juandrie/CURSUS_JULIETTE/GNL/DEPOTGIT/text", O_RDONLY);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL)
//             break;
//         printf("%s", line);
//         free(line);
//     }
//     return (0);
    
// }

int main(void)
{
    int fd[3];
    char    *line;

    fd[0] = open("/mnt/nfs/homes/juandrie/CURSUS_JULIETTE/GNL/DEPOTGIT/text", O_RDONLY);
    fd[1] = open("/mnt/nfs/homes/juandrie/CURSUS_JULIETTE/GNL/DEPOTGIT/textfd", O_RDONLY);

    while (1)
        {
            line = get_next_line(fd[0]);
            printf("%s", line);
            if (line == NULL)
                break ;
            line = get_next_line(fd[1]);
            printf("%s", line);
            if (line == NULL)
                break ;
        }
}