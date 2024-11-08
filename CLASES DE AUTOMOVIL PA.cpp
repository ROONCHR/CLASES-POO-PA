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
	canPasajeros +=m;
	return canPasajeros;
}

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


int main(){
	Camion cam();
	Camion cam1("124-f58","Toyota","azul",120.5,180.5);
	Automovil autop();
	Automovil auto1("154-y59","mazda","Verde",125.0,15,7);
	
	auto1.mostrarAutomovil();
	cam1.mostrarCamion();
	
	return 0;
}
