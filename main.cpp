#include <iostream>
#include <list>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Declaracion de las estructuras
struct calificacionInfo{
    //Esta estructura nos permite capturar y mostrar calificaciones.
    private :
        float Cal1,Cal2,Cal3,Promedio;
    public :
        void CapturarCalificaciones();
        void MostrarCalificaciones();
};
struct alumnoInfo{
    //Esta estructura nos permite capturar y mostrar la informacion de un alumno.
    private :
       string Id;
       string Nombre;
       calificacionInfo Calificaciones;//Creamos un objeto de estrutura calificacionInfo.
    public :
       void CapturarAlumno();
       void MostraInfo();

};

typedef list<alumnoInfo> Lista;//Creamos una definicion para nuestra linked list
void menuPrincipal();

int main()
{
    //Lista que contendra la informacion de cada Alumno capturado.
    Lista salonDeAlumnos;
    int opcion = -1;

    //Mostrar el menu en pantalla hasta que seleccione la opcion salir.
    while(opcion != 3 ){

        system("cls");//Limpiamos pantalla
        menuPrincipal();//Mostrar menu principal
        cin>>opcion;

            if(opcion==1){ //Captura de alumnos
                system("cls");
                cout<<"\t\t** Captura de Alumnos **\n\n";
                alumnoInfo registroAlumno;//Creamos un nuevo objeto tipo alumnoInfo para agregar a la lista
                registroAlumno.CapturarAlumno();//Capturar alumno
                salonDeAlumnos.push_back(registroAlumno);//Agregar a la lista el regitro del alumno
                cout<<"\n\t[PRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU]\n";
                cin.ignore();
                getchar();
            }else if(opcion==2){//Mostrar lista de alumnos
                system("cls");
                cout<<"\t\t** Alumnos registrados **\n";
                cout<<"\n\n\tSe encuantran "<<salonDeAlumnos.size()<<" registrados.\n\n";

                if(salonDeAlumnos.size() > 0){//Mostrar la lista solo si hay alumnos agregados.

                    for(Lista::iterator iAlumno = salonDeAlumnos.begin();iAlumno!= salonDeAlumnos.end();iAlumno++ ){
                       cout<<"\n\n";
                       iAlumno->MostraInfo();
                       cout<<"\n=================================================";
                    }

                }
                cout<<"\n\t[PRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU]\n";
                cin.ignore();//Limpiamos el buffer de caracteres.
                getchar();

            }
            else if(opcion == 3){
                cout<<"\n\t\t[GRACIAS POR USAR EL SISTEMA]\n";

            }else{
            cout<<"\n\t\t[OPCION INVALIDA]\n";
            cin.ignore();
            getchar();
            }

    }

    return 0;
}

//Menu Principal
void menuPrincipal(){
    cout<<"\t\t.::Menu::.          "<<endl;
    cout<<"\t 1.-Captura de Alumnos"<<endl;
    cout<<"\t 2.-Mostrar Alumnos   "<<endl;
    cout<<"\t 3.-Salir             "<<endl;
    cout<<"Opcion:";
}
//Implementacion de las funciones de las estructuras
void calificacionInfo::CapturarCalificaciones(){

    cout<<"Calificacion Periodo #1:";
    cin>>Cal1;
    cout<<"Calificacion Periodo #2:";
    cin>>Cal2;
    cout<<"Calificacion Periodo #3:";
    cin>>Cal3;

    Promedio = ((Cal1+Cal2+Cal3)/3);

}
void calificacionInfo::MostrarCalificaciones(){

    cout<<"\tCalificaciones"<<endl;
    cout<<"\tPeriodo #1:"<<Cal1<<endl;
    cout<<"\tPeriodo #2:"<<Cal2<<endl;
    cout<<"\tPeriodo #3:"<<Cal3<<endl;
    cout<<"\t-----------------"<<endl;
    cout<<"\t  Promedio:"<<Promedio<<endl<<endl;

}

void alumnoInfo::CapturarAlumno(){

    cout<<"Nombre del Alumno:\n";
    cin.ignore();
    getline(cin,Nombre);
    cout<<"Id:";
    cin>>Id;
    Calificaciones.CapturarCalificaciones();

}
void alumnoInfo::MostraInfo(){

    cout<<"   Id#:"<<Id<<endl;
    cout<<"Alumno:"<<Nombre<<endl;
    Calificaciones.MostrarCalificaciones();

}
