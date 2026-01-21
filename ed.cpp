#include<iostream>
#include<string>

using namespace std;

class fecha{
    private:
        int dias,mes,anio;
    public:
        fecha(int d, int m, int a):dias(d),mes(m),anio(a){}
        void mostrarfecha(){
            cout<<dias<<"/"<<mes<<"/"<<anio;
        }
};
class Hora{
    private:
        int hora,minuto;
    public:
        Hora(int h,int min):hora(h),minuto(min){}
        void mostrarhora(){
        
            cout<<"    tiempo: "<<hora<<":"<<minuto<<endl; 
        }
        
};
class examen{
    private:
        string nombreasignatura,ciclo,tipo;
        fecha fecha;
        Hora hora;
    public:
        examen(string asig,string c,string t,int d,int m,int a,int h,int min)
        :nombreasignatura(asig),ciclo(c),tipo(t),fecha(d,m,a),hora(h,min){}
        void mostrarinformacion(){
            
            cout<<"tipo: "<<tipo<<endl;
            cout<<"asigantura: "<<nombreasignatura<<endl;
            cout<<"ciclo: "<<ciclo<<endl;
            cout<<" fecha:";fecha.mostrarfecha();
            hora.mostrarhora();
            
    }
};

int main(){
    string tipo,curso,ciclo;
    int d,m,a,h,min;
    int n;

cout<<"ingrese la cantidad de examenes a  registrar: ";cin>>n;
cin.ignore();
  examen* ex[n];
    
    for(int i=0;i<n;i++){
        cout<<"registro tipo de examen\n1.parcial\n2.practico\n3.sustitutorio"; 
        cout<<"\n escriba el tipo de examen: ";getline(cin,tipo);
     
    system("cls");
        if(tipo=="parcial" ){
           
            cout<<"\n======examen asigantura:=========\n ";
            cout<<"\nPARCIAL\n";
             
             cout<<"nombre de la asignatura: ";getline(cin,curso);
                cout<<"ciclo: ";getline(cin,ciclo);
                cout<<"fecha del examen dia: ";cin>>d;
                cout<<"mes: ";cin>>m;
                cout<<"anio: ";cin>>a;
                cout<<"hora del examen: ";cin>>h;
                cout<<"minuto: ";cin>>min;
                cin.ignore();
                ex[i]=new examen(curso,ciclo,tipo,d,m,a,h,min);
             }
        else if(tipo=="practico"){
             cout<<"\n======examen asigantura:=========\n ";
               cout<<"\nPRACTICO\n";
               cout<<"nombre de la asignatura: ";getline(cin,curso);
                cout<<"ciclo: ";getline(cin,ciclo);
                cout<<"fecha del examen dia: ";cin>>d;
                cout<<"mes: ";cin>>m;
                cout<<"anio: ";cin>>a;
                cout<<"hora del examen: ";cin>>h;
                cout<<"minuto: ";cin>>min;
                cin.ignore();
                ex[i]=new examen(curso,ciclo,tipo,d,m,a,h,min);
            }
        else if(tipo=="sustitutorio"){
             cout<<"\n======examen asigantura:=========\n ";
               cout<<"\nsustitutorio\n";
               cout<<"nombre de la asignatura: ";getline(cin,curso);
                cout<<"ciclo: ";getline(cin,ciclo);
                cout<<"fecha del examen dia: ";cin>>d;
                cout<<"mes: ";cin>>m;
                cout<<"anio: ";cin>>a;
                cout<<"hora del examen: ";cin>>h;
                cout<<"minuto: ";cin>>min;
                cin.ignore();
                ex[i]=new examen(curso,ciclo,tipo,d,m,a,h,min);
            }
      }
    system("cls");
     for(int i=0;i<n;i++){
        cout<<"\n==========datos del examen "<<i+1<<"=============\n";
        ex[i]->mostrarinformacion();
     }
 

    
    return 0;
 }