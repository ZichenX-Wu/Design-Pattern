双重分发

+ accept 调用方法是 element.accept(visitor)
+ visit 调用方法是visitor.visit(element)

将处理算法从数据结构中分离出来
+ 易于增加Visitor (方便多种visitor 访问element, 以不同的操作)
+ 难以增加Element
+ Element必须向Visitor公开足够的信息

Reference:
+ https://www.cnblogs.com/ring1992/p/9593591.html
+ https://blog.csdn.net/kenjianqi1647/article/details/119632572