#include <code.h>
#include <config.h>

QString alphaToMorse(const QString& symbol)
{
    return MORSE.value(symbol, "");
}

QString morseToAlpha(const QString& morseCode)
{
    return ALPHA.value(morseCode, "");
}

QString encode(const QString& text)
{
    QString encodedText;
    foreach (const QChar& symbol, text) {
        if (auto code = alphaToMorse(symbol.toUpper()); !code.isEmpty()) { // игнорируем незнакомые символы
            encodedText += code;
            encodedText += ' ';
        } else if (symbol == ' ') {
            encodedText += ' ';
        }
    }
    
    encodedText = encodedText.left(encodedText.size() - 1); // удалить пробел в конце
    
    return encodedText;
}

QString decode(const QString& encodedText)
{
    QString decodedText;
    foreach (const QString& code, encodedText.split(' ')) {
        auto alpha = morseToAlpha(code);
        decodedText += alpha;
        
        if (alpha.isEmpty()) {
            decodedText += ' '; // два пробела - новое слово (пробел не закодирован)
        }
    }
    
    return decodedText;
}
