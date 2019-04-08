#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

std::string makeMessage(std::string file, std::string function , int line)
{

	std::string message = "error in " + file + " in function " + function + " at line " + std::to_string(line);
	return message;
}

class index_error : public std::logic_error
{
public:
	explicit index_error(const std::string& s) : logic_error("index error " + s) { }
	explicit index_error(const char* c) : logic_error(c) {}
};

class vecteur_length_error : public std::logic_error
{
	explicit vecteur_length_error(const std::string& s) : logic_error("length error " + s) { }
	explicit vecteur_length_error(const char* c) : logic_error(c) {}
};
class  vector_length_mismatch : public std::logic_error
{
public:
	explicit vector_length_mismatch(const std::string& s) : logic_error("vector length mismatch " + s) { }
	explicit vector_length_mismatch(const char* c) : logic_error(c) {}
};

class not_square_matrix : public std::logic_error
{
public:
	explicit not_square_matrix(const std::string& s) : logic_error("trying to add diagonal of a non square matrix " +s) { }
	explicit not_square_matrix(const char* c) : logic_error(c) {}
};

class matrix_size_mismatch : public std::logic_error
{
public:
	explicit matrix_size_mismatch(const std::string& s) : logic_error("matrix size mismatch "+s) { }
	explicit matrix_size_mismatch(const char* c) : logic_error(c) {}
};


#endif