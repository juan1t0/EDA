#include <iostream>

using namespace std;

template <class  T>
struct Nodo{
	T valor;
	Nodo<T> *next;
	Nodo<T> *prev;
	
	Nodo(){next=NULL;prev=NULL;}
	Nodo(T a,Nodo<T>*& n,Nodo<T>*& p){valor=a;next=n;prev=p;}
	~Nodo();
};

template <class T>
struct LCDE{
	Nodo<T> *tan;
	LCDE(){tan=0;};
	~LCDE(){};
	
	bool find(T z, Nodo<T>**& p);
	void insertNodo(T x);
	void printLista();
};

template <class T>
bool LCDE<T>::find(T z, Nodo<T>**& p){
	p = &tan;
	while (*p != tan && (*p)->valor <= z) {
		if((*p)->valor == z)
			return true;
		p = &(*p)->next;
		
	}
	return false;
}
template <class T>
void LCDE<T>::insertNodo(T x){
	Nodo<T>** ptr ;
	bool as = find(x, ptr);
	if (as == true)
		;
	else{
		*ptr=new Nodo<T>(x,*ptr,(*ptr)->prev);
	}
}
template <class T>
void LCDE<T>::printLista(){
	Nodo<T>* ptr=tan;
	cout<<"- ";
	while((ptr->next)!=tan)
		cout<<ptr->valor<<" - ";
}
int main()
{
	LCDE<int> ll;
	ll.insertNodo(3);
	ll.printLista();
	return 0;
}
