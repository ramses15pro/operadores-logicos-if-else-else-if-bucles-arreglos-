#include <iostream>
#include <iomanip> //setprecision :para mostar la nota con 1 decimal
using namespace std;

int main(){
    //----1. declaracion de variables----------------
    float nota; //nota del estudiante (0.0-5.0)
    int asistencia; //porcentaje de asistencia (0 a 100)
    int categoria; //1superior 2 alto 3 basico 4 bajo

    cout << fixed << setprecision(1);
    cout << "===CLASIFICADOR DE DESEMPEÑO ACADEMICO===" << endl << endl;

    //-------2. DATOS DE PRUEBA -------
    // Se usan valores predeterminados porque este entorno no proporciona
    // entrada interactiva durante la ejecución.
    nota = 4.5f;
    asistencia = 85;
    cout << "Datos usados: nota " << nota
         << ", asistencia " << asistencia << "%" << endl << endl;

    /*-------3. validacion por rangos---------
    usamos el operador logico // (0): basta con que UNA de las
    dos condiciones sea verdadera para que el dato sea invalido
    return 1 termina el programa indicando ERROR */
    if (nota < 0|| nota >5.0) {
        cout << "ERROR la nota debe estar entre 0.0 y 5.0 " << endl;
        return 1;
    }

    if (asistencia <0 || asistencia >100 ){
        cout << "ERROR la asistencia debe estar entre 0 y 100" << endl;
        return 1;
    }

    /*------------4.Clasificacion CON else if ----------------
    el orden IMPORTA: C++ evalua de arriba hacia abajoy se
    detiene en la primera condicion verdadera.por eso no hace
    falta escribir (nota >=4.6 && nota <= 5.0) en el primer caso  */
    if (nota >=4.6){
        categoria=1; // superior
    }else if (nota >=4.0 ){
        categoria=2; //alto
    }else if (nota>3.0){
        categoria=3; //basico
    }else {
        categoria=4; //bajo
    }

    /*-----------------5.CONDICIONAL ANIDADO-------------------
    un if dentro de otro if la regla instruccional dice que
    aunque la nota se aprobatoria (>=3.0) el estudiante
    reprueba si su asistencia es menor a 70%*/
    bool aprobado;

    if(nota>=3.0){
        if (asistencia >=70){
            aprobado=true;
        }else{
            aprobado=false; //nota buena pero baja asistencia
            categoria=4;
        }
    }else{
        aprobado=false;
    }

    /*--------6. Mensaje con switch case ----------
    switch solo funciona con valores EXACTOS de tipo entero o
    char, nunca con sus rangos. por eso primero convertimos el rangos de notas en la variable entera "categoria".
    sin break la ejecucion continua hasta el siguiente case */
    cout<<"-----------------------------"<<endl;
    cout<< "Nota registrada : " <<nota <<endl;
    cout<<"asistencia       : "<<asistencia<< "%" << endl;
    cout <<"desempeño       : ";

    switch(categoria){
        case 1:
            cout<<"Superior" << endl;
            cout<<"Excelente trabajo , mantenga el ritmo. " <<endl;
            break;

        case 2 :
            cout<<"ALTO"<<endl;
            cout<<"Muy buen resultado esta cerca del nivel superior" << endl;
            break;

        case 3:
            cout<<"basico"<< endl;
            cout<<"Aprobado , pero conviene reforzar los temas vistos."<< endl;
         break;

        case 4:
            cout<<"BAJO"<< endl;
            cout<<"DEBE presentar plan de mejoramiento" << endl;
            break;
        default:
            cout<<"SIN CLASIFICAR"<< endl;
    }
    //-------------7.RESULTADO FINAL (if-else simple)-------------------
    if(aprobado) {
        cout<<"Estado               : APROBADO "<<endl;
    }else{
        cout<<"Estado               : REPROBADO"<< endl;
    }
    cout<<"----------------------------------------------------------------------"<<endl;

    return 0;
}