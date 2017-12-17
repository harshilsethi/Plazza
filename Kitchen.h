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
#include <chrono>
#include "Cooker.h"
#include "Team.h"
#include "Pizza/PizzaFactory.h"
#include "Manager.h"

class Kitchen {
private:
	int id;
	PizzaFactory pizzaFactory;
	int nbBusyCookers;
	int nbMaxCookers;
	std::queue<std::string> orders;
	std::list<Cooker> cookers;
	pid_t pid;
	int time;

public:
	explicit Kitchen(int,int);
	~Kitchen();

	int getId();
        void setNbOfBusyCookers(int);
	int getNbBusyCookers();
	std::list<Cooker> &getCookers();
	void addOrder(std::string &);
	std::string giveOrder();
	void deleteOrder();
	void dispatch(Team &, int, PizzaFactory *);
	void updateStatus(int);
	void quit();
	void timer(int);
	int getNbMaxCookers();

};

#endif //KITCHEN_H__
