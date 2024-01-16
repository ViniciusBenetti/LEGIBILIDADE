#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

extern "C" {

const char* gradeC(const char *texto) {
    const char *grade;
    double S = 1.0, L = 1.0, letras = 0, frases = 0, palavras = 1;

    for (const char *ptr = texto; *ptr != '\0'; ++ptr) {
        char letra = *ptr;
        if (letra != ' ') {
            if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
                letras++;
            } else if (letra == '!' || letra == '?' || letra == '.') {
                frases++;
            }
        }
        if (letra == ' ') {
            palavras++;
        }
    }

    L = letras / palavras * 100;
    S = frases / palavras * 100;

    int score = static_cast<int>(std::round(0.0588 * L - 0.296 * S - 15.8));

    if (score > 16) {
        grade = "Score Muito Baixo";
    } else if (score >= 11) {
        grade = "Score Baixo";
    } else if (score >= 6) {
        grade = "Score Alto ";
    } else {
        grade = "Score muito Alto";
    }

    // Alocar memória para a string e copiar o conteúdo
    grade = strdup(grade);

    return grade;
}

}  // extern "C"

