#include <iostream>
#include <string>
#include <format>
#include <fstream>

void logMessage(std::string, int tag);
void logMessage(std::string message, std::string archivo, int linea);

enum TAGS {DEBUG, INFO, WARNING, ERROR, CRITICAL};
const std::string tagStrings[] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};

int main() {

    for (int i = DEBUG; i <= CRITICAL; i++) {
        logMessage(std::format("{} test message.", tagStrings[i]), i);
    }
    logMessage("Mensaje con error", 666);

    logMessage("Syntax Error", "ejercicio_1.cpp", 25);

    return 0;
}

// Ejercicio a
void logMessage(std::string message, int tag) {
    // Abre el archivo en modo append
    std::ofstream outFile("log.txt", std::ios::app);
    std::string tag_string;

    /* Checkea que el tag usado sea correcto, de lo contrario inserta un tag de error con el 
        mensaje de error*/
    if (tag >= DEBUG && tag <= CRITICAL) {
        tag_string = tagStrings[tag];

        if (outFile.is_open()) {
            outFile << std::format("[{}] <{}>\n", tag_string, message);
        } else {
            std::cerr << "Error abriendo archivo \n";
        }
    } else {
        logMessage(std::format("Intento de uso de logMessage invalido, TAG: {}, mensaje: {}", tag, message), ERROR);
    }
}

// Ejercicio b
void logMessage(std::string message, std::string archivo, int linea) {
    std::string errorMessage = std::format("{} en la linea {} del archivo {}", message, linea, archivo);
    logMessage(errorMessage, ERROR);
}