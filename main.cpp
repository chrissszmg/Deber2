
/* * Programa: currency_converter.cpp 
* Objetivo: Motor de cambio de divisas con sesiones y estadísticas 
* Tema: Lazos estructurados, acumuladores, estadísticas en tiempo real 
* Autor: Christian Morales*
 Fecha: 23/02/2026
 * IA utilizada: [Sí]- Uso de Chatgpt para correccion de codigo final y revision de funcionalidades requeridas en el deber] 
  * Decisiones de diseño: 
  * * - Uso de do-while para menú principal (garantiza al menos una ejecución) 
  * * - Inicialización de min con numeric_limits<double>::max() 
  * * - Validación de entrada numérica con try-catch o verificación manual */






#include <iostream>
#include <string>
// [AI-START] Se agregan librerias para validacion de entradas y formateo de salida
#include <cctype>
#include <iomanip>
#include <sstream>
// [AI-END] 
using namespace std;

// [AI-START] Guia de la estructura base y validación de entradas por parte del usuario
string pedirDivisa(const string& mensaje) {
    string divisa;

    while (true) {
        cout << mensaje;
        cin >> divisa;

      
        for (char &c : divisa) {
            c = toupper(static_cast<unsigned char>(c));
        }

        
        if (divisa.length() != 3 ||
            !isalpha(divisa[0]) ||
            !isalpha(divisa[1]) ||
            !isalpha(divisa[2])) {

            cout << "Error: la divisa debe tener exactamente 3 letras alfabeticas.\n";
        } else {
            break;
        }
    }
    return divisa;
}
// [AI-END] 

long double pedirNumeroPositivo(const string& mensaje) {
    long double valor;

    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail() && valor > 0 && cin.peek() == '\n') {
            break;
        }

        cout << "Error: el valor debe ser numerico y mayor a 0.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return valor;
}

// [AI-START] Ayuda para realizar el formateo de dinero y se muestre con comas y dos decimales
string formatearDinero(long double valor) {
    stringstream ss;
    ss << fixed << setprecision(2) << valor;
    string s = ss.str();

    size_t punto = s.find('.');
    for (int i = punto - 3; i > 0; i -= 3) {
        s.insert(i, ",");
    }
    return s;
}
// [AI-END] 
int main() {
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {

       
        string base = pedirDivisa("Ingrese la divisa base (3 letras): ");
        string cotizada = pedirDivisa("Ingrese la divisa cotizada (3 letras): ");

        cout << "Par seleccionado: " << base << "/" << cotizada << "\n\n";

        // [AI-START] Ayuda para pedir la tasa de cambio y validarla como un numero positivo
        long double tasa = pedirNumeroPositivo("Ingrese la tasa de cambio: ");
        cout << fixed << setprecision(4);
        cout << "Tasa capturada: " << tasa << "\n\n";
// [AI-END] 
       
        long double monto_base =
            pedirNumeroPositivo("Ingrese el monto en " + base + ": ");

        long double monto_convertido = monto_base * tasa;

       
        cin.ignore(10000, '\n');
        string timestamp;
        cout << "Ingrese el timestamp del snapshot (YYYY-MM-DD HH:MM:SS): ";
        getline(cin, timestamp);

        // [AI-START] Ayuda del formato de salida para el snapshot unicamente.
        cout << "\n===== MARKET SNAPSHOT =====\n";
        cout << "Par de divisas: " << base << "/" << cotizada << "\n";
        cout << "Timestamp: " << timestamp << "\n";
        cout << fixed << setprecision(4);
        cout << "Tasa: " << tasa << "\n";
        cout << "Monto Base (" << base << "): "
             << formatearDinero(monto_base) << "\n";
        cout << "Monto Convertido (" << cotizada << "): "
             << formatearDinero(monto_convertido) << "\n";
        cout << "===========================\n\n";

    
        cout << "Desea realizar otra conversion? (s/n): ";
        cin >> continuar;
        cin.ignore(10000, '\n');
    }
// [AI-END] 
    return 0;

}
