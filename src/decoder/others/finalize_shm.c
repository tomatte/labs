/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_shm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 18:43:16 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"


static void	send_response(int key, char *text)
{
	int		shmid;
	char	*mem;
	char	*response;
	char	*ref;

	response = strdup("---------- DECODED MESSAGE ----------\n");
	ref = response;
	response = ft_strjoin(response, text);
	shmid = shmget(key, strlen(response) + 1, 0644 | IPC_CREAT);
	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, response, strlen(response) + 1);
	free(response);
	free(ref);
}

void	finalize_shm(unsigned char *data, char *text)
{
	int		shmid;
	key_t	key;
	char	*response;

	key = get_key();
	shmid = get_block(key);
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);
	send_response(key, text);
	printf("Message decoded and saved to shared memory. Now you can execute encoder program again.\n");
}
