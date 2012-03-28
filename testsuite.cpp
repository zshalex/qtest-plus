#include "testsuite.h"

TestSuite TestSuite::m_suite;

TestSuite::TestSuite(QObject *parent) :
    QObject(parent),
    m_totleCount(0),
    m_errorCount(0),
    m_successCount(0),
    m_runCount(0)
{
}

TestSuite * TestSuite::instance()
{
    return &m_suite;
}

void TestSuite::addTestCase(TestCase *testCase)
{
    m_cases.insert(testCase->name(),testCase);
}

bool TestSuite::execute(int argc, char **argv)
{
}
