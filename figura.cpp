#include<iostream>
#include<string>

using namespace std;

class Figura{

    protected:
        float area,perimetro;
    public:
     Figura():area(0.0f),perimetro(0.0f){}
     virtual void hallarperimetro()=0;
     virtual void hallararea()=0;
     virtual void mostrardatos()=0;
    
     void mostrarresultado(){
        cout<<"\narea :"<<area<<endl;
        cout<<"perimetro: "<<perimetro<<endl;
     }
     virtual ~Figura(){};

};
    
class triangulo:public Figura{
        private:
            float base,altura,lado1,lado2;

        public:
        triangulo(float b,float h,float l1,float l2) 
        : base(b),altura(h),lado1(l1),lado2(l2){}
            void hallarperimetro(){
                perimetro= lado1+lado2+base;
            }
            void hallararea(){
                area=(base*altura)/2;
            }
            void mostrardatos(){
                cout<<" triangulo:\n";
                cout<<"\n                \n";    
                cout<<"         **       \n";
                cout<<"        *  *      \n";
                cout<<"       *    *     \n";
                cout<<"      *      *    \n";
                cout<<"     **********   \n";

                cout<<"base: "<<base<<" - altura: "<<altura<<" - lado1: "<<lado1<<" - lado2: "<<lado2<<endl;
            }


};
class rectangulo: public Figura{

        private:
            float basr,alrec;
        
        public:

        rectangulo(float br,float ar)
        :basr(br),alrec(ar) {}
        void hallarperimetro(){
            perimetro=(2*basr)+(2*alrec);
        }
        void hallararea(){
            area=basr*alrec;
        }
        void mostrardatos(){
            cout<<" retangulo:\n";
                cout<<"\n***********************\n";
                cout<<"**                   **\n";
                cout<<"**                   **\n";
                cout<<"**                   **\n";
                cout<<"***********************\n";

                cout<<"base: "<<basr<<" - altura: "<<alrec;
        }

};

int main(){
    float base,altura,lado1,lado2,basr,alrec;

    int opcion;
    Figura* fig;
    
    cout<<"==========figuras=========\n";
    cout<<"1.triangulo: \n";
    cout<<"2.rectangulo: \n";
    cout<<"ingrese la opcion: ";cin>>opcion;

    switch(opcion){


        case 1:{
            cout<<"ingrese base: ";cin>>base;
            cout<<"ingrese altura: ";cin>>altura;
            cout<<"ingrese lado1: ";cin>>lado1;
            cout<<"ingrese lado2: ";cin>>lado2;
            fig=new triangulo(base,altura,lado1,lado2);
            fig->hallararea();
            fig->hallarperimetro();
            fig->mostrardatos();
            fig->mostrarresultado();
        
            
            delete fig;
                break;
        }
        case 2:{
            cout<<"ingrese base: ";cin>>basr;
            cout<<"ingrese altura: ";cin>>alrec;
            fig=new rectangulo(basr,alrec);
                 fig->hallararea();
                 fig->hallarperimetro();
                 fig->mostrardatos();
                 fig->mostrarresultado();

    delete fig;
           break;
        }
        default:
         cout<<"no hay figura\n";
         break;
    }

    return 0;
}