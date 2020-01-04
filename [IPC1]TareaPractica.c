#include <stdio.h>
#include <conio.h>

typedef struct nodo{

    int codigo;
    char nombre;
    int edad;
    char telefono;

    struct nodo* siguiente;
    struct nodo* anterior;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarRegistro();
void mostrar();
void modificar();
void eliminar();

int main(){

    menu();
    return 0;
}

void menu(){

    int opcionMenu = 0;
	do{
		printf("\n|------------------|");
		printf("\n|     ° Menu °     |");
		printf("\n|------------------|");
		printf("\n| 1. Insertar      |");
		printf("\n| 2. Modificar     |");
		printf("\n| 3. Eliminar      |");
		printf("\n| 4. Mostrar       |");
		printf("\n| 5. Salir         |");
		printf("\n|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				insertarRegistro();
				break;
			case 2:
			    modificar();
				break;
			case 3:
			    eliminar();
				break;
			case 4:
				mostrar();
				break;
			case 5:
                break;
			default:
				printf("\n\n Opcion No Valida \n\n");
		}
	}while(opcionMenu != 5);
}

void insertarRegistro(){

    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    printf("\nIngrese el codigo: ");
    scanf("%d", &nuevo->codigo);
    printf("\nIngrese el nombre: ");
    scanf("%s", &nuevo->nombre);
    printf("\nIngrese la edad: ");
    scanf("%d", &nuevo->edad);
    printf("\nIngrese el telefono: ");
    scanf("%s", &nuevo->telefono);

    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = ultimo;
        ultimo = nuevo;

    }

    printf("\nRegistro guardado correctamente!!\n\n");

}

void mostrar(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
    actual = primero;
    if(primero!=NULL){
        while(actual!=NULL){
            printf("\nCodigo del Registro:  %d", actual->codigo);
            actual = actual->siguiente;
        }
    }else{
        printf("\n La lista esta vacia\n\n");
    }
}

void modificar(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el codigo del registro a modificar: ");
	scanf("%d", &nodoBuscado);

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->codigo == nodoBuscado){
				printf("\n El registro con el codigo ( %d ) encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo codigo para este registro: ");
				scanf("%d", &actual->codigo);
				printf("\n Registro modificado con exito!!\n\n");
				encontrado = 1;
			}

			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n El registro no existe\n\n");
		}
	}else{
		printf("\n La lista esta vacia\n\n");
	}
}

void eliminar(){
    nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el codigo del registro a eliminar: ");
	scanf("%d", &nodoBuscado);

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->codigo == nodoBuscado){

				if(actual==primero){
					primero = primero->siguiente;
					primero->anterior = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");

				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}
