#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


using namespace std;


struct Profesor {
    int tipo;
    int id_profesor;
    char CUI[14];
    char Nombre[25];
    char Curso[25];
};


struct Estudiante {
    int tipo;
    int id_estudiante;
    char CUI[14];
    char Nombre[25];
    char Carnet[25];
};


static string Ruta = "registro.dat";
static int i = 0, j = 0;


bool Existente(string file){
    FILE * archivo;
    if ((archivo = fopen(file.c_str(), "r"))){
        fclose(archivo);
        return true;
    }
    return false;
}


void crearArchivo(){
    if(!(Existente(Ruta))){
        FILE *file;
        char buff[2*1024];
        int tamano = (2*1024);
        for (int i=0; i < 1024; i++){
            buff[i] = '\0';
        }
        file = fopen(Ruta.c_str(), "wb");
        for (int i=0; i < tamano; i++){
            fwrite(&buff, 1, 1, file);
        }
        fclose(file);
        cout << "Archivo de Datos Creado con Exito!!!" << endl;
    } else {
        cout << "Archivo de Datos Abierto con Exito!!!" << endl;
    }
}


void showStudent(Estudiante student) {
    cout << "------------------------------------------------------------" << endl;
    cout << "                           Alumno                           " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "              ID: " + to_string(student.id_estudiante) << endl;
    cout << "              CUI: " << student.CUI << endl;
    cout << "              Nombre: " << student.Nombre << endl;
    cout << "              Carnet: " << student.Carnet << endl;
    cout << "------------------------------------------------------------" << endl;
}


void showProfesor(Profesor prof) {
    cout << "------------------------------------------------------------" << endl;
    cout << "                           Alumno                           " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "              ID: " + to_string(prof.id_profesor) << endl;
    cout << "              CUI: " << prof.CUI << endl;
    cout << "              Nombre: " << prof.Nombre << endl;
    cout << "              Curso: " << prof.Curso << endl;
    cout << "------------------------------------------------------------" << endl;
}


void registerProfesor(){
    Profesor prof, lectp;
    FILE *file;
    prof.tipo = 0;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                        ID Profesor                       *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> prof.id_profesor;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                   CUI Max 13 caracteres                  *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> prof.CUI;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                 Nombre Max 25 caracteres                 *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> prof.Nombre;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                  Curso Max 25 caracteres                 *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> prof.Curso;

    showProfesor(prof);
    file = fopen(Ruta.c_str(), "rb+");
    fseek(file, 0, SEEK_SET);
    fread(&lectp, sizeof(Profesor), 1, file);
    while ((strcmp(lectp.Curso, "") != 0)){
        fseek(file, i, SEEK_SET);
        fread(&lectp, sizeof(Profesor), 1, file);
        i += sizeof(Profesor);
    }
    fseek(file, i, SEEK_SET);
    fwrite(&prof, sizeof(Profesor), 1, file); // (puntero donde tiene los datos a escribir, tamano struct, numero de objetos a leer, archivo)
    fclose(file);
    cout << "Profesor " << prof.Nombre << " Agregado al Archivo!!!" << endl;
}


void registerStudent(){
    Estudiante est, lecte;
    FILE *file;
    est.tipo = 1;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                       ID Estudiante                      *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> est.id_estudiante;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                   CUI Max 13 caracteres                  *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> est.CUI;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                 Nombre Max 25 caracteres                 *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> est.Nombre;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Ingreso de Datos                     *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                 Carnet Max 10 caracteres                 *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    cin >> est.Carnet;

    showStudent(est);
    file = fopen(Ruta.c_str(), "rb+");
    fseek(file, 0, SEEK_SET);
    fread(&lecte, sizeof(Estudiante), 1, file);
    while ((strcmp(lecte.Carnet, "") != 0)){
        fseek(file, i, SEEK_SET);
        fread(&lecte, sizeof(Estudiante), 1, file);
        i += sizeof(Estudiante);
    }
    fseek(file, i, SEEK_SET);
    fwrite(&est, sizeof(Estudiante), 1, file);
    fclose(file);
    cout << "Estudiante " << est.Nombre << " Agregado al Archivo!!!" << endl;
}

void showRegs(){
    Estudiante lecte;
    Profesor lectp;
    FILE *file;
    int k = 0;
    cout << "*----------------------------------------------------------*" << endl;
    cout << "*                     Mostrar Registros                    *" << endl;
    cout << "*----------------------------------------------------------*" << endl;
    file = fopen(Ruta.c_str(), "rb+");
    fseek(file, 0, SEEK_SET);
    fread(&lectp, sizeof(Profesor), 1, file);
    while (k < 100) {
        fseek(file, j, SEEK_SET);
        fread(&lectp, sizeof(Profesor), 1, file);
        if(lectp.tipo == 1) {
            if(!(strcmp(lectp.Curso, "")==0)) {
                showProfesor(lectp);
            }
        } else if (lectp.tipo == 1) {
            if (!(strcmp(lectp.Carnet, "")==0)) {
                lecte.tipo = lectp.tipo;
                strcpy(lecte.Nombre, lectp.Nombre);
                strcpy(lecte.CUI, lectp.CUI);
                strcpy(lecte.Carnet, lectp.Curso);
                lecte.id_estudiante, lectp.id_profesor;
                showStudent(lecte);
            }
        }
        j += sizeof(Profesor);
        k++;
    }
} 


int main(){
    int option;
    crearArchivo();

    while (true) {
        cout << "1. Registro de Profesor"<<endl;
        cout << "2. Registro de Estudiante"<<endl;
        cout << "3. Ver Registros" <<endl;
        cout << "4. Salir" <<endl;

        cin >> option;

        switch (option) {
            case 1:
                registerProfesor();
                break;
            case 2:
                registerStudent();
                break;
            case 3:
                showRegs();
                break;
            case 4:
                return 0;
                break;
        }
    }
}
