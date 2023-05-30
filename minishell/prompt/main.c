/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/05/27 13:10:39 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
			// Gestion du signal SIGINT (CTRL + C)
		printf("\nSignal SIGINT reçu. Fermeture du shell.\n");
		exit(EXIT_SUCCESS);
	}
}

void	execute_command(char *command, char **envp)
{
	char *arguments[MAX_ARGUMENTS];
	int i;

	while (*command != '\0')
	{
			// Ignorer les espaces au début
		while (*command == ' ')
			command++;
			// Sauvegarder le début de l'argument
		arguments[i] = command;
		i++;
			// Recherche le prochain espace ou fin de chaîne
		while (*command != ' ' && *command != '\0')
			command++;
			// Remplace l'espace par un caractère nul pour terminer l'argument
		if (*command != '\0')
			*command = '\0';
		command++;
	}
	arguments[i] = NULL;
	i = 0;
	while (arguments[i])
	{
		printf("%s\n", arguments[i]);
		i++;
	}
		// Crée un nouveau processus, le fils aura un pid a 0
	pid_t pid = fork();
        	// Code exécuté par le processus fils
	if (pid == 0)
	{
		int	i;

		i = 0;
		while(envp[i])
		{
			printf("%s\n", envp[0]);
			i++;
		}
			// Exécute la commande
 		execve(arguments[0], arguments, envp);
			// Si execvp échoue, affiche un message d'erreur
		perror("Erreur d'exécution de la commande");
		exit(EXIT_FAILURE);
	} 
        	// Erreur lors de la création du processus fils
	else if (pid < 0)
        	perror("Erreur lors de la création du processus");
        	// Code exécuté par le processus parent
        	// Attends que le processus fils se termine
 	else
        	wait(NULL);

}

void	shell_loop(char **envp)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
		// Affiche le prompt
	printf("J'affiche ce que je veut avant le prompt >> $ ");
	fflush(stdout);

		// Lit la commande entrée par l'utilisateur
	fgets(command, sizeof(command), stdin);

		// Supprime le saut de ligne final
	command[strcspn(command, "\n")] = '\0';

		// Vérifie si l'utilisateur veut quitter le shell
	if (strcmp(command, "exit") == 0/* || keysym == 119 || keysym == 65362*/)
		break;

		// Exécute la commande
	execute_command(command, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	// Lance la boucle du shell
	shell_loop(envp);

	return (0);
}
