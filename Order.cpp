//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#include "Order.h"

Order::Order(std::string &order) : command(order) {

}

Order::~Order() = default;

int Order::getId() const {
	return id;
}