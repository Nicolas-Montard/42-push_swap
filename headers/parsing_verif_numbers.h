/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_numbers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:40:46 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/20 14:50:26 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_VERIF_H
# define PARSING_VERIF_H

int	numbers_are_int(char **numbers);

int	number_is_int_negative(char *number);

int	number_is_int_positive(char *number);

int	has_no_same_number(char **values);

int	has_only_number(char **values);

#endif