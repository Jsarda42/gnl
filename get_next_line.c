/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:21:07 by jsarda            #+#    #+#             */
/*   Updated: 2023/11/26 11:35:47 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_cpy_line(char *buffer)
{
	char *line;
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int	bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		if (bytes_read == -1)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		str = buffer;
	} 
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char *line;

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_cpy_line(buffer);
	return (line);
}

int main() {
    int fd; // Replace this with your actual file descriptor

    // Open the file and get its descriptor (file_descriptor)
	fd = open("example.txt", O_RDONLY);
    char *line = get_next_line(fd);
	char *line2 = get_next_line(fd);
    if (line != NULL) {
        printf("Line read: %s\n", line);
		printf("Line2 read: %s\n", line2);
        free(line); // Free the allocated memory for the line
    } else {
        printf("No more lines or error occurred.\n");
    }

    // Close the file descriptor and perform other necessary cleanup

    return 0;
}
