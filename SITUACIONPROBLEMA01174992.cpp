// Programa creado por Carolina De los Santos Reséndiz

#include <iostream>
#include <cstring>

using namespace std;

class trabajador {

private:
    string nombre;
    int edad;
    string puesto;
    double sueldo;

public:
    // Constructor de la clase
    trabajador(string nombre, int edad, string puesto, double sueldo)
    {   this->nombre = nombre;
        this->edad = edad;
        this->puesto = puesto;
        this->sueldo = sueldo;
    }

    // Constructor por omisión
    trabajador()
    {
        nombre = "";
        edad = 0;
        puesto = "";
        sueldo = 0;
    }

    // Métodos getter y setter
    string getNombre() {
        return nombre;
    }
        
    string getPuesto() {
        return puesto;
    }
    
    int getEdad() {
        return edad;
    }
    
    double getSueldo() {
        return sueldo;
    }
    
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    
    void setEdad(int edad) {
        this->edad = edad;
    }
    
    void setPuesto(string puesto) {
        this->puesto = puesto;
    }
    
    void setSueldo(double sueldo) {
        this->sueldo = sueldo;
    }
};

class pyme {

private:
    string nombreEmpresa, razonSocial, direccion, nombreDirector;
    int numTrabajadores;
    double cantidadGenerada;
    trabajador* trabajadores;

public:
    // Constructor de la clase
    pyme (string nombreEmpresa, string razonSocial, string direccion, string nombreDirector, int numTrabajadores, double cantidadGenerada)
    {
        this->nombreEmpresa = nombreEmpresa;
        this->razonSocial = razonSocial;
        this->direccion = direccion;
        this->nombreDirector = nombreDirector;
        this->numTrabajadores = 0;
        this->cantidadGenerada = cantidadGenerada;
        this->trabajadores = new trabajador[250];
    }
    
    // Constructor por omisión
    pyme()
    {
        nombreEmpresa = "";
        razonSocial = "";
        direccion = "";
        nombreDirector = "";
        numTrabajadores = 0;
        cantidadGenerada = 0;
        this->trabajadores = new trabajador[250];
    }

    // Métodos getter y setter
    string getNombreEmpresa() {
        return nombreEmpresa;
    }
    
    string getRazonSocial() {
        return razonSocial;
    }
    
    string getDireccion() {
        return direccion;
    }
    
    string getNombreDirector() {
        return nombreDirector;
    }
    
    trabajador* getTrabajadores() {
        return trabajadores;
    }
    
    int getNumTrabajadores() {
        return numTrabajadores;
    }
    
    double getCantidadGenerada() {
        return cantidadGenerada;
    }

    void setNombreEmpresa(string nombreEmpresa) {
        this->nombreEmpresa = nombreEmpresa;
    }
    
    void setRazonSocial(string razonSocial) {
        this->razonSocial = razonSocial;
    }
    
    void setDireccion(string direccion) {
        this->direccion = direccion;
    }
    
    void setNombreDirector(string nombreDirector) {
        this->nombreDirector = nombreDirector;
    }
    
    void setNumTrabajadores(int numTrabajadores) {
        this->numTrabajadores = numTrabajadores;
    }
    
    void setCantidadGenerada(double cantidadGenerada) {
        this->cantidadGenerada = cantidadGenerada;
    }
    
    void setTrabajadores(trabajador* trabajadores) {
        this->trabajadores = trabajadores;
    }
};

int readInt() {
    string cadena;
    getline(cin,cadena);
    // .c_str() extrae los caracteres de una string C++ como arreglo char estilo C
    return atoi(cadena.c_str());
}

double readDouble() {
    string cadena;
    getline(cin,cadena);
    return atof(cadena.c_str());
}

string readString() {
    string cadena;
    getline(cin,cadena);
    return cadena;
}

