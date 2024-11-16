#include <iostream>
using namespace std;
class Persona{
	protected:
	string nombre;
	string dni;
	int edad;
	public:
		//contructores
		Persona();
		Persona(string,string,int);
		//funciones
		void mostrarDatos();
};
Persona::Persona(){
	nombre=" ";
	dni=" ";
	edad=0;
}
Persona::Persona(string n,string d,int e){
	nombre=n;
	dni=d;
	edad=e;
}
void Persona::mostrarDatos(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Dni: "<<dni<<endl;
	cout<<"Edad: "<<edad<<endl;
}

class Estudiante : Persona{
	
	int nNotas;
	float notas[5];
	string codigo;
	public:
		Estudiante(string,string,int,float [],int,string);
		void mostrarEstudiante();
		void visualisarNotas();
		
};
Estudiante::Estudiante(string n,string d,int e, float nota[],int nN,string code):Persona(n,d, e){
	nNotas=nN;
	for(int i=0; i<nNotas;i++){
		notas[i]=nota[i];
	}
	codigo=code;
}
void Estudiante::mostrarEstudiante(){
	mostrarDatos();
	cout<<"Codigo: "<<codigo<<endl;
}
void Estudiante::visualisarNotas(){
	for(int i=0;i<nNotas;i++){
		cout<<"nota "<<i+1<<": "<<notas[i];
	}
}
class Docente:Persona{
	float sueldo;
	string especialidad;
	public:
		Docente(string n,string d,int e,float s,string esp);
		void mostrarDocente();
		//void ingresarNotas();
		//void visualizarRegistro();
};
Docente::Docente(string n,string d,int e,float s,string esp):Persona(n,d,e){
	sueldo=s;
	especialidad=esp;
}
void Docente::mostrarDocente(){
	mostrarDatos();
	cout<<"Sueldo: "<<sueldo<<endl;
	cout<<"Especialidad :"<<especialidad<<endl;
}

int main(){
	string nombre; 
	Persona p("Juan Perez", "40302010",25);
	p.mostrarDatos();
	cout<<endl;
	Docente d("Pablo Iglesias", "10203040", 54, 3000, "Auditoria informatica");
	d.mostrarDocente(); 
	cout<<endl; 
	float nota[] = {20, 19, 18}; 
	cout<<"Ingrese nombre de estudiante: ";
	fflush(stdin); getline(cin, nombre);
	Estudiante e(nombre, "90706050", 19, nota, 3, "2021-123");
	e.mostrarEstudiante(); 
	cout<<endl; 
	return 0;
	return 0;
}
