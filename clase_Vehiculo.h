#include<iostream>
#include<cstdlib>
#include<string>

using namespace  std;
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
