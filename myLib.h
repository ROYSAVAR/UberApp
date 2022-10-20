#include<iostream>
#include<cstdlib>
#include<fstream> 
#include<vector>
#include<string>
#include<map>
#include<set>
#include<ctime>
#include<thread>

using namespace  std;
    
void menu()
{
    cout<<"\nChoose an option:\n";
    cout<<"1. Travel now. \n2. Show previous trips.\n3. Reserve a future trip.\n4. Leave an extra tip to the drivers.\n5. Show drivers' information and cars information.\n6. Suggest adding new cars.\n7. Show suggested cars.\n8. Exit.\n\n ";
}

void login()
{
  int cont = 0;
  string usuario = "Passenger1"; string contrasena = "password123"; string usuarioMetido, contraMetida;
  cout<<"\n------------------Login---------------------------------------------------------------------"<<endl<<"Enter username and password"<<endl; 

    do //LOGIN
    {
       cout<<"USSERNAME: "; cin>>usuarioMetido; cout<<"PASSWORD:  "; cin>>contraMetida; 

       if(cont == 3) //si se intenta mas de 3 veces terminar el programa 
       {
        cout<<"Too many trys, temporaly bloked."<<endl;
        exit(-1);  //salir de todo el programa
       } 

       if(contraMetida!=contrasena || usuario != usuarioMetido) // si ususario o contra estan mal, volver a intentar
       {
       cout<<"Ussername or password are wrong, please try again."<<endl;
       }
       cont++;
    } while (contraMetida!=contrasena || usuario != usuarioMetido);
}


//---------fecha y hora del sistema----------
string date_hour()
{
  string dia, num_dia, month, anio, hora,min;
  time_t now = time(0);
  tm *time = localtime(&now);
   
  vector<string> dia_semana;
  dia_semana.push_back("Sunday");
  dia_semana.push_back("Monday");
  dia_semana.push_back("Tuesday");
  dia_semana.push_back("Wednesday");
  dia_semana.push_back("Thursday");
  dia_semana.push_back("Friday");
  dia_semana.push_back("Saturday");
  
  vector<string> mes;
  mes.push_back("January");
  mes.push_back("February");
  mes.push_back("March");
  mes.push_back("April");
  mes.push_back("May");
  mes.push_back("Jun");
  mes.push_back("July");
  mes.push_back("Agust");
  mes.push_back("September");
  mes.push_back("October");
  mes.push_back("November");
  mes.push_back("December");

  int year = 1900 + time -> tm_year;
 
  dia = dia_semana[time->tm_wday];
  num_dia = to_string(time->tm_mday); //convertir int a string
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

string nombre_conductor(int chofi)
{
                string driver_name;
                if(chofi == 1){driver_name = "Ricardo Espinoza";}
                if(chofi == 2){driver_name = "Ivan Galban";}
                if(chofi == 3){driver_name = "Angel Alcantara";}
                if(chofi == 4){driver_name = "Caleb Flores";}
                if(chofi == 5){driver_name = "Maria Rodriguez";}
                if(chofi == 6){driver_name = "Ana Martinez ";}
                if(chofi == 7){driver_name = "Juan Hernandez";}

  return driver_name;
}

string nombre_vehiculo(int carro)
{
                string car;
                if(carro == 1){car = "VolksWagen Sedan";}
                if(carro == 2){car = "Nissan Sentra"; }
                if(carro == 3){car = "VolksWagen Vento";}
                if(carro == 4){car = "Nissan March"; }
                if(carro == 5){car = "Nissan Frontier";}
                if(carro == 6){car = "VolksWagen Chevy";}
                if(carro == 7){car = "Lamborhini Veneno";}
                if(carro == 8){car = "Camaro ZL1"; }
                if(carro == 9){car = "Audi A200"; }
  return car;
}

int vehiculo_precio(int carro)
{
                int precio_carro;
                if(carro == 1){precio_carro = 1000;}
                if(carro == 2){precio_carro = 1500;}
                if(carro == 3){precio_carro = 1500;}
                if(carro == 4){precio_carro = 1250;}
                if(carro == 5){precio_carro = 1900;}
                if(carro == 6){precio_carro = 1100;}
                if(carro == 7){precio_carro = 3500;}
                if(carro == 8){precio_carro = 4500;}
                if(carro == 9){precio_carro = 4150;}
  return precio_carro;
}

string nombre_destino(int dest)
{
  string destino;
                if(dest == 1){destino = "Colima"; }
                if(dest == 2){destino = "Quintana Roo"; }
                if(dest == 3){destino = "Guadalajara"; }
                if(dest == 4){destino = "Zacatecas";}
                if(dest == 5){destino = "Monterrey"; }
                if(dest == 6){destino = "Chihuahua"; }
                if(dest == 7){destino = "Veracruz";  }
                if(dest == 8){destino = "CDMX";  }
                if(dest == 9){destino = "Durango";  }
                if(dest ==10){destino = "Sinaloa"; }
  return destino;
}

int destino_precio(int dest)
{
  int precio_destino;
                if(dest == 1){precio_destino = 850;}
                if(dest == 2){precio_destino = 1600;}
                if(dest == 3){precio_destino = 450;}
                if(dest == 4){precio_destino = 250;}
                if(dest == 5){precio_destino = 650;}
                if(dest == 6){precio_destino = 850;}
                if(dest == 7){precio_destino = 1050;}
                if(dest == 8){precio_destino = 900;}
                if(dest == 9){precio_destino = 650;}
                if(dest ==10){ precio_destino = 850;}
  return precio_destino;
}