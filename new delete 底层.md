在C++中，`operator new`、`operator new[]`、`operator delete` 和 `operator delete[]` 是底层内存管理的基础工具，它们与 `new`/`new[]` 和 `delete`/`delete[]` 密切相关，但职责不同。以下是它们的核心区别和底层机制：

------

### **1. `operator new` 与 `operator new[]`**

#### **功能**

-   `operator new`

    分配单个对象所需的内存（不调用构造函数）。

    <CPP>

    ```cpp
    void* operator new(size_t size);
    ```

-   `operator new[]`

    分配数组所需的内存（不调用构造函数）。

    <CPP>

    ```cpp
    void* operator new[](size_t size);
    ```

#### **关键区别**

| **特性**         | `operator new`           | `operator new[]`                             |
| ---------------- | ------------------------ | -------------------------------------------- |
| **用途**         | 分配单个对象的内存       | 分配数组的内存                               |
| **参数**         | `size = sizeof(MyClass)` | `size = sizeof(MyClass) * N + 额外信息`      |
| **额外信息存储** | 无                       | 可能存储数组元素数量（仅当元素有析构函数时） |

#### **底层行为**

-   **`operator new[]` 的额外存储**：
     当数组元素是**自定义类型且有析构函数**时，`operator new[]` 会在分配的内存头部存储数组元素个数（通常是一个 `size_t`，占4或8字节）。
    -   例如：`MyClass* arr = new MyClass[5];`
        实际分配的内存大小为 `5 * sizeof(MyClass) + sizeof(size_t)`，头部存储 `5`。
-   **内置类型数组**：
     若数组元素是内置类型（如 `int`），`operator new[]` 不会存储额外信息。

------

### **2. `operator delete` 与 `operator delete[]`**

#### **功能**

-   `operator delete`

    释放单个对象的内存（不调用析构函数）。

    <CPP>

    ```cpp
    void operator delete(void* ptr);
    ```

-   `operator delete[]`

    释放数组的内存（不调用析构函数）。

    <CPP>

    ```cpp
    void operator delete[](void* ptr);
    ```

#### **关键区别**

| **特性**         | `operator delete`  | `operator delete[]`                              |
| ---------------- | ------------------ | ------------------------------------------------ |
| **用途**         | 释放单个对象的内存 | 释放数组的内存                                   |
| **参数**         | 指向对象内存的指针 | 指向数组内存的指针                               |
| **额外信息处理** | 无                 | 需读取头部存储的元素个数（仅当元素有析构函数时） |

#### **底层行为**

-   **`operator delete[]` 的额外处理**：
     若数组元素是**自定义类型且有析构函数**，`operator delete[]` 需要从内存头部读取元素个数，以确定需要调用多少次析构函数。
    -   例如：`delete[] arr;`
        实际释放的内存地址是 `arr - sizeof(size_t)`，因为头部存储了元素个数。
-   **内置类型数组**：
     若数组元素是内置类型，直接释放原始地址。

------

### **3. `new`/`delete` 与 `operator new`/`operator delete` 的关系**

#### **`new` 的底层步骤**

1.  **分配内存**：调用 `operator new`（或 `operator new[]`）分配内存。
2.  **构造对象**：调用构造函数（对数组，依次为每个元素调用构造函数）。

#### **`delete` 的底层步骤**

1.  **析构对象**：调用析构函数（对数组，逆序为每个元素调用析构函数）。
2.  **释放内存**：调用 `operator delete`（或 `operator delete[]`）释放内存。

#### **代码示例**

<CPP>

