#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <shared_mutex>
#include <mutex>
#include "User.h"

namespace fs = std::filesystem;

class Logger
{
	std::fstream log_file;
	std::mutex m;
	std::shared_mutex s;
public:
	Logger()
	{
		std::fstream log_file = std::fstream("users.txt", std::ios::in | std::ios::out);
		if (!log_file)
			log_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
	}

	void write(User& user)
	{
		if (log_file) {
			m.lock();
			log_file << user << std::endl;
			m.unlock();
		}
	}
	void read(User user) {
		s.lock_shared();

		log_file >> user;
		std::cout << user << std::endl;
		s.unlock_shared();
	}
		
	~Logger()
	{
		log_file.clear();
		log_file.seekg(0, std::ios_base::end);
		log_file.seekp(0, std::ios_base::end);
		log_file.close();
	}
	Logger(Logger const&) = delete;
	Logger& operator=(Logger const&) = delete;
	
	std::fstream& getLog_file()
	{
		return log_file;
	}

};
