/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dettach_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:25:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 13:26:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	dettach_segment(t_segment segment)
{
	shmdt(segment.mem);
	shmctl(segment.shmid, IPC_RMID, NULL);
}
