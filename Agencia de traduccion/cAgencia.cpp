//
//  cAgencia.cpp
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#include "cAgencia.h"

cAgencia::cAgencia(){
    nEmpleados = 0;
    nServicios = 0;
    for (int i=0; i<100; i++) {
        empleados[i]=NULL;
    }
    for (int i=0; i<10; i++) {
        servicios[i]=NULL;
    }
    importarFichero();
}

cAgencia::~cAgencia(){
    
    for (int i=0; i<nEmpleados; i++) {
        delete empleados[i];
    }
    for (int i=0; i<nServicios; i++) {
        delete servicios[i];
    }
}

void cAgencia::importarFichero(){
    
    fstream fich;
    string nombre,idiomas[5];
    int nIdiomas;
    int i=0,j=0;
    
    fich.open("Empleados.txt");
    if (!fich) {
        cout<<endl<<"Error en la apertura del fichero."<<endl;
    }
    else
    {
        fich>>nEmpleados;
        while (i<nEmpleados){
            fich>>nombre>>nIdiomas;
            if (nIdiomas!=0) {
                while (j<nIdiomas) {
                    fich>>idiomas[j];
                    j++;
                }
                j=0;
            }
            empleados[i]= new cEmpleadoUnico(nombre,nIdiomas,idiomas);
            i++;
        }
    }
    fich.close();
}

void cAgencia::menu(){
    
    int opcion;
    bool finalizar=false;
    
    do {
        
        cout<<endl<<"******* BIENVENIDO A LA AGENCIA DE TRADUCTORES *******";
        cout<<endl<<"************ ¿Que accion desea realizar? *************";
        cout<<endl<<"************ 1 - Contratar servicio ******************";
        cout<<endl<<"************ 2 - Rescindir servivo *******************";
        cout<<endl<<"************ 3 - Visualizar los servicios actuales ***";
        cout<<endl<<"************ 4 - Contratar empleado ******************";
        cout<<endl<<"************ 5 - Despedir empleado *******************";
        cout<<endl<<"************ 6 - Mostrar empleado ********************";
        cout<<endl<<"************ 7 - Visualizar empleados ****************";
        cout<<endl<<"************ 8 - Salir *******************************"<<endl;
        cin>>opcion;
    
        switch (opcion) {
            case 1:
                contratarServicio();
                getchar();
                getchar();
                break;
            case 2:
                rescindirServicio();
                getchar();
                getchar();
                break;
            case 3:
                visualizarServicios();
                getchar();
                getchar();
                break;
            case 4:
                contratarEmpleado();
                getchar();
                getchar();
                break;
            case 5:
                despedirEmpleado();
                getchar();
                getchar();
                break;
            case 6:
                mostrarEmpleado();
                getchar();
                getchar();
                break;
            case 7:
                listaEmpleados();
                getchar();
                getchar();
                break;
            case 8:
                cout<<"Gracias por utilizar esta agencia de traduccion."<<endl;
                finalizar=true;
                break;

            default:
                cout<<"El numero introducido no es una opcion, vuelva a introducir un numero."<<endl;
                break;
        }
    } while (!finalizar);
    
    cout<<endl<<"¡¡¡Gracias por utilizar nuestra agencia de traductores!!!"<<endl;
    
}

