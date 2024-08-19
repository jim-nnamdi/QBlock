#ifndef QKEY_H
#define QKEY_H
#include <iostream>
#include <tuple>

class QKeygen{
    public:
    QKeygen() = default;
    QKeygen(const QKeygen& qkeygen) = default;
    std::tuple<unsigned char*, unsigned char*> QGenKeyPairs();
    ~QKeygen() = default;
};
#endif