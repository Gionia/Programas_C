#include <iostream>
#include "Persona.h"

using namespace std;

Persona::Persona( char _nombre[25], int _edad ){

    int  i = 0;

    while( _nombre[i] != '\0' ){
        nombre[i] = _nombre[i];
        i+=1;
    }

    nombre[i] = '\0';
    edad = _edad;

}//fin de setter de Persona

void Persona::imprimirDatos(){

    cout<<"El nombre es: "<<puts( nombre )<<endl;
    cout<<"La edad es: "<<edad<<endl;

}//fin de imprime datos

Empleado::Empleado( char _nombre[], int _edad, int _NumEmploy, int _salary ): Persona( _nombre, _edad ){

    NumEmploy = _NumEmploy;
    salary = _salary;

}

void Empleado::imprimirEmpleado(){

    imprimirDatos();
    cout<<"El numero de empleado es: "<<NumEmploy<<endl;
    cout<<"El salario es: "<<salary<<endl;

}


int main()
{
    Empleado empleado1("Armando",33, 334, 12 );

    empleado1.imprimirEmpleado();

    return 0;
}
