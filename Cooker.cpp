//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.cpp
//

#include "Cooker.h"
#include "Pizza/Margarita.h"
#include "Pizza/American.h"
#include "Pizza/Fantasia.h"
#include "Pizza/Regina.h"

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
	busy = origin.busy;
}

Cooker &Cooker::operator=(Cooker const &origin) {
	if (this != &origin) {
		id = origin.id;
		kitchen = origin.kitchen;
		pizza = origin.pizza;
		busy = origin.busy;
	}
	return *this;
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

void Cooker::cookPizza(std::string pizza, std::string size, int timeBase) {
	long int timeToWait;
	cookerMtx.lock();
	std::cout << "Cooking the pizza: " << pizza << std::endl;
	if (pizza == "Margarita") {
		APizza *pizzaCooked = new Margarita(size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "American") {
		APizza *pizzaCooked = new American(size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "Fantasia") {
		APizza *pizzaCooked = new Fantasia(size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "Regina") {
		APizza *pizzaCooked = new Regina(size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	}
	cookerMtx.unlock();
	busy = false; //at the end
}

void Cooker::runThread(const std::string &aPizza, const std::string &aSize, int timeBase) {
	std::thread cookerTh(&Cooker::cookPizza, this, aPizza, aSize, timeBase);
	busy = true;
	cookerTh.join();
}

void Cooker::reset() {
	kitchen = -1; // not sure ...
	pizza = nullptr;
	busy = false;
}

bool Cooker::isBusy() {
	return busy;
}