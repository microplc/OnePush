# OnePush

用单个按键实现多种功能的很小的一个 Arduino 库。你可以使用任意按键实现每次按压开或关或做不同的事情，包含四个例子。

**仅在 Arduino Due 上面测试过**

## 介绍

**这个库需要 Debounce 库，仅仅引入包含即可，其余的由 OnePush 库来实现**

在你的程序中引入库头文件：

    #include <Debounce.h>
    #include <OnePush.h>

### 构造器

有两种方法创建你的 OnePush 对象。

### 单级按钮

下面语句将创建单级按钮对象，按下按键打开再按关闭。

    OnePush myButton = OnePush(10); // 10 代表引脚，可以是变量

### 多级按钮

下面语句创建多个等级的按钮对象：

    OnePush myButton = OnePush(10, 3); // Button pin 10, 3 levels, plus level 0.

你可以有很多个等级，范围1-255，每次你按压按钮就会切入下一个等级，你可以设计不同的事情对应每一个等级，有点像老电话机，发短信时按压同一个键几次来切换不同的字母。

### 函数

OnePush 有6个函数。

#### update()

读取消抖后的按钮值并更新一些变量。你一般情况下不需调用它因为其他的函数自动对他进行调用。

    myButton.update();

#### status()

返回当前的状态，等级0返回False，其他的等级返回True，用于确认它是否处于某个等级。

    myButton.status(); // Returns false for Level 0, true otherwise.

#### state()

类似于 status() ，但返回的是 HIGH/LOW 而不是 true/false。

    myButton.state(); // Returns LOW for Level 0, HIGH otherwise.

#### level()

返回当前等级。

    (myButton.level() == 2); // Returns true if 2 is the current level, false otherwise.

#### set(level)

设置当前的等级，不合法的等级将会被忽略。

    myButton.set(10); // 如果没有那么多等级将会被忽略
    myButton.set(1); // Changes to Level 1.
    myButton.set(10) == 10; // 由于等级不被接受返回False
    myButton.set(1) == 1; // 设置为等级1并返回True

#### next()

切换到下一个等级，如果当前等级是最后一个则切换回等级0。

    myButton.next(); // Moves from current Level to the next one.
