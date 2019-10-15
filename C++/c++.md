

# C/C++

### const

#### 作用

1. 修饰变量，说明该变量不可以被改变；
2. 修饰指针，分为指向常量的指针和指针常量；
3. 常量引用，经常用于形参类型，即避免了拷贝，又避免了函数对值的修改；
4. 修饰成员函数，说明该成员函数内不能修改成员变量。

#### 使用

```c++
// 类
class A
{
private:
    const int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    A() : a(0) { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
};

void function()
{
    // 对象
    A b;                        // 普通对象，可以调用全部成员函数、更新常成员变量
    const A a;                  // 常对象，只能调用常成员函数
    const A *p = &a;            // 常指针
    const A &q = a;             // 常引用

    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量
    char* const p3 = greeting;          // 常指针，指向字符数组变量
    const char* const p4 = greeting;    // 常指针，指向字符数组常量
}

// 函数
void function1(const int Var);           // 传递过来的参数在函数内不可变
void function2(const char* Var);         // 参数指针所指内容为常量
void function3(char* const Var);         // 参数指针为常指针
void function4(const int& Var);          // 引用参数在函数内为常量

// 函数返回值
const int function5();      // 返回一个常数
const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();
```

### static

#### 作用

1. 修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，在 main 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
2. 修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命名空间里的函数重名，可以将函数定位为 static。
3. 修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。
4. 修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在 static 函数内不能访问非静态成员。

### this指针

1. `this` 指针是一个隐含于每一个非静态成员函数中的特殊指针。它指向调用该成员函数的那个对象。
2. 当对一个对象调用成员函数时，编译程序先将对象的地址赋给 `this` 指针，然后调用成员函数，每次成员函数存取数据成员时，都隐式使用 `this` 指针。
3. 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。
4. `this` 指针被隐含地声明为: `ClassName *const this`，这意味着不能给 `this` 指针赋值；在 `ClassName` 类的 `const` 成员函数中，`this` 指针的类型为：`const ClassName* const`，这说明不能对 `this` 指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）；
5. `this` 并不是一个常规变量，而是个右值，所以不能取得 `this` 的地址（不能 `&this`）。
6. 在以下场景中，经常需要显式引用this指针：
   1. 为实现对象的链式引用；
   2. 为避免对同一对象进行赋值操作；
   3. 在实现一些数据结构时，如 `list`。

### inline内联函数

#### 特征

- 相当于把内联函数里面的内容写在调用内联函数处；
- 相当于不用执行进入函数的步骤，直接执行函数体；
- 相当于宏，却比宏多了类型检查，真正具有函数特性；
- 编译器一般不内联包含循环、递归、switch 等复杂操作的内联函数；
- 在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数。

#### 使用

```c++
// 声明1（加 inline，建议使用）
inline int functionName(int first, int second,...);

// 声明2（不加 inline）
int functionName(int first, int second,...);

// 定义
inline int functionName(int first, int second,...) {/****/};

// 类内定义，隐式内联
class A {
    int doA() { return 0; }         // 隐式内联
}

// 类外定义，需要显式内联
class A {
    int doA();
}
inline int A::doA() { return 0; }   // 需要显式内联
```

#### 编译器对 inline 函数的处理步骤

1. 将 inline 函数体复制到 inline 函数调用点处；
2. 为所用 inline 函数中的局部变量分配内存空间；
3. 将 inline 函数的的输入参数和返回值映射到调用方法的局部变量空间中；
4. 如果 inline 函数有多个返回点，将其转变为 inline 函数代码块末尾的分支（使用 GOTO）。

#### 优缺点

##### 优点

1. 内联函数同宏函数一样将在被调用处进行代码展开，省去了参数压栈、栈帧开辟与回收，结果返回等，从而提高程序运行速度。
2. 内联函数相比宏函数来说，在代码展开时，会做安全检查或自动类型转换（同普通函数），而宏定义则不会。
3. 在类中声明同时定义的成员函数，自动转化为内联函数，因此内联函数可以访问类的成员变量，宏定义则不能。
4. 内联函数在运行时可调试，而宏定义不可以。

##### 缺点

1. 代码膨胀。内联是以代码膨胀（复制）为代价，消除函数调用带来的开销。如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。
2. inline 函数无法随着函数库升级而升级。inline函数的改变需要重新编译，不像 non-inline 可以直接链接。
3. 是否内联，程序员不可控。内联函数只是对编译器的建议，是否对函数内联，决定权在于编译器。

#### 虚函数（virtual）可以是内联函数（inline）吗？

