#include<iostream>
#include<string>
using namespace std;

class publicacion{
    protected:
        string titulo;
        int anio;
    public:
        publicacion(string t,int a):titulo(t),anio(a){}
        virtual string obtenerreferencia()=0;
        virtual void mostrardatos()=0;
        virtual ~publicacion(){}
    };
class libro: public publicacion{
    private:
        string autor,editorial;
    public:
         libro(string t,int a,string au,string ed):publicacion(t,a),autor(au),editorial(ed){}
        string obtenerreferencia(){
           return autor+" - "+titulo+" - "+editorial+" - "+to_string(anio);
        }
        void mostrardatos(){
            cout<<"\nLIBRO\n";
            cout<<"Titulo: "<<titulo<<endl;
            cout<<"Autor: "<<autor<<endl;
            cout<<"Editorial: "<<editorial<<endl;
            cout<<"Anio: "<<anio<<endl;
            cout<<"Referencia: "<<obtenerreferencia()<<endl;
        }
};
class articulo:public publicacion{
    private:
        string nombrerevista,dio;
    public:
        articulo(string t,int a,string nr,string d):publicacion(t,a),nombrerevista(nr),dio(d){}
        string obtenerreferencia(){
            return titulo+" - "+nombrerevista+" - "+to_string(anio)+" - "+dio;    
        }
        void mostrardatos(){
            cout<<"\nARTICULO\n";
            cout<<"Titulo: "<<titulo<<endl;
            cout<<"Nombre Revista: "<<nombrerevista<<endl;
            cout<<"DIO: "<<dio<<endl;
            cout<<"Anio: "<<anio<<endl;
            cout<<"Referencia: "<<obtenerreferencia()<<endl;

        }
        
};

int main (){
    int n;
    cout<<"ingrese numero de publicaciones: ";cin>>n;
    publicacion* pub[n];
    for(int i=0;i<n;i++)    {   
        int tipo=0;
        cout<<" ingrese el tipo de publicacion\n 1. libro: \n2.articulo: \n";cin>>tipo;
        cin.ignore();
        string titulo;
        int anio;
        
        if(tipo==1){
            cout<<"\nINGRESE DATOS DEL LIBRO\n";
            string au,editorial;
            cin.ignore();
            cout<<"titulo:  ";
            cin>>titulo;
            cout<<"anio: ";
            cin>>anio;
            cout<<"autor: ";
            cin>>au;
            cout<<"editorial: ";
            cin>>editorial;
            pub[i]=new libro(titulo,anio,au,editorial);
            
        }
    }
}