/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:18:18 by user              #+#    #+#             */
/*   Updated: 2020/05/12 22:11:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


   #include <stdio.h>
#include "libft.h"
#include "byte_tokenizer.h"
#include "converter_utils.h"
#include "converter.h"



static void		destroy_bytelines(t_vector_byteline lines)
{
	const int	lines_count = vec_size(&lines);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		vec_destroy(&lines[line].labels);
		vec_destroy(&lines[line].bytetokens);
		line += 1;
	}
	vec_destroy(&lines);
}

// static void print(const t_vector_char *lines)
// {
// 	printf("BYTECODE:\n");
// 	for (int i = 0; i < vec_size(&lines); ++i) {
// 		for (int j = 0; j < vec_size((t_vector)&lines[i]); ++j) {
// 			char *str = num_to_bits(&lines[i][j], 1);
// //			printf("%x", lines[i][j]);
// 			printf("%s ", str);
// 			free(str);
// 		}
// 		printf("\n");
// 	}
// }


t_vector_char	*convert_to_bytecode(const t_vector_token *tokens)
{
	t_vector_byteline	bytelines;
	t_vector_char		*bytecode;

	bytelines = byte_tokenizer(tokens);
	bytecode = generate_bytecode(bytelines);
//	print(bytecode);
	destroy_bytelines(bytelines);
	return (bytecode);
}
