#include <iostream>
#include <vector>
using namespace std;
template<class T>
class Matrix;

template <class T>
struct nodo
{
	int x , y;
	T val;
	
	nodo(){}
	nodo(int x, int y,T valo){
		this->x = x;
		this->y = y;
		this->val = valo;
	}
	~nodo(){}
};
template<class T>
struct LACOSA{
	int a,b;
	Matrix<T> *A;
	
	LACOSA(int x,int y,Matrix<T>* s){
		a=x;b=y;A=s;
		
	}
	~LACOSA(){}
	void operator =(T w){
		A->set(a,b,w);
	}
	operator T(){
		return A->get(a,b);
	}
};

template <class T>
class Matrix
{
	vector<vector<nodo<T>*>*> M;
	bool insert(int i, int j, T valor){
		nodo<T> *nn=new nodo<T>(i,j,valor);
		M[i]->push_back(nn);
	//	cout<<M[0]->at(0)->val<<"##"<<nn->val<<endl;
		return 1;
	}
	bool cambiar(int i, int j, T valor){
		int siz= (M[i]->size());
		if(siz == 0)return insert(i, j, valor);
		for(int a=0;a<siz;a++){
			if((M[i])->at(a)->y == j){
			   (M[i])->at(a)->val = valor;return 1;}
		}
		return insert(i,j,valor);
	}
	bool borrar(int i,int j){
		return 1;
	}
public:
	Matrix(int a,int b){
		for(int i = 0; i < a; i++)
			M.push_back(new vector<nodo<T>*>);
	}
	~Matrix(){}

	void set(int i, int j, T valor){
		if(valor == 0)borrar(i,j);
		//cout<<valor<<"sss"<<endl;
		cambiar(i,j,valor);
	}
	T get(int i, int j){
		T aux=0;
		int siz= (M[i]->size());
		for(int a=0;a<siz;a++){
			if((M[i])->at(a)->y == j)
				aux=(M[i])->at(a)->val; 
		} 
	}
	
	void print(){
		int sizy=M.size(),sizx;
		//cout<<M[0]->at(0)->val<<" |"<<endl;
		for(int i=0;i<sizy;i++){
			sizx = M[i]->size();
			cout<<"-> ";
			for(int j=0;j<sizx;j++)
				cout<<M[i]->at(j)->val<<" - ";
			cout<<endl;
		}
	}
	LACOSA<T> operator()(int a, int b){
		LACOSA<T> *t = new LACOSA<T>(a,b,this);
		return *t;
	}
};

int main(int argc, char *argv[]) {
	Matrix<int> M(3,3);
	M(0,0)=2;
	M(0,2)=4;
	M(1,2)=5;
	M.print();
	int a = M(0,0);
	cout<<" ll l l"<<a<<endl;
	return 0;
}

