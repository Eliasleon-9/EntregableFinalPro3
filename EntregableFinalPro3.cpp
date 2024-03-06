#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const size_t TAMANO = 10;

// Definicion de la clase Libro
class Libro {
private:
    int nISBN;
    string sTitulo;
    string sAutor;
    int nPublicacion;
    string sGenero;
    double dPrecio;
    int nPaginas;
public:
    //constructor por defecto
    Libro() {
        this->nISBN = 0;
        this->sTitulo = "";
        this->sAutor = "";
        this->nPublicacion = 0;
        this->sGenero = "";
        this->dPrecio = 0.0;
        this->nPaginas = 0;
    }
    // Constructor por atributos
    Libro(int isbn, string titulo, string autor, int publicacion, string genero, double precio, int paginas) {
        this->nISBN = isbn;
        this->sTitulo = titulo;
        this->sAutor = autor;
        this->nPublicacion = publicacion;
        this->sGenero = genero;
        this->dPrecio = precio;
        this->nPaginas = paginas;
    }
    // Metodos de obtencion de los atributos
    int get_ISBN() const { return nISBN; }
    string get_Titulo() const { return sTitulo; }
    string get_Autor() const { return sAutor; }
    int get_Publicacion() const { return nPublicacion; }
    string get_Genero() const { return sGenero; }
    double get_Precio() const { return dPrecio; }
    int get_Paginas() const { return nPaginas; }
    // Metodos de modificacion de los atributos
    void set_ISBN(int isbn) { nISBN = isbn; }
    void set_Titulo(const string& titulo) { sTitulo = titulo; }
    void set_Autor(const string& autor) { sAutor = autor; }
    void set_Publicacion(int publicacion) { nPublicacion = publicacion; }
    void set_Genero(const string& genero) { sGenero = genero; }
    void set_Precio(double precio) { dPrecio = precio; }
    void set_Paginas(int paginas) { nPaginas = paginas; }
};
// Definicion de la clase Persona
class Persona {
private:
    int nID;
    string sNombre;
    string sApellido;
    string sEmail;
public:
    // Constructor por defecto
    Persona() {
        this->nID = 0;
        this->sNombre = "sin nombre";
        this->sApellido = "sin apellido";
        this->sEmail = "sin email";
    }
    // Constructor por parametros
    Persona(int id, string nombre, string apellido, string email) {
        this->nID = id;
        this->sNombre = nombre;
        this->sApellido = apellido;
        this->sEmail = email;
    }
    // Metodos de obtencion de los atributos
    int get_ID() const { return nID; }
    string get_Nombre() const { return sNombre; }
    string get_Apellido() const { return sApellido; }
    string get_Email() const { return sEmail; }
    // Metodos de modificacion de los atributos
    void set_ID(int id) { nID = id;}
    void set_Nombre(const string& nombre) { sNombre = nombre; }
    void set_Apellido(const string& apellido) { sApellido = apellido; }
    void set_Email(const string& email) { sEmail = email; }
};
// Definicion de la clase Usuario
class Usuario : public Persona {
private:
    int nCelular;
public:
    // Constructor por defecto
    Usuario() {
        this->nCelular = 0;
    }
    //constructor por parametros
    Usuario(int id, string nombre, string apellido, string email, int celular): Persona(id, nombre, apellido, email){
        this->nCelular=celular;
    }
    // Metodos de obtencion de los atributos
    int get_Celular() const { return nCelular; }
    // Metodos de modificacion de los atributos
    void set_Celular(int celular) { nCelular = celular; }
};
// Definicion de la clase Bibliotecario
class Bibliotecario : public Persona {
private:
    double dSalario;
public:
    // Constructor por defecto
    Bibliotecario() {
        this->dSalario = 0.0;
    }
    //constructor por parametros
    Bibliotecario(int id, string nombre, string apellido, string email, double salario): Persona(id, nombre, apellido, email){
        this->dSalario=salario;
    }
    // Metodos de obtencion de los atributos
    double get_Salario() const { return dSalario; }
    // Metodos de modificacion de los atributos
    void set_Salario(double salario) { dSalario = salario; }
};
// Definición de la clase GestorLibros
class GestorLibros {
private:
    Libro libros[TAMANO];
    int tamanoActual;
public:
    GestorLibros() : tamanoActual(0) {}
    bool tituloRepetido(const string& titulo, int cantidad) const {
        for (int i = 0; i < cantidad; i++) {
            if (titulo == libros[i].get_Titulo()) {
                return true; // Si el titulo esta repetido
            }
        }
        return false; // Si el titulo no esta repetido
    }
    void llenar() {
        string listaTitulo[] = {"Programacion I", "Programacion II", "Programacion III", "Aprende Linux", "Aprende php", "Aprende Java", "Calculo I", "Calculo II", "anlan", "La Metamorfosis"};
        string listaAutor[] = {"Jorge Luis", "Gabriel Garcia ", "George Orwell", "Miguel de Cervantes", "J.K. Rowling", "Homero", "Mark Twain", "Antoine de Saint", "George Orwell", "Franz Kafka"};
        string listaGenero[] = {"Ficcion", "Novela", "Codigos", "Clasico", "Fantasia", "Misterio", "Aventura", "Infantil", "Fabula", "Terror"};
        srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
        tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
        for (int i = 0; i < TAMANO; i++) {
            string tituloAleatorio;
            do {
                int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
                tituloAleatorio = listaTitulo[indiceTitulo];
            } while (tituloRepetido(tituloAleatorio, tamanoActual)); // Verificar si el titulo esta repetido
            int isbnAleatorio = i + 1;
            int indiceAutor = rand() % 10;
            int indiceGenero = rand() % 10;
            int publicacionAleatoria = rand() % 25 + 1980; // Años entre 1980 y 2024
            double precioAleatorio = rand() % 300 + 50; // Precios entre 50 y 349
            int paginasAleatorias = rand() % 500 + 100; // Paginas entre 100 y 599
            string AutorAleatorio = listaAutor[indiceAutor];
            string GeneroAleatorio = listaGenero[indiceGenero];
            libros[i] = Libro(isbnAleatorio, tituloAleatorio,AutorAleatorio , publicacionAleatoria,GeneroAleatorio , precioAleatorio, paginasAleatorias);
            tamanoActual++;
        }
    }
    void mostrar() const {
        if (tamanoActual == 0) { // Verifica si no hay libros llenados
            cout << "Datos no llenados." << endl;
            return;
        }
        //imprimir datos de los libros
        cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10) << "Paginas" << endl;
        for (int i = 0; i < tamanoActual; i++) {
            cout << left << setw(8) << libros[i].get_ISBN() << setw(25) << libros[i].get_Titulo() << setw(25) << libros[i].get_Autor() << setw(11) << libros[i].get_Publicacion() << setw(15) << libros[i].get_Genero() << setw(10) << libros[i].get_Precio() << setw(10) << libros[i].get_Paginas() << endl;
        }
    }
    // Función para mostrar los datos de los libros en forma de bloque
