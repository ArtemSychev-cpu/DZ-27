#pragma once
#include <string>
#include <fstream>

class Message
{
    string _text;
    string _sender;
    string _receiver;


public:
	Message(string text, string sender, string receiver) :_text(text), _sender(sender), _receiver(receiver) {}
	
	
	friend fstream& operator >>(fstream& is, Message& obj1)
	{
		is >> obj1._text;
		is >> obj1._sender;
		is >> obj1._receiver;
		return is;
	}
	friend ostream& operator <<(ostream& os, const Message& obj1)
	{
		os << obj1._text;
		os << ' ';
		os << obj1._sender;
		os << ' ';
		os << obj1._receiver;
		return os;
	}
};
