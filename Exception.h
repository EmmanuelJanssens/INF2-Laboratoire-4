/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Exception.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Classe gérant les exceptions

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

std::string makeMessage(std::string file, std::string function, int line) {

   std::string message = "error in " + file + " in function " +
           function + " at line " + std::to_string(line);
   return message;
}

class out_of_range : public std::logic_error {
public:

   explicit out_of_range(const std::string& s) :
   logic_error(" index error " + s) {
   }

   explicit out_of_range(const char* c) : logic_error(c) {
   }
};

class length_error : public std::logic_error {
public:

   explicit length_error(const std::string& s) :
   logic_error("length error " + s) {
   }

   explicit length_error(const char* c) : logic_error(c) {
   }
};


class not_square_matrix : public std::logic_error {
public:

   explicit not_square_matrix(const std::string& s) :
   logic_error("MATRIX : illegal operation on non square matrix " + s) {
   }

   explicit not_square_matrix(const char* c) : logic_error(c) {
   }
};


class range_error : public std::runtime_error {
public:

   explicit range_error(const std::string& s) :
   runtime_error("could not resize " + s) {
   }

   explicit range_error(const char* c) : runtime_error(c) {
   }
};



#endif