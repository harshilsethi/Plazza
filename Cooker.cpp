//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.cpp
//

#include "Cooker.h"

static int nextId = 0;

Cooker::Cooker(){
	nextId++;
	pizza = nullptr;
	id = nextId;
}

Cooker::~Cooker(){
	delete pizza;
}

Cooker::Cooker(const Cooker &origin) {
	id = origin.id;
	kitchen = origin.kitchen;
	pizza = origin.pizza;
	threadRun = origin.threadRun;
	busy = origin.busy;
}

Cooker Cooker::operator=(Cooker &origin) {
	Cooker temp(origin);
	return (temp);
}

int Cooker::getId() const{
	return (id);
}

int Cooker::getKitchen() const {
	return kitchen;
}

const APizza &Cooker::getPizza() const {
	return *pizza;
}

void Cooker::cookPizza(std::string pizza) {
	cookerMtx.lock();
	std::cout << "Cooking the pizza: " << pizza << std::endl;
	cookerMtx.unlock();
	threadRun = false; //at the end
}

void Cooker::runThread(const std::string &aPizza) {
	std::thread cookerTh(&Cooker::cookPizza, this, aPizza);
	threadRun = true;
	cookerTh.join();
}

void Cooker::reset() {
	kitchen = -1; // not sure ...
	pizza = nullptr;
	busy = false;
	threadRun = false;
}