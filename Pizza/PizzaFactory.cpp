/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** PizzaFactory.cpp
*/

#include "PizzaFactory.h"

std::unique_ptr<APizza> PizzaFactory::createPizza(PizzaFactory::PizzaType pizzaType, std::string const &size) {
	try {
		switch (pizzaType) {
			case MARGARITA:
				return std::make_unique<Margarita>(size);
			case REGINA:
				return std::make_unique<Regina>(size);
			case AMERICAN:
				return std::make_unique<American>(size);
			case FANTASIA:
				return std::make_unique<Fantasia>(size);
		}
	} catch (std::exception const &e) {
		std::cerr << "Error : Invalid pizza type" << std::endl;
	}
	return nullptr;
}