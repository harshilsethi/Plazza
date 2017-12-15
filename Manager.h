/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** Manager.h
*/

#ifndef MANAGER_H__
#define MANAGER_H__

#include <zconf.h>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <sys/wait.h>
#include "Kitchen.h"
#include "Order.h"

class Manager {
public:
	Manager();
	~Manager();

	std::queue<std::string> convertInputIntoOrder(Order order);
	std::queue<std::string> getPizzas();
	void manageKitchens(unsigned int, PizzaFactory *);
	void setTime(int);
	int getTime();
        unsigned int getOrderID();
        void nextOrderID();
	std::list<Kitchen *> getKitchens();
	std::map<int, int> getKitchenStatus();

private:
	std::queue<std::string> pizzas;
	std::list<Kitchen *> kitchens;
	Team managerTeam;
	int baseTime;
        unsigned int orderID;
        unsigned int idKitchen;
};

#endif /* ! MANAGER_H__ */