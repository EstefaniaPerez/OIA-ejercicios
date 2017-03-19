#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream entrada;
ofstream salida;

struct e{
	int k1, k2;
	string letra;
};

vector<e>registro;
vector<vector<int> > conexiones;

bool buscar(int k1, int k2){
	bool resp=false;
	for (int x=0; x<conexiones[k1].size(); x++){
		if(conexiones[k1][x]==k2){
		resp= true;
		break;}
	}
	if(resp==false){
    vector<int>::iterator it;
	it=conexiones[k1].begin();
		while(resp==false && it!=conexiones[k1].end()){
			int a=*it;
	     	for (int x=0; x<conexiones[a].size(); x++){
	         	if(conexiones[a][x]==k2){
	            	resp= true;
	            	break;} 
         	}
			it++;
		}
	}
	return resp;	
}

void hacerConexiones(){
	bool resp=false;
	conexiones.resize(10);
	for(int x=0; x<10; x++)
	  conexiones[x].resize(10);
	e e1;
	for(int x=0; x<registro.size(); x++){
		e1=registro[x];
		if(e1.letra=="C"){
			conexiones[e1.k1].push_back(e1.k2);
			conexiones[e1.k2].push_back(e1.k1);
		}
		else if(e1.letra=="P"){
			resp=buscar(e1.k1, e1.k2);
			if(resp==true)
			cout<<"S";
			else
			cout<<"N";
		}		
	}
}

void cargarDatos(){
	entrada.open("conectar.in");
	salida.open("conectar.out");
	string letra;
	int k1, k2;
	registro.resize(1);
	e vec;
	entrada>>letra;
	while(letra!="F"){
	entrada>>k1>>k2;
	vec.k1=k1;
	vec.k2=k2;
	vec.letra=letra;
     registro.push_back(vec);
     entrada>>letra;
	}
	
//	cout<<registro.size();
}

int main(){
	cargarDatos();
	hacerConexiones();
}
