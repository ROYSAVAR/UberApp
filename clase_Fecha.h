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

class Fecha
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

string diasRestantes(Fecha a){
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
    return to_string(contador);
}
string date(Fecha fecha)  //recive una fecha y la imprime
{
  string dia, num_dia, month, anio;
  
  string months[] = {"January","February","March","April","May","Jun","July","Agust","September","October","November","December"};
  vector<string> mes;

  for(int i=0; i<12; i++)
  {
    mes.push_back(months[i]);
  }

  num_dia = to_string(fecha.getDia()); 
  month = mes[fecha.getMes()-1];
  anio = to_string(fecha.getAnio());
  
  string final;

  final += num_dia;
  final += " "; 
  final += month;
  final += " ";
  final += anio; 
  
  return final;
}

string date_hour()//------fecha y hora actual del sistema ----------
{
  string dia, num_dia, month, anio, hora,min;
  time_t now = time(0);
  tm *time = localtime(&now);
  string days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};   
  vector<string> dia_semana;

  for(int i=0; i<7; i++)
  {
    dia_semana.push_back(days[i]);
  }
  
  string months[] = {"January","February","March","April","May","Jun","July","Agust","September","October","November","December"};
  vector<string> mes;

  for(int i=0; i<12; i++)
  {
    mes.push_back(months[i]);
  }

  int year = 1900 + time -> tm_year;
 
  dia = dia_semana[time->tm_wday];
  num_dia = to_string(time->tm_mday);
  month = mes[time->tm_mon];
  anio = to_string(year);
  hora = to_string(time->tm_hour);
  if(time->tm_min < 10)
  {
    string aux = to_string(time->tm_min) ;
    min += "0";
    min += aux;
  }
  else
  {
     min = to_string(time->tm_min) ;
  }

  string final;
  final += dia; 
  final += " ";
  final += num_dia;
  final += " "; 
  final += month;
  final += " ";
  final += anio; 
  final += "      Time:  ";     
  final += hora;
  final += ":"; 
  final += min;  

  return final;
}
Fecha::~Fecha(){}