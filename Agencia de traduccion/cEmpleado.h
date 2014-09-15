//
//  cEmpleado.h
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#ifndef Agencia_de_traduccion_cEmpleado_h
#define Agencia_de_traduccion_cEmpleado_h
#include <iostream>

using namespace std;

class cEmpleado{
    
protected:
    
    string nombre;              //Nombre del empleado
    int nIdiomas;               //Numero de idiomas que conoce
    string idiomas[5];          //Como maximo solo puede tener 5 idiomas.
    bool disponible;            //Indica si el empleado está disponible para trabajar.
    
public:
    
    virtual void mostrarEmpleados()=0;              //Muestra la informacion de los empleados, dependiendo de si son individuales o por equipo.

};

#endif
