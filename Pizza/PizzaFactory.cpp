/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** PizzaFactory.cpp
*/

#include "PizzaFactory.h"

std::unique_ptr<APizza> PizzaFactory::createPizza(PizzaFactory::PizzaType pizzaType, std::string const &size) {
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
	throw "invalid pizza type";
}