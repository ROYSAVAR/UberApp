#include<iostream>
#include<cstdlib>
#include<fstream> 
#include<vector>
#include<string>
#include<map>
#include<set>
#include<ctime>
#include<windows.h>
#include<pthread.h>
using namespace  std;
    
//clase vehiculo-----------
class Vehiculo
{
    private:  
        string nombre;
        string marca;
    public:
        Vehiculo();
        Vehiculo(string,string);
        virtual string mostrar(); 
};

Vehiculo::Vehiculo(){}
Vehiculo::Vehiculo(string _nombre, string _marca){ nombre = _nombre; marca = _marca;}
string Vehiculo::mostrar()
{
  string aux;
  aux += nombre;
  aux += " ";
  aux += marca;
  return aux;
}

class automovil: public Vehiculo
{
    private:
        string color;
    public:
        automovil();
        automovil(string,string,string);
        string mostrar();
};

automovil::automovil(){}
automovil::automovil(string _nombre, string _marca, string _color): Vehiculo(_nombre,_marca){color = _color;}
string automovil::mostrar()
{
  string aux;
  aux += Vehiculo::mostrar();
  aux += " ";
  aux += color;
  return aux;
}

class moto: public Vehiculo
{
    private:
        int llantas;
    public:
        moto();
        moto(string,string,int);
        string mostrar();      
};

moto::moto(){}
moto::moto(string _nombre,string _marca, int _llantas): Vehiculo(_nombre,_marca){llantas = _llantas;} 
string moto::mostrar()
{
  string aux; string num;
  num = to_string(llantas);
  aux += Vehiculo::mostrar();
  aux += " ";
  aux += num;  //conv llantas a string
  return aux;
}

//elegir conductor

 
class Calificacion //calificar conductores
{
    int n_estrellas;
    string name;

    public: 
        Calificacion():n_estrellas(0),name("")  {} //inicializarlo vacío
        Calificacion(int n_estrellas, string name):n_estrellas(n_estrellas),name(name){}  //con esto ya no es necesario hacer los gets 
  
        void print() const
        {
            ofstream archivoEscr;
            archivoEscr.open("calificaciones.txt", ios :: out | ios::app);
            if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

            archivoEscr<<"Name: "<<name<<"\t  ------------->  Number of stars: "<<n_estrellas<<endl;
            archivoEscr.close();
        }
        bool operator<(const Calificacion &other) const  //esto es para que jale sets y maps con objetos, ya que usa < para comparar y ordenar
        {
            return n_estrellas < other.n_estrellas;
        }
};

