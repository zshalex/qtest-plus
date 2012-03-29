#include "testcase.h"
#include "testsuite.h"

namespace ZSHALEX_QTEST_PLUS {

TestCase::TestCase(const QString &name) :
    QObject(NULL),
    m_name(name)
{
    TestSuite::instance()->addTestCase(this);
}

}
