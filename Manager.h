/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** Manager.h
*/

#ifndef MANAGER_H__
#define MANAGER_H__

#include <zconf.h>
#include <string>
#include <queue>
#include <list>
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
	void manageKitchens(unsigned int);

private:
	std::queue<std::string> pizzas;
	std::list<Kitchen *> kitchens;
	Team managerTeam;
};

#endif /* ! MANAGER_H__ */