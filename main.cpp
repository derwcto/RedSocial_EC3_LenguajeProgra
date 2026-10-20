#include <iostream>
#include <vector>
#include "Usuario.h"
#include "RedSocial.h"

using namespace std;

void menuUsuario(vector<Usuario>& usuarios, int sesionActiva) {
    int opc;
    do {
        cout << "\n--- MENU DE RED SOCIAL ---\n";
        cout << "1. Ver mi perfil\n";
        cout << "2. Publicar estado\n";
        cout << "3. Agregar amigo\n";
        cout << "4. Cerrar sesion\n";
        cout << "Elige una opcion: ";
        cin >> opc;
        cin.ignore(); 

        if (opc == 1) {
            mostrarPerfil(usuarios[sesionActiva]);
        }
        else if (opc == 2) {
            string texto;
            cout << "Escribe tu publicacion: ";
            getline(cin, texto);
            agregarPublicacion(usuarios[sesionActiva], texto);
            cout << "¡Publicado con exito!\n";
        }
        else if (opc == 3) {
            string amigo;
            cout << "Ingresa el username de tu amigo: ";
            cin >> amigo;
            enviarSolicitudAmistad(usuarios, sesionActiva, amigo);
        }
    } while (opc != 4);
}

int main() {
    vector<Usuario> usuarios; 
    int opcion;

    do {
        cout << "\n=== PROTOTIPO RED SOCIAL (C++) ===\n";
        cout << "1. Registrarse\n";
        cout << "2. Iniciar Sesion\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string u, p;
            cout << "Nuevo usuario: ";
            cin >> u;
            cout << "Contrasena: ";
            cin >> p;
            if (registrarUsuario(usuarios, u, p)) {
                cout << "¡Registro exitoso!\n";
            }
            else {
                cout << "El usuario ya existe. Intenta con otro.\n";
            }
        }
        else if (opcion == 2) {
            string u, p;
            cout << "Usuario: ";
            cin >> u;
            cout << "Contrasena: ";
            cin >> p;
            int index = iniciarSesion(usuarios, u, p);
            if (index != -1) {
                cout << "¡Bienvenido, " << u << "!\n";
                menuUsuario(usuarios, index); 
            }
            else {
                cout << "Usuario o contraseña incorrectos.\n";
            }
        }
    } while (opcion != 3);

    cout << "Saliendo del programa...\n";
    return 0;
}