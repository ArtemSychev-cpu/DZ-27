#pragma once

class User
{
    std::string _name;
    std::string _login;
    std::string _pass;
	
public:
	User() = default;
	User(std::string name, std::string login, std::string pass) :_name(name), _login(login), _pass(pass) {}

	friend std::fstream& operator >>(std::fstream& is, User& obj)
	{
		is >> obj._name;
		is >> obj._login;
		is >> obj._pass;
		return is;
	}
	friend std::ostream& operator <<(std::ostream& os, const User& obj)
	{
		os << obj._name;
		os << ' ';
		os << obj._login;
		os << ' ';
		os << obj._pass;
		return os;
	}
	
};
