//
// EPITECH PROJECT, 2017
// Plazza Project
// File description:
// Order.cpp
//

#include "Order.h"

Order::Order(std::string &order) : command(order) {

}

Order::~Order() = default;

int Order::getId() const {
	return id;
}

std::string Order::getCommand() {
	return command;
}