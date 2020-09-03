#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QHash>
#include <QString>

// Коды отсюда: https://ru.wikipedia.org/wiki/%D0%90%D0%B7%D0%B1%D1%83%D0%BA%D0%B0_%D0%9C%D0%BE%D1%80%D0%B7%D0%B5
inline QHash<QString, QString> MORSE;
inline QHash<QString, QString> ALPHA;

void initDictionaries();

#endif
