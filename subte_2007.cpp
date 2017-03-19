#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 
ifstream subtes;

vector<vector<int> > lineas;

void iniciar(int, int, int);
void encontrar_fin(int, int,int);

void cargar_datos(int& n, int& m, int& k, int& inicio, int& fin){
	int l;
	lineas.resize(n);

	subtes.open("subte.in");
	subtes>>n>>m;
	lineas.resize(n);
	for (int x=0; x<n; x++){
		subtes>>k;
		for (int y=0; y<k; y++){
			subtes>>l;
			lineas[x].push_back(l);
		}
		lineas[x].resize(k);
	}
	subtes>>inicio>>fin;
	iniciar(inicio, fin, n);
}

vector<int> lineas_inicio;
vector<int>columna;
vector<int>visitados;


void iniciar(int inicio, int fin, int n ){
	lineas_inicio.resize(n+1); 
	columna.resize(n);
	visitados.resize(9);
	int cont=0;
	for(int z=0; z<n; z++){
		for(int y=0; y<lineas[z].size(); y++){
		if (lineas[z][y]==inicio){
			lineas_inicio[cont]=z;
			columna[cont]=y;
			cont++;
			break;
	      }
	     }
	}
lineas_inicio.resize(cont);
columna.resize(cont);
	encontrar_fin(inicio, fin, n);	
} 

bool buscar(int& contlineas, int fin){
	bool r=false;
     for(int a=0; a<lineas_inicio.size();a++){
     	for(int y=0; y<lineas[lineas_inicio[a]].size(); y++){
		if (lineas[lineas_inicio[a]][y]==fin){
		contlineas++;
		visitados[0]=lineas_inicio[a]+1;	
	        r=true;
			break;
	      }
	     }
	     if(r==true)
	     break;
	 }
	 return r;
}

bool buscar2(int fin,int n, int& contlineas){
		bool r=false;
	for(int z=0; z<n; z++){
		for(int y=0; y<lineas[z].size(); y++){
		if (lineas[z][y]==fin){
			contlineas++;
			r=true;
	      }
		  if(r==true)
		  break;
	     }
	    
	}
	return r;
}

bool recorrer(int& contlineas, int nbuscado,int fin, int n,int inicio){
	bool r=false;
	int visit=1;
	for(int z=0; z<n; z++){
		for(int y=0; y<lineas[z].size(); y++){
		if (lineas[z][y]==nbuscado){
			r=buscar2(fin,n,contlineas);
			if(r==true){
		visitados[1]=z+1;
	}
	      }
	      if(r==true)
		  break;
	     }
		
	}
	return r;
}

void encontrar_fin(int inicio, int fin, int n){
	int contlineas=1, contador=0;
	bool resp=false;
	resp=buscar(contlineas,fin);
	
	if (resp==false){
		for(int a=0; a<lineas_inicio.size();a++){
			int w=columna[a];
     	for(int y=0; y<lineas[lineas_inicio[a]].size(); y++){
     		w++;
		resp=recorrer(contlineas,lineas[lineas_inicio[a]][w],fin,n, inicio);
		if (resp==true){
			visitados[0]=lineas_inicio[a]+1;
		break;}
	     }
	     if(resp==true)
	     break;
	 } 
	}
	int h=0;
	if (resp==true){
	cout<<contlineas<<endl;
	while(visitados[h]>0 && visitados[h]<99){
	cout<<visitados[h]<<" ";
	h++;}}
	
	if(resp==false)
	cout<<"no hay salida";
}

int main(){
	int n,m,k,inicio,fin;
	cargar_datos(n,m,k, inicio, fin);
}
