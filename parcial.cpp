#include <iostream>
using namespace std;
/**
 * Se define la estrucutura para el Arbol Binario.
 * @param data Dato dela rama.
 * @param left Puntero a la siguiente rama.
 * @param right Puntero a la siguiente rama.
 */
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};
struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *atras;

} *primero, *ultimo;
int pesoInt = 0;
int nLista = 0;
/**
 * Funcion para añadir una rama en el arbol.
 * @param root Hace referencia al nodo principal del arbol.
 * @param value Valor que se agrega al arbol.
 * @param current Variable de apoyo para no modificar el valor de 'root'
 */
void create(Tree *&root, int value)
{

    Tree *current = root; // Se crea un puntero de Tree para guardar 'root'

    if (root != NULL) // Valida si ya existe 'root' (Ya hay al menos un valor)
    {
        if (root->data == value)
        {
            cout << "VALOR YA INGRESADO" << endl;
            return;
        }

        // El dato actual seleccionado del arbol es mayor al valor a ingresar, por ende el valor va a la derecha del rama actual.
        if (root->data > value)
        {
            /**
             * Se valida si el puntero a la izquierda está vacio para así ingresar ahí el nuevo valor, de lo contrario
             * se entiende que ya existe un valor a la izquierda del rama actual.
             */
            if (root->left == NULL)
            {
                Tree *_new = new Tree;
                _new->data = value;
                _new->left = nullptr;
                _new->right = nullptr;
                root->left = _new;
            }
            /**
             * Para cuando ya hay un valor a la izquierda de la Rama acutual, por ende tocar moverse a esa Rama.
             * Se crea un puntero de current, para así no cambiar el valor de 'root', y este nuevo dato se usa para guardar la
             * rama de la izquierda y asi se manda nuevamente para validar.
             */
            else
            {
                Tree *current = new Tree;
                current = root->left;
                create(current, value);
            }
        }

        // El dato actual seleccionado del arbol es menor al valor a ingresar, por ende el valor va a la izquierda de la rama actual.
        else
        {

            /**
             * Se valida si el puntero a la derecha está vacio para así ingresar ahí el nuevo valor, de lo contrario
             * se entiende que ya existe un valor a la derecha de la rama actual.
             */
            if (root->right == NULL)
            {
                Tree *_new = new Tree;
                _new->data = value;
                _new->left = nullptr;
                _new->right = nullptr;
                root->right = _new;
            }
            else
            {
                /**
                 * Para cuando ya hay un valor a la derecha de la Rama acutual, por ende tocar moverse a esa Rama.
                 * Se crea un puntero de current, para así no cambiar el valor de 'root', y esta nueva variable se usa para guardar la
                 * rama de la derecha y asi se manda nuevamente para validar.
                 */
                Tree *current = new Tree;
                current = root->right;  // Nos movemos un nivel en el arbol.
                create(current, value); // Se llama a la misma funcion para así validar.
            }
        }
    }
    /**
     * Algoritmo para cuando se ingresa el primer valor del Arbol.
     */
    else
    {
        Tree *_new = new Tree; // Se inicializa una variable '_new'
        _new->data = value;    // Se actoualiza el dato de _new.data a 'value' (Variable recibida por la funcion)
        _new->left = NULL;     //
        _new->right = NULL;    //
        root = _new;           // Se crea el 'root'
    }
}
/**
 * Funcion para imprimir el arbol.
 * @param root
 * @param level Variable tipo int para saber el nivel del arbol, y así imprimir un espacio.
 *
 * Lo que hace está funcion es llamarse asi misma hasta que llegue a la ultima rama de arbol, empezando por la derecha, cuando llega al final
 * este imprime espacios dependiendo de 'level' (esta varaible aunmenta cada vez que la funcion se llame así misma), despues se imprime el valor del arbol,
 * y se vuelve a llamar así misma, pero ahora pasandole a donde apunta root.left, y vuelve a validar si exisite. si existe empieza otra vez el proceso
 * pero por la parte de la izquierda, cuando esta parte termina se acaba, para dar paso al procedimiento anterior antes de la llamada actual.
 * ()
 *
 * */
void read(Tree *&root, int level)
{
    // Se valida si 'root' está vacia (Sirve tanto para saber si hay datos, o si ya se llegó al final del arbol)
    if (root == NULL)
    {

        return;
    }
    // Se vuelve a llamar a la funcion, pero ahora se le pasa la rama de la derecha, y se le suma un 1 al nivel del arbol
    read(root->right, level + 1);
    // Bucle para impirmir la cantidad de espacios
    for (int i = 0; i < level; i++)
    {
        cout << "       ";
    }
    cout << root->data << "\n";
    // Se vuelve a llamar a la funcion, pero ahora se le pasa la rama de la izquierda, y se le suma un 1 al nivel del arbol.
    read(root->left, level + 1);
}
void peso(Tree *&arbol, int level)
{
    if (arbol == NULL)
    {
        if (pesoInt < level)
        {
            pesoInt = level;
        }
        return;
    }
    else
    {
        peso(arbol->left, level + 1);
        peso(arbol->right, level + 1);
    }
}

