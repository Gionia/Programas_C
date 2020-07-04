#ifndef _clase_H
#define _clase_H
#include <stdlib.h>
#include <iostream>
#include <string>
class Persona
{

    public:
        Persona( char*, int );
        void imprimirDatos();
    private:
        char* nombre;
        int edad;

};//fin de la clase persona

class Empleado: public Persona
{

    public:
        Empleado( char*, int, int, int );
        void imprimirEmpleado();
    private:
        int NumEmploy;
        int salary;

};//fin de la clase empleado

class alumno: public Persona
{

    public:
        alumno();
        void _alumno( int, char );
        void imprimeAlumno( char*, int, char, int );
    private:
        char* escuela;
        int matricula;

};//fin de la clase alumno

class universitario : public alumno
{

    private:
        int semestre;
        char carrera;
    public:
        universitario();
        void imprimirUniversitario( char *, int, char, int, int, char );

};//fin de la clase universitario


#endif // _clase_H


