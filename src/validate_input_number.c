/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:44:56 by valero            #+#    #+#             */
/*   Updated: 2025/08/22 19:21:55 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_validate_chars_result	validate_chars(const char *current_arg,
									int i, int it_has_digit,
									t_validate_chars_result result);
static t_extract_number_result	extract_number(
									const char *str, int len,
									t_extract_number_result result);
static int						extract_input_splittable(
									t_push_swap *push_swap,
									char *current_arg);
static int						extract_input_unique(
									t_push_swap *push_swap,
									char *current_arg);

int	extract_input(t_push_swap *self, int argc, char **argv)
{
	t_validate_chars_result	char_validation;
	int						result;

	if (!self || !argc || !argv || !*argv)
		return (0);
	char_validation = BEGIN_CHARS_VALIDATION;
	result = 1;
	while (--argc >= 1)
	{
		char_validation = validate_chars(argv[argc], -1, 0, char_validation);
		if (char_validation == CHARS_VALIDATION_ERROR)
			return (0);
		if (char_validation == IS_CHARS_SPLITTABLE)
		{
			if (result)
				result = extract_input_splittable(self, argv[argc]);
		}
		else if (result)
		{
			result = extract_input_unique(self, argv[argc]);
		}
	}
	if (!result)
		self->destroy(&self);
	return (result);
}

static t_validate_chars_result	validate_chars(const char *current_arg, int i,
	int it_has_digit, t_validate_chars_result result)
{
	char					current_char;

	if (!current_arg || !current_arg[0])
		return (CHARS_VALIDATION_ERROR);
	while (current_arg[++i])
	{
		current_char = current_arg[i];
		if (!is_valid_char(current_char))
			return (CHARS_VALIDATION_ERROR);
		if ((ft_issign(current_char) && current_arg[i + 1]
				&& !ft_isdigit(current_arg[i + 1])) || (ft_isdigit(current_char)
				&& current_arg[i + 1] && !is_nbr_or_space(current_arg[i + 1])))
			return (CHARS_VALIDATION_ERROR);
		if (current_char == ' ' && (current_arg[i + 1]
				&& current_arg[i + 1] != ' '))
			result = IS_CHARS_SPLITTABLE;
		if (ft_isdigit(current_char))
			it_has_digit = 1;
	}
	if (!it_has_digit)
		return (CHARS_VALIDATION_ERROR);
	if (result == BEGIN_CHARS_VALIDATION)
		return (CHARS_VALIDATION_OK);
	return (result);
}

static int	extract_input_splittable(t_push_swap *push_swap, char *current_arg)
{
	int						split_len;
	char					**splitted_numbers;
	t_extract_number_result	extractted_number;

	extractted_number.number = 0;
	extractted_number.validation_info = BEGIN_NUMBER_VALIDATION;
	if (!push_swap || !current_arg)
		return (0);
	splitted_numbers = ft_split(current_arg, ' ');
	if (!splitted_numbers)
		return (0);
	split_len = 0;
	while (splitted_numbers[split_len])
		split_len++;
	while (--split_len >= 0)
	{
		extractted_number = extract_number(splitted_numbers[split_len],
				ft_strlen(splitted_numbers[split_len]), extractted_number);
		if (extractted_number.validation_info == NUMBER_VALIDATION_ERROR)
			return (0);
		if (!fill_stack_a(push_swap, extractted_number.number))
			return (!!ft_destroy_char_matrix(&splitted_numbers));
	}
	ft_destroy_char_matrix(&splitted_numbers);
	return (1);
}

static int	extract_input_unique(t_push_swap *push_swap, char *current_arg)
{
	t_extract_number_result	extractted_number;
	char					*trimmed_number;

	extractted_number.number = 0;
	extractted_number.validation_info = BEGIN_NUMBER_VALIDATION;
	if (!push_swap || !current_arg)
		return (0);
	trimmed_number = ft_strtrim(current_arg, " ");
	if (!trimmed_number)
		return (0);
	extractted_number = extract_number(trimmed_number,
			ft_strlen(trimmed_number), extractted_number);
	if (extractted_number.validation_info == NUMBER_VALIDATION_ERROR)
		return (0);
	if (!fill_stack_a(push_swap, extractted_number.number))
	{
		free(trimmed_number);
		return (0);
	}
	free(trimmed_number);
	return (1);
}

static t_extract_number_result	extract_number(
		const char *str, int len, t_extract_number_result result)
{
	if (!str || !*str)
	{
		result.validation_info = NUMBER_VALIDATION_ERROR;
		return (result);
	}
	if (ft_issign(*str) && len > INT_MIN_LENGTH)
	{
		result.validation_info = NUMBER_VALIDATION_ERROR;
		return (result);
	}
	if (len > INT_MAX_LENGTH)
	{
		result.validation_info = NUMBER_VALIDATION_ERROR;
		return (result);
	}
	result.number = ft_atol(str);
	if (result.number > INT_MAX || result.number < INT_MIN)
	{
		result.validation_info = NUMBER_VALIDATION_ERROR;
		return (result);
	}
	result.validation_info = NUMBER_VALIDATION_OK;
	return (result);
}
