/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 07:09:00 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/02/09 07:39:06 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	brainfuck_interpreter(const char* instruction, const size_t cnt)
{
	char* tshilidzi = calloc(cnt,1);
	char* ptr = &tshilidzi[0];
	
	for (;*instruction != '\0'; ++instruction)
	{
		switch (*instruction)
		{
			case '>': ++ptr; break;
			case '<': --ptr; break;
			case '+': ++*ptr; break;
			case '-': --*ptr; break;
			case '.': printf("%c", *ptr); break;
			case ',': *ptr = getchar(); break;
			case '[':
					  if (!*ptr)
					  {
						  size_t loop_cnt = 1;
						  while (loop_cnt)
						  {
							  ++instruction;
							  if (*instruction == ']')
								  --loop_cnt;
							  else if (*instruction == '[')
								  ++loop_cnt;
						  }
					  }
					  break;
			case ']':
					  if (*ptr)
					  {
						  size_t loop_cnt = 1;
						  while (loop_cnt)
						  {
							  --instruction;
							  if (*instruction == '[')
								  --loop_cnt;
							  else if (*instruction == ']')
								  ++loop_cnt;
						  }
					  }
					  break;
		}
	}

	free(tshilidzi);
}

int		main(int c, char **v)
{
	if (c == 2)
		brainfuck_interpreter(v[1], sizeof(v[1]));
	else
		printf("Invalid number of arguments\n");
	return 0;
}
