#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include "Usuario.h"


int buscarUsuario(const vector<Usuario>& usuarios, const string& username);
bool registrarUsuario(vector<Usuario>& usuarios, const string& user, const string& pass);
int iniciarSesion(const vector<Usuario>& usuarios, const string& user, const string& pass);
void enviarSolicitudAmistad(vector<Usuario>& usuarios, int indexActual, const string& amigoUser);

#endif#pragma once
