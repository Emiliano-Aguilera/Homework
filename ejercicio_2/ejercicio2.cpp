#include <iostream>
#include <string>
#include <format>
#include <fstream>

void logMessage(std::string, int tag); // logMessage normal
void logMessage(std::string message, std::string archivo, int linea); // logMessage error en linea de archivo
void logMessage(std::string message, std::string username); // logMessage seguridad de usuario

int test_logMessage();

// LAST no es valido, se usa para poder añadir nuevas tags sin necesidad de modificar el check
enum TAGS {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY, LAST};
const std::string tagStrings[] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL", "SECURITY"};

int main() {
    return test_logMessage();
}

// Ejercicio a
void logMessage(std::string message, int tag) {
    // Abre el archivo en modo append
    std::ofstream outFile("log.txt", std::ios::app);
    std::string tag_string;

    /* Checkea que el tag usado sea correcto, de lo contrario inserta un tag de error con el 
        mensaje de error*/
    if (tag >= DEBUG && tag < LAST) {
        tag_string = tagStrings[tag];

        if (outFile.is_open()) {
            outFile << std::format("[{}] <{}>\n", tag_string, message);
        } else {
            std::cerr << "Error abriendo archivo \n";
        }
    } else {
        std::string errorMessage = std::format(
            "Intento de uso de logMessage invalido, TAG: {}, mensaje: {}", tag, message);
        logMessage(errorMessage, ERROR);
    }
}

// Ejercicio b
// Ejercicio II
void logMessage(std::string message, std::string archivo, int linea) {
    std::string errorMessage = std::format("{} en la linea {} del archivo {}", message, linea, archivo);
    logMessage(errorMessage, ERROR);
}

// Ejercicio III
void logMessage(std::string message, std::string username){
    std::string accessMessage = std::format("{} to {}", message, username);
    logMessage(accessMessage, SECURITY);
}

// Ejercicio IV
int test_logMessage() {

    // Una entrada de cada tipo para logMessage (ejercicio a)
    for (int i = DEBUG; i <= CRITICAL; i++) {
        logMessage(std::format("{} test message.", tagStrings[i]), i);
    }

    // Una entrada con un tipo invalido, genera un log tipo ERROR
    logMessage("Mensaje con error", 666);

    // Una entrada de tipo ERROR que especifica la linea y el archivo (ejercicio b II)
    logMessage("Syntax Error", "ejercicio_1.cpp", 25);

    // Una entrada de tipo Security que loggea el acceso de un usuario (ejercicio b III)
    logMessage("Access Granted", "emiag");

    return 0;
}