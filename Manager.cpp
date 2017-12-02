/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** Manager.cpp
*/

#include "Manager.h"
#include <boost/algorithm/string.hpp>

Manager::Manager() {
	std::cout << "Manager : I'm the Plazza's manager !" << std::endl;
}

Manager::~Manager() {
	std::cout << "Manager : Here is the end of the day, see you !" << std::endl;
}

static inline std::string &ltrim(std::string &s) {
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	return s;
}

template <class Container>
void split5(const std::string& str, Container& cont,
	    const std::string& delims = ";")
{
	boost::split(cont, str, boost::is_any_of(delims));
}

std::queue<std::string> Manager::convertInputIntoOrder(Order order) {
	std::cout << order.getCommand() << std::endl;
	std::string orderToConvert = order.getCommand(); // "Margarita L 2 ; American XL 1"
	std::vector<std::string> result;
	int PizzaCounter = 0;

	ltrim(orderToConvert);
	std::cout << orderToConvert << std::endl; // "MargaritaL2;AmericanXL1"
	split5(orderToConvert, result);
	std::copy(result.begin(), result.end(),
		  std::ostream_iterator<std::string>(std::cout, "\n"));
	for (auto &entry : result){
		PizzaCounter = entry.back();
		for (int i = 0; i < PizzaCounter - 48; ++i) {
			pizzas.push(entry);
			pizzas.back().pop_back();
		}
	}

	return pizzas;
	/*
	 *
	 * 	std::string delimiter = ";";
	size_t pos = 0;
	std::string token;
	while ((pos = orderToConvert.find(delimiter)) != std::string::npos) {
		token = orderToConvert.substr(0, pos);
		std::cout << token << std::endl;
		pizzas.push(token);
		orderToConvert.erase(0, pos + delimiter.length());
	} */
}

std::queue<std::string> Manager::getPizzas() {
	return pizzas;
}
