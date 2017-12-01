//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#include <iostream>
#include "Cooker.h"

Cooker::Cooker() : pizza(nullptr) {
}

Cooker::~Cooker() = default;

int Cooker::getKitchen() const {
	return kitchen;
}

const APizza &Cooker::getPizza() const {
	return pizza;
}

void Cooker::cookPizza(std::string &pizza) {
	std::cout << "Cooking the pizza " << std::endl;
}
