/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_shm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 19:21:23 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

void	finalize_shm(char *mem)
{
	int		shmid;
	key_t	key;

	key = get_key();
	shmid = get_block(key);
	shmdt(mem);
	shmctl(shmid, IPC_RMID, NULL);
}
