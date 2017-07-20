/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 08:59:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/07/12 10:38:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb);
int		ft_recursive_factorial(int nb);
int		ft_iterative_power(int nb, int power);
int		ft_recursive_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);

int		main(void)
{
	int nb;
	int power;
	int index;

	nb = 0;
	power = 0;
	index = 0;

	printf("Donner la valeur d'entree de \"ft_iterative_factorial\"\n");
	scanf("%i", &nb);
	printf("%i\n", ft_iterative_factorial(nb));
	printf("Donner la valeur d'entree de \"ft_recursive_factorial\"\n");
	scanf("%i", &nb);
	printf("%i\n", ft_recursive_factorial(nb));

	printf("Donner les 2 valeurs d'entree de \"ft_iterative_power\" (separees par un espace)\n");
	scanf("%i %i", &nb, &power);
	printf("%i\n", ft_iterative_power(nb, power));
	printf("Donner les 2 valeurs d'entree de \"ft_recursive_power\" (separees par un espace)\n");
	scanf("%i %i", &nb, &power);
	printf("%i\n", ft_recursive_power(nb, power));

	printf("Donner la valeur d'entree de \"ft_fibonacci\"\n");
	scanf("%i", &index);
	printf("%i\n", ft_fibonacci(index));

	printf("Donner la valeur d'entree de \"ft_sqrt\"\n");
	scanf("%i", &nb);
	printf("%i\n", ft_sqrt(nb));

	printf("Donner la valeur d'entree de \"ft_is_prime\"\n");
	scanf("%i", &nb);
	printf("%i\n", ft_is_prime(nb));

	printf("Donner la valeur d'entree de \"ft_find_next_prime\"\n");
	scanf("%i", &nb);
	printf("%i\n", ft_find_next_prime(nb));

	return (0);
}
