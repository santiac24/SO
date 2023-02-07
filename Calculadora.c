#include <stdio.h>
#include <math.h>
#include <ctype.h>

float stack[8];

void impPila(void){ //Imprime la pila
    printf("---CALCULADORA---\n");
    printf("Pila: \n");
    for (int i = 0; i < 8; i++){ //Se hace un for para mostrar las posiciones de la pila
        printf("%d)", 8-i);
        printf("%f\n", stack[i]);
    }
    printf("\n");
}

void CargarPila(void){ //Sube los elementos una posicion en la fila
    for(int i = 7; i >= 0;i--){
        stack[i] = stack[i - 1];
    }
}

void DescargarPila(void){ //Baja los elementos una posicion en la fila
     int i = 0;
     do{
        stack[i - 1] = stack[i];
        i++;
     }while (i < 8);
}

void anadirAPila(float num){ //Agrega valores a la pila
    stack[7] = num;
    printf("\n\n");
}

void LimpiarPila(void){ //Limpia la pila
    for(int i = 0;i < 8; i++){
        stack[i] = 0;
    }
}

void printMenu(void){
    //Funcion para imprimir las opciones
    impPila();
    printf("Seleccione una opción:\n");
    printf("1. Ingresar un número\n");
    printf("2. Seleccione Operacion\n");
    printf("3. Limpiar último valor\n");
    printf("4. Limpiar toda la pila\n");
    printf("5. Salir\n");
    printf("\n");
}

/**/
int main(){
    int opc, aux, operacion; //Declaramos 3 variables que nos ayudaran con las selecciones de los menús
    float num, resultado = 0;
    char c;
    //Ciclo que imprime el menú principal
    do{
        printMenu();
        //while ((c = getchar()) != '\n' && c != EOF);
        if (scanf("%d", &aux) != 1 || aux > 5 || aux < 0){
            printf("Ingrese una opcion valida\n");
            printf("Intentalo nuevamente con un opcion valida\n");
        }else{
            opc = aux;
            if(opc == 1){
                if(stack[0] == 0){
                    printf("\n\n");
                    printf("Ingrese un número: \n\n");
                    if(scanf("%f",&num) != 1){
                        printf("El valor ingresado no es un numero \n");
                    }else{
                        DescargarPila();
                        anadirAPila(num);
                        printf("\n\n");
                    }
                
                }
                else{
                printf("\n\n");
                printf("Pila llena\n");
                printf("Elimine un valor o realice una operación para continuar\n\n");
                }
            }if(opc == 2){
            //Menú con las operaciones
                printf("\n");
                printf("-------------------------------------\n");
                printf("¿Qué operación desea hacer?\n");
                printf("1. Suma\n");
                printf("2. Resta\n");
                printf("3. Multiplicación\n");
                printf("4. División\n");
                printf("5. Potencia\n");
                printf("6. Raíz\n");
                printf("7. Seno\n");
                printf("8. Coseno\n");
                printf("9. Tangente\n");
                printf("-------------------------------------\n");
                printf("Seleccione la operacion a realizar: \n\n");
                scanf("%s", &operacion);

                switch (operacion){ //Se hace un switch con las opciones posibles de la calculadora
                case '1': //Suma
                    resultado = stack[6] + stack[7]; //Se hace la operacion con los valores que estan abajo en la pila
                    CargarPila(); //Se carga la pila
                    anadirAPila(resultado); //Se añade el resultado a la pila
                    printf("\n\n");
                    break; //Se aplica la misma logica en todas las operaciones
                case '2': //Resta
                    resultado = stack[6] - stack[7];
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                case '3': //Multiplicacion
                    resultado = stack[6] * stack[7];
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                case '4': //Division
                    if(stack[7] == 0){ //Si se divide por 0 saca error ya que esto no se puede hacer
                        printf("\n");
                        printf("Error matematico\n");
                        break;
                    }else
                    {
                        resultado = stack[6] / stack[7];
                        CargarPila();
                        anadirAPila(resultado);
                        printf("\n\n");
                        break;
                    }
                case '5': //Potencia
                    resultado = pow(stack[6],stack[7]);
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                case '6': //Raíz
                    if(stack[7] > 0){
                        resultado = sqrt(stack[7]);
                        CargarPila();
                        anadirAPila(resultado);
                        printf("\n\n");
                        break;
                    }else if(stack[7] < 0){ //Si el número es negativo saca error porque no hay raíz negativa
                        printf("\n");
                        printf("      Error Matematico \n");
                        break;
                    }
                case '7': //Seno
                    resultado = sin(stack[7]);
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                case '8': //Coseno
                    resultado = cos(stack[7]);
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                case '9': //Tangente
                if((int)stack[7] % 90 == 0){ //Sale error si la tangente es multiplo de 90, estos numeros no tienen tangente
                    printf("\n");
                    printf("Error matematico");
                    break;
                }else{
                    resultado = tan(stack[7]);
                    CargarPila();
                    anadirAPila(resultado);
                    printf("\n\n");
                    break;
                }default: //Si alguien pone un valor que no esta en el menú
                    printf("Hubo un error en la selección de la operación");
                    break;
                }                         


            //Se ponen las otras funcionalidades del menú principal
            }if(opc == 3){
                CargarPila();
                printf("\n");
            }if(opc == 4){
                LimpiarPila();
            }if(opc == 5){
                printf("Fin del programa...");
            }
        }
        
    }while(opc != 5);

}