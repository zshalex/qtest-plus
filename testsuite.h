#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QStringList>
#include <QMap>

#include "testcase.h"
#include "qtest-plus_global.h"

class QTESTPLUSSHARED_EXPORT TestSuite : public QObject
{
    Q_OBJECT
public:
    static TestSuite * instance();

    explicit TestSuite(QObject *parent = 0);

    void addTestCase(TestCase *testCase);

    bool execute(int argc, char** argv);

    inline int totalCount(){return m_totleCount;}
    inline int errorCount(){return m_errorCount;}
    inline int successCount(){return m_successCount;}
    inline int runCount(){return m_runCount;}
private:
    void loadArg(int argc, char** argv);
private:
    static TestSuite m_suite;
    static const char *optString;
    static const struct option longOpts[];

    QMap<QString, TestCase*> m_cases;
    int m_totleCount;
    int m_errorCount;
    int m_successCount;
    int m_runCount;
    QStringList m_errorTest;
    QStringList m_includeTest;
    QStringList m_excludeTest;
    QStringList m_runTest;
};

#endif // TESTSUITE_H
