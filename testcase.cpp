#include "testcase.h"
#include "testsuite.h"

TestCase::TestCase(const QString &name) :
    QObject(NULL),
    m_name(name)
{
    TestSuite::instance()->addTestCase(this);
}
