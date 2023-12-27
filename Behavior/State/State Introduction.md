使用State对象改变自己行为的对象被称为Context对象；
相似的，使用Strategy对象改变自己行为的对象叫Context对象。
记住，Client和Context打交道。
在**状态模式**中，Context把 方法调用 委托给 当前的状态对象m_pState, 状态的变化是 ; 在策略模式中，Context使用的Strategy对象，是被当做**参数传递**过来的，或在Context对象被**创建时就被提供的**。


不管是状态模式还是策略模式，它们都是能 让一个对象在运行时改变其行为的 一种模式。


Reference:
+ https://www.cnblogs.com/ring1992/p/9593533.html
+ [状态模式 VS 策略模式](https://zhuanlan.zhihu.com/p/142056182)