int main(){
    const int MAX_PYMES = 100; // número máximo de pymes
    pyme pymes[MAX_PYMES];
    int nPymes = 0; // número actual de pymes
    string nombre, puesto, nombreEmpresa, direccion, razonSocial, nombreDirector;
    int edad;
    double sueldo, cantidadGenerada;
    bool pyme_encontrada, trabajador_encontrado;
    int op = 1;
    while(op != 5){
        cout << endl;
        cout << "INVENTARIO DE PYMES Y TRABAJADORES" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Agregar PYME" << endl;
        cout << "2. Agregar trabajador" << endl;
        cout << "3. Consultar PYME" << endl;
        cout << "4. Consultar trabajador" << endl;
        cout << "5. Cerrar" << endl;
        cout << "----------------------------------" << endl;
        cout << "Ingrese una opción: ";
        op = readInt();
        cout << endl;
        switch(op){
            case 1:
                cout << "Ingrese el nombre de la empresa: ";
                nombreEmpresa = readString();
                cout << "Ingrese la razón social de la empresa: ";
                razonSocial = readString();
                cout << "Ingrese la dirección de la empresa: ";
                direccion = readString();
                cout << "Ingrese el nombre del director de la empresa: ";
                nombreDirector = readString();
                cout << "Ingrese la cantidad de pesos que genera al año la empresa: ";
                cantidadGenerada = readDouble();
                pymes[nPymes].setNombreEmpresa(nombreEmpresa);
                pymes[nPymes].setRazonSocial(razonSocial);
                pymes[nPymes].setDireccion(direccion);
                pymes[nPymes].setNombreDirector(nombreDirector);
                pymes[nPymes].setNumTrabajadores(0);
                pymes[nPymes].setCantidadGenerada(cantidadGenerada);
                nPymes++;
                break;
            case 2:
                cout << "Ingrese el nombre de la PYME empleadora: ";
                nombreEmpresa = readString();
                int i;
                for(i = 0; i < nPymes; i++) {
                    if(pymes[i].getNombreEmpresa()==nombreEmpresa)
                        break;
                }
                if(i == nPymes) {
                    cout << "PYME no encontrada." << endl << "Debe registrar la PYME para poder asociarle trabajadores." << endl;
                }
                else {
                    cout << "Ingrese el nombre del trabajador: ";
                    nombre = readString();
                    cout << "Ingrese la edad del trabajador: ";
                    edad = readInt();
                    cout << "Ingrese el puesto del trabajador: ";
                    puesto = readString();
                    cout << "Ingrese el sueldo del trabajador: ";
                    sueldo = readDouble();
                    int n = pymes[i].getNumTrabajadores();
                    trabajador* trabajadores = pymes[i].getTrabajadores();
                    trabajadores[n].setNombre(nombre);
                    trabajadores[n].setEdad(edad);
                    trabajadores[n].setPuesto(puesto);
                    trabajadores[n].setSueldo(sueldo);
                    pymes[i].setNumTrabajadores(n + 1);
                }
                break;
            case 3:
                cout << "Ingrese el nombre de la PYME a buscar: ";
                nombreEmpresa = readString();
                pyme_encontrada = false;
                for(int i = 0; i < nPymes; i++) {
                    if(nombreEmpresa == pymes[i].getNombreEmpresa()) {
                        pyme_encontrada = true;
                        cout << "PYME encontrada." << endl;
                        cout << "Nombre: " << pymes[i].getNombreEmpresa() << endl;
                        cout << "Razón social: " << pymes[i].getRazonSocial() << endl;
                        cout << "Dirección: " << pymes[i].getDireccion() << endl;
                        cout << "Nombre del director: " << pymes[i].getNombreDirector() << endl;
                        cout << "Número de trabajadores: " << pymes[i].getNumTrabajadores() << endl;
                        cout << "Cantidad generada anual: " << pymes[i].getCantidadGenerada() << endl;
                    }
                }
                if(!pyme_encontrada) {
                    cout << "PYME no encontrada en los registros." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el nombre del trabajador a buscar: ";
                nombre = readString();
                trabajador_encontrado = false;
                for(int p = 0; p < nPymes; p++) {
                    trabajador* trabajadores = pymes[p].getTrabajadores();
                    for(int t = 0; t < pymes[p].getNumTrabajadores(); t++) {
                        if(nombre == trabajadores[t].getNombre()) {
                            trabajador_encontrado = true;
                            cout << "Trabajador encontrado." << endl;
                            cout << "Nombre: " << trabajadores[t].getNombre() << endl;
                            cout << "Edad: " << trabajadores[t].getEdad() << endl;
                            cout << "Puesto: " << trabajadores[t].getPuesto() << endl;
                            cout << "Sueldo: " << trabajadores[t].getSueldo() << endl;
                            cout << "Nombre de la empresa: " << pymes[p].getNombreEmpresa() << endl;
                            cout << "Dirección de la empresa: " << pymes[p].getDireccion() << endl;
                            cout << "Razón social de la empresa: " << pymes[p].getRazonSocial() << endl;
                        }
                    }
                }
                if(!trabajador_encontrado) {
                    cout << "Trabajador no encontrado en los registros." << endl;
                }
                break;
            case 5:
                cout << "Programa finalizado" << endl;
                cout << "---------------------------------------------------" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    }
    return 0;
}

