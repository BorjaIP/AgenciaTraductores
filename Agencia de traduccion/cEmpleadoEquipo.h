//
//  cEmpleadoEquipo.h
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#ifndef Agencia_de_traduccion_cEmpleadoEquipo_h
#define Agencia_de_traduccion_cEmpleadoEquipo_h
#include "cEmpleado.h"
#include "cEmpleadoUnico.h"

class cEmpleadoEquipo:public cEmpleado {
    
private:
    
    int numeroE;
    cEmpleadoUnico *empleados[3];
    string nombreServicio;
    
public:
    
    cEmpleadoEquipo();
    ~cEmpleadoEquipo();
    cEmpleadoEquipo(cEmpleadoUnico[],int,string);
    void mostrarEmpleados();
};


#endif