void cAgencia::contratarServicio(){
    
    cEmpleadoUnico Equipo[3];
    cEmpleado *empleadoEquipo;
    string idiomaOrigen,idiomaDestino,nom;
    bool encontrado=false;
    int posicion = 0;
    
    if (nServicios<10) {
        
        cout<<endl<<"Introduzca el idioma origen: "<<endl;
        cin>>idiomaOrigen;
        cout<<endl<<"Introduzca el idioma final: "<<endl;
        cin>>idiomaDestino;
        
        //Buscamos en los empleados, si alguno tiene el idioma origen y destino a la vez.
        for (int i=0; (i<nEmpleados)&&(!encontrado); i++) {
            if ((empleados[i]->buscarIdioma(idiomaOrigen)) && (empleados[i]->buscarIdioma(idiomaDestino))) {
                encontrado=true;
                posicion=i;
            }
        }
        if (encontrado) {
            empleados[posicion]->setDisponible(false);
            cout<<endl<<"Se ha encontrado un empleado para el servicio."<<endl;
            cout<<"Introduzca el nombre del servicio: "<<endl;
            cin>>nom;
            servicios[nServicios]=new cServicio(*empleados[posicion],nom,idiomaOrigen,idiomaDestino);
            nServicios++;
        }
        //Si no se encuentra un traductor que pueda hacer todo.
        else
        {
            bool encontrado1=false;
            bool encontrado2=false;
            int posicion1 = 0,posicion2 = 0;
            //Buscamos un empleado que tenga el idiomaOrigen.
            for (int i=0; (i<nEmpleados)&&(!encontrado); i++) {
                if ((empleados[i]->buscarIdioma(idiomaOrigen)) && empleados[i]->getDisponible()) {
                    posicion1=i;
                    empleados[i]->setDisponible(false);
                    Equipo[0]=(*empleados[i]);
                    encontrado1=true;
                }
            }
            //Buscamos un empleado que tenga el idiomaDestino.
            for (int i=0; (i<nEmpleados)&&(!encontrado); i++) {
                if ((empleados[i]->buscarIdioma(idiomaDestino)) && empleados[i]->getDisponible()) {
                    posicion2=i;
                    empleados[i]->setDisponible(false);
                    Equipo[1]=(*empleados[i]);
                    encontrado2=true;
                }
            }
            if ((encontrado1)&&(encontrado2)) {
                bool idiomaComun=false;
                //Comprobamos si tienen entre los dos empleados un idioma en comun.
                for (int i=0; (i<Equipo[0].getnIdiomas())&&(!idiomaComun); i++) {
                    if (Equipo[1].buscarIdioma(Equipo[0].getidiomas(i))) {
                        idiomaComun=true;
                    }
                }
                if (idiomaComun) {
                    cout<<endl<<"Se han encontrado dos empleados para el servicio."<<endl;
                    cout<<"Introduzca el nombre del servicio: "<<endl;
                    cin>>nom;
                    empleadoEquipo=new cEmpleadoEquipo(Equipo,2,nom);
                    servicios[nServicios]=new cServicio(*empleadoEquipo,nom,idiomaOrigen,idiomaDestino);
                    nServicios++;
                }
                //Si no tienen el idioma en comun.
                else
                {
                    encontrado=false;
                    string idioma1,idioma2;
                    //Vamos a recorrer los idiomas del primer miembro del equipo.
                    for (int i=0; (i<Equipo[0].getnIdiomas()&&(!encontrado)); i++) {
                        //Guardamos cada idioma en una variable para luego buscar.
                        idioma1=Equipo[0].getidiomas(i);
                        //Buscamos que empleados tienen el idioma en comun.
                        for (int j=0; ((j<nEmpleados)&&(!encontrado)); j++) {
                            //si encuentra un empleado con un idioma en comun.
                            if (empleados[j]->buscarIdioma(idioma1)) {
                                //Buscamos si el empleado tiene en comun un idioma con el segundo.
                                for (int k=0; ((k<Equipo[1].getnIdiomas())&&(!encontrado)); k++) {
                                    //Guardamos cada idioma del segundo en una variable para luego buscar.
                                    idioma2=Equipo[1].getidiomas(k);
                                    //Miramos si entre los empleados alguno tiene el segundo idioma y esta disponible.
                                    if (empleados[j]->buscarIdioma(idioma2)&&empleados[j]->getDisponible()) {
                                        encontrado=true;
                                        empleados[j]->setDisponible(false);
                                        Equipo[2]=(*empleados[j]);
                                    }
                                }
                            }
                        }
                    }
                }
                if (encontrado) {
                    cout<<endl<<"Se han encontrado tres empleados para el servicio."<<endl;
                    cout<<"Introduzca el nombre del servicio: "<<endl;
                    cin>>nom;
                    empleadoEquipo=new cEmpleadoEquipo(Equipo,3,nom);
                    servicios[nServicios]=new cServicio(*empleadoEquipo,nom,idiomaOrigen,idiomaDestino);
                    nServicios++;
                }
                //Si no se encuentra un tercero, el servicio no se puede realizar.
                else
                {
                    //Volvemos a poner a todos los empleados a disponibles.
                    empleados[posicion1]->setDisponible(true);
                    empleados[posicion2]->setDisponible(true);
                    cout<<endl<<"No se puede realizar el servicio."<<endl;
                }
            }
            else
            {
                //Volvemos a poner a todos los empleados a disponibles.
                empleados[posicion1]->setDisponible(true);
                empleados[posicion2]->setDisponible(true);
                cout<<endl<<"No se puede realizar el servicio."<<endl;
            }
        }
    }
}

