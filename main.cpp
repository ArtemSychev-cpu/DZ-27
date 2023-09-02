#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Message.h"
#include <thread>
#include <shared_mutex>
#include <mutex>
#include "Logger.h"
using namespace std;

fstream log_file;
mutex m;
shared_mutex s;



int main()
{	
	User user1("Arnold", "Swarchenegger", "123");
	User user2("Bruce", "Willis", "1234");
	
	std::thread w1(Logger::write, user1);
	std::thread r1(Logger::read, user1);
	std::thread w2(Logger::write, user2);
	std::thread r2(Logger::read, user2);

	w1.join();
	r1.join();
	w2.join();
	r2.join();
return 0;
}
