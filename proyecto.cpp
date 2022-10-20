#include"myLib.h"

using namespace std;
class Calificacion
{
    int n_estrellas;
    string name;

    public: 
        Calificacion():n_estrellas(0),name("")
        {

        }
        Calificacion(int n_estrellas, string name):n_estrellas(n_estrellas),name(name)  //con esto ya no es necesario hacer los gets 
        {

        }
  
        void print() const
        {
          
            ofstream archivoEscr;
            archivoEscr.open("calificaciones.txt", ios :: out | ios::app);
            if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

            archivoEscr<<"Name: "<<name<<"  ------------->  Number of stars: "<<n_estrellas<<endl;

            archivoEscr.close();
        }
        bool operator<(const Calificacion &other) const  //esto es para que jale sets y maps con objetos, ya que usa < para comparar
        {
            return name < other.name;
        }
};


string driver_name, car, destino; string text; int chofi, destin, carro; int precio_carro, precio_destino, precio_final;  //op 1 travel now
int num;  vector<int> propas;  int suma_Propinas =0;  //op4 propinas
set<Calificacion> calificacion; int stars=0; //op 4 calificar drivers
string color, nombre; int llantas;  string marca; //op 6  suggestions

int main()
{
  login();
    ofstream archivoEscr;
    ifstream archivoLec;
    
    cout<<"Welcome!"<<endl;
    int opcion;
    do
    {
      menu();
      cin>>opcion;
        switch (opcion)
        {
        case 1:  //viajar ahora     //ir guardando en historial
                
                archivoEscr.open("viajes_realizados.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

                //elegir destino 
                cout<<"\nChoose the destination: "; 
                archivoLec.open("Destinos.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available destinations: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                cin>>destin;
                destino = nombre_destino(destin);
                precio_destino = destino_precio(destin);

                //elegir conductor
                cout<<"\nChoose the driver: "; 
                archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available drivers: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                cin>>chofi;
                driver_name = nombre_conductor(chofi);

                //elegir carro
                cout<<"\nChoose the car : ";  
                archivoLec.open("Carros.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available cars: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                cin>>carro;
                car = nombre_vehiculo(carro);
                precio_carro = vehiculo_precio(carro);

                //imprimir en historial 
                precio_final = precio_carro + precio_destino;
                archivoEscr<<date_hour()<<endl;
                archivoEscr<<"Driver: "<<driver_name<<"    "<<"Car: "<<car<<"    "<<"Destination: "<<destino<<"    "<<"Total Price: "<<precio_final<<endl<<endl;
                archivoEscr.close();
                cout<<"Trip created, wait for your uber at the point where you are right now.\n\n";
                break;
        case 2:
                archivoLec.open("viajes_realizados.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Previous trips: \n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close();
          break;
        case 3: //reserve a future trip

               
                cout<<"Booked trip, be aware of the date the uber will pick you up.\n\n";
                
          break;
        case 4: //leave xtra tips and calificate drivers

                cout<<"Choose the driver you want to rate: "; 

                archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available drivers: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                cin>>chofi;
                driver_name = nombre_conductor(chofi);

                cout<<"Type the number of stars: (1-5): "; cin>>stars;
                calificacion.insert(Calificacion(stars,driver_name));

                for(set<Calificacion>::iterator it = calificacion.begin(); it != calificacion.end(); it++)  //solo imprimir
                {
                 it-> print();
                }
              
          break;

        case 5: //show info drivers and cars 
           archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
           if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Drivers: \n\n";
           while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
           archivoLec.close();

           archivoLec.open("Carros.txt", ios::in);  //abrir archivo en modo lectura
           if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"\nAvailable Cars: \n\n";
           while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
           archivoLec.close(); 
          break;

        case 6: //sugerir añadir nuevos vehiculos
          cout<<"Propose to add new vehicles"<<endl; cout<<"If you want to suggest a car, press 1, if is a motorbike, press 2"<<endl;
          
          int n; cin>>n;   
          Vehiculo *vector[3];

          archivoEscr.open("sugeridos.txt", ios :: out | ios::app);
          if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}
          
          switch (n)
          {
                case 1:
                  cout<<"Suggest the car"<<endl;
                  cout<<"Type vehicle name: "; cin>>nombre;  cout<<"\nType vehicle brand: "; cin>>marca;   cout<<"\nType the color: "; cin>>color;
                  vector[0] = new automovil(nombre,marca,color);
                  archivoEscr<<"Vehicle information: (color, name, model): "<<vector[0]->mostrar(); archivoEscr<<endl;
                break;
                case 2:
                  cout<<"Suggest the motorbike"<<endl;
                  cout<<"Type vehicle name: "; cin>>nombre;  cout<<"\nType vehicle brand: "; cin>>marca;   cout<<"\nType the number of tires: "; cin>>llantas;
                  vector[1] = new moto(nombre,marca,llantas);
                  archivoEscr<<"Vehicle information: (color, name, number of tires): "<<vector[1]->mostrar();  archivoEscr<<endl;
                break;
                default: 
                  cout<<"Please enter a correct option "<<endl;
                break;
          }          
                archivoEscr.close();
                cout<<"Request made, thanks.\n";      
                  
          break; 

        case 7: //mostrar carros sugeridos
          archivoLec.open("sugeridos.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Suggested cars: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close();
          break;
        case 8: //salir 
        cout<<"Closing App, Bye."<<endl;
          break;          
        
        default: cout<<"Please enter a correct option"<<endl;
          break;
        }
    } while (opcion!=8);
    
  return 0;
}