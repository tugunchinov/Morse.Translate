#ifndef CODE_HPP
#define CODE_HPP

#include <QString>

QString alphaToMorse(const QString& symbol);
QString morseToAlpha(const QString& morseCode);

QString encode(const QString& text);
QString decode(const QString& encodedText);

#endif