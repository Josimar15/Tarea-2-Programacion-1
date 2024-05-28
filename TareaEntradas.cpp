#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Venta {
    int numeroFactura;
    string cedula;
    string nombre;
    int localidad;
    int cantidadEntradas;
    string nombreLocalidad;
    double precioPorEntrada;
    double subtotal;
    double cargosServicios;
    double totalPagar;
};

void mostrarEstadisticas(int entradasSol, double dineroSol, int entradasSombra, double dineroSombra, int entradasPreferencial, double dineroPreferencial) {
    cout << "\nEstadisticas finales:\n";
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << entradasSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << dineroSol << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << entradasSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << dineroSombra << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << entradasPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << dineroPreferencial << endl;
}

int main() {
	
	vector<Venta> ventas;
    char continuar;

    int entradasSol = 0;
    double dineroSol = 0.0;
    int entradasSombra = 0;
    double dineroSombra = 0.0;
    int entradasPreferencial = 0;
    double dineroPreferencial = 0.0;

    do {
        Venta venta;

        cout << "Ingrese numero de factura: ";
        cin >> venta.numeroFactura;
        cout << "Ingrese cedula: ";
        cin >> venta.cedula;
        cout << "Ingrese nombre del comprador: ";
        cin.ignore();
        getline(cin, venta.nombre);
        do {
            cout << "Ingrese localidad (1- Sol Norte/Sur, 2- Sombra Este/Oeste, 3- Preferencial): ";
            cin >> venta.localidad;
        } while (venta.localidad < 1 || venta.localidad > 3);
        do {
            cout << "Ingrese cantidad de entradas (maximo 4): ";
            cin >> venta.cantidadEntradas;
        } while (venta.cantidadEntradas < 1 || venta.cantidadEntradas > 4);

        switch (venta.localidad) {
            case 1:
                venta.precioPorEntrada = 10500;
                venta.nombreLocalidad = "Sol Norte/Sur";
                entradasSol += venta.cantidadEntradas;
                dineroSol += venta.precioPorEntrada * venta.cantidadEntradas;
                break;
            case 2:
                venta.precioPorEntrada = 20500;
                venta.nombreLocalidad = "Sombra Este/Oeste";
                entradasSombra += venta.cantidadEntradas;
                dineroSombra += venta.precioPorEntrada * venta.cantidadEntradas;
                break;
            case 3:
                venta.precioPorEntrada = 25500;
                venta.nombreLocalidad = "Preferencial";
                entradasPreferencial += venta.cantidadEntradas;
                dineroPreferencial += venta.precioPorEntrada * venta.cantidadEntradas;
                break;
        }

        venta.subtotal = venta.cantidadEntradas * venta.precioPorEntrada;
        venta.cargosServicios = venta.cantidadEntradas * 1000;
        venta.totalPagar = venta.subtotal + venta.cargosServicios;

        ventas.push_back(venta);

        cout << "\nDetalles de la venta:\n";
        cout << "Numero de Factura: " << venta.numeroFactura << endl;
        cout << "Cedula: " << venta.cedula << endl;
        cout << "Nombre Comprador: " << venta.nombre << endl;
        cout << "Localidad: " << venta.nombreLocalidad << endl;
        cout << "Cantidad de Entradas: " << venta.cantidadEntradas << endl;
        cout << "Subtotal: " << venta.subtotal << endl;
        cout << "Cargos por Servicios: " << venta.cargosServicios << endl;
        cout << "Total a Pagar: " << venta.totalPagar << endl;

        cout << "¿Desea registrar otra venta? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    mostrarEstadisticas(entradasSol, dineroSol, entradasSombra, dineroSombra, entradasPreferencial, dineroPreferencial);
	
	
	return 0;
}