```cpp
// 单个对象
MyClass* obj = new MyClass();
// 等价于：
void* ptr = operator new(sizeof(MyClass)); // 分配内存
MyClass* obj = new (ptr) MyClass();        // 调用构造函数（placement new）

delete obj;
// 等价于：
obj->~MyClass();                           // 调用析构函数
operator delete(obj);                      // 释放内存

// 数组
MyClass* arr = new MyClass[5];
// 等价于：
size_t extra = sizeof(size_t);             // 额外存储元素数量
void* arr_ptr = operator new[](5 * sizeof(MyClass) + extra);
*(size_t*)arr_ptr = 5;                     // 在头部存储元素数量
MyClass* arr = (MyClass*)((char*)arr_ptr + extra); // 调整指针
for (int i = 0; i < 5; ++i) {
    new (&arr[i]) MyClass();               // 调用构造函数
}

delete[] arr;
// 等价于：
size_t* count_ptr = (size_t*)((char*)arr - extra);
size_t count = *count_ptr;                 // 读取元素数量
for (int i = count - 1; i >= 0; --i) {     // 逆序析构
    arr[i].~MyClass();
}
operator delete[](count_ptr);              // 释放内存（传入原始地址）

```

------

### **4. 常见问题与错误**

#### **1. 错误配对使用**

-   `new[]` 必须对应 `delete[]`若 用`delete`释放`new[]`分配的数组内存：

    <CPP>

    ```cpp
    MyClass* arr = new MyClass[5];delete arr; // 错误！应使用 delete[] arr;
    ```

    -   **后果**：仅调用一次析构函数，且内存释放地址错误（未考虑头部存储的元素数量），导致内存泄漏或崩溃。

#### **2. 内置类型数组的特殊性**

-   无额外存储：对内置类型数组（如int* arr = new int[5];），operator new[]不会存储元素数量。
    -   即使错误使用 `delete` 释放，可能不会崩溃（但行为未定义）。

#### **3. 重载 `operator new[]`**

-   需处理额外存储：若自定义operator new[]，需手动处理头部存储的元素数量：

    <CPP>

    ```cpp
    void* operator new[](size_t size) {
        size_t extra = sizeof(size_t);
        void* ptr = malloc(size + extra);
        *(size_t*)ptr = (size - extra) / sizeof(MyClass); // 计算元素数量
        return (char*)ptr + extra;
    }
    
    void operator delete[](void* ptr) {
        size_t* count_ptr = (size_t*)((char*)ptr - sizeof(size_t));
        free(count_ptr);
    }
    ```

------

### **总结**

| **操作**            | **职责**           | **额外行为**                           |
| ------------------- | ------------------ | -------------------------------------- |
| `operator new`      | 分配单个对象的内存 | 无额外存储                             |
| `operator new[]`    | 分配数组的内存     | 可能存储元素数量（仅自定义类型有析构） |
| `operator delete`   | 释放单个对象的内存 | 无额外处理                             |
| `operator delete[]` | 释放数组的内存     | 需读取元素数量（仅自定义类型有析构）   |

#### **核心原则**

-   **严格配对**：`new` ↔ `delete`，`new[]` ↔ `delete[]`。
-   **底层透明性**：`operator new[]` 和 `operator delete[]` 的额外存储对用户不可见，但需通过正确的 `delete[]` 触发。



---

在 C++ 中，`operator new` 和 `operator new[]` **仅负责分配内存**，**不会调用构造函数**。这是它们与 `new`/`new[]` 操作符的核心区别。以下是详细解释：

------

### **4. `operator new` 和 `operator new[]` 的职责**

#### **功能定位**

-   `operator new`和`operator new[]`是 `C++` 的底层内存分配函数，仅完成以下任务：
    -   根据请求的内存大小分配原始内存（字节流）。
    -   返回指向该内存的指针。
-   **不涉及任何对象构造**，即不会调用类的构造函数。

#### **示例代码**

<CPP>

```cpp
// 分配内存但不构造对象
void* raw_memory = operator new(sizeof(MyClass));       // 单个对象
void* array_memory = operator new[](5 * sizeof(MyClass)); // 数组
```

------

### **5. `new` 和 `new[]` 的完整行为**

#### **`new` 的底层步骤**

当使用 `new` 表达式时（如 `MyClass* obj = new MyClass();`），实际行为分为两步：

1.  **调用 `operator new` 分配内存**
    底层通过 `operator new(sizeof(MyClass))` 分配内存。
2.  **在分配的内存上调用构造函数**
    使用 **placement new** 语法调用构造函数：`new (raw_memory) MyClass();`。

#### **`new[]` 的底层步骤**

