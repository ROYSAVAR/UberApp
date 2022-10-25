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
/*
class Fecha //clase fecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:


        Fecha();
        Fecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        int getDias();
        string getFecha();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        void setFecha(int,int,int);
        void avanzarDia();
        ~Fecha();

        bool operator>(const Fecha & other){
            bool res=false;
            if(this->anio>other.anio){
                res=true;
                return res;
            }
            if(this->mes > other.mes  &&  this->anio > other.anio){
                res=true;
                return true;
            }
            if(this->dia > other.dia  &&  this->mes > other.mes &&  this->anio > other.anio){
                res=true;
                return res;
            }
            if(this->dia > other.dia  &&  this->mes <= other.mes &&  this->anio <= other.anio){
                res=true;
                return res;
            }
            return res;
        }

        bool operator<(const Fecha &other) const 
        {
             bool res=true;
            if(this->anio>other.anio){
                res=false;
                return res;
            }
            if(this->mes > other.mes  &&  this->anio > other.anio){
                res=false;
                return true;
            }
            if(this->dia > other.dia  &&  this->mes > other.mes &&  this->anio > other.anio){
                res=false;
                return res;
            }
            if(this->dia > other.dia  &&  this->mes <= other.mes &&  this->anio <= other.anio){
                res=false;
                return res;
            }
            return res;
        }
};

Fecha::Fecha(){}

Fecha::Fecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

int Fecha::getDias(){
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        return 31;
    }
    else if(mes==2){
            return 28;
        }
        else{
            return 30;
        }
}

string Fecha::getFecha(){
    string cad;
    cad=to_string(getDia())+("/")+to_string(getMes())+("/")+to_string(getAnio());
    return cad;
}

void Fecha::setDia(int dia){
    this->dia=dia;
}

void Fecha::setMes(int mes){
    this->mes=mes;
}

void Fecha::setAnio(int anio){
    this->anio=anio;
}

void Fecha::setFecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

void Fecha::avanzarDia(){
    if(dia==getDias() && mes!=12){
        mes++;
        dia=1;
    }
    else if(dia==getDias() && mes==12){
        mes=1;
        dia=1;
        anio++;
    }
    else{
        dia++;
    }
}

bool iguales(Fecha a,Fecha b){
    if(a.getDia()==b.getDia() && a.getMes()==b.getMes() && a.getAnio()==b.getAnio()){
        return true;
    }else{
        return false;
    }
}

int diasRestantes(Fecha a)
{
    time_t now=time(0);
    tm*tiempo=localtime(&now);
    int diahoy=tiempo->tm_mday;
    int meshoy=tiempo->tm_mon+1;
    int aniohoy=(tiempo->tm_year-100)+2000;


    Fecha hoy=Fecha(diahoy,meshoy,aniohoy);

    int contador=0;
    while(iguales(hoy,a)==false){
        hoy.avanzarDia();
        contador++;
    }
    //return to_string(contador);
    return contador;
}*/