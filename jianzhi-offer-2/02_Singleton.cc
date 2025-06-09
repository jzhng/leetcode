// 面试题2：实现Singleton模式
// 题目：设计一个类，我们只能生成该类的一个实例。

// Myer's Singleton
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() {}
    ~Singleton() {}
};
