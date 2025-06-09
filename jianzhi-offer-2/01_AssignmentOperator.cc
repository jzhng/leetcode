// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include <cstring>
#include <cstdio>
#include <utility>  // for std::swap

class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator=(const CMyString& str);

private:
    char* m_pData;
};

CMyString& CMyString::operator=(const CMyString& str) {
    if (this == &str)
        return *this;

    delete[]m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

// Note:
// 1. Basics
// 2. Exception safety

class Resource {

};

class ResourceHolder {
public:
    ResourceHolder() : data_(nullptr) {}
    
    // 拷贝构造函数
    ResourceHolder(const ResourceHolder& other) 
        : data_(other.data_ ? new Resource(*other.data_) : nullptr) {}
    
    // 移动构造函数
    ResourceHolder(ResourceHolder&& other) noexcept
        : data_(other.data_) {
        other.data_ = nullptr;
    }
    
    // 拷贝赋值运算符（拷贝并交换）
    ResourceHolder& operator=(ResourceHolder other) { // 注意：按值传递
        swap(*this, other);
        return *this;
    }
    
    // 移动赋值运算符
    ResourceHolder& operator=(ResourceHolder&& other) noexcept {
        swap(*this, other);
        return *this;
    }
    
    ~ResourceHolder() {
        delete data_;
    }
    
    friend void swap(ResourceHolder& a, ResourceHolder& b) noexcept {
        using std::swap;
        swap(a.data_, b.data_);
    }
    
private:
    Resource* data_;
};
