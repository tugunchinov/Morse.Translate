#include <backend.h>
#include <code.h>

Backend::Backend(QQuickItem* parent): QQuickItem(parent)
{}

QString Backend::input() const
{
    return m_input;
}

void Backend::changeInput(const QString& input)
{
    if (input == m_input) {
        return;
    }
    
    m_inputType = detectLanguage(input);
    
    m_input = input;
    if (m_inputType == ENGLISH) {
        m_outputType = MORSE;
        m_output = encode(input);
    } else {
        m_outputType = ENGLISH;
        m_output = decode(input);
    }

    emit inputChanged();
    emit outputChanged();
    emit inputTypeChanged();
    emit strInputTypeChanged();
    emit outputTypeChanged();
    emit strOutputTypeChanged();
}

void Backend::changeOutput(const QString& output)
{
    if (output == m_output) {
        return;
    }
    m_output = output;
    
    emit inputChanged();
    emit outputChanged();
}

Backend::IOtype Backend::inputType() const
{
    return m_inputType;
}

void Backend::changeInputType(IOtype inputType)
{
    if (inputType == m_inputType) {
        return;
    }
    
    m_inputType = inputType;
    emit inputTypeChanged();
    emit strInputTypeChanged();
}


QString Backend::output() const
{
    return m_output;
}

QString Backend::strInputType() const
{
    switch (m_inputType) {
        case ENGLISH:
            return "English";
        case MORSE:
            return "Morse";
    }
    
    return "";
}

Backend::IOtype Backend::outputType() const
{
    return m_outputType;
}

QString Backend::strOutputType() const
{
    switch (m_outputType) {
        case ENGLISH:
            return "English";
        case MORSE:
            return "Morse";
    }
    
    return "";
}

void Backend::changeOutputType(Backend::IOtype outputType)
{
    if (outputType == m_outputType) {
        return;
    }
    
    m_outputType = outputType;
    emit outputTypeChanged();
    emit strOutputTypeChanged();
}

#include <QDebug>

Backend::IOtype Backend::detectLanguage(const QString& text)
{
    if (text.isEmpty()) {
        return ENGLISH;
    }
    
    foreach (const QString& code, text.split(' ')) {
        if (!code.isEmpty() && morseToAlpha(code).isEmpty()) {
            return ENGLISH;
        }
    }
    
    return MORSE;
}
