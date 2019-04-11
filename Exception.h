/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Vecteur.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Classe gérant les exceptions

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

std::string makeMessage(std::string file, std::string function, int line) {

   std::string message = "error in " + file + " in function " +
           function + " at line " + std::to_string(line);
   return message;
}

class vecteur_index_error : public std::logic_error {
public:

   explicit vecteur_index_error(const std::string& s) :
   logic_error("VECTEUR : index error " + s) {
   }

   explicit vecteur_index_error(const char* c) : logic_error(c) {
   }
};

class vecteur_length_error : public std::logic_error {
public:

   explicit vecteur_length_error(const std::string& s) :
   logic_error("VECTEUR : length error " + s) {
   }

   explicit vecteur_length_error(const char* c) : logic_error(c) {
   }
};

class vector_length_mismatch : public std::logic_error {
public:

   explicit vector_length_mismatch(const std::string& s) :
   logic_error("VECTEUR : length mismatch " + s) {
   }

   explicit vector_length_mismatch(const char* c) : logic_error(c) {
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

class matrix_size_mismatch : public std::logic_error {
public:

   explicit matrix_size_mismatch(const std::string& s) :
   logic_error("MATRIX : matrix size mismatch " + s) {
   }

   explicit matrix_size_mismatch(const char* c) : logic_error(c) {
   }
};

class vecteur_range_error : public std::runtime_error {
public:

   explicit vecteur_range_error(const std::string& s) :
   runtime_error("VECTEUR : could not resize vecteur " + s) {
   }

   explicit vecteur_range_error(const char* c) : runtime_error(c) {
   }
};



#endif