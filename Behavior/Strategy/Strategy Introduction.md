## Strategy Pattern


使用场合:

当存在以下情况时使用Strategy模式：

+ 许多相关的类仅仅是行为有异。"策略"提供了一种用多个行为中的一个行为来配置一个类的方法；
+ 需要使用一个算法的不同变体；
+ 算法使用客户不应该知道的数据。可使用策略模式以避免暴露复杂的、与算法相关的数据结构；
+ 一个类定义了多种行为，并且这些行为在这个类的操作中以多个条件语句的形式出现。将相关的条件分支移入它们各自的Strategy类中以替代这些条件语句。（是不是和状态模式有点一样哦？）



### 代码解析

代码的核心:

类的设计:

+ 抽象策略
+ 具体策略A, 具体策略B, ...

+ Context
  + 抽象策略* m_strategy
  + ContextInterface(): m_strategy->StrategyInterface() //多态


使用方法:


Reference:
+ https://www.cnblogs.com/ring1992/p/9593575.html