void insertarLista(Nodo *&lista, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    // 8 9 6
    //
    if (lista == NULL)
    {
        lista = nuevo_nodo;
        return;
    }
    Nodo *current = lista;
    while (current->siguiente != NULL)
    {
        current = current->siguiente;
    }
    current->siguiente = nuevo_nodo;
    nuevo_nodo->atras = current;
    ultimo = nuevo_nodo;
}
void mostrarLista(Nodo *lista)
{

    Nodo *actual = new Nodo();
    actual = lista;
    while (actual != NULL)
    {

        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
}
void quicksort(Nodo *&head, Nodo *&primer, Nodo *&ultim)
{
    Nodo *current = head;
    Nodo *laste = new Nodo();
    laste = ultim;

    // 0    5
    int pivote = head->dato; // El pivote se elige como el primer elemento.
                             // 8
    while (current->dato <= laste->dato)
    {
        cout << "HERE" << endl;
        while (current->dato < pivote)
        {
            current = current->siguiente;
        }
        while (current->dato > pivote)
        {
            laste = laste->atras;
        }
        // (i <= j)
        if (current->dato <= laste->dato)
        {
            // Intercambio de elementos con depuración
            int temp = current->dato;
            current->dato = laste->dato;
            laste->dato = temp;

            current = current->siguiente;
            laste = laste->atras;
        }
    }

    quicksort(*&head, primer, laste);  // Llamada recursiva al subarreglo izquierdo
    quicksort(*&head, current, ultim); // Llamada recursiva al subarreglo derecho
}
void buscarListaBinaria(Nodo *lista, int n)
{
    Nodo *inicio = lista;
    Nodo *fin = nullptr;

    while (inicio != fin)
    {
        Nodo *actual = inicio;
        int count = 0;
        while (actual != fin)
        {
            actual = actual->siguiente;
            count++;
        }

        actual = inicio;
        for (int i = 0; i < count / 2; i++)
        {
            actual = actual->siguiente;
        }

        if (actual->dato == n)
        {
            cout << "Elemento encontrado: " << n << endl;
            return;
        }
        else if (actual->dato < n)
        {
            inicio = actual->siguiente;
        }
        else
        {
            fin = actual;
        }
    }

    cout << "Elemento no encontrado -1: " << n << endl;
}
int main()
{
    Tree *root = NULL;
    Nodo *head = NULL;
    int choise, value;

    do
    {
        cout << "OPCIONES: " << endl;
        cout << "0. CreateOne: Para crear un dato en el arbol" << endl;
        cout << "1. ReadAll: Para leer todos los datos del arbol" << endl;
        cout << "2. Peso: Muestra el peso del arbol " << endl;
        cout << "3. Crear Nodo Lista" << endl;
        cout << "4. Mostrar Lista" << endl;
        cout << "5. Ordenar Lista" << endl;
        cout << "6. Ordenar Lista" << endl;
        cout << "Ingrese la opcion que desea: ";
        cin >> choise;
        switch (choise)
        {
        case 0:
            cout << "Numero a ingresar: ";
            cin >> value;
            create(root, value);

            break;
        case 1:
            read(root, 0);
            break;
        case 2:
            peso(root, 0);
            cout << "PESO DEL ARBOL: " << pesoInt;
            break;
        case 3:
            cout << "Numero a ingresar: ";
            cin >> value;
            insertarLista(*&head, value);
            break;
        case 4:
            mostrarLista(*&head);
            break;
        case 5:
            quicksort(*&head, *&head, ultimo);
            break;
        case 6:
            cout << "Numero a bsucar: ";
            cin >> value;
            buscarListaBinaria(*&head, value);
            break;
        case 99:
            create(root, 9);
            create(root, 5);
            create(root, 7);
            create(root, 3);
            create(root, 15);
            create(root, 13);
            create(root, 18);
            create(root, 19);
            break;
        case 100:
            insertarLista(*&head, 8);
            insertarLista(*&head, 2);
            insertarLista(*&head, 4);
            break;
        default:
            cout << "Opcion invalida";
            break;
        }
        cout << "\nOpciones: \n"
             << "0:Finalizar 1:Seguir" << endl;
        cin >> choise;
    } while (true);
}