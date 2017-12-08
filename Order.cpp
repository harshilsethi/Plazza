//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#include "Order.h"

#include <utility>

Order::Order() {

}

Order::Order(std::string &order) : command(order) {
}

Order::~Order() = default;

int Order::getId() const {
	return id;
}

std::string Order::getCommand() {
	return command;
}

void Order::setCommand(std::string command) {
	this->command = std::move(command);
}