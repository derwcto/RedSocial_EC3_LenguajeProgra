#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Publicacion {
    string contenido;
    string fecha;
};

struct Usuario {
    string username;
    string password;
    vector<Publicacion> posts;
    vector<string> amigos;
};

void mostrarPerfil(const Usuario& u);
void agregarPublicacion(Usuario& u, const string& texto);

#endif#pragma once
