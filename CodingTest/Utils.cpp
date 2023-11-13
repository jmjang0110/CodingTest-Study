#include "pch.h"
#include "Utils.h"

/// delimiter�� �������� string �� ������. 
std::vector<std::string> Utils::Split(std::string Input, char delimiter)
{
	// #include <sstream>
	std::vector<std::string> Output;
	std::stringstream ss(Input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		Output.push_back(temp);
	}
	return Output;
}
