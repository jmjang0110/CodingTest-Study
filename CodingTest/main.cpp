
#undef UNICODE
#undef _UNICODE 

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <vector>

int main(void)
{
	TCHAR str[] = _T("test");
	std::cout << sizeof(str) << std::endl;

	std::vector<int> v;
	v.resize(10);
	std::cout << v[9] << std::endl;


	return 0;
}
