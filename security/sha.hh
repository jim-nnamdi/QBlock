#ifndef SHA_H
#define SHA_H
#include <iostream>

class QHash{
    public:
    QHash();
    QHash(const QHash& qhash);
    std::string QHashBlock(unsigned char* blockinfo);
    ~QHash(){std::cout << "QHash_Class_Terminated\n\n";};
};
#endif