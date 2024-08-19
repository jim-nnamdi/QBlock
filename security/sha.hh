#ifndef SHA_H
#define SHA_H
#include <iostream>

class QHash{
    public:
    QHash() = default;
    QHash(const QHash& qhash) = default;
    std::string QHashBlock(unsigned char* blockinfo);
    ~QHash();
};
#endif