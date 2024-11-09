#include <iostream>

using namespace std;
class Vehiculo{
	protected:
		string placa;
		string marca;
		string color;
		float velocimetro;
	public:
		Vehiculo();
		Vehiculo(string p,string m, string c, float v);
	    void mostrarDatos();
		float cambiarVelocidad(float nv);
		
	
};

//CONSTRUCTORES
Vehiculo::Vehiculo(){
			placa="";
			marca="";
			color="";
			velocimetro=0;	
}
Vehiculo::Vehiculo(string p,string m, string c, float v){
			placa=p;
			marca=m;
			color=c;
			velocimetro=v;
}
void Vehiculo::mostrarDatos(){
	cout<<"Numero de Placa: "<<placa<<endl;
	cout<<"Marca: "<<marca<<endl;
	cout<<"Color: "<<color<<endl;
	cout<<"Velocimetro"<<velocimetro<<endl;
}
float Vehiculo::cambiarVelocidad(float nv){
	velocimetro=nv;
}
//CLASE AUTOMOVIL
class Automovil : public Vehiculo{
	private:
		int canPuertas;
		int canPasajeros;
		
	public:
		Automovil();
		Automovil(string,string,string,float,int , int );
		void mostrarAutomovil();
		int subirPasajeros(int);
		int bajarPasajeros(int);
		void cambiardatosAuto();
};
Automovil::Automovil(){
	canPuertas = 0;
	canPasajeros =0;
}
Automovil::Automovil(string p,string m, string c, float v, int np,int nps): Vehiculo(p,m,c,v){
	canPuertas = np;
	canPasajeros = nps;
}
void Automovil::mostrarAutomovil(){
	mostrarDatos();
	cout<<"Numero de Puertas: "<<canPuertas<<endl;
	cout<<"Numero de pasajeros: "<<canPasajeros<<endl;
	
}
int Automovil::subirPasajeros(int n){
	canPasajeros +=n;
	return canPasajeros;
}
int Automovil::bajarPasajeros(int m){
	canPasajeros -=m;
	return canPasajeros;
}
//CLASE CAMION
class Camion : public Vehiculo{
	private:
		float carga;
	public:
		Camion();
		Camion(string,string,string,float,float);
		void mostrarCamion();
		float cambiarCarga(float);
		
};
Camion::Camion(){
	carga=0.0;
}
Camion::Camion(string p,string m, string c, float v,float ca): Vehiculo(p,m,c,v){
	carga=ca;
}
void Camion :: mostrarCamion(){
	mostrarDatos();
	cout<<"Carga en Kg: "<<carga<<endl;
	
}
float Camion :: cambiarCarga(float n){
	carga=n;
	return carga;
}

void Automovil :: cambiardatosAuto(){
	cin.ignore();
	cout<<"Numero de Placa: ";getline(cin,placa);
	cout<<"Marca: ";getline(cin,marca);
	cout<<"Color: ";getline(cin,color);
	cout<<"Velocimetro";cin>>velocimetro;
	cout<<"cantidad de puertas:";cin>>canPuertas;
	cout<<"cantidad de pasajeros:";cin>>canPasajeros;
	
}
int main(){
	Camion cam();
	//Camion cam1("124-f58","Toyota","azul",120.5,180.5);
	Automovil autop();
	//Automovil auto2("154-y59","mazda","Verde",125.0,15,7);
	
	
	
	cout<<"Inicializar Datos de camion : \n";
	string p1,m1,c1;
	float v1;
	float carg;
	cin.ignore();
	cout<<"Numero de Placa: ";getline(cin,p1);
	cout<<"Marca: ";getline(cin,m1);
	cout<<"Color: ";getline(cin,c1);
	cout<<"Velocimetro";cin>>v1;
	cout<<"carga:";cin>>carg;
	
	Camion cam1(p1,m1,c1,v1,carg);
	//cam1.mostrarCamion();
	
	
	cout<<"Inicializar Datos de Auto:\n";
	string p,m,c;
	float v;
	int cp,cps;
	cin.ignore();
	cout<<"Numero de Placa: ";getline(cin,p);
	cout<<"Marca: ";getline(cin,m);
	cout<<"Color: ";getline(cin,c);
	cout<<"Velocimetro";cin>>v;
	cout<<"cantidad de puertas:";cin>>cp;
	cout<<"cantidad de pasajeros:";cin>>cps;
	Automovil auto1(p,m,c,v,cp,cps);
	int resp;
	do{
		cout<<"Programa de clases de herencia Vehiculos:\n\n";
		cout<<"opciones para vehiculo:\n";
		cout<<"1) cambiar datos(construir)\n";
		cout<<"2) mostrar datos de automovil\n";
		cout<<"3)subir pasajeros\n";
		cout<<"4)bajar pasajero\n";
		cout<<"Opciones para Camion:\n";
		cout<<"5)mostrar camion\n";
		cout<<"6)cambiar carga\n";
		cout<<"\n\n0)salir";
		cin>>resp;
		if(resp==1){
			auto1.cambiardatosAuto();
		}else if(resp==2){
			auto1.mostrarAutomovil();
		}else if(resp==3){
			int n;
			cout<<"Ingrese los pasajeros a subir: ";
			cin>>n;
			cout<<"Nueva cantidad de pasajeros : "<<auto1.subirPasajeros(n)<<endl;
			//system("pause");
		}else if(resp==4){
			int n;
			cout<<"Ingrese los pasajeros a bajar: ";
			cin>>n;
			cout<<"Nueva cantidad de pasajeros : "<<auto1.bajarPasajeros(n)<<endl;
			system("pause");
		}else if(resp==5){
			cam1.mostrarCamion();
		}else if(resp==6){
			int n;
			cout<<"ingrese la nueva carga:";cin>>n;
			cam1.cambiarCarga(n);
			
		}
		system("pause");
		system("cls");
	
	}while(resp!=0);
	
	return 0;
}
