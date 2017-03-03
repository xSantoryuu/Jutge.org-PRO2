#include <iostream>
#include <vector>
#include "Estudiant.hh"

vector<Estudiant> simplificarVectorEstudiants1(const vector<Estudiant>& v){
    // Pre: Un vector con o sin estudiantes repetidos pero válidos.
    // Post: Devuelve un vector con los estudiantes simplificados.

    int nEst = v.size();
    vector<Estudiant> vfinal(nEst);
    
    int u = 0;
    for(int i = 0; i < nEst; ++i){

        // Si el estudiante es igual al anterior (exceptuando el primer estudiante)
        if(i != 0 and v[i].Estudiant::consultar_DNI() == v[i-1].Estudiant::consultar_DNI()){

            // Si ambos tienen nota, modificar el final
            if(v[i].Estudiant::te_nota() and vfinal[u-1].Estudiant::te_nota() and v[i].Estudiant::consultar_nota() > vfinal[u-1].Estudiant::consultar_nota()){
                vfinal[u-1].Estudiant::modificar_nota(v[i].Estudiant::consultar_nota());
            
            // Si sólo el primero tiene nota nota, añadírsela al segundo
            } else if(v[i].Estudiant::te_nota() and !vfinal[u-1].Estudiant::te_nota()) {
                vfinal[u-1].Estudiant::afegir_nota(v[i].Estudiant::consultar_nota());
            }

        // Si el estudiante no es igual al anterior, añadir al estudiante con su nota (si es que tiene)
        } else {
            vfinal[u] = Estudiant(v[i].Estudiant::consultar_DNI());
            if(v[i].Estudiant::te_nota()) vfinal[u].Estudiant::afegir_nota(v[i].Estudiant::consultar_nota());
            ++u;
        }
    }

    return vfinal;
}

void simplificarVectorEstudiants2(vector<Estudiant>& v){
    int nEst = v.size();

    for(int i = 1; i < nEst; ++i){
        if(v[i].Estudiant::consultar_DNI() == v[i-1].Estudiant::consultar_DNI()){
            if(v[i].Estudiant::te_nota() and v[i-1].Estudiant::te_nota() and v[i].Estudiant::consultar_nota() > v[i-1].Estudiant::consultar_nota()){
                // Eliminar dni estudiante (FALTA)
            } else if (v[i].Estudiant::te_nota() and !v[i-1].Estudiant::te_nota()){
                // Eliminar dni estudiante (FALTA)
            }
        }
    }

}

void escribirVectorSimplificado(const vector<Estudiant>& v){
    // Pre: vector simplificado con un número de estudiantes menor al tamaño del vector, cuyos
    //      estudiantes vacíos contienen un dni con valor 0.
    // Post: Escribe los estudiantes no vacíos del vector.

    int i = 0;
    int nEst = v.size();
    bool finish = false;
    // Escribir estudiantes hasta que se acabe el vector o hasta que se acaben los estudiantes
    while(i < nEst and !finish){
        if(v[i].Estudiant::consultar_DNI() != 0) v[i].Estudiant::escriure();
        else finish = true;
        ++i;
    }
}

int main(){
    // Crear vector
    int nEst;
    std::cin >> nEst;
    vector<Estudiant> v(nEst);

    // Leer estudiantes
    for(int i = 0; i < nEst; ++i) v[i].Estudiant::llegir();

    // Simplificar
    simplificarVectorEstudiants2(v);

    // Escribir estudiantes
    escribirVectorSimplificado(v);    
}