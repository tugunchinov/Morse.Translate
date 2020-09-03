#ifndef BACKEND_H
#define BACKEND_H

#include <QQuickItem>
#include <QString>
#include <qqml.h>

#include <QDebug>

class Backend: public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QString input READ input WRITE changeInput NOTIFY inputChanged)
    Q_PROPERTY(QString output READ output WRITE changeOutput NOTIFY outputChanged)
    Q_PROPERTY(IOtype inputType READ inputType WRITE changeInputType NOTIFY inputTypeChanged)
    Q_PROPERTY(QString strInputType READ strInputType NOTIFY strInputTypeChanged)
    Q_PROPERTY(IOtype outputType READ outputType WRITE changeOutputType NOTIFY outputTypeChanged)
    Q_PROPERTY(QString strOutputType READ strOutputType NOTIFY strOutputTypeChanged)
public:
    enum IOtype {
        ENGLISH,
        MORSE
    };
    Q_ENUM(IOtype)
    
    explicit Backend(QQuickItem* parent = nullptr);

    [[nodiscard]] QString input() const;
    [[nodiscard]] QString output() const;
    [[nodiscard]] IOtype inputType() const;
    [[nodiscard]] QString strInputType() const;
    [[nodiscard]] IOtype outputType() const;
    [[nodiscard]] QString strOutputType() const;
    
    [[nodiscard]] static IOtype detectLanguage(const QString& text);
    
public slots:
    void changeInput(const QString& input);
    void changeOutput(const QString& output);
    void changeInputType(IOtype inputType);
    void changeOutputType(IOtype outputType);

signals:
    void inputChanged();
    void outputChanged();
    void inputTypeChanged();
    void outputTypeChanged();
    void strInputTypeChanged();
    void strOutputTypeChanged();

private:
    QString m_input;
    QString m_output;
    IOtype m_inputType = ENGLISH;
    IOtype m_outputType = MORSE;
};

#endif //BACKEND_H