当使用 `new[]` 表达式时（如 `MyClass* arr = new MyClass[5];`），行为类似：

1.  **调用 `operator new[]` 分配内存**
    底层通过 `operator new[](5 * sizeof(MyClass) + 额外信息)` 分配内存（可能包含数组大小等元数据）。
2.  **依次为每个元素调用构造函数**
    对每个数组元素执行构造：`new (&arr[i]) MyClass();`。

------

### **6. `operator new` 与 `new` 的关系对比**

#### **代码示例**

<CPP>

```cpp
// 使用 new 表达式（自动构造对象）
MyClass* obj = new MyClass(); // 分配内存 + 调用构造函数

// 等价于以下两步：
void* raw_mem = operator new(sizeof(MyClass)); // 1. 分配内存
MyClass* obj = new (raw_mem) MyClass();        // 2. 调用构造函数（placement new）
```

#### **关键区别**

| **操作**         | `operator new`   | `new` 表达式                   |
| ---------------- | ---------------- | ------------------------------ |
| **内存分配**     | ✔️ 分配内存       | ✔️ 调用 `operator new` 分配内存 |
| **构造函数调用** | ❌ 不调用构造函数 | ✔️ 自动调用构造函数             |
| **用途**         | 底层内存管理     | 高层对象创建                   |

------

### **7. 为什么需要这种分离？**

#### **灵活性**

-   **手动控制构造时机**：允许在分配内存后延迟构造（例如内存池预分配）。
-   **避免冗余操作**：对于某些场景（如反序列化），可能不需要默认构造函数。

#### **示例：手动构造对象**

<CPP>

```cpp
void* buffer = operator new(sizeof(MyClass)); // 分配内存
MyClass* obj = new (buffer) MyClass(42);      // 手动调用构造函数（带参数）
// ...
obj->~MyClass();                              // 手动调用析构函数
operator delete(buffer);                      // 释放内存
```

------

### **5. `operator delete` 和 `delete` 的对比**

#### **`operator delete`**

-   仅释放内存，**不调用析构函数**。
-   需手动调用析构函数（若有需要）。

#### **`delete` 表达式**

1.  **调用析构函数**：销毁对象。
2.  **调用 `operator delete`**：释放内存。

#### **代码示例**

<CPP>

```cpp
// 使用 delete 表达式（自动析构对象）
delete obj; // 调用析构函数 + 释放内存

// 等价于以下两步：
obj->~MyClass();          // 1. 调用析构函数
operator delete(obj);     // 2. 释放内存
```

------

### **8. 常见误区与后果**

#### **错误 1：混淆 `operator new` 与 `new`**

<CPP>

```cpp
// 错误！仅分配内存，未构造对象
MyClass* obj = static_cast<MyClass*>(operator new(sizeof(MyClass)));
obj->doSomething(); // 未定义行为！对象未构造！
```

#### **错误 2：直接释放未析构的对象**

<CPP>

```cpp
void* buffer = operator new(sizeof(MyClass));
MyClass* obj = new (buffer) MyClass();
operator delete(buffer); // 错误！应先调用析构函数！
// 正确流程：
obj->~MyClass();
operator delete(buffer);
```

------

### **总结**

| **操作**          | **内存分配** | **构造函数调用** | **析构函数调用** | **内存释放** |
| ----------------- | ------------ | ---------------- | ---------------- | ------------ |
| `operator new`    | ✔️            | ❌                | ❌                | ❌            |
| `new` 表达式      | ✔️            | ✔️                | ❌                | ❌            |
| `operator delete` | ❌            | ❌                | ❌                | ✔️            |
| `delete` 表达式   | ❌            | ❌                | ✔️                | ✔️            |

#### **核心规则**

-   `operator new`/`operator new[]` **仅分配内存**，不构造对象。
-   `new`/`new[]` **自动调用构造函数**。
-   `operator delete`/`operator delete[]` **仅释放内存**，不析构对象。
-   `delete`/`delete[]` **自动调用析构函数**。

理解这一分离机制是手动管理内存（如实现内存池或高性能容器）的关键。