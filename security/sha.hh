#ifndef SHA_H
#define SHA_H
#include <iostream>

class QHash{
    QHash() = default;
    QHash(const QHash& qhash) = default;
    std::string QHashBlock(const char* blockinfo);
    ~QHash();
};
#endif