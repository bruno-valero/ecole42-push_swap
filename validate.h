/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:28:29 by valero            #+#    #+#             */
/*   Updated: 2025/08/22 18:27:00 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# ifndef INT_MIN_LENGTH
#  define INT_MIN_LENGTH 11
# endif

# ifndef INT_MAX_LENGTH
#  define INT_MAX_LENGTH 10
# endif

typedef struct s_push_swap	t_push_swap;

typedef enum e_validate_chars_result
{
	BEGIN_CHARS_VALIDATION,
	IS_CHARS_SPLITTABLE,
	CHARS_VALIDATION_ERROR,
	CHARS_VALIDATION_OK
}	t_validate_chars_result;

typedef enum e_validate_number_result
{
	BEGIN_NUMBER_VALIDATION,
	NUMBER_VALIDATION_ERROR,
	NUMBER_VALIDATION_OK
}	t_validate_number_result;

typedef struct s_extract_number_result
{
	long int					number;
	t_validate_number_result	validation_info;
}	t_extract_number_result;

int	extract_input(t_push_swap *self, int argc, char **argv);
int	is_nbr_or_space(int c);
int	is_valid_char(int c);

#endif
