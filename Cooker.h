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

class Cooker {
private:
	std::mutex cookerMtx;
	int kitchen;
	int id;
	APizza *pizza; // pointeur ?
	bool busy;
	bool threadRun;
public:
	Cooker();
	~Cooker();

	Cooker(const Cooker &);
	Cooker &operator=(Cooker const &);
	int getId() const;
	int getKitchen() const;
	const APizza &getPizza() const;
	void cookPizza(std::string);
	void runThread(const std::string &);
	void reset(); // reinit the cooker
};


#endif //COOKER_H
