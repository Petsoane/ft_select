/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:22:49 by lpetsoan          #+#    #+#             */
/*   Updated: 2020/01/26 14:28:51 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELELCT
# define FT_SELECT
#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>

// Check if the termcap library is unix or gnu
#ifdef unix
    // Create a buffer explicitly
    static char term_buffer[2048];
#else
    // Set the buffer to null.
    #define term_buffer 0
#endif
#endif