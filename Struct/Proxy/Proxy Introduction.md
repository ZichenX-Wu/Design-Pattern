代理模式：为其他对象提供一种代理以控制对这个对象的访问。

代理模式分为四类：远程代理，虚代理，保护代理和智能引用。在下面使用场合会对这四种进行分别介绍。

Proxy

1. 保存一个引用使得代理可以访问实体。若RealSubject和Subject的接口相同，Proxy会引用Subject，就相当于在代理类中保存一个Subject指针，该指针会指向RealSubject；
2. 提供一个与Subject的接口相同的接口，这样代理就可以用来替代实体；
3. 控制对实体的存取，并可能负责创建和删除它；
4. 其它功能依赖于代理的类型，例如：
    远程代理负责对请求及其参数进行编码，并向不同地址空间中的实体发送已编码的请求；
    虚代理可以缓存实体的附加信息，以便延迟对它的访问；
    保护代理检查调用者是否具有实现一个请求所必须的访问权限。

Subject：定义RealSubject和Proxy的共用接口，这样就在任何使用RealSubject的地方都可以使用Proxy；

RealSubject：定义Proxy所代理的实体。

Reference:
+ https://www.cnblogs.com/ring1992/p/9593286.html