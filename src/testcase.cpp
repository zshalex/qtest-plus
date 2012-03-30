#include <QDebug>
#include <QMetaMethod>

#include "testcase.h"
#include "testsuite.h"

TestCase::TestCase(const QString &name) :
    QObject(NULL),
    m_name(name)
{
    TestSuite::instance()->addTestCase(this);
}

void TestCase::addMethod(QString name)
{
    m_methods.append(name);
}

int TestCase::methodCount()
{
    return m_methods.count();
}

QString TestCase::method(int index)
{
    return m_methods.at(index);
}
