#ifndef QQBLOCK_H
#define QQBLOCK_H
#include <iostream>
#include <cstdint>
#include <stdbool.h>

struct QQBlock{
    uint64_t QBlockId;
    uint64_t QBlockHash;
    uint64_t QWalletBal;
    uint64_t QBlockPrevHash;
    unsigned char* QBlockUser;
    bool QBlockValidated;
};

class QBlock {
    public:
    QBlock();
    QBlock(const QBlock& qblock);
    // creating a block requires only the public key of the user
    // and also requires a transaction amount based on the block
    QQBlock* QcreateBlock(unsigned char* Qacc, uint64_t QtxAmount);
    static void QPrintBlockData(QQBlock* qblock);
    ~QBlock();
};
#endif