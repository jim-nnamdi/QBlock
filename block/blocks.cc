#include "blocks.hh"
#include "../security/sha.hh"
#include "../security/keygen.hh"

#include <stdexcept>

QQBlock* QBlock::QcreateBlock(unsigned char *Qacc, uint64_t QtxAmount)
{
    if(QtxAmount <= 0) throw std::runtime_error("zero Tx");
    QHash qHash;
    auto qmakesignet = qHash.QHashBlock(Qacc);
    auto bprevhashid = std::stoi(qHash.QHashBlock((unsigned char*)"prevhash"));
    auto qblock = new QQBlock();
    uint64_t hashsignet = std::stoi(qmakesignet);
    qblock->QBlockHash = hashsignet; qblock->QBlockId = hashsignet;
    qblock->QWalletBal = QtxAmount; qblock->QBlockUser = Qacc;
    qblock->QBlockPrevHash = bprevhashid; qblock->QBlockValidated = false;
    return qblock;
}
