#include "slent_api.h"
#include <iostream>
#include <string>

extern "C" {

	SLENT_API bool string_equals(const std::string& self, const std::string& str) {
		return self == str;
	}
	
	SLENT_API int string_compare(const std::string& self, const std::string& str) {
		return self.compare(str);
	}

	SLENT_API char string_getCharAt(const std::string& self, int index) {
		return self[index];
	}

	SLENT_API int string_length(const std::string& self) {
		return self.length();
	}

	SLENT_API char* string_toCharArray(const std::string& self) {
		char* buffer = new char[self.size() + 1];
		std::strcpy(buffer, self.c_str());
		return buffer;
	}

	SLENT_API std::string string_subStr(const std::string& self, int startIndex) {
		return self.substr(startIndex);
	}

	SLENT_API std::string string_subStr(const std::string& self, int startIndex, int length) {
		return self.substr(startIndex, length);
	}

}
