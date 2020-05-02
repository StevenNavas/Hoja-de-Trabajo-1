/*Ejercicio # 1:
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, así como el total de jugadores por 
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
struct jugador{
	string nombre;
	string nacionalidad;
	int edad;
	float salario =2500;
};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){ // menu principal
	
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar jugador "<<"\n";
		cout<<" 2 - Mostrar jugadores "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void grabar_archivo(){
	//variables basadas en la estructura
	string nombre_jug;
	string nacionalidad_jug;
	int edad_jug;
	float salario_jug = 2500;
	fflush(stdin);
	cout<<"Ingrese Nombre del jugador: "<<endl;
	getline(cin,nombre_jug);
	fflush(stdin);
	cout<<"Ingrese nacionalidad del jugador: "<<endl;
	getline(cin,nacionalidad_jug);
	cout<<"Ingrese la edad del jugador: "<<endl;
	cin>>edad_jug;
	
	ofstream archivo; //leer archivo 
	archivo.open("jugador.txt",ios::app);
	
	if(15 <= edad_jug and edad_jug <= 20){
		salario_jug = salario_jug + 1400;
	} else if(21 <=edad_jug and edad_jug <=25){
		salario_jug = salario_jug + 1500;
	} else if(26<=edad_jug and edad_jug<=30){
        salario_jug = salario_jug + 1200;
	} else if(edad_jug >30){
		salario_jug = salario_jug + 800;
	} 
	
	if(nacionalidad_jug != "guatemalteco"){
		salario_jug = salario_jug +500;
	}
		
	//archivo.open(na.c_str(),ios::app);
	archivo<<nombre_jug<<"\t"<<nacionalidad_jug<<"\t"<<edad_jug<<"\t"<<salario_jug<<endl;
	archivo.close();
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("jugador.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float sumatoriasalarial=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	jugador recordset[lineas];
	
	archivo.open("jugador.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].nombre>>recordset[i].nacionalidad>>recordset[i].edad>>recordset[i].salario;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].edad<<" "<<recordset[i].nombre<<" "<<recordset[i].nacionalidad<<" "<<recordset[i].salario<<endl;
    	sumatoriasalarial+=recordset[i].salario;
	}
	cout<<"Sumatorial total: "<<sumatoriasalarial;
	system("PAUSE");
}
