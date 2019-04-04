#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
class out: public std::logic_error
{
public:

	explicit out(const std::string& s):  logic_error(s){ }
	explicit out(const char* c): logic_error(c){}

};

#endif