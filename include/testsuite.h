/** @file testsuite.h
*  @defgroup QTEST-PLUS
*  @author Alex Zhao
*  @version 1.0
*  @date 2012-03-29
*  @{
*/

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QStringList>
#include <QMap>

#include "testcase.h"
#include "qtest-plus_global.h"

/** @class TestSuite
*  单元测试套件.用于保存所有注册的单元测试,并控制单元测试的执行.
*/
class QTESTPLUSSHARED_EXPORT TestSuite : public QObject
{
    Q_OBJECT
public:
    /**
    *  单元测试套件的单体.
    *  @return 返回单元测试套件的单体.
    */
    static TestSuite * instance();

    explicit TestSuite(QObject *parent = 0);
    ~TestSuite();

    /**
    *  将单元测试注册到单元测试套件中
    *  @param testCase 需要注册的单元测试.
    */
    void addTestCase(TestCase *testCase);
    /**
    *  根据命令行参数执行套件中的单元测试.
    *  @param argc 参数个数
    *  @param argv 参数数组
    */
    int execute(int argc, char** argv);

    /**
    *  获取单元测试的总数.
    *  @return 单元测试的总数.
    */
    inline int totalCount(){return m_totleCount;}
    /**
    *  获取错误单元测试的个数.
    *  @return 错误单元测试的个数.
    */
    inline int errorCount(){return m_errorCount;}
    /**
    *  获取成功单元测试的个数.
    *  @return 成功单元测试的个数.
    */
    inline int successCount(){return m_successCount;}
    /**
    *  获取已经执行的单元测试的个数.
    *  @return 已经执行的单元测试的个数.
    */
    inline int runCount(){return m_runCount;}
private:
    void loadArg(int argc, char** argv);
    void filterTestCase();
    void analyseTestCase(TestCase *obj);
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

/**
  @}
*/

#endif // TESTSUITE_H
