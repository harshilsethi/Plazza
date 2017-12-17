//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.h
//

#ifndef COOKER_H__
#define COOKER_H__

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "Pizza/APizza.h"
#include "Pizza/PizzaFactory.h"
//#include "Kitchen.h"

class Kitchen;

class Cooker {
private:
	std::mutex cookerMtx;
	Kitchen *kitchen;
	int id;
	APizza *pizza;
	bool busy;
public:
	Cooker();
	~Cooker();

	Cooker(const Cooker &);
	Cooker &operator=(Cooker const &);
	int getId() const;
	Kitchen *getKitchen() const;
	void setKitchen(Kitchen *kitchen);
	const APizza &getPizza() const;
	void cookPizza(std::string, std::string, int, PizzaFactory *);
	void runThread(const std::string &, const std::string &, int, PizzaFactory *);
	void reset(); // reinit the cooker
	bool isBusy();
};


#endif //COOKER_H
