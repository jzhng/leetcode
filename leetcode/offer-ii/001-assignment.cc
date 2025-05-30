#include <cstring>

class CMyString
{
public:
    CMyString(char *m_pData = nullptr);
    CMyString(const CMyString &);
    CMyString& operator=(const CMyString &);
    ~CMyString(void);

private:
    char *m_pData;
};

CMyString& CMyString::operator=(const CMyString &other) {
    if (this == &other) {
        return *this;
    }

    delete[] m_pData;
    m_pData = nullptr;
    m_pData = new char(strlen(other.m_pData)+1);
    strcpy(m_pData, other.m_pData);

    return *this;
}

CMyString& CMyString::operator=(const CMyString &other) {
    if (this != &other) {
        CMyString strTemp(other);

        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
