#include <iostream>
using namespace std;

template <class T>
struct nodo{
	T valor;
	nodo<T> *next;
	
	nodo(T x, nodo<T>* nn){
		valor =x;
		next=nn;
	}
};
template <class T>
struct lista{
	nodo<T>* head;
	
	bool buscar(T vv, nodo<T>**&){
		nodo<T>** th = &head;
		while(**th != 0){
			if(**th == vv)
				return true;
			th=*th.
		}
		return false;
	}
};
int main(int argc, char *argv[]) {
	
	return 0;
}