void cAgencia::rescindirServicio(){
    
    bool encontrado=false;
    int i=0;
    string nombre;
    
    cout<<endl<<"Primero le mostramos un listado de los servicios:"<<endl;
    for (int j=0; j<nEmpleados; j++) {
        cout<<endl<<"Nombre: "<<servicios[i]->getNombre();
    }
    cout<<endl<<"Escriba el nombre del servicio que quiere rescindir: ";
    cin>>nombre;
    
    while ((!encontrado) && (i<nEmpleados)) {
        if (nombre == servicios[i]->getNombre()) {
            encontrado=true;
            for (int j=0; j<nServicios; j++) {
                servicios[j]=servicios[j+1];
            }
            nServicios--;
        }
        else
            cout<<endl<<"El nombre del servicio que ha introducido no es correcto";
        i++;
        cout<<endl<<"Se ha recindido el servicio "<<servicios[i]->getNombre();
    }
}

void cAgencia::visualizarServicios(){
    
    if (nServicios!=0) {
        for (int i=0; i<nServicios; i++) {
            servicios[i]->mostrarServicio();
        }
    }
    else
        cout<<endl<<"No hay servicios para mostrar."<<endl;
    
}

void cAgencia::contratarEmpleado(){
    
    string nombre,idiomas[5];
    int nIdiomas;
    int i=0;
    
    if (nEmpleados<100) {
        cout<<"Escriba su nombre: ";
        cin>>nombre;
        cout<<"Escriba el numero de idiomas: ";
        cin>>nIdiomas;
        if (nIdiomas!=0) {
            do {
                cout<<"Escriba el idioma (max 5): ";
                cin>>idiomas[i];
                i++;
            }while (i<nIdiomas);
        }
        empleados[nEmpleados] = new cEmpleadoUnico(nombre,nIdiomas,idiomas);
        nEmpleados++;
        cout<<endl<<"Has contratado a "<<nombre<<".";
    }
    else
        cout<<endl<<"No se pueden contratar mas empleados."<<endl;
}

void cAgencia::despedirEmpleado(){
    
    bool encontrado=false;
    int i=0;
    string nombre;
    
    cout<<endl<<"Primero le mostramos un listado de los empleados:"<<endl;
    for (int j=0; j<nEmpleados; j++) {
        cout<<endl<<"Nombre: "<<empleados[j]->getNombre();
    }
    cout<<endl<<"Escriba el nombre del empleado que quiere despedir: ";
    cin>>nombre;
    
    while ((!encontrado) && (i<nEmpleados)) {
        if (nombre == empleados[i]->getNombre()) {
            encontrado=true;
            delete empleados[i];
            for (int k=i; k<nEmpleados-1; k++) {
                empleados[k]=empleados[k+1];
            }
            nEmpleados--;
        }
        i++;
    }
    if (encontrado) {
        cout<<endl<<"El empleado "<<empleados[i]->getNombre()<<" ha sido despedido.";
    }
    else
        cout<<endl<<"El nombre del trabajador que ha introducido no es correcto";
}

void cAgencia::mostrarEmpleado(){
    
	int i=0;
    string nom;
	bool encontrado=false;
    
    cout<<endl<<"Indique el nombre del empleado que quiere mostrar: ";
    cin>>nom;
    
    while((i<nEmpleados) && (!encontrado)){
        if(empleados[i]->getNombre()==nom){
            encontrado=true;
            empleados[i]->mostrarEmpleados();
        }
		i++;
    }
    if(!encontrado)
        cout<<endl<<"No se ha encontrado ningun empleado con ese nombre."<<endl;
}

void cAgencia::listaEmpleados(){
    
    if (nEmpleados!=0) {
        for (int i=0; i<nEmpleados; i++) {
            empleados[i]->mostrarEmpleados();
        }
    }
    else
        cout<<endl<<"No hay empleados para mostrar"<<endl;
}

