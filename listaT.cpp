#include <iostream>
using namespace std;

template <class T>
struct nodo {
	T valor;
	nodo<T> *next;
	nodo(){}
	nodo(T x, nodo<T>* nn) {
		valor = x;
		next = nn;
	}
	~nodo(){}
};
template <class T>
struct lista {
	nodo<T>* head;
	lista(){
		head = nullptr;
	}
	bool buscar(T vv, nodo<T>**& th) {
		nodo<T> **t = &head;
		while (*t != nullptr && (*t)->valor <= vv) {
			if((*t)->valor == vv){
				th=t;
				return true;
			}
			t = &(*t)->next;
			
		}
		th=t;
		return false;
	}
	void insertar(T a) {
		nodo<T>** ptr = &head;
		bool as = buscar(a, ptr);
		if (as == true)
			;
		else
			*ptr=new nodo<T>(a,*ptr);
	}
	void borrar(T a) {
		nodo<T>** ptr = &head;
		bool c = buscar(a, ptr);
		if (c == true){
			nodo<T>** temp = ptr;
			*ptr=(*ptr)->next;
			delete temp;
		}
	}
	void print(void) {
		cout << "- ";
		nodo<T> *t=head;
		while (t != 0){
			cout << t->valor << " - ";
			t=t->next;
		}
		cout << endl;
	}
	~lista(){}
};
int main(int argc, char *argv[]) {
	lista<int> l;
	l.print();
	l.insertar(2);
	l.print();
	
	l.insertar(4);
	cout<<"aaaa"<<endl;
	l.insertar(6);
	l.insertar(8);
	l.print();
	l.insertar(5);
	l.insertar(4);
	l.print();
	l.borrar(6);
	l.print();
	return 0;
	
}