void mostrar(string bloque) const {
    if (tamanoActual == 0) { // Verifica si no hay libros llenados
        cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
        return;
    }
    cout << "Datos de libros en bloques: " << endl;
    for (int i = 0; i < tamanoActual; i++) {
        
        cout << "ISBN: " << libros[i].get_ISBN() << endl;
        cout << "Titulo: " << libros[i].get_Titulo() << endl; 
        cout << "Autor: " << libros[i].get_Autor() << endl;
        cout << "Anio: " << libros[i].get_Publicacion() << endl; 
        cout << "Genero: " << libros[i].get_Genero() << endl; 
        cout << "Precio: " << libros[i].get_Precio() << endl;
        cout << "Paginas: " << libros[i].get_Paginas() << endl << endl;
    }
    cout << bloque << endl;
}
    // Funcion para convertir una cadena a minusculas
    string convertir(const string& cadena) const {
        string resultado = cadena;
        for (char& c : resultado) {
            c = tolower(c);
        }
        return resultado;
    }
    // Funcion recursiva para buscar libros por titulo
    void buscar(int indice, int fin, const string& busqueda) const {
        if (indice < fin) { //condicion base
            // Convertir a minúsculas los atributos del libro y la cadena de búsqueda
            string tituloMinuscula = convertir(libros[indice].get_Titulo());
            string autorMinuscula = convertir(libros[indice].get_Autor());
            string generoMinuscula = convertir(libros[indice].get_Genero());
            string precioStr = to_string(libros[indice].get_Precio());
            string busquedaMinuscula = convertir(busqueda);
            if (indice == 0) { //mostrar el encabezado de la tabla
                cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10) << "Paginas" << endl;
            }
            // Verificar si la busqueda coincide con el titulo, autor, genero o precio
            if (tituloMinuscula.find(busquedaMinuscula) != string::npos || autorMinuscula.find(busquedaMinuscula) != string::npos || generoMinuscula.find(busquedaMinuscula) != string::npos || precioStr.find(busquedaMinuscula) != string::npos) {
                //imprime los datos de los libros que coincidan con la busqueda
                cout << left << setw(8) << libros[indice].get_ISBN() << setw(25) << libros[indice].get_Titulo() << setw(25) << libros[indice].get_Autor() << setw(11) << libros[indice].get_Publicacion() << setw(15) << libros[indice].get_Genero() << setw(10) << libros[indice].get_Precio() << setw(10) << libros[indice].get_Paginas() << endl;
            }
            buscar(indice + 1, fin, busqueda); // Llamada recursiva con el siguiente libro
        }
    }
};
// Definicion de la clase GestorUsuarios
class GestorUsuarios {
private:
    Usuario usuarios[TAMANO];
    int tamanoActual;
public:
    GestorUsuarios() : tamanoActual(0) {}
    void llenar() { // Funcion para llenar el arreglo de usuarios con datos aleatorios
        string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
        string listaApellidos[] = {"Peralta", "Osinaga", "Rodriguez", "Escobar", "Lopez", "Gonzalez", "Mendoza", "Roca", "Garcia", "Torres"};
        srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
        tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
        for (int i = 0; i < TAMANO; ++i) {
            int indiceNombre = rand() % 10; //generacion de numero randomico de 0 al 9
            int indiceApellido = rand() % 10; //generacion de numero randomico de 0 al 9
            int idAleatorio = i + 1;
            int celularAleatorio = (rand() % 2 + 6) * 10000000 + rand() % 10000000;
            //asignar nombre y apellido de los arrays de acuerdo al indice generado randomicamente
            string nombreAleatorio = listaNombres[indiceNombre];
            string apellidoAleatorio = listaApellidos[indiceApellido];
            string emailAleatorio = nombreAleatorio + apellidoAleatorio + "@gmail.com";
            usuarios[i] = Usuario(idAleatorio, nombreAleatorio, apellidoAleatorio, emailAleatorio, celularAleatorio);
            tamanoActual++; // Incrementar el contador de usuarios
        }
    }
    void mostrar() const {  // Funcion para mostrar los datos de los usuarios en forma de tabla
        if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
            cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
            return;
        }
        cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Celular" << endl;
        for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
            cout << left << setw(15) << usuarios[i].get_ID() << setw(15) << usuarios[i].get_Nombre() << setw(15) << usuarios[i].get_Apellido() << setw(30) << usuarios[i].get_Email() << setw(15) << usuarios[i].get_Celular() << endl;
        }
    }
    // Función para mostrar los datos de los usuarios en forma de bloques
    void mostrar(string bloque) const {
        if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
            cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
            return;
        }
        cout << "Datos de Usuarios en Bloques:" << endl;
        for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
            //cout << "Usuario " << i+1 << ":" << endl;
            cout << "User ID: " << usuarios[i].get_ID() << endl;
            cout << "Nombre: " << usuarios[i].get_Nombre() << endl;
            cout << "Apellido: " << usuarios[i].get_Apellido() << endl;
            cout << "Email: " << usuarios[i].get_Email() << endl;
            cout << "Celular: " << usuarios[i].get_Celular() << endl << endl;
        }
    }
    // Funcion para convertir una cadena a minusculas
    string convertir(const string& cadena) const { 
        string resultado = cadena;
        for (char& c : resultado) {
            c = tolower(c);
        }
        return resultado;
    }
    // Funcion recursiva para buscar usuarios por nombre, apellido o nombre completo
    void buscar(int inicio, int fin, const string& busqueda) const {
        if (inicio < fin) {  //condicion base
            // Convertir a minusculas los atributos del usuario y la cadena de busqueda
            string nombreMinuscula = convertir(usuarios[inicio].get_Nombre()); //convertir las cadenas a minusculas
            string apellidoMinuscula = convertir(usuarios[inicio].get_Apellido());
            string emailMinuscula = convertir(usuarios[inicio].get_Email());
            string celularStr = to_string(usuarios[inicio].get_Celular());
            string busquedaMinuscula = convertir(busqueda);
            if (inicio == 0) { //mostrar el encabezado de la tabla
                cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Celular" << endl;
            }
            // Verifica si la busqueda coincide con el nombre, apellido o nombre completo
            if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || celularStr.find(busquedaMinuscula) != string::npos){
                // Imprimir los datos del usuario que coincidan con la busqueda
                cout << left << setw(15) << usuarios[inicio].get_ID() << setw(15) << usuarios[inicio].get_Nombre() << setw(15) << usuarios[inicio].get_Apellido() << setw(30) << usuarios[inicio].get_Email() << setw(15) << usuarios[inicio].get_Celular() << endl;
            }
            buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente usuario
        }
    }
};
// Definicion de la clase GestorBibliotecarios
class GestorBibliotecarios {
private:
    Bibliotecario bibliotecarios[TAMANO];
    int tamanoActual;
public:
    GestorBibliotecarios() : tamanoActual(0) {}
    void llenar() { // Función para llenar el arreglo de bibliotecarios con datos aleatorios
        string listaNombres[] = {"Santiago", "Belen", "Luz", "Isabel", "Fabian", "Carla", "Sergio", "Gustavo", "Mario", "Melanie"};
        string listaApellidos[] = {"Leon", "Roca", "Justiniano", "Soliz", "Rivero", "Torrico", "Cuellar", "Tantani", "Rivas", "Roque"};
        srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
        tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
        for (int i = 0; i < TAMANO; ++i) {
            int indiceNombre = rand() % 10; //generar numero randomico del 0 al 9
            int indiceApellido = rand() % 10;
            int idAleatorio = i + 1;
            double salarioAleatorio = rand() % 1501 + 1500; // salario entre 1500 y 3000
            bibliotecarios[i] = Bibliotecario(idAleatorio, listaNombres[indiceNombre], listaApellidos[indiceApellido], listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com", salarioAleatorio);
            tamanoActual++;
        }
    }
    void mostrar() const {  // Funcion para mostrar los datos de los bibliotecarios en forma de tabla
        if (tamanoActual == 0) { // Verificar si no hay bibliotecarios para mostrar
            cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
            return;
        }
        //imprimir datos de los bibliotecarios
        cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
        for (int i = 0; i < tamanoActual; ++i) {
            cout << left << setw(15) << bibliotecarios[i].get_ID() << setw(15) << bibliotecarios[i].get_Nombre() << setw(15) << bibliotecarios[i].get_Apellido() << setw(30) << bibliotecarios[i].get_Email() << bibliotecarios[i].get_Salario() << "Bs" << endl;
        }
    }
    // Función para mostrar los datos de los bibliotecarios en forma de bloques
    void mostrar(string bloque) const {
        if (tamanoActual == 0) {  // Verificar si no hay bibliotecarios para mostrar
            cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
            return;
        }
        cout << "Datos de Bibliotecarios en Bloques:" << endl;
        for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los bibliotecarios
            //cout << "Bibliotecario " << i+1 << ":" << endl;
            cout << "Employee ID: " << bibliotecarios[i].get_ID() << endl;
            cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
            cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
            cout << "Email: " << bibliotecarios[i].get_Email() << endl;
            cout << "Salario: " << bibliotecarios[i].get_Salario() << " Bs" << endl << endl;
        }
    }
    string convertir(const string& cadena) const { // Funcion para convertir una cadena a minusculas
        string resultado = cadena;
        for (char& c : resultado) {
            c = tolower(c);
        }
        return resultado;
    }
    // Funcion recursiva para buscar bibliotecarios por nombre, apellido o nombre completo
    void buscar(int inicio, int fin, const string& busqueda) const {
        if (inicio < fin) { //condicion base
            // Convertir a minusculas los atributos del bibliotecario y la cadena de busqueda
            string nombreMinuscula = convertir(bibliotecarios[inicio].get_Nombre());
            string apellidoMinuscula = convertir(bibliotecarios[inicio].get_Apellido());
            string emailMinuscula = convertir(bibliotecarios[inicio].get_Email());
            string salarioStr= to_string(bibliotecarios[inicio].get_Salario());
            string busquedaMinuscula = convertir(busqueda);
            if (inicio == 0) { //mostrar el encabezado de la tabla
                cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
            }
            // Verifica si la busqueda coincide con el nombre, apellido o nombre completo
            if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || salarioStr.find(busquedaMinuscula) != string::npos) {
                // Imprimir los datos del bibliotecario que coincidan con la busqueda
                cout << left << setw(15) << bibliotecarios[inicio].get_ID() << setw(15) << bibliotecarios[inicio].get_Nombre() << setw(15) << bibliotecarios[inicio].get_Apellido() << setw(30) << bibliotecarios[inicio].get_Email() << bibliotecarios[inicio].get_Salario() << "Bs" << endl;
            }
        buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente bibliotecario
        }
    }
};
// Menu para mostrar los listados
void menuListados(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
    int opcionListados;
    do {
        cout << "\nSubmenu de Listados:" << endl;
        cout << "1. Listado de Libros" << endl;
        cout << "2. Listado de Usuarios" << endl;
        cout << "3. Listado de Bibliotecarios" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionListados;
        switch (opcionListados) {
            case 1:
                {
                    char respuesta;
                    cout << "Desea ver los datos en forma de tabla? (s/n): ";
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S'){
                        gestorL.mostrar();
                    } else {
                        gestorL.mostrar("bloque");
                    }
                }  
                break;
            case 2:
                {
                    char respuesta;
                    cout << "Desea ver los datos en forma de tabla? (s/n): ";
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S') {
                        gestorU.mostrar();
                    } else {
                        gestorU.mostrar("Bloque");
                    }
                }
                break;
            case 3:
                {
                    char respuesta;
                    cout << "Desea ver los datos en forma de tabla? (s/n): ";
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S') {
                        gestorB.mostrar();
                    } else {
                        gestorB.mostrar("Bloque");
                    }
                }
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionListados != 0);
}
// Menu para realizar busquedas
void menuBusqueda(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
    int opcionBusqueda;
    do {
        cout << "\nSubmenu de Busqueda:" << endl;
        cout << "1. Busqueda de Libro" << endl;
        cout << "2. Busqueda de Usuario" << endl;
        cout << "3. Busqueda de Bibliotecario" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionBusqueda;
        switch (opcionBusqueda) {
            case 1:
                {
                string sBusquedaL;
                cout << "Ingrese el titulo del libro que desea buscar: ";
                cin.ignore(); // Limpiar el buffer de entrada
                getline(cin, sBusquedaL); // Leer la cadena de búsqueda
                cout << "\nResultados de la busqueda:" << endl;
                gestorL.buscar(0, TAMANO, sBusquedaL); // Realizar la busqueda de libros
                }
                break;
            case 2:
                {
                string sBusquedaU;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore(); // Limpiar el buffer de entrada
                getline(cin, sBusquedaU); // Leer la cadena de búsqueda
                cout << "\nResultados de la busqueda:" << endl;
                gestorU.buscar(0, TAMANO, sBusquedaU); // Realizar la busqueda de usuarios
                }
                break;
            case 3:
                {
                string sBusquedaB;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore(); // Limpiar el buffer de entrada
                getline(cin, sBusquedaB); // Leer la cadena de búsqueda
                cout << "\nResultados de la busqueda:" << endl;
                gestorB.buscar(0, TAMANO, sBusquedaB); // Realizar la busqueda de usuarios
                }
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionBusqueda != 0);
}
// Menu principal
void menuPrincipal(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
    int opcionPrincipal;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Llenar Datos" << endl;
        cout << "2. Listados" << endl;
        cout << "3. Busqueda" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionPrincipal;
        cin.ignore(); //Limpiar el buffer de entrada
        switch (opcionPrincipal) {
            case 1:
                gestorL.llenar();
                gestorU.llenar();
                gestorB.llenar();
                cout << "Datos llenados exitosamente." << endl;
                break;
            case 2:
                menuListados(gestorL, gestorU, gestorB);
                break;
            case 3:
                menuBusqueda(gestorL, gestorU, gestorB);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 0);
}
int main() {
    srand(time(nullptr));
    // Crear instancias de los gestores de libros, usuarios y bibliotecarios
    GestorLibros gestorL;
    GestorUsuarios gestorU;
    GestorBibliotecarios gestorB;
    // Llamar a la función del menú principal, pasando los gestores como argumentos
    menuPrincipal(gestorL, gestorU, gestorB);
    return 0;
}
