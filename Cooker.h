//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef COOKER_H__
#define COOKER_H__


#include "Pizza/APizza.h"

class Cooker {
private:
	int kitchen;
	int id;
	APizza pizza;
	bool busy;
	bool threadRun;
public:
	Cooker();
	~Cooker();

	int getKitchen() const;
	const APizza &getPizza() const;
	void cookPizza(std::string &pizza);
};


#endif //COOKER_H
