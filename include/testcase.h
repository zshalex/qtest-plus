/**
  @defgroup QTEST-PLUS
  @author Alex Zhao
  @version 1.0
  @date 2012-03-29
*/

#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>
#include <QTest>

#include "qtest-plus_global.h"

namespace ZSHALEX_QTEST_PLUS {

/**
  声明一个单元测试类的静态变量,并添加一个构造函数.
*/
#define DECLARE_TEST_CASE(type) \
    type(const QString &name):TestCase(name) {} \
    static type tc

/** @brief 初始化单元测试的静态变量.*/
#define INIT_TEST_CASE(type, name) \
    type type::tc(name)

/**
  单元测试的基类.在创建单元测试的实例时,TestCase会自动的将自己注册到
  TestSuite中去.
*/
class QTESTPLUSSHARED_EXPORT TestCase : public QObject
{
    Q_OBJECT
public:
    /**
      构造函数,向TestSuite中注册自己.
      @param name 单元测试的名称.
    */
    explicit TestCase(const QString &name);

    /**
      获取单元测试的名称.
      @return 单元测试的名称.
    */
    inline QString name() {return m_name;}
protected:
    QString m_name;
};

}

#endif // TESTCASE_H
