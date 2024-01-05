在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。

Memento在这个过程中起到了载体的作用。
主要的交互对象是Originator和Caretaker。
Originator是我们服务的类;
Caretaker是保存一系列memnto的类;

Originator通过调用自身的saveStateToMemento()会生成一个新的Memento对象。我们需要把这个对象存入到Caretaker中。
Originator通过调用自身的restoreStateToMemento()来获取先前的Memento对象，但是该方法需要传入一个Memento对象，这个对象我们需要从Caretaker中get到。


优点：
1. 封装了对象的状态，使得可以在不破坏封装性的情况下恢复对象的状态。
2. 可以随时保存和恢复对象状态，这使得程序能够更加容易地进行“回滚”或“撤销”操作。
3. 同时也可以避免由于对象状态不对称而导致对象之间的错误协作。

缺点：
1. Memento在捕获对象状态时可能会消耗大量系统资源，特别是在状态较大的对象时可能会导致性能问题。
2. 由于Memento会保存对象状态的历史版本，因此它可能会导致大量的使用空间，从而影响程序的性能。

应用场景：
1. 当需要将对象状态恢复到之前的某个状态时，可以考虑使用Memento Pattern。
2. 当一个操作可能会导致对象的状态发生大量的变化，但同时可能需要进行“撤销”或“回滚”操作时，可以考虑使用Memento Pattern。
3. 当需要提供对象的“快照”或版本控制功能时，可以使用Memento Pattern。
4. 当需要记录对象状态的变化过程或历史版本时，可以使用Memento Pattern。


Reference:
+ https://zhuanlan.zhihu.com/p/636062329
+ https://www.cnblogs.com/ring1992/p/9593487.html