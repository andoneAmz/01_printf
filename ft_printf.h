/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamezque <aamezque@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:32:49 by aamezque          #+#    #+#             */
/*   Updated: 2025/02/18 10:32:51 by aamezque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_format
{
	char    align;      // defaut, left, zero padding
	char    sign;       // default, +, blankspace
	int     width;      // Field width
	int     precision;  // Precision for floats/strings
	int     alt_format; // Alternate format (#)
	char    mod;       // Length modifier (h, l, etc.)
	char    type;       // Format specifier (d, s, x, etc.)
} t_format;
