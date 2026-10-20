#include "Usuario.h"

void mostrarPerfil(const Usuario& u) {
    cout << "\n==============================\n";
    cout << " PERFIL: " << u.username << "\n";
    cout << " Amigos: " << u.amigos.size() << "\n";
    cout << " Publicaciones: " << u.posts.size() << "\n";
    cout << "==============================\n";
    cout << "Ultimos Posts:\n";
    if (u.posts.empty()) {
        cout << "(No hay publicaciones aun)\n";
    }
    else {
        for (int i = (int)u.posts.size() - 1; i >= 0; i--) {
            cout << "- " << u.posts[i].contenido << " (" << u.posts[i].fecha << ")\n";
        }
    }
    cout << "------------------------------\n";
}

void agregarPublicacion(Usuario& u, const string& texto) {
    Publicacion p;
    p.contenido = texto;
    p.fecha = "Hoy"; 
    u.posts.push_back(p);
}