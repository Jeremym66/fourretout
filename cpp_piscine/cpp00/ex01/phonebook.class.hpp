/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:00:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 08:58:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "contact.class.hpp"

class phonebook {

public:

	contact contacts[8];

	phonebook(void);
	~phonebook(void);

	void addcontact(contact newcontact);

private:

	int	_nb_contact;

};

#endif
