/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:27 by badriano          #+#    #+#             */
/*   Updated: 2024/07/26 17:39:32 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_printf/ft_printf.h"

void receive_bits(int bit)
{
	static char res;
	static int i;
	
	
	res = res * 2;
	if (bit == SIGUSR1)
	{
		res = res + 1;
	}
	i++;
	if(i == 8)
	{
		write(1, &res, 1);
		i = 0;
		res = 0;
	}
}

int main(void)
{
	ft_printf("welcome to my belmiros server\n");
	ft_printf("the servrs PID number is: %d\n", getpid());
	
	while(1)
	{
		signal(SIGUSR1, receive_bits);
		signal(SIGUSR2, receive_bits);
		pause();
	}
	
	return(0);
}
