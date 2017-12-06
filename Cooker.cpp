//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.cpp
//

#include <iostream>
#include "Cooker.h"

static int nextId = 0;

Cooker::Cooker() : pizza(nullptr) {
	nextId++;
	id = nextId;
}

Cooker::~Cooker(){
	delete cookerTh;
}

int Cooker::getId() const{
	return (id);
}

int Cooker::getKitchen() const {
	return kitchen;
}

const APizza &Cooker::getPizza() const {
	return pizza;
}

void Cooker::cookPizza(std::string pizza) {
	std::cout << "Cooking the pizza: " << pizza << std::endl;
}
/*
void Cooker::setThread(std::string &aPizza) {
	cookerTh = new std::thread(&Cooker::cookPizza, &aPizza);
}
*/
