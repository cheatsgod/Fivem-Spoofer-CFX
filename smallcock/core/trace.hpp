#pragma once
#include "common.hpp"

class trace
{
public:
	void setup();
	void destroy();
	std::string set_folder(std::string title);
public:
	std::string m_save_path{ "save.txt" };
	std::string m_fivem_path;
};

inline std::unique_ptr<trace> g_trace;