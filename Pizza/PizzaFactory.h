/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** PizzaFactory.h
*/

#ifndef PIZZAFACTORY_H__
#define PIZZAFACTORY_H__

#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>

#include "APizza.h"
#include "Margarita.h"
#include "American.h"
#include "Fantasia.h"
#include "Regina.h"

class PizzaFactory
{
public:
	enum PizzaType {
		MARGARITA,
		REGINA,
		AMERICAN,
		FANTASIA
	};

	static std::unique_ptr<APizza> createPizza(PizzaType pizzaType, std::string const &size);
};

#endif /* ! PIZZAFACTORY_H__ */