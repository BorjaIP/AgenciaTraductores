//
//  cEmpleadoEquipo.cpp
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#include "cEmpleadoEquipo.h"

cEmpleadoEquipo::cEmpleadoEquipo(){
    numeroE=0;
    nombreServicio="";
    for (int i=0; i<3; i++) {
        empleados[i]=NULL;
    }
}

cEmpleadoEquipo::~cEmpleadoEquipo(){
    for (int i=0; i<3; i++) {
        delete empleados[i];
    }
}

cEmpleadoEquipo::cEmpleadoEquipo(cEmpleadoUnico emple[3],int n,string nom){
    
    nombreServicio=nom;
    numeroE=n;
    for (int i=0; i<numeroE; i++) {
        empleados[i]=&emple[i];
    }
}

void cEmpleadoEquipo::mostrarEmpleados(){
    for (int i=0; i<numeroE; i++) {
        empleados[i]->mostrarEmpleados();
    }
}

