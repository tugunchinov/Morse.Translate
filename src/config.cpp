#include <config.h>

void initMorse()
{
    MORSE = QHash<QString, QString>{
            {"A",  ".-"},
            {"B",  "-..."},
            {"C",  "-.-."},
            {"D",  "-.."},
            {"E",  "."},
            {"F",  "..-."},
            {"G",  "--."},
            {"H",  "...."},
            {"I",  ".."},
            {"J",  ".---"},
            {"K",  "-.-"},
            {"L",  ".-.."},
            {"M",  "--"},
            {"N",  "-."},
            {"O",  "---"},
            {"P",  ".--."},
            {"Q",  "--.-"},
            {"R",  ".-."},
            {"S",  "..."},
            {"T",  "-"},
            {"U",  "..-"},
            {"V",  "...-"},
            {"W",  ".--"},
            {"X",  "-..-"},
            {"Y",  "-.--"},
            {"Z",  "--.."},
            {".",  "......"},
            {"-",  "-....-"},
            {",",  ".-.-.-"},
            {";",  "-.-.-."},
            {"/",  "-..-."},
            {"\"", ".-..-."},
            {"?",  "..--.."},
            {"!",  "--..--"},
            {":",  "---..."},
            {"\'", ".----."}
    };
}

void initAlpha()
{
    foreach (const QString& symbol, MORSE.uniqueKeys()) {
        foreach (const QString& morse_code, MORSE.values(symbol)) {
            ALPHA[morse_code] = symbol;
        }
    }
}

void initDictionaries()
{
    initMorse();
    initAlpha();
}
