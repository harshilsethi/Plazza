//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.h
//

#ifndef COOKER_H__
#define COOKER_H__

#include <iostream>
#include <thread>
#include <mutex>
#include "Pizza/APizza.h"

class Cooker {
private:
	std::thread *cookerTh;
	std::mutex cookerMtx;
	int kitchen;
	int id;
	APizza pizza;
	bool busy;
	bool threadRun;
public:
	Cooker();
	~Cooker();

	int getId() const;
	int getKitchen() const;
	const APizza &getPizza() const;
	void cookPizza(std::string &);
	void setThread(std::string &);
};


#endif //COOKER_H
