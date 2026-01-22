#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class alumno{
    private:
        int codigo;
        char nombre[50];
        float promedio;
    public:
        alumno():codigo(0),promedio(0.0f){
              nombre[0]='\0';
        }
        void setDatos(int c,const char* n,float p){
            codigo=c;
            strcpy(nombre,n);
            promedio=p;
          }

        int getcodigo(){
            return codigo;
        }
        void mostrar(){
            cout<<"-> datos del alumno\n";
            cout<<"--------------------------\n";
            cout<<"codigo: "<<codigo<<endl;
            cout<<"nombre: "<<nombre<<endl;
              cout<<"promedio: "<<promedio<<endl;
        }
};


int main(){

    int opcion;
    cout<<"menu de opciones\n";
    cout<<"1. registrar alumno\n";
    cout<<"2. mostrar alumno\n";
    cout<<"3. buscar alumno\n";
    cout<<"4. salir\n";
    cout<<"ingrese una opcion: ";cin>>opcion;

     switch (opcion){
        case 1:{ 
            ofstream archivo("alumno.dat",ios::app | ios:: binary);
            if(!archivo){
                cout<<"error al abrir el archivo";
                break;
            }
            int codigo;
            char nombre[50];
            float promedio;
            cout<<"ingrese codigo: ";cin>>codigo;
            cin.ignore();
            cout<<"ingrese nombre: ";cin.getline(nombre,50);
            cout<<"ingrese promedio: ";cin>>promedio;

            alumno a;
            a.setDatos(codigo,nombre,promedio);
            archivo.write((char*)&a,sizeof(alumno));
            archivo.close();
            cout<<"alumno registrado correctamente\n";
            break;
        }
        case 2:
        {
            ifstream archivo("alumno.dat",ios::binary);
            if(!archivo){
                cout<<"error al abrir el archivo";
                break;
            }
            alumno a;
            cout<<"\n====LISTADO DE ALUMNOS=====\n";
            while(archivo.read((char*)&a,sizeof(alumno))){
                a.mostrar();
                 }
                cout<<"--------------------------\n";

                archivo.close();
            break;

            }
        case 3:{
            ifstream archivo("alumno.dat",ios::binary);

            if(!archivo){
                cout<<"error al abrir el archivo";
                break;

            }

            int codigobuscar;
            bool encontrado=false;
             alumno a;
            cout<<"ingrese el codigo del alumno a buscar: ";cin>>codigobuscar;
           while(archivo.read((char*)&a,sizeof(alumno))){
              if(a.getcodigo()==codigobuscar){
                cout<<"\nalumno encontrado\n";
                a.mostrar();
                encontrado=true;
                break;

              }
           }
           if(!encontrado){
            cout<<"alumno no encontrado\n";
           }
           archivo.close();
              break;


        }
        case 0:{
            cout<<"saliendo del programa...\n";
            break;
        }
        default:{
            cout<<"opcion no valida\n";
            break;
        }
             }
             return 0;
}
