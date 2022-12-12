#pragma once
#include <iostream>
class InvalidPosition : public std::invalid_argument {
public:
	using invalid_argument::invalid_argument;
};
class Invalidcommand : public std::domain_error {
public:
	using domain_error::domain_error;
};
