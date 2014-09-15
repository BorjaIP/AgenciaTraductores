//
//  cServicio.h
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#ifndef Agencia_de_traduccion_cServicio_h
#define Agencia_de_traduccion_cServicio_h
#include "cEmpleado.h"
#include <iostream>

using namespace std;

class cServicio{
    
private:
    
    cEmpleado *empleado;   
    string idiomaOrigen;
    string idiomaDestino;
    string nombreServicio;
    
public:
    
    cServicio();
    cServicio(cEmpleado,string,string,string);
    string getNombre(){return nombreServicio;}      //Delvuelve el nombre sel servicio.
    void mostrarServicio();                         //Muestra la informacion sel servicio.
};

#endif
