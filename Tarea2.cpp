#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado {
    string cedula;
    string nombre;
    int tipo;
    int horasLaboradas;
    double precioPorHora;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

void mostrarEstadisticas(int cantidadOperarios, double acumuladoOperarios, int cantidadTecnicos, double acumuladoTecnicos, int cantidadProfesionales, double acumuladoProfesionales) {
    cout << "\nEstadisticas finales:\n";
    cout << "1) Cantidad Empleados Tipo Operarios: " << cantidadOperarios << endl;
    cout << "2) Acumulado Salario Neto para Operarios: " << acumuladoOperarios << endl;
    cout << "3) Promedio Salario Neto para Operarios: " << (cantidadOperarios > 0 ? acumuladoOperarios / cantidadOperarios : 0) << endl;
    cout << "4) Cantidad Empleados Tipo Tecnico: " << cantidadTecnicos << endl;
    cout << "5) Acumulado Salario Neto para Tecnicos: " << acumuladoTecnicos << endl;
    cout << "6) Promedio Salario Neto para Tecnicos: " << (cantidadTecnicos > 0 ? acumuladoTecnicos / cantidadTecnicos : 0) << endl;
    cout << "7) Cantidad Empleados Tipo Profesional: " << cantidadProfesionales << endl;
    cout << "8) Acumulado Salario Neto para Profesional: " << acumuladoProfesionales << endl;
    cout << "9) Promedio Salario Neto para Profesionales: " << (cantidadProfesionales > 0 ? acumuladoProfesionales / cantidadProfesionales : 0) << endl;
}


int main() {
	
	vector<Empleado> empleados;
    char continuar;

    int cantidadOperarios = 0;
    double acumuladoOperarios = 0.0;
    int cantidadTecnicos = 0;
    double acumuladoTecnicos = 0.0;
    int cantidadProfesionales = 0;
    double acumuladoProfesionales = 0.0;

    do {
        Empleado emp;

        cout << "Ingrese numero de cedula: ";
        cin >> emp.cedula;
        cout << "Ingrese nombre del empleado: ";
        cin.ignore();
        getline(cin, emp.nombre);
        do {
            cout << "Ingrese tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
            cin >> emp.tipo;
        } while (emp.tipo < 1 || emp.tipo > 3);
        cout << "Ingrese cantidad de horas laboradas: ";
        cin >> emp.horasLaboradas;
        cout << "Ingrese precio por hora: ";
        cin >> emp.precioPorHora;

        emp.salarioOrdinario = emp.horasLaboradas * emp.precioPorHora;

        switch (emp.tipo) {
            case 1:
                emp.aumento = emp.salarioOrdinario * 0.15;
                cantidadOperarios++;
                acumuladoOperarios += emp.salarioOrdinario;
                break;
            case 2:
                emp.aumento = emp.salarioOrdinario * 0.10;
                cantidadTecnicos++;
                acumuladoTecnicos += emp.salarioOrdinario;
                break;
            case 3:
                emp.aumento = emp.salarioOrdinario * 0.05;
                cantidadProfesionales++;
                acumuladoProfesionales += emp.salarioOrdinario;
                break;
        }

        emp.salarioBruto = emp.salarioOrdinario + emp.aumento;
        emp.deduccionCCSS = emp.salarioBruto * 0.0917;
        emp.salarioNeto = emp.salarioBruto - emp.deduccionCCSS;

        
        switch (emp.tipo) {
            case 1:
                acumuladoOperarios += emp.salarioNeto;
                break;
            case 2:
                acumuladoTecnicos += emp.salarioNeto;
                break;
            case 3:
                acumuladoProfesionales += emp.salarioNeto;
                break;
        }

        empleados.push_back(emp);

        cout << "\nDatos del Empleado:\n";
        cout << "Cedula: " << emp.cedula << endl;
        cout << "Nombre Empleado: " << emp.nombre << endl;
        cout << "Tipo Empleado: " << emp.tipo << endl;
        cout << "Salario por Hora: " << emp.precioPorHora << endl;
        cout << "Cantidad de Horas: " << emp.horasLaboradas << endl;
        cout << "Salario Ordinario: " << emp.salarioOrdinario << endl;
        cout << "Aumento: " << emp.aumento << endl;
        cout << "Salario Bruto: " << emp.salarioBruto << endl;
        cout << "Deduccion CCSS: " << emp.deduccionCCSS << endl;
        cout << "Salario Neto: " << emp.salarioNeto << endl;

        cout << "¿Desea registrar otro empleado? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    mostrarEstadisticas(cantidadOperarios, acumuladoOperarios, cantidadTecnicos, acumuladoTecnicos, cantidadProfesionales, acumuladoProfesionales);
	
	return 0;
}
