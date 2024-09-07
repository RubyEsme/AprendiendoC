#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int salir = 0;
char seleccion;

iniciarRegistro(){
    char nombreCompleto[48];
    int edad = 0;
    char sexo[12];
    char direccion[60];
    int telefono = 0;
    char email[50];

    printf("\nIngrese nombre de alumno completo (apellidos y nombre): ");
    getchar();
    scanf("%[^\n]%*c", &nombreCompleto);
    printf("\n");
    printf("Ingrese edad del alumno: ");
    scanf("%d", &edad);
    printf("\n");
    printf("Ingrese sexo del alumno (F, M, Femenino, Masculino) ");
    getchar();
    scanf("%[^\n]%*c", &sexo);
    printf("\n");
    printf("Ingrese direccion del alumno (domicilio) ");
    getchar();
    scanf("%[^\n]%*c", &direccion);
    printf("\n");
    printf("Ingrese telefono (movil o fijo) sin espacios ");
    scanf("%d", &telefono );
    printf("\n");
    printf("Ingrese el correo electronico  ");
    getchar();
    scanf("%[^\n]%*c", email);
    printf("\n");

    if(nombreCompleto && edad && sexo && direccion && telefono && email){
        printf("Iniciando proceso de insertar datos en documento");

        FILE * fpointer = fopen("registro.txt", "a");

        fprintf(fpointer, "\nNombre de alumno: %s\n" ,nombreCompleto);
        fprintf(fpointer, "Edad: %d\n" ,edad );
        fprintf(fpointer, "Sexo: %s\n" , sexo );
        fprintf(fpointer, "Direccion: %s\n" , direccion );
        fprintf(fpointer, "Telefono: %d\n" ,telefono );
        fprintf(fpointer, "Correo electronico: %s\n" , email );

        fclose(fpointer);

        printf("\nProceso de registro terminado \n");
    }else{
        printf("Falto algun dato, inicie nuevamente el proceso");
    }
    return 0;

}

int printRegister(){
    printf("Eligio opcion B, Estos son los registros hasta ahora: ");

    FILE * fpointer = fopen("registro.txt", "r");
    char line[3000];

    //toma linea por linea, por eso en un while para que vaya recorriendo una a la vez y asi imprima todo
    while(fgets(line,3000, fpointer )){
        printf("\n");
        printf("%s", line);
    }

    return 0;
}

int promedioEdades(){
    float sumaEdades = 0;
    float conteo = 0;
    float age = 0;
    char line[2000];
    float promedio = 0;

    FILE * fpointer = fopen("registro.txt", "r");

    //toma linea por linea, checar donde diga edad y asi acceder a el valor que tenga
    while (fgets(line, sizeof(line), fpointer)){
        if(strncmp(line, "Edad:", 5) == 0){
            age = atoi(line + 6);

            sumaEdades += age;
            conteo = conteo + 1;
        }
    }

    promedio = sumaEdades / conteo;

    fclose(fpointer);

    printf("El promedio de las edades de los alumnos es: %.2f", promedio);
    return 0;
}

int textoInicio(){
    printf("\t\t\tINSTITUTO POLITECNICO NACIONAL\t\t\n");
    printf("\tUNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAMPUS ZACATECAS\n");
    printf("\t\t\tZACATECAS, ZAC A 05 DE SEPTIEMBRE DE 2024\t\n");
    printf("\t\t\tELABORADO POR: RUBY ESMERALDA LOPEZ CORREA\n\n");
}

int ordenarDatos(){
    //desconozco de un orden ya sea mediante una funcion ya previamente hecha, osea libreria o algo que se refiera a un orden de la estructura, no logre esta funcion.
    return 0;
}

int main(){
    //menu del programa
    textoInicio();

    printf("-----------------SELECCION DEL PROGRAMA---------\n");
    printf("-------LETRAS CORRESPONDIENTES AL PROCESO A REALIZAR-----\n");
    printf("\n");
    printf("-------A) INICIAR REGISTRO0 \b\b B) IMPRIMIR DATOS  \n");
    printf("-------C) ORDENAR DATOS    \b\b D) MOSTRAR PROMEDIO DE EDADES\n");
    printf("------------- E) Salir de programa-------------\n");
    printf("\n");

    //usar while para mantener el programa ejecutandose hasta que de salir
    while(salir == 0){
        printf("\nPor favor seleccione alguna opcion del menu: ");
        scanf("%c", &seleccion);
        printf("\n");

        if(seleccion){
                if(seleccion == 'A' || seleccion == 'a'){

                printf("Selecciono la opcion A, Iniciaremos con el registro de alumno: \n");
                iniciarRegistro();

            } if ( seleccion == 'B' || seleccion == 'b' ){

                printf("Selecciono la opcion B");
                printRegister();

            }if ( seleccion == 'C' || seleccion == 'c' ){

                printf("Coming soon...");

            } if ( seleccion == 'D' || seleccion == 'd' ){
                promedioEdades();

            } if ( seleccion == 'E' || seleccion == 'e' ){
                salir = 1;
            }


        }else{
         printf("coloque una eleccion existente");
        }


    }

    printf("Ha seleccionado el salir del programa, Hasta luego!! \n �FIN DEL CURSO!");

}

/* olvide la estructura del switch:v
        switch(seleccion)
            case seleccion == 'A' || seleccion == 'a':
                printf("Selecciono la A, muy bien");
                salir = 1;
            break;
            case seleccion == 'B' || seleccion == 'b':
                printf("Selecciono la B");
                salir = 1;
            break;
            case seleccion == 'C' || seleccion == 'c':
                printf("Selecciono la C");
                salir = 1;
            break;
            case seleccion == 'D' || seleccion == 'd':
                printf("Selecciono la D");
                salir = 1;
            break;
            case seleccion == 'E' || seleccion == 'e':
                printf("Selecciono la E");
                salir = 1;
            break;

            default:
                printf("Por favor seleccione una opcion existente...");
                salir = 1;
*/
