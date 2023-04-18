/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:31:37 by kaly              #+#    #+#             */
/*   Updated: 2023/04/10 20:06:33 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_show_file(File *file)//affiche la liste 
{
	int	i;
	Element	*show_file;

	if (!file)
		return ;
	show_file = file->first;
	i = 1;
	while (show_file != NULL)
	{
		printf("nb %d : %d\n", i, show_file->nb);
		show_file = show_file->next;
		i++;
	}
}

void	ft_unstack(File *file)//supprime le dernier maillon de la chaine
{
	Element	*element_unstack;
	Element *previous;

	if (file->first == NULL)
		return ;
	element_unstack = file->first;
	previous = NULL;
	while (element_unstack->next != NULL)
	{
		previous = element_unstack;
		element_unstack = element_unstack->next;
	}
	if (previous == NULL)
		file->first;
	else
		previous->next = NULL;
	file->nb_element--;
	file->average = (file->average * (file->nb_element + 1) - element_unstack->nb) / file->nb_element;
	free(element_unstack);
}

void	ft_stack(File *file, int new_nb)//ajoute un element a la chaine
{
	Element *new;
	Element *existing;

	new = malloc(sizeof(*new));
	existing = file->first;
	if (!new || !file)
		return ;
	new->nb = new_nb;
	new->next = NULL;
	if (file->first == NULL)
		file->first = new;
	else
	{
		while (existing->next != NULL)
			existing = existing->next;
		existing->next = new;
	}
	file->nb_element++;
	printf("le nombre d'elements dans ma liste est de : %d\n", file->nb_element);
	file->average = (file->average * (file->nb_element - 1) + new_nb) / file->nb_element;
	printf("la moyenne des elements de ma liste est de : %f\n", file->average);	
}	

File	*ft_init_list()//initialise la liste a 0;
{
	File	*file;

	file = malloc(sizeof(*file));
	if (!file)
		exit(EXIT_FAILURE);
	file->first = NULL;
	file->nb_element = 0;
	file->average = 0;
	return (file);
}

int	main(int argc, char **argv)
{
	File	*file1;
	File	*file2;
	int	i;

	i = 0;
	if (argc > 1)
	{
		file1 = ft_init_list();
		file2 = ft_init_list();
		while (++i < argc)
			ft_stack(file1, ft_atoi(argv[i]));
	}
	else
		return (printf("mauvais format vous devez ajouter des arguments!\n"));
	ft_show_file(file1);
	ft_unstack(file1);
	ft_unstack(file1);
	printf("le nombre d'elements dans ma liste 1 est de : %d\n", file1->nb_element);
	printf("la moyenne des elements de ma liste 1 est de : %f\n", file1->average);	
	printf("le nombre d'elements dans ma liste 2 est de : %d\n", file2->nb_element);
	printf("la moyenne des elements de ma liste 2 est de : %f\n", file2->average);	
	return (0);
}
