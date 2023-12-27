使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，直到有一个对象处理它为止；



使用场合
+ 有多个的对象可以处理一个请求，由哪个对象处理该请求是在运行时刻自动确定的；
+ 如果想在不明确指定接收者的情况下，向多个对象中的一个提交一个请求；
+ 可以处理一个请求的对象集合应被动态指定。

优缺点
1. 降低耦合度；职责链模式使得一个对象不用知道是哪一个对象处理它的请求。对象仅需要知道该请求会被正确的处理。接收者和发送者都没有对方的明确的信息，且链中的对象不需要知道链的结构；
2. 增强了给对象指派职责的灵活性；当在对象中分派职责时，职责链给你更多的灵活性。你可以通过在运行时对该链进行动态的增加或修改来增加或改变处理一个请求的那些职责；
3. 不保证被接受，既然一个请求没有明确的接收者，那么就不能保证它一定会被处理；该请求可能一直到链的末端都得不到处理。一个请求也可能因该链没有被正确配置而得不到处理。

职责链模式在实现时，需要处理好它的后继者的问题，就是说，如果我不处理这个请求，那么我将把这个请求发给谁去处理呢？同时，职责链模式在实现时，它的**链的形状并不是由职责链本身建立和维护的，而是由客户进行创建的**，由客户指定每一个处理者的后继者是谁。 (我们在代码里面创建对象时，指定对象的 **谁是谁的后继者**) ，这就大大的提高了职责链的灵活性。在实际中，我们也可以将职责链模式与组合模式相结合，一个构件的父构件可以作为它的后继者。

Reference:
+ https://www.cnblogs.com/ring1992/p/9593305.html