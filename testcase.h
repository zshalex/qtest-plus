#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>

#include "qtest-plus_global.h"

#define DECLARE_TEST_CASE(type) \
    static type tc

#define INIT_TEST_CASE(type, name) \
    type type::tc(name)

#define CREATE_TEST_CASE(type) \
    type(const QString &name):TestCase(name) {}

class QTESTPLUSSHARED_EXPORT TestCase : public QObject
{
    Q_OBJECT
public:
    explicit TestCase(const QString &name);

    inline QString name() {return m_name;}
protected:
    QString m_name;
};

#endif // TESTCASE_H
