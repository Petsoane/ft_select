/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:23:52 by lpetsoan          #+#    #+#             */
/*   Updated: 2020/01/26 14:35:30 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h";

// Initilize the terminal data.
void    init_terminal_data()
{
    // Get the terminal type from the environmet.
    char *termtype = getenv("TERM");
    int success;

    // Check if the terminal type is found.
    if (termtype == 0)
    {
        printf("Specify the termial type with setenv");
        exit(1);
    }
    // Get the terminal information,
    success = tgetent(term_buffer, termtype);
    // Check if the information is retrivable
    if (success < 0)
    {
        printf("Could not access termcap database.");
        exit(1);
    }
    if (success == 0)
    {
        printf("The specified terminal type is not found in the database");
        exit(1);
    }

    // No return type because tgetent retains the
    // information about the terminal internally.
}