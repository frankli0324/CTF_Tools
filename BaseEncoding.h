#pragma once
#include<string>
//开个python很难么Orz
namespace base64 {
	std::string b64encode(std::string txt);
	std::string b64decode(std::string enc);

	std::string b32encode(std::string txt);
	std::string b32decode(std::string enc);

	std::string b16encode(std::string txt);
	std::string b16decode(std::string enc);
}