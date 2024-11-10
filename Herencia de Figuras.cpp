#include <iostream>

using namespace std;
class Figura{
	protected:
		string color;
	public:
		Figura();
		Figura(string);
};
Figura::Figura(){
	color=" ";
}
Figura::Figura(string c){
	color=c;
}
//CLASE TRIANGULO
class Triangulo: public Figura{
	private:
		float base;
		float altura;
		string tipo;
	public:
		Triangulo();
		Triangulo(string,float,float,string);
		float calcularArea();
		
};
Triangulo::Triangulo(){
	base=0;
	altura=0;
	tipo=" ";
	
}
Triangulo::Triangulo(string c,float b,float a, string t):Figura(c){
	base=b;
	altura=a;
	tipo=t;
}
float Triangulo::calcularArea(){
	return (base*altura)/2;
} 
//CLASE RECTANGULO
class Rectangulo: public Figura{
	private:
		float base;
		float altura;
	public:
		Rectangulo();
		Rectangulo(string,float,float);
		float calcularArea();
};
Rectangulo::Rectangulo(){
	base=0;
	altura=0;
	
}
Rectangulo::Rectangulo(string c,float b, float a):Figura(c){
	altura=a;
	base=b;
}
float Rectangulo::calcularArea(){
	return base*altura;
}
//CLASE CIRCULO
class Circulo: public Figura{
	private:
		float radio;
	public:
		Circulo();
		Circulo(string,float);
		float calcularArea();
		float calcularPerimetro();
};
Circulo::Circulo(){
	radio=0;
	
}
Circulo::Circulo(string c,float r):Figura(c){
	radio=r;
}
float Circulo::calcularArea(){
	return 3.14*radio*radio;
}
float Circulo::calcularPerimetro(){
	return 3.14*2*radio;
}

int main(){
	int resp;
	cout<<"\nInicializar triangulo(constructor)\n";
	float b,a;
	string c,t;
	cout<<"base: ";cin>>b;
	cout<<"altura: ";cin>>a;
	cin.ignore();
	cout<<"color:";getline(cin,c);
	cout<<"tipo:";getline(cin,t);
	Triangulo tri1(c,b,a,t);
	cout<<"\nInicializar rectangulo(constructor)\n";
	float b1,a1;
	string c1;
	cout<<"base: ";cin>>b1;
	cout<<"altura: ";cin>>a1;
	cin.ignore();
	cout<<"color:";getline(cin,c1);
	Rectangulo rec1(c1,b1,a1);
	cout<<"\nInicializar circulo(constructor)\n";
	float r;
	string c2;
	cout<<"radio: ";cin>>r;
	cin.ignore();
	cout<<"color:";getline(cin,c2);
	Circulo cir1(c2,r);
	do{
		cout<<"Prueba de Clases de Figura\n";
		cout<<"1)Calcular area Triangulo\n";
		cout<<"2)Calcular area Rectangulo\n";
		cout<<"3)Calcular area circulo\n";
		cout<<"4)Calcular perimetro circulo\n";
		cout<<"0)salir\n";	
		cout<<"Respueta: ";
		cin>>resp;
		if(resp==1){
			cout<<"Area del triangulo:"<<tri1.calcularArea()<<endl;	
		}else if(resp==2){
			cout<<"Area de rectangulo:"<<rec1.calcularArea()<<endl;
		}else if(resp==3){
			cout<<"Area del circulo:"<<cir1.calcularArea()<<endl;
		}else if(resp==4){
			cout<<"Perimetro de circulo:"<<cir1.calcularPerimetro()<<endl;
		}
		system("pause");
	}while(resp!=0);
	return 0;
	
}
