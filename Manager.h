/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** Manager.h
*/

#ifndef MANAGER_H__
#define MANAGER_H__

#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

#include "Order.h"

class Manager {
public:
	Manager();
	~Manager();

	std::queue<std::string> convertInputIntoOrder(Order order);
	std::queue<std::string> getOrders();

private:
	std::queue<std::string> pizzas;
};

#endif /* ! MANAGER_H__ */