[[详见该链接](http://www.cs.technion.ac.il/users/yechiel/c++-faq/inline-virtuals.html)]()

- 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
- 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
- `inline virtual` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 `Base::who()`），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

##### 虚函数内联使用

```c++
#include <iostream>  
using namespace std;
class Base
{
public:
    inline virtual void who()
    {
        cout << "I am Base\n";
    }
    virtual ~Base() {}
};
class Derived : public Base
{
public:
    inline void who()  // 不写inline时隐式内联
    {
        cout << "I am Derived\n";
    }
};

int main()
{
    // 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。 
    Base b;
    b.who();

    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。  
    Base *ptr = new Derived();
    ptr->who();

    // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
    delete ptr;
    ptr = nullptr;

    system("pause");
    return 0;
} 
```

### volatile

```c++
volatile int i = 10; 
```

- volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素（操作系统、硬件、其它线程等）更改。所以使用 volatile 告诉编译器不应对这样的对象进行优化。
- volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）
- const 可以是 volatile （如只读的状态寄存器）
- 指针可以是 volatile

### assert()

断言，是宏，而非函数。assert 宏的原型定义在 `<assert.h>`（C）、`<cassert>`（C++）中，其作用是如果它的条件返回错误，则终止程序执行。可以通过定义 `NDEBUG` 来关闭 assert，但是需要在源代码的开头，`include <assert.h>` 之前。

##### assert() 使用

```c++
#define NDEBUG          // 加上这行，则 assert 不可用
#include <assert.h>

assert( p != NULL );    // assert 不可用
```

### sizeof()

- sizeof 对数组，得到整个数组所占空间大小。
- sizeof 对指针，得到指针本身所占空间大小。

### #pragma pack(n)

设定结构体、联合以及类成员变量以 n 字节方式对齐

##### \#pragma pack(n) 使用

```c++
#pragma pack(push)  // 保存对齐状态
#pragma pack(4)     // 设定为 4 字节对齐

struct test
{
    char m1;
    double m4;
    int m3;
};

#pragma pack(pop)   // 恢复对齐状态
```

### 位域

```c++
Bit mode: 2;    // mode 占 2 位
```

类可以将其（非静态）数据成员定义为位域（bit-field），在一个位域中含有一定数量的二进制位。当一个程序需要向其他程序或硬件设备传递二进制数据时，通常会用到位域。

- 位域在内存中的布局是与机器有关的
- 位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定
- 取地址运算符（&）不能作用于位域，任何指针都无法指向类的位域

### extern"C"

- 被 extern 限定的函数或变量是 extern 类型的
- 被 `extern "C"` 修饰的变量和函数是按照 C 语言方式编译和链接的

`extern "C"` 的作用是让 C++ 编译器将 `extern "C"` 声明的代码当作 C 语言代码处理，可以避免 C++ 因符号修饰导致代码不能和C语言库中的符号进行链接的问题。

##### extern "C" 使用

```c++
#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *, int, size_t);

#ifdef __cplusplus
}
#endif
```

### struct  和  typedef struct

##### C中

```c
// c
typedef struct Student {
    int age; 
} S;
```

等价于

```c
// c
struct Student { 
    int age; 
};

typedef struct Student S;
```

此时 `S` 等价于 `struct Student`，但两个标识符名称空间不相同。

另外还可以定义与 `struct Student` 不冲突的 `void Student() {}`。

##### C++中

由于编译器定位符号的规则（搜索规则）改变，导致不同于C语言。

一、如果在类标识符空间定义了 `struct Student {...};`，使用 `Student me;` 时，编译器将搜索全局标识符表，`Student` 未找到，则在类标识符内搜索。

即表现为可以使用 `Student` 也可以使用 `struct Student`，如下：

```c++
// cpp
struct Student { 
    int age; 
};

void f( Student me );       // 正确，"struct" 关键字可省略
```

二、若定义了与 `Student` 同名函数之后，则 `Student` 只代表函数，不代表结构体，如下

```c++
typedef struct Student { 
    int age; 
} S;

void Student() {}           // 正确，定义后 "Student" 只代表此函数

//void S() {}               // 错误，符号 "S" 已经被定义为一个 "struct Student" 的别名

int main() {
    Student(); 
    struct Student me;      // 或者 "S me";
    return 0;
}
```

### C++中struct和class

总的来说，struct 更适合看成是一个数据结构的实现体，class 更适合看成是一个对象的实现体。

##### 区别

最本质的一个区别就是默认的访问控制

1. 默认的继承访问权限。struct 是 public 的，class 是 private 的。
2. struct 作为数据结构的实现体，它默认的数据访问控制是 public 的，而 class 作为对象的实现体，它默认的成员变量访问控制是 private 的。

### Union联合

联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

- 默认访问控制符为 public
- 可以含有构造函数、析构函数
- 不能含有引用类型的成员
- 不能继承自其他类，不能作为基类
- 不能含有虚函数
- 匿名 union 在定义所在作用域可直接访问 union 成员
- 匿名 union 不能包含 protected 成员或 private 成员
- 全局匿名联合必须是静态（static）的

##### union 使用

```c++
#include<iostream>

union UnionTest {
    UnionTest() : i(10) {};
    int i;
    double d;
};

static union {
    int i;
    double d;
};

int main() {
    UnionTest u;

    union {
        int i;
        double d;
    };

    std::cout << u.i << std::endl;  // 输出 UnionTest 联合的 10

    ::i = 20;
    std::cout << ::i << std::endl;  // 输出全局静态匿名联合的 20

    i = 30;
    std::cout << i << std::endl;    // 输出局部匿名联合的 30

    return 0;
}
```

### C实现C++类

C 实现 C++ 的面向对象特性（封装、继承、多态）

- 封装：使用函数指针把属性与方法封装到结构体中
- 继承：结构体嵌套
- 多态：父类与子类方法的函数指针不同

### explicit（显示）关键字

- explicit 修饰构造函数时，可以防止隐式转换和复制初始化
- explicit 修饰转换函数时，可以防止隐式转换，但 [按语境转换](https://zh.cppreference.com/w/cpp/language/implicit_conversion) 除外

##### explicit 使用

```c++
struct A
{
    A(int) { }
    operator bool() const { return true; }
};

struct B
{
    explicit B(int) {}
    explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main()
{
    A a1(1);        // OK：直接初始化
    A a2 = 1;        // OK：复制初始化
    A a3{ 1 };        // OK：直接列表初始化
    A a4 = { 1 };        // OK：复制列表初始化
    A a5 = (A)1;        // OK：允许 static_cast 的显式转换 
    doA(1);            // OK：允许从 int 到 A 的隐式转换
    if (a1);        // OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
    bool a6（a1）;        // OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
    bool a7 = a1;        // OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
    bool a8 = static_cast<bool>(a1);  // OK ：static_cast 进行直接初始化

    B b1(1);        // OK：直接初始化
    B b2 = 1;        // 错误：被 explicit 修饰构造函数的对象不可以复制初始化
    B b3{ 1 };        // OK：直接列表初始化
    B b4 = { 1 };        // 错误：被 explicit 修饰构造函数的对象不可以复制列表初始化
    B b5 = (B)1;        // OK：允许 static_cast 的显式转换
    doB(1);            // 错误：被 explicit 修饰构造函数的对象不可以从 int 到 B 的隐式转换
    if (b1);        // OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
    bool b6(b1);        // OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
    bool b7 = b1;        // 错误：被 explicit 修饰转换函数 B::operator bool() 的对象不可以隐式转换
    bool b8 = static_cast<bool>(b1);  // OK：static_cast 进行直接初始化

    return 0;
}
```

### friend友元类和友元函数

- 能访问私有成员
- 破坏封装性
- 友元关系不可传递
- 友元关系的单向性
- 友元声明的形式及数量不受限制

### using

#### using声明

一条 `using 声明` 语句一次只引入命名空间的一个成员。它使得我们可以清楚知道程序中所引用的到底是哪个名字。如：

```c++
using namespace_name::name;
```

#### 构造函数的using声明

在 C++11 中，派生类能够重用其直接基类定义的构造函数。

```c++
class Derived : Base {
public:
    using Base::Base;
    /* ... */
};
```

如上 using 声明，对于基类的每个构造函数，编译器都生成一个与之对应（形参列表完全相同）的派生类构造函数。生成如下类型构造函数：

```c++
Derived(parms) : Base(args) { }
```

#### using指示

`using 指示` 使得某个特定命名空间中所有名字都可见，这样我们就无需再为它们添加任何前缀限定符了。如：

```c++
using namespace_name name;
```

#### 尽量少使用 `using 指示` 污染命名空间

```markdown
一般说来，使用 using 命令比使用 using 编译命令更安全，这是由于它只导入了指定的名称。如果该名称与局部名称发生冲突，编译器将发出指示。using编译命令导入所有的名称，包括可能并不需要的名称。如果与局部名称发生冲突，则局部名称将覆盖名称空间版本，而编译器并不会发出警告。另外，名称空间的开放性意味着名称空间的名称可能分散在多个地方，这使得难以准确知道添加了哪些名称。
```

#### using使用

尽量少使用using指示

```c++
using namespace std;
```

多使用using声明

```c++
int x;
std::cin >> x ;
std::cout << x << std::endl;
```

或者

```c++
using std::cin;
using std::cout;
using std::endl;
int x;
cin >> x;
cout << x << endl;
```

### ::范围解析运算符

#### 分类

1. 全局作用域符（`::name`）：用于类型名称（类、类成员、成员函数、变量等）前，表示作用域为全局命名空间
2. 类作用域符（`class::name`）：用于表示指定类型的作用域范围是具体某个类的
3. 命名空间作用域符（`namespace::name`）:用于表示指定类型的作用域范围是具体某个命名空间的

##### ::使用

```c++
int count = 0;        // 全局（::）的 count

class A {
public:
    static int count; // 类 A 的 count（A::count）
};

int main() {
    ::count = 1;      // 设置全局的 count 的值为 1

    A::count = 2;     // 设置类 A 的 count 为 2

    int count = 0;    // 局部的 count
    count = 3;        // 设置局部的 count 的值为 3

    return 0;
}
```

### enum 枚举类型

#### 限定作用域的枚举类型

```c++
enum class open_modes { input, output, append };
```

#### 不限定作用域的枚举类型

```c++
enum color { red, yellow, green };
enum { floatPrec = 6, doublePrec = 10 };
```

#### decltype

decltype 关键字用于检查实体的声明类型或表达式的类型及值分类。语法：

```c++
decltype ( expression )
```

##### decltype 使用

```c++
// 尾置返回允许我们在参数列表之后声明返回类型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // 处理序列
    return *beg;    // 返回序列中一个元素的引用
}
// 为了使用模板参数成员，必须用 typename
template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
    // 处理序列
    return *beg;    // 返回序列中一个元素的拷贝
}
```



### 引用

#### 左值引用

常规引用，一般表示对象的身份。

#### 右值引用

右值引用就是必须绑定到右值（一个临时对象、将要销毁的对象）的引用，一般表示对象的值。

右值引用可实现转移语义（Move Sementics）和精确传递（Perfect Forwarding），它的主要目的有两个方面：

- 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
- 能够更简洁明确地定义泛型函数。

#### 引用折叠

- `X& &`、`X& &&`、`X&& &` 可折叠成 `X&`
- `X&& &&` 可折叠成 `X&&`

### 宏

宏定义可以实现类似于函数的功能，但是它终归不是函数，而宏定义中括弧中的“参数”也不是真的参数，在宏展开的时候对 “参数” 进行的是一对一的替换





### 成员初始化列表

#### 好处

- 更高效：少了一次调用默认构造函数的过程。
- 有些场合必须要用初始化列表：
  1. 常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
  2. 引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
  3. 没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化



### initializer_list 列表初始化

用花括号初始化器列表初始化一个对象，其中对应构造函数接受一个 

```
std::initializer_list 参数.
```

#### initializer_list使用

```c++
#include <iostream>
#include <vector>
#include <initializer_list>

template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // 在 return 语句中复制列表初始化
                                   // 这不使用 std::initializer_list
    }
};

template <typename T>
void templated_fn(T) {}

int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // 复制初始化
    s.append({6, 7, 8});      // 函数调用中的列表初始化

    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";

    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';

    std::cout << "Range-for over brace-init-list: \n";

    for (int x : {-1, -2, -3}) // auto 的规则令此带范围 for 工作
        std::cout << x << ' ';
    std::cout << '\n';

    auto al = {10, 11, 12};   // auto 的特殊规则

    std::cout << "The list bound to auto has size() = " << al.size() << '\n';

//    templated_fn({1, 2, 3}); // 编译错误！“ {1, 2, 3} ”不是表达式，
                             // 它无类型，故 T 无法推导
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // 也 OK
}

```

### 面向对象

面向对象程序设计（Object-oriented programming，OOP）是种具有对象概念的程序编程典范，同时也是一种程序开发的抽象方针。

![](https://raw.githubusercontent.com/huihut/interview/master/images/%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%9F%BA%E6%9C%AC%E7%89%B9%E5%BE%81.png)

面向对象三大特征 —— 封装、继承、多态

#### 封装

把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。关键字：public, protected, private。不写默认为 private。

- `public` 成员：可以被任意实体访问
- `protected` 成员：只允许被子类及本类的成员函数访问
- `private` 成员：只允许被本类的成员函数、友元类或友元函数访问

#### 继承

基类（父类）——> 派生类（子类）

#### 多态

- 多态，即多种状态（形态）。简单来说，我们可以将多态定义为消息以多种形式显示的能力。
- 多态是以封装和继承为基础的。
- C++ 多态分类及实现：
  1. 重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
  2. 子类型多态（Subtype Polymorphism，运行期）：虚函数
  3. 参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
  4. 强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换

##### 静态多态（编译器/早绑定）

函数重载

```c++
class A
{
public:
    void do(int a);
    void do(int a, int b);
};
```

##### 动态多态（运行期期/晚绑定）

- 虚函数：用 virtual 修饰成员函数，使其成为虚函数

**注意：**

- 普通函数（非类成员函数）不能是虚函数
- 静态函数（static）不能是虚函数
- 构造函数不能是虚函数（因为在调用构造函数时，虚表指针并没有在对象的内存空间中，必须要构造函数调用完成后才会形成虚表指针）
- 内联函数不能是表现多态性时的虚函数，解释见：[虚函数（virtual）可以是内联函数（inline）吗？](https://github.com/huihut/interview#%E8%99%9A%E5%87%BD%E6%95%B0virtual%E5%8F%AF%E4%BB%A5%E6%98%AF%E5%86%85%E8%81%94%E5%87%BD%E6%95%B0inline%E5%90%97)

动态多态的使用

```c++
class Shape                     // 形状类
{
public:
    virtual double calcArea()
    {
        ...
    }
    virtual ~Shape();
};
class Circle : public Shape     // 圆形类
{
public:
    virtual double calcArea();
    ...
};
class Rect : public Shape       // 矩形类
{
public:
    virtual double calcArea();
    ...
};
int main()
{
    Shape * shape1 = new Circle(4.0);
    Shape * shape2 = new Rect(5.0, 6.0);
    shape1->calcArea();         // 调用圆形类里面的方法
    shape2->calcArea();         // 调用矩形类里面的方法
    delete shape1;
    shape1 = nullptr;
    delete shape2;
    shape2 = nullptr;
    return 0;
}
```

#### 虚析构函数

虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。

虚析构函数使用

```c++
class Shape
{
public:
    Shape();                    // 构造函数不能是虚函数
    virtual double calcArea();
    virtual ~Shape();           // 虚析构函数
};
class Circle : public Shape     // 圆形类
{
public:
    virtual double calcArea();
    ...
};
int main()
{
    Shape * shape1 = new Circle(4.0);
    shape1->calcArea();    
    delete shape1;  // 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
    shape1 = NULL;
    return 0；
}
```

#### 纯虚函数

纯虚函数是一种特殊的虚函数，在基类中不能对虚函数给出有意义的实现，而把它声明为纯虚函数，它的实现留给该基类的派生类去做。

```cpp
virtual int A() = 0;
```

#### 虚函数、纯虚函数

- 类里如果声明了虚函数，这个函数是实现的，哪怕是空实现，它的作用就是为了能让这个函数在它的子类里面可以被覆盖（override），这样的话，编译器就可以使用后期绑定来达到多态了。纯虚函数只是一个接口，是个函数的声明而已，它要留到子类里去实现。
- 虚函数在子类里面可以不重写；但纯虚函数必须在子类实现才可以实例化子类。
- 虚函数的类用于 “实作继承”，继承接口的同时也继承了父类的实现。纯虚函数关注的是接口的统一性，实现由子类完成。
- 带纯虚函数的类叫抽象类，这种类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。抽象类被继承后，子类可以继续是抽象类，也可以是普通类。
- 虚基类是虚继承中的基类，具体见下文虚继承。

[CSDN . C++ 中的虚函数、纯虚函数区别和联系](https://blog.csdn.net/u012260238/article/details/53610462)

#### 虚函数指针、虚函数表

- 虚函数指针：在含有虚函数类的对象中，指向虚函数表，在运行时确定。
- 虚函数表：在程序只读数据段（`.rodata section`，见：[目标文件存储结构](https://interview.huihut.com/#/?id=%e7%9b%ae%e6%a0%87%e6%96%87%e4%bb%b6%e5%ad%98%e5%82%a8%e7%bb%93%e6%9e%84)），存放虚函数指针，如果派生类实现了基类的某个虚函数，则在虚表中覆盖原本基类的那个虚函数指针，在编译时根据类的声明创建。

[C++中的虚函数(表)实现机制以及用C语言对其进行的模拟实现](https://blog.twofei.com/496/)

#### 虚继承

虚继承用于解决多继承条件下的菱形继承问题（浪费存储空间、存在二义性）。

底层实现原理与编译器相关，一般通过**虚基类指针**和**虚基类表**实现，每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）和虚基类表（不占用类对象的存储空间）（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；当虚继承的子类被当做父类继承时，虚基类指针也会被继承。

实际上，vbptr 指的是虚基类表指针（virtual base table pointer），该指针指向了一个虚基类表（virtual table），虚表中记录了虚基类与本类的偏移地址；通过偏移地址，这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。

#### 虚继承、虚函数

- 相同之处：都利用了虚指针（均占用类的存储空间）和虚表（均不占用类的存储空间）
- 不同之处：
  - 虚继承
    - 虚基类依旧存在继承类中，只占用存储空间
    - 虚基类表存储的是虚基类相对直接继承类的偏移
  - 虚函数
    - 虚函数不占用存储空间
    - 虚函数表存储的是虚函数地址

#### 模板类、成员模板、虚函数

- 模板类中可以使用虚函数
- 一个类（无论是普通类还是类模板）的成员模板（本身是模板的成员函数）不能是虚函数

#### 抽象类、接口类、聚合类

- 抽象类：含有纯虚函数的类
- 接口类：仅含有纯虚函数的抽象类
- 聚合类：用户可以直接访问其成员，并且具有特殊的初始化语法形式。满足如下特点：
  - 所有成员都是 public
  - 没有定义任何构造函数
  - 没有类内初始化
  - 没有基类，也没有 virtual 函数

### 分配内存和管理

#### malloc、calloc、realloc、alloca

1. malloc：申请指定字节数的内存。申请到的内存中的初始值不确定。
2. calloc：为指定长度的对象，分配能容纳其指定个数的内存。申请到的内存的每一位（bit）都初始化为 0。
3. realloc：更改以前分配的内存长度（增加或减少）。当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定。
4. alloca：在栈上申请内存。程序在出栈的时候，会自动释放内存。但是需要注意的是，alloca 不具可移植性, 而且在没有传统堆栈的机器上很难实现。alloca 不宜使用在必须广泛移植的程序中。C99 中支持变长数组 (VLA)，可以用来替代 alloca。

#### malloc、free

用于分配、释放内存

malloc、free 使用

申请内存，确认是否申请成功

```cpp
char *str = (char*) malloc(100);
assert(str != nullptr);
```

释放内存后指针置空

```cpp
free(p); 
p = nullptr;
```

#### new、delete

1. new / new[]：完成两件事，先底层调用 malloc 分配了内存，然后调用构造函数（创建对象）。
2. delete/delete[]：也完成两件事，先调用析构函数（清理资源），然后底层调用 free 释放空间。
3. new 在申请内存时会自动计算所需字节数，而 malloc 则需我们自己输入申请内存空间的字节数。

new、delete 使用

申请内存，确认是否申请成功

```cpp
int main()
{
    T* t = new T();     // 先内存分配 ，再构造函数
    delete t;           // 先析构函数，再内存释放
    return 0;
}
```

#### 定位 new

定位 new（placement new）允许我们向 new 传递额外的地址参数，从而在预先指定的内存区域创建对象。

```cpp
new (place_address) type
new (place_address) type (initializers)
new (place_address) type [size]
new (place_address) type [size] { braced initializer list }
/*
 *place_address 是个指针
 *initializers 提供一个（可能为空的）以逗号分隔的初始值列表
 */
```

#### delete this合法吗[?](https://isocpp.org/wiki/faq/freestore-mgmt#delete-this)

合法，但：

1. 必须保证 this 对象是通过 `new`（不是 `new[]`、不是 placement new、不是栈上、不是全局、不是其他对象成员）分配的
2. 必须保证调用 `delete this` 的成员函数是最后一个调用 this 的成员函数
3. 必须保证成员函数的 `delete this` 后面没有调用 this 了
4. 必须保证 `delete this` 后没有人使用了

#### 如何定义一个只能在堆上（栈上）生成对象的类[?](https://www.nowcoder.com/questionTerminal/0a584aa13f804f3ea72b442a065a7618)

##### 只能在堆上

方法：将析构函数设置为私有

原因：C++ 是静态绑定语言，编译器管理栈上对象的生命周期，编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性。若析构函数不可访问，则不能在栈上创建对象。

##### 只能在栈上

方法：将 new 和 delete 重载为私有

原因：在堆上生成对象，使用 new 关键词操作，其过程分为两阶段：第一阶段，使用 new 在堆上寻找可用内存，分配给对象；第二阶段，调用构造函数生成对象。将 new 操作设置为私有，那么第一阶段就无法完成，就不能够在堆上生成对象。

### 智能指针

#### C++标准库（STL）中

```cpp
//头文件
#include<memory>
```

#### C++98

```cpp
std::auto_ptr<std::string> ps (new std::string(str))；
```

#### C++ 11

1. shared_ptr
2. unique_ptr
3. weak_ptr
4. auto_ptr（被 C++11 弃用）
5. Class shared_ptr 实现共享式拥有（shared ownership）概念。多个智能指针指向相同对象，该对象和其相关资源会在 “最后一个 reference 被销毁” 时被释放。为了在结构较复杂的情景中执行上述工作，标准库提供 weak_ptr、bad_weak_ptr 和 enable_shared_from_this 等辅助类。
6. Class unique_ptr 实现独占式拥有（exclusive ownership）或严格拥有（strict ownership）概念，保证同一时间内只有一个智能指针可以指向该对象。你可以移交拥有权。它对于避免内存泄漏（resource leak）——如 new 后忘记 delete ——特别有用。

##### shared_ptr

多个智能指针可以共享同一个对象，对象的最末一个拥有着有责任销毁对象，并清理与该对象相关的所有资源。

- 支持定制型删除器（custom deleter），可防范 Cross-DLL 问题（对象在动态链接库（DLL）中被 new 创建，却在另一个 DLL 内被 delete 销毁）、自动解除互斥锁

##### weak_ptr

weak_ptr 允许你共享但不拥有某对象，一旦最末一个拥有该对象的智能指针失去了所有权，任何 weak_ptr 都会自动成空（empty）。因此，在 default 和 copy 构造函数之外，weak_ptr 只提供 “接受一个 shared_ptr” 的构造函数。

- 可打破环状引用（cycles of references，两个其实已经没有被使用的对象彼此互指，使之看似还在 “被使用” 的状态）的问题

##### unique_ptr

unique_ptr 是 C++11 才开始提供的类型，是一种在异常时可以帮助避免资源泄漏的智能指针。采用独占式拥有，意味着可以确保一个对象和其相应的资源同一时间只被一个 pointer 拥有。一旦拥有着被销毁或编程 empty，或开始拥有另一个对象，先前拥有的那个对象就会被销毁，其任何相应资源亦会被释放。

- unique_ptr 用于取代 auto_ptr

##### auto_ptr

被 c++11 弃用，原因是缺乏语言特性如 “针对构造和赋值” 的 `std::move` 语义，以及其他瑕疵。

##### auto_ptr 与 unique_ptr 比较

- auto_ptr 可以赋值拷贝，复制拷贝后所有权转移；unqiue_ptr 无拷贝赋值语义，但实现了`move` 语义；
- auto_ptr 对象不能管理数组（析构调用 `delete`），unique_ptr 可以管理数组（析构调用 `delete[]` ）；

### [强制类型转换运算符](https://interview.huihut.com/#/?id=%e5%bc%ba%e5%88%b6%e7%b1%bb%e5%9e%8b%e8%bd%ac%e6%8d%a2%e8%bf%90%e7%ae%97%e7%ac%a6)

> [MSDN . 强制转换运算符](https://msdn.microsoft.com/zh-CN/library/5f6c9f8h.aspx)

#### [static_cast](https://interview.huihut.com/#/?id=static_cast)

- 用于非多态类型的转换
- 不执行运行时类型检查（转换安全性不如 dynamic_cast）
- 通常用于转换数值数据类型（如 float -> int）
- 可以在整个类层次结构中移动指针，子类转化为父类安全（向上转换），父类转化为子类不安全（因为子类可能有不在父类的字段或方法）

> 向上转换是一种隐式转换。

#### [dynamic_cast](https://interview.huihut.com/#/?id=dynamic_cast)

- 用于多态类型的转换
- 执行行运行时类型检查
- 只适用于指针或引用
- 对不明确的指针的转换将失败（返回 nullptr），但不引发异常
- 可以在整个类层次结构中移动指针，包括向上转换、向下转换

#### [const_cast](https://interview.huihut.com/#/?id=const_cast)

- 用于删除 const、volatile 和 __unaligned 特性（如将 const int 类型转换为 int 类型 ）

#### [reinterpret_cast](https://interview.huihut.com/#/?id=reinterpret_cast)

- 用于位的简单重新解释
- 滥用 reinterpret_cast 运算符可能很容易带来风险。 除非所需转换本身是低级别的，否则应使用其他强制转换运算符之一。
- 允许将任何指针转换为任何其他指针类型（如 `char*` 到 `int*` 或 `One_class*` 到 `Unrelated_class*` 之类的转换，但其本身并不安全）
- 也允许将任何整数类型转换为任何指针类型以及反向转换。
- reinterpret_cast 运算符不能丢掉 const、volatile 或 __unaligned 特性。
- reinterpret_cast 的一个实际用途是在哈希函数中，即，通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。

#### [bad_cast](https://interview.huihut.com/#/?id=bad_cast)

- 由于强制转换为引用类型失败，dynamic_cast 运算符引发 bad_cast 异常。

bad_cast 使用

```cpp
try {  
    Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);   
}  
catch (bad_cast b) {  
    cout << "Caught: " << b.what();  
} 
```

### [运行时类型信息 (RTTI)](https://interview.huihut.com/#/?id=%e8%bf%90%e8%a1%8c%e6%97%b6%e7%b1%bb%e5%9e%8b%e4%bf%a1%e6%81%af-rtti)

#### [dynamic_cast](https://interview.huihut.com/#/?id=dynamic_cast-1)

- 用于多态类型的转换

#### [typeid](https://interview.huihut.com/#/?id=typeid)

- typeid 运算符允许在运行时确定对象的类型
- type_id 返回一个 type_info 对象的引用
- 如果想通过基类的指针获得派生类的数据类型，基类必须带有虚函数
- 只能获取对象的实际类型

#### [type_info](https://interview.huihut.com/#/?id=type_info)

- type_info 类描述编译器在程序中生成的类型信息。 此类的对象可以有效存储指向类型的名称的指针。 type_info 类还可存储适合比较两个类型是否相等或比较其排列顺序的编码值。 类型的编码规则和排列顺序是未指定的，并且可能因程序而异。
- 头文件：`typeinfo`

typeid、type_info 使用

```cpp
class Flyable                       // 能飞的
{
public:
    virtual void takeoff() = 0;     // 起飞
    virtual void land() = 0;        // 降落
};
class Bird : public Flyable         // 鸟
{
public:
    void foraging() {...}           // 觅食
    virtual void takeoff() {...}
    virtual void land() {...}
};
class Plane : public Flyable        // 飞机
{
public:
    void carry() {...}              // 运输
    virtual void take off() {...}
    virtual void land() {...}
};

class type_info
{
public:
    const char* name() const;
    bool operator == (const type_info & rhs) const;
    bool operator != (const type_info & rhs) const;
    int before(const type_info & rhs) const;
    virtual ~type_info();
private:
    ...
};

class doSomething(Flyable *obj)                 // 做些事情
{
    obj->takeoff();

    cout << typeid(*obj).name() << endl;        // 输出传入对象类型（"class Bird" or "class Plane"）

    if(typeid(*obj) == typeid(Bird))            // 判断对象类型
    {
        Bird *bird = dynamic_cast<Bird *>(obj); // 对象转化
        bird->foraging();
    }

    obj->land();
};
```

## [⭐️ Effective](https://interview.huihut.com/#/?id=%e2%ad%90%ef%b8%8f-effective)

### [Effective C++](https://interview.huihut.com/#/?id=effective-c)

1. 视 C++ 为一个语言联邦（C、Object-Oriented C++、Template C++、STL）
2. 宁可以编译器替换预处理器（尽量以 `const`、`enum`、`inline` 替换 `#define`）
3. 尽可能使用 const
4. 确定对象被使用前已先被初始化（构造时赋值（copy 构造函数）比 default 构造后赋值（copy assignment）效率高）
5. 了解 C++ 默默编写并调用哪些函数（编译器暗自为 class 创建 default 构造函数、copy 构造函数、copy assignment 操作符、析构函数）
6. 若不想使用编译器自动生成的函数，就应该明确拒绝（将不想使用的成员函数声明为 private，并且不予实现）
7. 为多态基类声明 virtual 析构函数（如果 class 带有任何 virtual 函数，它就应该拥有一个 virtual 析构函数）
8. 别让异常逃离析构函数（析构函数应该吞下不传播异常，或者结束程序，而不是吐出异常；如果要处理异常应该在非析构的普通函数处理）
9. 绝不在构造和析构过程中调用 virtual 函数（因为这类调用从不下降至 derived class）
10. 令 `operator=` 返回一个 `reference to *this` （用于连锁赋值）
11. 在 `operator=` 中处理 “自我赋值”
12. 赋值对象时应确保复制 “对象内的所有成员变量” 及 “所有 base class 成分”（调用基类复制构造函数）
13. 以对象管理资源（资源在构造函数获得，在析构函数释放，建议使用智能指针，资源取得时机便是初始化时机（Resource Acquisition Is Initialization，RAII））
14. 在资源管理类中小心 copying 行为（普遍的 RAII class copying 行为是：抑制 copying、引用计数、深度拷贝、转移底部资源拥有权（类似 auto_ptr））
15. 在资源管理类中提供对原始资源（raw resources）的访问（对原始资源的访问可能经过显式转换或隐式转换，一般而言显示转换比较安全，隐式转换对客户比较方便）
16. 成对使用 new 和 delete 时要采取相同形式（`new` 中使用 `[]` 则 `delete []`，`new` 中不使用 `[]` 则 `delete`）
17. 以独立语句将 newed 对象存储于（置入）智能指针（如果不这样做，可能会因为编译器优化，导致难以察觉的资源泄漏）
18. 让接口容易被正确使用，不易被误用（促进正常使用的办法：接口的一致性、内置类型的行为兼容；阻止误用的办法：建立新类型，限制类型上的操作，约束对象值、消除客户的资源管理责任）
19. 设计 class 犹如设计 type，需要考虑对象创建、销毁、初始化、赋值、值传递、合法值、继承关系、转换、一般化等等。
20. 宁以 pass-by-reference-to-const 替换 pass-by-value （前者通常更高效、避免切割问题（slicing problem），但不适用于内置类型、STL迭代器、函数对象）
21. 必须返回对象时，别妄想返回其 reference（绝不返回 pointer 或 reference 指向一个 local stack 对象，或返回 reference 指向一个 heap-allocated 对象，或返回 pointer 或 reference 指向一个 local static 对象而有可能同时需要多个这样的对象。）
22. 将成员变量声明为 private（为了封装、一致性、对其读写精确控制等）
23. 宁以 non-member、non-friend 替换 member 函数（可增加封装性、包裹弹性（packaging flexibility）、机能扩充性）
24. 若所有参数（包括被this指针所指的那个隐喻参数）皆须要类型转换，请为此采用 non-member 函数
25. 考虑写一个不抛异常的 swap 函数
26. 尽可能延后变量定义式的出现时间（可增加程序清晰度并改善程序效率）
27. 尽量少做转型动作（旧式：`(T)expression`、`T(expression)`；新式：`const_cast<T>(expression)`、`dynamic_cast<T>(expression)`、`reinterpret_cast<T>(expression)`、`static_cast<T>(expression)`、；尽量避免转型、注重效率避免 dynamic_casts、尽量设计成无需转型、可把转型封装成函数、宁可用新式转型）
28. 避免使用 handles（包括 引用、指针、迭代器）指向对象内部（以增加封装性、使 const 成员函数的行为更像 const、降低 “虚吊号码牌”（dangling handles，如悬空指针等）的可能性）
29. 为 “异常安全” 而努力是值得的（异常安全函数（Exception-safe functions）即使发生异常也不会泄露资源或允许任何数据结构败坏，分为三种可能的保证：基本型、强列型、不抛异常型）
30. 透彻了解 inlining 的里里外外（inlining 在大多数 C++ 程序中是编译期的行为；inline 函数是否真正 inline，取决于编译器；大部分编译器拒绝太过复杂（如带有循环或递归）的函数 inlining，而所有对 virtual 函数的调用（除非是最平淡无奇的）也都会使 inlining 落空；inline 造成的代码膨胀可能带来效率损失；inline 函数无法随着程序库的升级而升级）
31. 将文件间的编译依存关系降至最低（如果使用 object references 或 object pointers 可以完成任务，就不要使用 objects；如果能够，尽量以 class 声明式替换 class 定义式；为声明式和定义式提供不同的头文件）
32. 确定你的 public 继承塑模出 is-a（是一种）关系（适用于 base classes 身上的每一件事情一定适用于 derived classes 身上，因为每一个 derived class 对象也都是一个 base class 对象）
33. 避免遮掩继承而来的名字（可使用 using 声明式或转交函数（forwarding functions）来让被遮掩的名字再见天日）
34. 区分接口继承和实现继承（在 public 继承之下，derived classes 总是继承 base class 的接口；pure virtual 函数只具体指定接口继承；非纯 impure virtual 函数具体指定接口继承及缺省实现继承；non-virtual 函数具体指定接口继承以及强制性实现继承）
35. 考虑 virtual 函数以外的其他选择（如 Template Method 设计模式的 non-virtual interface（NVI）手法，将 virtual 函数替换为 “函数指针成员变量”，以 `tr1::function` 成员变量替换 virtual 函数，将继承体系内的 virtual 函数替换为另一个继承体系内的 virtual 函数）
36. 绝不重新定义继承而来的 non-virtual 函数
37. 绝不重新定义继承而来的缺省参数值，因为缺省参数值是静态绑定（statically bound），而 virtual 函数却是动态绑定（dynamically bound）
38. 通过复合塑模 has-a（有一个）或 “根据某物实现出”（在应用域（application domain），复合意味 has-a（有一个）；在实现域（implementation domain），复合意味着 is-implemented-in-terms-of（根据某物实现出））
39. 明智而审慎地使用 private 继承（private 继承意味着 is-implemented-in-terms-of（根据某物实现出），尽可能使用复合，当 derived class 需要访问 protected base class 的成员，或需要重新定义继承而来的时候 virtual 函数，或需要 empty base 最优化时，才使用 private 继承）
40. 明智而审慎地使用多重继承（多继承比单一继承复杂，可能导致新的歧义性，以及对 virtual 继承的需要，但确有正当用途，如 “public 继承某个 interface class” 和 “private 继承某个协助实现的 class”；virtual 继承可解决多继承下菱形继承的二义性问题，但会增加大小、速度、初始化及赋值的复杂度等等成本）
41. 了解隐式接口和编译期多态（class 和 templates 都支持接口（interfaces）和多态（polymorphism）；class 的接口是以签名为中心的显式的（explicit），多态则是通过 virtual 函数发生于运行期；template 的接口是奠基于有效表达式的隐式的（implicit），多态则是通过 template 具现化和函数重载解析（function overloading resolution）发生于编译期）
42. 了解 typename 的双重意义（声明 template 类型参数是，前缀关键字 class 和 typename 的意义完全相同；请使用关键字 typename 标识嵌套从属类型名称，但不得在基类列（base class lists）或成员初值列（member initialization list）内以它作为 base class 修饰符）
43. 学习处理模板化基类内的名称（可在 derived class templates 内通过 `this->` 指涉 base class templates 内的成员名称，或藉由一个明白写出的 “base class 资格修饰符” 完成）
44. 将与参数无关的代码抽离 templates（因类型模板参数（non-type template parameters）而造成代码膨胀往往可以通过函数参数或 class 成员变量替换 template 参数来消除；因类型参数（type parameters）而造成的代码膨胀往往可以通过让带有完全相同二进制表述（binary representations）的实现类型（instantiation types）共享实现码）
45. 运用成员函数模板接受所有兼容类型（请使用成员函数模板（member function templates）生成 “可接受所有兼容类型” 的函数；声明 member templates 用于 “泛化 copy 构造” 或 “泛化 assignment 操作” 时还需要声明正常的 copy 构造函数和 copy assignment 操作符）
46. 需要类型转换时请为模板定义非成员函数（当我们编写一个 class template，而它所提供之 “与此 template 相关的” 函数支持 “所有参数之隐式类型转换” 时，请将那些函数定义为 “class template 内部的 friend 函数”）
47. 请使用 traits classes 表现类型信息（traits classes 通过 templates 和 “templates 特化” 使得 “类型相关信息” 在编译期可用，通过重载技术（overloading）实现在编译期对类型执行 if...else 测试）
48. 认识 template 元编程（模板元编程（TMP，template metaprogramming）可将工作由运行期移往编译期，因此得以实现早期错误侦测和更高的执行效率；TMP 可被用来生成 “给予政策选择组合”（based on combinations of policy choices）的客户定制代码，也可用来避免生成对某些特殊类型并不适合的代码）
49. 了解 new-handler 的行为（set_new_handler 允许客户指定一个在内存分配无法获得满足时被调用的函数；nothrow new 是一个颇具局限的工具，因为它只适用于内存分配（operator new），后继的构造函数调用还是可能抛出异常）
50. 了解 new 和 delete 的合理替换时机（为了检测运用错误、收集动态分配内存之使用统计信息、增加分配和归还速度、降低缺省内存管理器带来的空间额外开销、弥补缺省分配器中的非最佳齐位、将相关对象成簇集中、获得非传统的行为）
51. 编写 new 和 delete 时需固守常规（operator new 应该内涵一个无穷循环，并在其中尝试分配内存，如果它无法满足内存需求，就应该调用 new-handler，它也应该有能力处理 0 bytes 申请，class 专属版本则还应该处理 “比正确大小更大的（错误）申请”；operator delete 应该在收到 null 指针时不做任何事，class 专属版本则还应该处理 “比正确大小更大的（错误）申请”）
52. 写了 placement new 也要写 placement delete（当你写一个 placement operator new，请确定也写出了对应的 placement operator delete，否则可能会发生隐微而时断时续的内存泄漏；当你声明 placement new 和 placement delete，请确定不要无意识（非故意）地遮掩了它们地正常版本）
53. 不要轻忽编译器的警告
54. 让自己熟悉包括 TR1 在内的标准程序库（TR1，C++ Technical Report 1，C++11 标准的草稿文件）
55. 让自己熟悉 Boost（准标准库）

### [More Effective c++](https://interview.huihut.com/#/?id=more-effective-c)

1. 仔细区别 pointers 和 references（当你知道你需要指向某个东西，而且绝不会改变指向其他东西，或是当你实现一个操作符而其语法需求无法由 pointers 达成，你就应该选择 references；任何其他时候，请采用 pointers）
2. 最好使用 C++ 转型操作符（`static_cast`、`const_cast`、`dynamic_cast`、`reinterpret_cast`）
3. 绝不要以多态（polymorphically）方式处理数组（多态（polymorphism）和指针算术不能混用；数组对象几乎总是会涉及指针的算术运算，所以数组和多态不要混用）
4. 非必要不提供 default constructor（避免对象中的字段被无意义地初始化）
5. 对定制的 “类型转换函数” 保持警觉（单自变量 constructors 可通过简易法（explicit 关键字）或代理类（proxy classes）来避免编译器误用；隐式类型转换操作符可改为显式的 member function 来避免非预期行为）
6. 区别 increment/decrement 操作符的前置（prefix）和后置（postfix）形式（前置式累加后取出，返回一个 reference；后置式取出后累加，返回一个 const 对象；处理用户定制类型时，应该尽可能使用前置式 increment；后置式的实现应以其前置式兄弟为基础）
7. 千万不要重载 `&&`，`||` 和 `,` 操作符（`&&` 与 `||` 的重载会用 “函数调用语义” 取代 “骤死式语义”；`,` 的重载导致不能保证左侧表达式一定比右侧表达式更早被评估）
8. 了解各种不同意义的 new 和 delete（`new operator`、`operator new`、`placement new`、`operator new[]`；`delete operator`、`operator delete`、`destructor`、`operator delete[]`）
9. 利用 destructors 避免泄漏资源（在 destructors 释放资源可以避免异常时的资源泄漏）
10. 在 constructors 内阻止资源泄漏（由于 C++ 只会析构已构造完成的对象，因此在构造函数可以使用 try...catch 或者 auto_ptr（以及与之相似的 classes） 处理异常时资源泄露问题）
11. 禁止异常流出 destructors 之外（原因：一、避免 terminate 函数在 exception 传播过程的栈展开（stack-unwinding）机制种被调用；二、协助确保 destructors 完成其应该完成的所有事情）
12. 了解 “抛出一个 exception” 与 “传递一个参数” 或 “调用一个虚函数” 之间的差异（第一，exception objects 总是会被复制（by pointer 除外），如果以 by value 方式捕捉甚至被复制两次，而传递给函数参数的对象则不一定得复制；第二，“被抛出成为 exceptions” 的对象，其被允许的类型转换动作比 “被传递到函数去” 的对象少；第三，catch 子句以其 “出现于源代码的顺序” 被编译器检验对比，其中第一个匹配成功者便执行，而调用一个虚函数，被选中执行的是那个 “与对象类型最佳吻合” 的函数）
13. 以 by reference 方式捕获 exceptions（可避免对象删除问题、exception objects 的切割问题，可保留捕捉标准 exceptions 的能力，可约束 exception object 需要复制的次数）
14. 明智运用 exception specifications（exception specifications 对 “函数希望抛出什么样的 exceptions” 提供了卓越的说明；也有一些缺点，包括编译器只对它们做局部性检验而很容易不经意地违反，与可能会妨碍更上层的 exception 处理函数处理未预期的 exceptions）
15. 了解异常处理的成本（粗略估计，如果使用 try 语句块，代码大约整体膨胀 5%-10%，执行速度亦大约下降这个数；因此请将你对 try 语句块和 exception specifications 的使用限制于非用不可的地点，并且在真正异常的情况下才抛出 exceptions）
16. 谨记 80-20 法则（软件的整体性能几乎总是由其构成要素（代码）的一小部分决定的，可使用程序分析器（program profiler）识别出消耗资源的代码）
17. 考虑使用 lazy evaluation（缓式评估）（可应用于：Reference Counting（引用计数）来避免非必要的对象复制、区分 operator[] 的读和写动作来做不同的事情、Lazy Fetching（缓式取出）来避免非必要的数据库读取动作、Lazy Expression Evaluation（表达式缓评估）来避免非必要的数值计算动作）
18. 分期摊还预期的计算成本（当你必须支持某些运算而其结构几乎总是被需要，或其结果常常被多次需要的时候，over-eager evaluation（超急评估）可以改善程序效率）

### STL

#### STL方法[索引](https://github.com/huihut/interview/tree/master/STL)

#### STL容器

| 容器                                                         | 底层数据结构      | 时间复杂度                                                | 有无序 | 可不可重复 | 其他                                                         |
| ------------------------------------------------------------ | ----------------- | --------------------------------------------------------- | ------ | ---------- | ------------------------------------------------------------ |
| [array](https://github.com/huihut/interview/tree/master/STL#array) | 数组              | 随机读改 O(1)                                             | 无序   | 可重复     | 支持随机访问                                                 |
| [vector](https://github.com/huihut/interview/tree/master/STL#vector) | 数组              | 随机读改、尾部插入、尾部删除 O(1) 头部插入、头部删除 O(n) | 无序   | 可重复     | 支持随机访问                                                 |
| [deque](https://github.com/huihut/interview/tree/master/STL#deque) | 双端队列          | 头尾插入、头尾删除 O(1)                                   | 无序   | 可重复     | 一个中央控制器 + 多个缓冲区，支持首尾快速增删，支持随机访问  |
| [forward_list](https://github.com/huihut/interview/tree/master/STL#forward_list) | 单向链表          | 插入、删除 O(1)                                           | 无序   | 可重复     | 不支持随机访问                                               |
| [list](https://github.com/huihut/interview/tree/master/STL#list) | 双向链表          | 插入、删除 O(1)                                           | 无序   | 可重复     | 不支持随机访问                                               |
| [stack](https://github.com/huihut/interview/tree/master/STL#stack) | deque / list      | 顶部插入、顶部删除 O(1)                                   | 无序   | 可重复     | deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时 |
| [queue](https://github.com/huihut/interview/tree/master/STL#queue) | deque / list      | 尾部插入、头部删除 O(1)                                   | 无序   | 可重复     | deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时 |
| [priority_queue](https://github.com/huihut/interview/tree/master/STL#priority_queue) | vector + max-heap | 插入、删除 O(log2n)                                       | 有序   | 可重复     | vector容器+heap处理规则                                      |
| [set](https://github.com/huihut/interview/tree/master/STL#set) | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 不可重复   |                                                              |
| [multiset](https://github.com/huihut/interview/tree/master/STL#multiset) | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 可重复     |                                                              |
| [map](https://github.com/huihut/interview/tree/master/STL#map) | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 不可重复   |                                                              |
| [multimap](https://github.com/huihut/interview/tree/master/STL#multimap) | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 可重复     |                                                              |
| [unordered_set](https://github.com/huihut/interview/tree/master/STL#unordered_set) | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 不可重复   |                                                              |
| [unordered_multiset](https://github.com/huihut/interview/tree/master/STL#unordered_multiset) | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 可重复     |                                                              |
| [unordered_map](https://github.com/huihut/interview/tree/master/STL#unordered_map) | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 不可重复   |                                                              |
| [unordered_multimap](https://github.com/huihut/interview/tree/master/STL#unordered_multimap) | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 可重复     |                                                              |

### [STL 算法](https://interview.huihut.com/#/?id=stl-%e7%ae%97%e6%b3%95)

| 算法                                                         | 底层算法                                            | 时间复杂度 | 可不可重复 |
| ------------------------------------------------------------ | --------------------------------------------------- | ---------- | ---------- |
| [find](http://www.cplusplus.com/reference/algorithm/find/)   | 顺序查找                                            | O(n)       | 可重复     |
| [sort](https://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/include/bits/stl_algo.h#L4808) | [内省排序](https://en.wikipedia.org/wiki/Introsort) | O(n*log2n) | 可重复     |

# 易混淆

### 指针

#### 数组作为函数参数

 函数参数传递原则：实参到形参的单向值传递

##### 数组作为函数参数的不同情形

1、数组元素作为函数实参
	将数组元素的值传递给形参变量 

```cpp
int change ( int a){ 
 	int b=rand();
 	a=b+a;
 	return a;
} 

int main ( ){ 
    int A[3]=[1,2,3];
 	int B[3],C[3];
 	int i;
 	for (i=0; i<3; i++){
		B[i] = change(A[i]);
 		C[i] = A[i];
 	}
 	for (i=0; i<3; i++)
 	cout<<C[i];
    return 0；
}
```

 2、数组名作为函数参数
	实参和形参都用数组名

```cpp
int change ( int a[ ], int length){ 
    int b=rand();
 	for (int i=0; i<length; i++
 	a[i] = b+a[i];
 	return 0;
}
 
int main ( ){ 
    int A[3]=[1,2,3];
 	int B[3],C[3];
 	int i;
 	for (i=0; i<3; i++){
 		B[i]=A[i]
 	}
 	change(A,3);
 	for (i=0; i<3; i++){
 		C[i] = A[i];
 	}
 	for (i=0; i<3; i++)
 	cout<<C[i];
    return 0;
} 
```

#### 指针与指针变量

 一个变量的地址就是该变量的指针

```cpp
int i; // i的指针是&i
```

指针变量：专门用来存放地址的变量

```cpp
int ptr = &i;// prt是一个指针变量
//它的值是整型变量i的指针（地址）
```

指针变量的定义 

```cpp
基类型 * 指针变量名;
//基类型是C++语言中任一合法的类型
//“*”号说明其后的变量是一个指针变量
//标识符给出的是指针变量名
```

列出的基类型并不是指针变量本身的类型，而是指针用于保存的地址值中
存储的变量的数据类型，即指针所指向变量的数据类型。 

```cpp
//比如： 
int *p1;
double *p2;
/*
说明：声明了p1、p2两个指针。其中p1指向
int型变量，p2指向double型变量。 
*/
```

注：用指针前，必须首先给它赋一个合法的值。否则，程序中对指针的访
问有可能导致系统崩溃。

与其他变量一样，指针可以通过初始化来赋值。

```cpp
//比如： 
int i,*p1=&i;
int *p2=0; 
/*
说明：
第1个声明就将指针p1的值初始化为变量i的内存地址；
第2个声明将指针p2的值初始化为0
值为0的指针叫空指针。 
*/
```

如果在声明时，指针初始化为0或根本没有初始化，使用前，就必须首先给
它赋有意义的值 

```cpp
//比如： 
int i,*p1；
p1=&i; 
```

#### 指针变量的运算

赋值：取变量的地址赋给一个指针变量
&：取址运算符
通过指针变量中存储的指针找到对应的内存单元中的变量值间接寻址
*：间接访问运算符 

```cpp
//比如： 
int i=1,*p=&i;
cout<<*p;//将输出变量i的值1
*p=2；
cout<<*p;  //输出2 

//错误形式
int *p;
*p=2； //错误，指针p没有赋值 
```

#### 指向指针的指针

指针变量也是一个变量，在内存中也需占据一定的空间，具有一个地址，这个地址也可以利用指针变量来保存
	声明一个指针来指向指针变量的地址——指向指针的指针，即二级指针

##### 一般形式：

```cpp
数据类型 **标识符;
//数据类型：通过两次间接寻址后所访问的变量的类型
//两个“*”号表示二级指针
//标识符为指针名 
```

比如：

```cpp
int i,*p=&i;
int **pp=&p;//声明了一个二级指针pp，指向指针p 
```

注：通过二级指针访问目的单元中的数据值必须使用两个“*”号 

#### 指针作为函数参数

##### 指针作为函数参数时，形参和实参都为指针类型

- 函数的实参和形参均为指针类型，实参传递给形参的是一个地址
  - 形参指针和实参指针指向同一个地址
  - 被调用函数中对形参指针所指向的内存地址中内容的任何改变都会保留下来
  - 函数调用结束的时候，指针类型的形参本身被释放，形参指针所指向的内存地址仍然存在，并且可以通过实参指针访问到
  - 仍然采用单向值传递的方式

例子：交换两个整数 

```cpp
#include<iostream>
using namespace std;

int main(){
	void swap(int *p1, int *p2);
	int *point_1, *point_2, a, b;
	cin>>a>>b;
	point_1=&a;
	point_2=&b;
 	if(a<b) swap (point_1, point_2);
 	cout<< ″In main function: ″<<endl;
 	cout<< ″max= ″<<a<< ″min= ″<<b<<endl;
 	return 0; 
}

void swap(int *p1,int *p2){ 
	int temp;
 	temp=*p1;
 	*p1=*p2;
 	*p2=temp; 
} 
//max=78 min=45 
```

#### 指针与数组

##### 数组名

——数组的起始地址，即数组首元素的地址

```cpp
 int x［5］,*px=x; 
/*
把指针px初始化为指向数组的第一个元素
第一个元素的地址即为数组名x
不需要使用取地址运算符“&”。
*/
```

等价于

```cpp
int x［5］,*px=&x[0];
```

#####  指向数组元素的指针

- 数组元素的地址: &x[0]
- 通常使用一个指向数组元素数据类型的指针变量: px
- 数组元素的顺序存放带来了一些特殊用法: px++, x--
  - 某个指针指向数组中的一个元素，就可以通过指针和整数的加
  - 减运算（包括增1和减1运算）来访问这个数组的每个元素
  - 数组名本身就是指向数组第一个元素的指针常量，因此，可以通过它和整数的加减运算来访问其中的元素

例子：访问数组元素

```cpp
#include<iostream>
using namespace std;
int main(){ 
    int a[10]={0,1,2,3,4,5,6,7,8,9}, i, *p=a;
 	for( i=0;i<10;i++)
 		cout<<a[i] )<<′ ′; //利用数组下标输出数组元素值，下标法
 	cout<<endl;

 	for(i=0;i<10;i++)
 		cout<<*(a+i)<<′ ′; //利用数组名输出数组元素值 ，指针法
 	cout<<endl;

 	for(p=a; p<(a+10);p++)
 		cout<<(*p)<<′ ′; //利用指针变量输出数组元素值
 	return 0;
}
 
```

利用指针对数组进行操作时，必须注意越界问题。

比如：

```cpp
 int a[10];
 int *p=a; //指针p指向数组x的首地址
 cout<<*(p+10);
 *p=5; 
/*
p=p+10已经使指针p指向的地址在数组之
外，*p=5表达式在这个地址中写入值有可
能造成严重的后果。
*/
```

#### 指针数组

数组中的每一个元素为指针

```cpp
//类型名 *数组名[数组长度];
/*类型名：指数组中各元素指针所指向的类型，
   同一指针数组中各指针元素指向的类型相同。
  数组名：是一个标识符，是指针数组的名字，即首地址
*/
int * p[4]; 
//注 不要写成 int (*p)[4]; 这是指向一维数组的指针变量 
```

例子：若干字符串按字母顺序（从小到大）输出

```cpp
#include<iostream>
using namespace std;
int main(){
	void sort(char *name[], int n); //声明函数
    void print(char *name[], int n);
    char *name[ ]= //字符指针数组，每个元素是指向字符的指针
    { “BASIC”,”FORTRAN”,”C++”,”Pascal”,”COBOL”};
    int n=5;
    sort(name, n);
    print(name, n);
    return 0;
}
void print(char *name[], int n){
    int i;
    for(i=0;i<n;i++)
    	cout<<name[i]<<endl;
} 
void sort(char *name[], int n){
	char *temp;
	int i, j, k;
	for(i=0; i<n-1;i++){
		k=i;
		for(j=i+1; j<n;j++)
			if(strcmp(name[k], name[j])>0) 
             	k=j;
		if(k!=i){ 
   			temp=name[i]; 
             name[i]=name[k]; 
             name[k]=temp; 
        }
	}
} 
/*
BASIC
COBOL
C++
FORTRAN
Pascal 
*/
```

#### 指 针 和 字 符 串

C++中除了可以用字符数组、字符串变量来存放字符串外，还可以用字符指针指向一个字符串 

```cpp
#include<iostream>
using namespace std;
int main()
{
 char *str="I love China!";
 cout<<str<<endl;
 return 0;
}
 
```

#### 函数指针

- 函数的地址：函数在编译时被分配的入口地址
  - 函数的指针
- 可以用一个指针变量指向函数，然后通过该指针变量调用函数

申明形式 

```cpp
函数类型 （*函数指针变量名）（函数形参表）；
//函数类型:函数返回值的类型 
//形参表中的内容应与指针所指向的函数的形参表相同 
```

使用函数指针时，必须先赋值

赋值形式：

```cpp
函数指针名=函数名;//函数名所代表的函数必须是函数指针可以指向的 
```

例子：

```cpp
#include<iostream>
using namespace std;
int main(){
	int max(int x, int y); //声明函数
 	int min(int x, int y);
	int (*p) (int, int); //定义指向函数的指针变量p
 	int a, b, m, flag;
 	cin>>a>>b>>flag;
 	if(flag = 0) p=max; //使p指向函数max
 	else p=min;
 	m=p(a,b);//通过函数指针调用函数max
 	return 0;
}
int max(int x, int y) {
    int z; 
 	if(x>y) z=x; 
 	else z=y; 
 	return z; 
} 

int min (int x, int y){ 
    int z;
 	if (x<y) z=x;
	else z=y;
 	return z;
}


```

#### 返 回 指 针 值 的 函 数 

定义返回指针的函数的函数头一般形式如下：

```cpp
类型名 *函数名（参数列表）；
//类型名：是函数返回的指针所指向数据的类型
```

注：指针作为函数返回值的情形，较多地出现在主调函数需要访问返回地址前后顺序存放的多个变量时，如数组、字符串。

当一个函数的返回值是指针时，通过返回的指针中存储的地址值，主调函数
就能访问相应内存中存放的数据，还能通过指针算术运算访问这个地址前后
内存中的值。 

#### void 指 针

情形分析：一般来说，只能用指向相同类型的指针给另一个指针赋值，不同类型指针间的赋值是错误的

比如：

```cpp
 int a;
 int *p1=&a;
 double *p2=p1; //错误
/*
两个指针指向的类型不同，因此，
它们之间不能相互赋值
除非进行强制类型转换
*/
```

-  void指针可以指向任何类型的C++数据
  - 也即可以用任一类型的指针直接给void指针赋值。
  - 如果需要将void指针的值赋给其他类型的指针，则需要进行强制类型转换 

```cpp
int a; // 声明int型变量
int *p1=&a; // 给指针p1赋值
void *p2=p1; // 用int型指针直接给void指针赋值，正确
int *p3=p2; // 用void指针直接给int型指针赋值，错误
int *p4=(int *)p2; // void指针通过强制类型转换给int型指针赋值，正确
```

例子：

```cpp
#include<iostream>
using namespace std;
int main(){
    int a=1;
    int *p1=&a,*p2=0;
    void *pv=p1; //用int型指针直接给void指针赋值
    cout<<″a=＼t″<<a<<endl;
    cout<<″*(int*)pv=＼t″<<*(int*)pv<<endl;
    //输出结果时，void指针必须强制类型转换
    p2=(int *)pv; //给int型指针赋值时，void指针必须转换
    cout<<″*p2=＼t″<<*p2<<endl;
    return 0; 
}
/*
    a= 1
    *(int*)pv= 1
    *p2= 1 
*/
```

#### const 指 针 

- 作用：

  - 指向常量的一个指针变量

    - 指针变量指向的内存单元中存放的内容不可变，但指针变量自身的值（指向哪一块内存）可变

      ```cpp
      const 类型名 * 指针变量名；
      ```

  - 常指针：

    - 指针变量自身的值不可变，但它指向的内存单元中存放的内容可变

      ```cpp
      类型名 *const 指针变量名；
      ```

  - 指向常量的常指针

    - 两个部分都不能变

      ```cpp
      const 类型名 *const 指针变量名；
      ```

    - 
      常指针必须在定义时完成初始化

```cpp
//指向常量的指针
int a=1,b=2;
const int *p1=0;//声明指向int型常量的指针p1
p1=&a;//将int型变量a的地址赋给指针
*p1=2;
 /*
 错误，
 不能通过指向常量的指
 针来改变它所指的值
 */
a=2
/*正确，
变量的值可通过变量名改变
*/
p1=&b;
/*正确，
指向常量的指针本⾝的值可以改变
*/

//常指针
int a=1,b=2;
int *const p1=&a;//声明指向int型的指针常量p1
int *const p2;
/*错误，
在声明指针常量时，必须初始化
*/
*p1=2;
/*正确，
指针常量指向的值可以改变
*/
p1=&b;
/*错误，
指针常量本⾝的值不可改变
*/

```

### 引用

对一个变量起一个别名，并非变量，也不开辟内存单元
引用：先申明（且只有声明），后使用
声明引用的一般形式 

```cpp
数据类型 &引用名=变量名；//在声明引用时需要同时初始化 
// 或 
数据类型 &引用名（变量名）；
/*
数据类型：指被引用变量的类型
“&”是引用运算符
变量名是被引用变量的名字 
*/
```

被引用的变量可以是任一类型的变量

比如：

```cpp
int a;
int &ra=a;
```

为一个变量声明了引用之后，引用就成了这个变量的别名。

例子：

```cpp
#include<iostream.h>
int main(){
    int a=0;
    int &ra=a;
    cout<<″a=″<<a<<endl;
    cout<<″ra=″<<ra<<endl;
    ra=2;
    cout<<″a=″<<a<<endl;
    cout<<″ra=″<<ra<<endl;
    cout<<″&a=″<<&a<<endl;
    cout<<″&ra=″<<&ra<<endl;
    //最后两条语句是输出变量的地址，语句中的“&”号是取地址运算符。
    return 0;
} 
//输出
/*
a=0
ra=0
a=2
ra=2
&a=0x0065FDF4
&ra=0x0065FDF4 
*/
```

##### 引 用 的 使 用 说 明 

- 求引用的地址，实际上返回的是被引用变量的地址
- 引用初始化后其值不能改变，即不允许把为一个变量建立的引用重新用作另一变量的别名。程序中，对引用重新赋值的意义是给被引用变量赋新值
- 不能建立引用数组
- 不能建立引用的引用
- 要注意区别引用声明符&和地址运算符& 

##### 引用的作用

-  用途：作为函数参数，以扩充函数传递数据的功能
- 函数参数传递回顾
  - 单向值传递，执行函数期间形参的值发生变化，并不传回给实参，因此有时候需要将指针变量作为形参，实参对应为变量的地址，此时，形参可以改变指针指向的内存单元中的值
  - 引用的出现，可以将引用作为形参，参数传递时建立形参
    和实参之间的引用关系，使得形参成为实参的引用——传
    址方式
    - 采用传址或引用调用，函数中传递的是对象的地址，不需要为
      对象临时建立一个副本，程序的效率将会提高


例子：要求将变量i和j值互换

1、实参、形参为变量名

```cpp
#include<iostream>
using namespace std;
int main(){
    void swap(int ,int ); //函数声明
    int i=3,j=5;
    swap(i , j); //实参为变量名
    cout<< ″i= ″<<i<< ′＼t′<< ″j= ″<<j<<endl;
    //i和j的值未互换
    return 0;
}

void swap(int a,int b){ //形参为变量名
    int temp;
    temp=a;
    a=b;
    b=temp;
}
// x=3 y=5 
```

2、形参为指针，实参为地址

```cpp
#include<iostream>
using namespace std;
int main(){
    void swap(int * ,int * ); //函数声明
    int i=3,j=5;
    swap(&i , &j); //实参为变量名地址
    cout<< ″i= ″<<i<< ′＼t′<< ″j= ″<<j<<endl;
    //i和j的值互换
    return 0;
}

void swap(int *p1,int *p2){  //形参为指针
    int temp;
    temp=*p1;
    *p1=*p2;
    *p1=temp;
} 
//x=5 y=3 
```

3、形参为引用，实参为变量名（引用调用）

```cpp
#include<iostream>
using namespace std;
int main(){
    void swap(int& ,int& ); //函数声明
    int i=3,j=5;
    swap(i , j); //实参为变量名
    cout<< ″i= ″<<i<< ′＼t′<< ″j= ″<<j<<endl;
    //i和j的值互换
    return 0;
}

void swap(int &a,int &b){ //形参为引用
    int temp;
    temp=a;
    a=b;
    b=temp;
} 
//x=5 y=3 
```

##### 函数的引用返回

函数可以返回引用，必须注意，引用只是一个别名，绝对不能返回不在作用域内的对象的引用。

```cpp
#include<iostream>
using namespace std;
int &fun(int &i);
int main(){
    int a;
    cout<<fun(a)<<endl;
    return 0;
}
int &fun(int &i){
    i=2;
    return i;
} 
//2
```

#### 指针与引用

- 引用不可以是空引用。如果对象有可能为空时，就必须采用指针
- 引用本身不能重新赋值。如果程序需要先指向一个对象，后又指向另一对象，也应该采用指针 

```cpp
#include<iostream> //空引用
#include<stdlib>
using namespace std;
int &fun();
int main(){
    int &rp=fun();
    int *p=&rp;
    cout<<rp;
    delete p; //释放内存后，引用rp是一个空引用
    return 0;
} 

int &fun(){
    int *p=new int;
    if(p==0)
    {
        cout<<"内存分配错误"<<endl;
        exit(1); //系统函数，用于终止程序的运行
    }
    int &rp=*p;
    rp=5;
    return rp;
} 
```

上例能编译运行。但它确实出现了空引用，这是不对的。

### 结构体

 作用：将不同类型的数据组合成一个有机的整体
声明方式：先声明结构体类型，再定义结构体变量

```cpp
struct 结构体类型名
{ 
    成员列表
}; //注意分号不要遗漏
//结构体类型名：用于定义结构体变量的结构体类型名 
struct Student
{ 
    int num; //学号
    char name[20]; //姓名
    char sex; //性别
    int // 年龄
};
```

#### 结构体变量的定义

##### 方法一：先声明结构体类型, 再定义变量 (建议使用)

```cpp
struct Student
{ 
    int num;
    char name[20];
};
Student student1, student2; 
```

注：C++中，声明结构体类型时可以不加关键字struct，而C一定要加 

##### 方法二：声明结构体类型的同时定义变量

```cpp
struct Student
{
    int num;
    char name[20];
}student1, s2, s3; 

```

##### 方法三：直接定义变量（不推荐使用）

```cpp
struct
{
    int num;
    char name[20];
}student1, s2, s3;
```

#### 结 构 体 使 用 说 明 

1. 结构体类型的结构根据需要而定
2. 注意区分结构体类型和结构体变量
3. 结构体成员也可以是一个结构体变量
4. 结构体成员可以单独使用 

```cpp
struct Student
{
    int num;
    char name[20];
    float score;
} hs_stu;

struct Student1
{
    int num;
    char name[20];
    string major;
} ug_stu; 
```

成员为结构体变量实例

```cpp
struct Date
{ 
    int month;
    int day;
    int year;
｝;
    
struct Student
{ 
    int num;
    char name[20];
    char sex;
    int age;
    Date birthday;
    char addr[30];
}student1, student2;
```

成员的使用

1. 成员运算符.
2. 成员的引用等同于普通变量

```cpp
struct S
{ 
    int num;
    char name[20];
}s1, s2;
//成员的使用：
 s1.num=20;
 strcpy(s1.name,"LiMing");
 s2.num=21;
 strcpy(s2.name, "ZhangHua")
```

#### 结 构 体 变 量 的 初 始 化

可在定义时指定结构体成员的初始值

```cpp
struct Student
{ 
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
｝student1={10001, "Zhang Xin",'M', 19, 90.5, "Shanghai"};
```

#### 结 构 体 变 量 的 使 用 

 相同结构的结构体变量之间可以赋值

```cpp
student1= student2;//属于同⼀结构体类型
```

结构体成员可以被引用：结构体变量名.成员名

1. 成员运算符：优先级最高, 自左向右结合
2. 对结构体变量的成员可以像普通变量一样进行运算

```cpp
 sum＝student1.score＋student2.score;
 student1.age++; 
//由于"."运算符的优先级高, 
//因此student1.age++相当于(student1.age)++
```

3. 成员本身也是结构体类型时，成员运算符可层递使用

```cpp
student1.birthday.month = 12; 
```

4.结构体变量不能整体输入输出，只能对结构体变量中的各个成员分别进行输入和输出

```cpp
cin>>student1.num;
cout<<student1.num; 
```

#### 结构体数组

每个数组元素都是一个结构体类型的数据
定义、使用和初始化与普通数组一致

```cpp
struct Student
{ 
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
}stu[3]={{10101, "Li Lin", 'M', 18, 87.5, "103 Beijing Road"},
         {10102, "Zhang Fun", 'M', 19, 99, "130 Shanghai Road"},
         {10104, "Wang Min", 'F', 20, 78.5, "1010, Zhongshan Road"}};
stu[1]= stu[2]; 
```

![](https://github.com/ZouZeBin/DS.github.io/blob/master/C++/image/186.png?raw=true)

#### 指 向 结 构 体 变 量 的 指 针 

##### 使用实例

1)指向结构体变量指针变量的定义
前提：需声明结构体类型

```cpp
struct Student
{ 
    long num;
    char name[20];
};
//定义的一般形式：结构体类型名 *变量名;
Student *p;
```

2)赋初值

```cpp
Student student1;
Student *p;
p=&student1;
 //指向确定) 
```

3)引用成员 

```cpp
student1.num=98001
 (*p).num=98001
//注意：
 //括号不能省略 
```

#### 指 向 运 算 符 ->

##### 指向结构体变量的运算符

优先级：最高级
结合性：自左向右

##### 三种等价的结构体变量成员引用方法 

直接访问：结构体变量.成员名

```cpp
student1.num = 25；
```

间接访问：p为指针

```cpp
//(*p).成员名
(*p).num = 25； 
//p->成员名
p->num = 25；
```

#### 结构体类型数据作为函数参数

##### 情形一：用结构体变量名作为参数

1. 单向值传递，结构体类型的实参的值传递给结构体类型的形参
2. 实参所占的内存单元的内容全部顺序传递给形参
3. 缺点：一般结构体变量所占内存单元规模比较大，使得实参向形参进行单向值传递时空间和时间开销会比较大

例子：有一个结构体变量stu, 内含学生学号、姓名和3门课的成绩。
要求在main函数中为各成员赋值, 在另一函数print中将它们的值输出

```cpp
//函数声明：
void print(Student);
//函数调用：
print(stu);
//函数定义：
void print(Student stu)
 { 
    cout<<stu.num<<……;
 }
/*
	实参stu和形参stu各占独立的内存,
	传递的是整个结构体成员值
*/
```

##### 情形二：用指向结构体变量的指针作为实参，将结构体变量的地址传给形参

```cpp
//函数声明：
void print(Student *);
//函数调用：
print(&stu);
//或 Student *pt;
pt=&stu;
print(pt);

//函数定义：
void print(Student *p)
{
    cout<<p->num……;
}
//形参p指向实参pt间传递的是结构体变量stu的首地址 
```

#####  情形三：将结构体变量的引用作为函数形参 

```cpp
//函数声明
void print(Student &);

//函数调用：
print(stu);

//函数定义：
void print(Student &stud)
{
    cout<<stud.num……;
}
//形参stud是实参stu的别名, 共占内存，传递的是结构体的首地址 
```

### 存 储 空 间 的 动 态 管 理 

#####  目的: 动态地分配和释放内存空间，以提高内存使用率

1. C语言：库函数malloc和free

2. C++：运算符new和delete

   

##### 运算符new的使用： 

new 类型 [(初值)] (初值为可选项)

1. 返回分配的存储空格键的地址（即指针）
2. 用new分配数组空间时不能指定初值
3. 由于内存不足等原因而无法正常分配空间, 则new会返回一个空指针NULL, 可以根据该指针的值判断分配空间是否成功

##### 运算符delete的使用： 

delete 指针变量 （对变量）

delete [ ] 指针变量 （对数组）

1. delete仅针对new分配的内存空间有效
2. 必须有指针变量指向new开辟的内存空间, 才可用delete释放
   例：new int; 开辟了, 却不能释放 

例： new int;
作用：开辟一个存放整数的存储空间, 返回一个指向该存储空间的地址(即指针) (注意：没有赋给变量, 下面的例子也是如此)

例： new int(100);
作用：开辟一个存放整数的空间, 并指定该整数的初值为100,返回一个指向该存储空间的地址

例： new char[10];
作用：开辟一个存放字符数组(包括10个元素)的空间, 返回首元素的地址

例： new int[5] [4];
作用：开辟一个存放二维整型数组(大小为5*4)的空间, 返回首元素的地址

例： float *p=new float(3.14159);
作用：开辟一个存放单精度数的空间, 并指定该实数的初值为3.14159,将返回的该空间的地址赋给指针变量p 

例： float *p=new float(3.14159);
	delete p;
作用：释放上面用new开辟的存放单精度数的空间。

例： char *pt=new char[10];
	delete [ ] pt;
作用：在指针变量前面加一对方括号, 表示是对数组空间的释放操作

例子：临时开辟一个存储空间存放一个结构体数组 

```cpp
#include<iostream>
#include<string>
using namespace std;
struct Student
{ 
    string name;
    int num;
    char sex;
};
int main()
{ 
    Student *p;
    p=new Student;
    p->name=“wang fang”;
    p->num=10123;
    p->sex=‘m’;
    cout<< p->name <<endl<< p->num <<endl << p->sex <<endl;
    delete p;
    return 0;
} 
/*
 输出： 
 wang fang
 10123
 m
*/
```

### 共 用 体

####  union类型

1. 将若干数据组合成一个共享存储空间的整体
2. 数据成员共占一段存储单元
3. 申明形式：

```cpp
union 共⽤体类型名
 ｛ 
 	成员表列
 ｝;
```

例：可把一个整型变量、一个字符型变量、一个双精度型变量放在同一个地址开始的内存单元中

```cpp
union data
{
    int i;
    char ch;
    double d;
｝; 
```

#### 共 用 体 使 用 注 意 事 项 

##### 使用共用体变量的目的：是希望用同一个内存段存放几种不同类型的数据

1. 在每一瞬时只能存放其中一种, 而不是同时存放几种
2. 能够访问的是共用体变量中最后一次被赋值的成员
3. 在对一个新的成员赋值后原有的成员就失去作用
4. 共用体变量的地址和它的各成员的地址都是同一地址。

##### 不能对共用体变量名赋值;

##### 不能企图引用共用体变量名来得到一个值

##### 不能在定义共用体变量时对它初始化

##### 不能用共用体变量名作为函数参数 

### typedef 的 使 用 说 明 

1.  typedef可以声明各种类型名, 但不能用来定义变量
2. 用typedef可以声明数组类型、字符串类型, 使用比较方便。
3. 用typedef只是对已经存在的类型增加一个类型名, 而没有创造新的类型。
4. 当在不同源文件中用到同一类型数据(尤其是像数组、指针、结构体等类型数据)时, 常用typedef声明一些数据类型,把它们单独放在一个头文件中, 然后在需要用到它们的文件中用＃include命令把它们包含进来, 以提高编程效率。
5. 使用typedef有利于程序的通用与移植。有时程序会依赖于硬
   件特性,用typedef便于移植 