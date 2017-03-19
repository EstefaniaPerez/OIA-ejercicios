#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream entrada2;

struct e{
	int hojas;
	vector<int> arboles_relacionados;
};
void mabel(int, int);

vector<e> vectores;
int cant_mabel;
int cant_pacifica;

void pacifica(int m, int p){
int c=999,z=0;
	for(int a=0; a<vectores[p].arboles_relacionados.size();a++){
		 z=vectores[p].arboles_relacionados[a];
		if (vectores[z].hojas<c && vectores[z].hojas!=0){
		  c=vectores[p].arboles_relacionados[a];} 
	}
	cant_pacifica=cant_pacifica+vectores[c].hojas;
	vectores[c].arboles_relacionados.erase(vectores[c].arboles_relacionados.begin(), vectores[c].arboles_relacionados.begin()+1);
	p=c;
	
	if (vectores[m].arboles_relacionados.size()>0)
	mabel(m,p);
	else if (vectores[m].arboles_relacionados.size()<1 && vectores[p].arboles_relacionados.size()>0)
	pacifica(m,p);
	else
	cout<<"mabel: "<<cant_mabel<<", pacifica: "<<cant_pacifica<<", diferencia: "<<cant_mabel-cant_pacifica;
}

void mabel(int m, int p){
	int c=0,z=0;
	for(int a=0; a<vectores[m].arboles_relacionados.size();a++){
		 z=vectores[m].arboles_relacionados[a];
		if (vectores[z].hojas>c){
		  c=vectores[m].arboles_relacionados[a];}
	}
	cant_mabel=cant_mabel+vectores[c].hojas;
	vectores[c].arboles_relacionados.erase(vectores[c].arboles_relacionados.begin(),vectores[c].arboles_relacionados.begin()+1);
	m=c;
	
	if (vectores[p].arboles_relacionados.size()>0)
	pacifica(m,p);
	else if (vectores[p].arboles_relacionados.size()<1 && vectores[m].arboles_relacionados.size()>0)
	mabel(m,p);
	else
	cout<<"mabel: "<<cant_mabel<<", pacifica: "<<cant_pacifica<<", diferencia: "<<cant_mabel-cant_pacifica;
}



void entrada(int& n, int& m, int& p){
	int b,u,v;
entrada2.open("arboles.in");
entrada2>>n>>m>>p;
m=m-1;
p=p-1;
for (int a=0; a<n; a++){
	entrada2>>b;
    vectores.push_back(e());
	vectores[a].hojas=b;	
}

for (int a=0; a<n-1; a++){
	entrada2>>u>>v;
	vectores[u-1].arboles_relacionados.push_back(v-1);
	vectores[v-1].arboles_relacionados.push_back(u-1); 
	//cout<<vectores[u-1].arboles_relacionados[0]<<endl;
}
cant_mabel=vectores[m].hojas;
vectores[m].arboles_relacionados.erase(vectores[m].arboles_relacionados.begin(),vectores[m].arboles_relacionados.begin()+1);

cant_pacifica=vectores[p].hojas;
vectores[p].arboles_relacionados.erase(vectores[p].arboles_relacionados.begin(),vectores[p].arboles_relacionados.begin()+1);

if(vectores[m].arboles_relacionados.size() && vectores[m].arboles_relacionados[0]>0)
mabel(m,p);
else
cout<<"mabel: "<<cant_mabel<<", pacifica: "<<cant_pacifica<<", diferencia: "<<cant_mabel-cant_pacifica;
}


int main(){
    int n,m,p;
    entrada(n,m,p);

    
    
    
}
