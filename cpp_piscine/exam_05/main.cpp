/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:08:14 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/22 19:35:34 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"

int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  ASpell* sort1 = new ASpell("trait de feu", "brule");
  // ASpell const sort1("trait de feu", "brule");

  std::cout << sort1->getName() << " " << sort1->getEffects() << std::endl;
  delete sort1;
  return (0);
}
