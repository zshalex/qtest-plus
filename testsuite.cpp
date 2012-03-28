#include <QtTest/QtTest>
#include <getopt.h>
#include <iostream>

#include "testsuite.h"

TestSuite TestSuite::m_suite;

const char* TestSuite::optString = "e:i:";

const struct option TestSuite::longOpts[] = {
    { "exclude", required_argument, NULL, 'e' },
    { "include", required_argument, NULL, 'i'},
    { NULL, no_argument, NULL, 0 }
};

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
    QString testName;
    QObject *obj;
    int result;
    loadArg(argc,argv);

    m_totleCount = m_cases.count();
    m_runCount = 0;
    m_errorCount = 0;
    m_successCount = 0;
    m_errorTest.clear();

    if (m_includeTest.count() > 0)
        m_runTest = m_includeTest;
    else
        m_runTest = m_cases.keys();

    for (int i = 0; i < m_excludeTest.count(); i++) {
        m_runTest.removeAll(m_excludeTest.at(i));
    }

    for (int i = 0; i < m_runTest.count(); i++) {
        obj = m_cases.value(m_runTest.at(i));
        if (obj) {
            m_runCount++;
            try
            {
                result = QTest::qExec(obj);
                if (result > 0) {
                    m_errorCount++;
                    m_errorTest.append(m_runTest.at(i));
                } else {
                    m_successCount++;
                }
            } catch(...) {

            }
        }
    }
    printf("Total: Success %d, Fail %d, Skip %d.\n",m_successCount,m_errorTest.count(),m_totleCount - m_successCount - m_errorTest.count());
    for (int i = 0; i < m_errorTest.count(); i++) {
        printf("Error Test Case %s. \n", m_errorTest.at(i).toAscii().data());
    }
    return m_errorTest.count() > 0 ? -1 : 0;
}

void TestSuite::loadArg(int argc, char **argv)
{
    int longIndex;
    QString context;
    m_includeTest.clear();
    m_excludeTest.clear();

    int opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    while( opt != -1 ) {
        switch( opt ) {
            case 'i':
                context = optarg;
                if (!context.isEmpty())
                    m_includeTest = context.split(" ");
                break;
            case 'e':
                context = optarg;
                if (!context.isEmpty())
                    m_excludeTest = context.split(" ");
                break;
            default:
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex);
    }
}
