//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#include <iostream>
#include "Cooker.h"

int Cooker::getKitchen() const {
	return kitchen;
}

const APizza &Cooker::getPizza() const {
	return pizza;
}

Cooker::Cooker() {

}

Cooker::~Cooker() {

}

void Cooker::cookPizza(std::string &pizza) {
	std::cout << "Cooking the pizza " << std::endl;
}
