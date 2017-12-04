//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef PLAZZAV1_COOKER_H
#define PLAZZAV1_COOKER_H

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


#endif //PLAZZAV1_COOKER_H
