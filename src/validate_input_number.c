/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:44:56 by valero            #+#    #+#             */
/*   Updated: 2025/08/20 22:38:46 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_char(char	c)
{
	return (ft_isdigit(c) || c == '+' || c == '-' || c == ' ');
}

t_validate_chars_result	validate_chars(const char *str)
{
	int						i;
	t_validate_chars_result	result;

	if (!str || !str[0])
		return (CHARS_VALIDATION_ERROR);
	result = BEGIN_CHARS_VALIDATION;
	i = -1;
	while (str[++i])
	{
		if (!is_valid_char(str[++i]))
			return (CHARS_VALIDATION_ERROR);
		if ((str[i] == '+' || str[i] == '-')
			&& str[i + 1] && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (CHARS_VALIDATION_ERROR);
		if (str[i] == ' ' && (str[i + 1] && str[i + 1] != ' '))
			result = IS_CHARS_SPLITTABLE;
	}
	if (result == BEGIN_CHARS_VALIDATION)
		return (CHARS_VALIDATION_OK);
	return (result);
}

t_extract_number_result	extract_number(const char *str)
{
	int						len;
	t_extract_number_result	result;

	result.number = 0;
	result.validation_info = BEGIN_NUMBER_VALIDATION;
	len = ft_strlen(str);
	if ((*str == '-' || *str == '+') && len > INT_MIN_LENGTH)
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

int	extract_input(t_push_swap *push_swap, int argc, char **argv)
{
	t_validate_chars_result	char_validation;
	t_extract_number_result	extractted_number;
	char					**splitted_numbers;
	char					*trimmed_number;

	splitted_numbers = NULL;
	trimmed_number = NULL;
	while (--argc >= 1)
	{
		char_validation = validate_chars(argv[argc]);
		if (char_validation == CHARS_VALIDATION_ERROR)
			return (0);
		if (char_validation == IS_CHARS_SPLITTABLE)
		{
			splitted_numbers = ft_split(argv[argc], ' ');
			while (splitted_numbers)
			{

			}
			return (0);
		}
		trimmed_number = ft_strtrim(argv[argc], " ");
		extractted_number = extract_number(trimmed_number);
		if (extractted_number.validation_info == NUMBER_VALIDATION_ERROR)
			return (0);
		if (!fill_stack_a(push_swap, extractted_number.number))
		{
			free(trimmed_number);
			return (0);
		}
		free(trimmed_number);
	}
}

int extract_input_splittable(t_push_swap *push_swap, char *current_arg, char **argv)
{
	int						i;
	char					**splitted_numbers;
	t_extract_number_result	extractted_number;

	splitted_numbers = ft_split(current_arg, ' ');
	i = -1;
	while (splitted_numbers[++i])
	{
		extractted_number = extract_number(splitted_numbers[++i]);
		if (extractted_number.validation_info == NUMBER_VALIDATION_ERROR)
			return (0);
		if (!fill_stack_a(push_swap, extractted_number.number))
		{
			// free(trimmed_number);
			return (0);
		}
		// free(trimmed_number);
	}
	return (0);
}
