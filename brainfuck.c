/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 07:09:00 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/02/09 12:48:37 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brainfuck_interpreter(char *inst)
{
	char *tshilidzi = (char *)malloc(sizeof(inst));
	char *ptr = tshilidzi;

	int index = 0; 
	
	while(ptr[index])
	{
		ptr[index++] = 0;
	}

	while (*inst != '\0')
	{
		if (*inst == '>')
			++ptr;
		else if (*inst == '<')
			--ptr;
		else if (*inst == '+')
			++*ptr;
		else if (*inst == '-')
			--*ptr;
		else if (*inst == '.')
			write(1, ptr, 1);
		else if (*inst == ',')
			read(0, ptr, 1);
		else if (*inst == '[')
		{
			if (!*ptr)
			{
				int loop_cnt = 1;
				while (loop_cnt)
				{
					++inst;
					if (*inst == ']')
						--loop_cnt;
					else if (*inst == '[')
						++loop_cnt;
				}
			}
			}
		else if (*inst == ']')
		{
			if (*ptr)
			{
				int loop_cnt = 1;
				while (loop_cnt)
				{
					--inst;
					if (*inst == '[')
						--loop_cnt;
					else if (*inst == ']')
						++loop_cnt;
				}
			}
		}
		inst++;
	}

	free(tshilidzi);
}

int		main(int c, char **v)
{
	if (c == 2)
		brainfuck_interpreter(v[1]);
	else
		write(1, "Invalid number of arguments\n", 28);
	return 0;
}
