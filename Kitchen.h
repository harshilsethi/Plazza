/*                                                                              
** EPITECH PROJECT, 2017                                                        
** Plazza project
** File description:                                                            
** Kitchen.h
*/

#ifndef KITCHEN_H__
#define KITCHEN_H__

#include <list>
#include <queue>
#include <string>
#include "Cooker.h"
#include "Team.h"
#include "Pizza/PizzaFactory.h"

class Kitchen {
private:
	int id;
	PizzaFactory pizzaFactory;
	int nbCookers;
	std::queue<std::string> orders;
	std::list<Cooker> cookers;
	pid_t pid;
public:
	explicit Kitchen(int,int);
	~Kitchen();

        int getId();
	int getNbCookers();
	std::list<Cooker> &getCookers();
	void addOrder(std::string &);
	std::string giveOrder();
	void deleteOrder();
	void dispatch(Team &, int);
	int getNbOfBusyCookers();
	void updateStatus();
	void quit();
};


#endif //KITCHEN_H__
