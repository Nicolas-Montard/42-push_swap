/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:42:48 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/22 13:28:57 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "parsing_verif_numbers.h"
# include "stack.h"

char	**verif_input(int argc, char *argv[], int flags[2], int *error);
int		adaptive(t_stacks *stacks);
char	**normalize_numbers(int argc, char *argv[]);

#endif