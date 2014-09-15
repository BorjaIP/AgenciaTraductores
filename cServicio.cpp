//
//  cServicio.cpp
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#include "cServicio.h"

cServicio::cServicio(){
    empleado=NULL;
    idiomaDestino="";
    idiomaOrigen="";
    nombreServicio="";
}

cServicio::cServicio(cEmpleado emple,string nom,string idiO,string idiD){
    
    empleado=&emple;
    nombreServicio=nom;
    idiomaOrigen=idiO;
    idiomaDestino=idiD;
}

void cServicio::mostrarServicio(){
    cout<<endl<<"Nombre: "<<nombreServicio;
    cout<<endl<<"Idioma Origen: "<<idiomaOrigen;
    cout<<endl<<"Idioma Origen: "<<idiomaDestino;
    empleado->mostrarEmpleados();
}