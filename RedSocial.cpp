#include "RedSocial.h"

int buscarUsuario(const vector<Usuario>& usuarios, const string& username) {
    for (size_t i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].username == username) {
            return (int)i; 
        }
    }
    return -1; 
}

bool registrarUsuario(vector<Usuario>& usuarios, const string& user, const string& pass) {
    if (buscarUsuario(usuarios, user) != -1) {
        return false; 
    }
    Usuario nuevo;
    nuevo.username = user;
    nuevo.password = pass;
    usuarios.push_back(nuevo);
    return true;
}

int iniciarSesion(const vector<Usuario>& usuarios, const string& user, const string& pass) {
    int idx = buscarUsuario(usuarios, user);
    if (idx != -1 && usuarios[idx].password == pass) {
        return idx; 
    }
    return -1; 
}

void enviarSolicitudAmistad(vector<Usuario>& usuarios, int indexActual, const string& amigoUser) {
    int idxAmigo = buscarUsuario(usuarios, amigoUser);
    if (idxAmigo == -1) {
        cout << "El usuario no existe.\n";
        return;
    }
    if (idxAmigo == indexActual) {
        cout << "No puedes agregarte a ti mismo.\n";
        return;
    }

    usuarios[indexActual].amigos.push_back(amigoUser);
    usuarios[idxAmigo].amigos.push_back(usuarios[indexActual].username);
    cout << "¡Ahora eres amigo de " << amigoUser << "!\n";
}