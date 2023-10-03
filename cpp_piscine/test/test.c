/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:56 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/02 16:24:57 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    printlist(t_list *data)
{
    // t_list *temp;
    int i;

    // temp = data;
    i = 0;
    while (data->next != NULL)
    {
        printf("le chiffre %d est : %d\n", i, data->nbr);
        data = data->next;
        i++;
    }
    printf("le chiffre %d est : %d\n", i, data->nbr);
}

void fonctionquicreeunmqillon(t_list *stack, int nb)
{
    t_list  *new_maillon;
    // t_list  *temp;

    new_maillon = malloc(sizeof(*new_maillon));
    if (!new_maillon)
        exit(EXIT_FAILURE);
    // temp = stack;
    while(stack->next != NULL)
        stack = stack->next;
    stack->next = new_maillon;
    new_maillon->nbr = nb;
    new_maillon->next = NULL;

}

void fonctionquimultipliepar2(t_list *stack)
{
    printf("le chiffre dans la fonction est : %d\n", stack->nbr);
    stack->nbr = stack->nbr * 2;
    printf("le chiffre dans la fonction est : %d\n", stack->nbr);
}

int main(int ac, char **av)
{
    t_list  *stack;
    int i;

    if (ac < 2)
        return (0);
    stack = malloc(sizeof(*stack));
    if (!stack)
        exit(EXIT_FAILURE);
    stack->nbr = atoi(av[1]);
    stack->next = NULL; // cest le pointeur du maillon suivant; 
    i = 1;
    while (av[++i])
        fonctionquicreeunmqillon(stack, atoi(av[i]));
    // printf("le chiffre est : %d\n", stack->nbr);
    // fonctionquimultipliepar2(stack);
    // printf("le chiffre est : %d\n", stack->nbr);
    printlist(stack);
    printf("adresse stack : %p\n", &stack);
    printlist(stack);
     printf("adresse stack : %p\n", &stack);
    return (0);
}

