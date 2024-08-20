#include "blocks.hh"
#include "../security/sha.hh"
#include "../security/keygen.hh"

#include <stdexcept>
#include <iomanip>

QBlock::QBlock()
{
}

QQBlock* QBlock::QcreateBlock(unsigned char *Qacc, uint64_t QtxAmount)
{
    if(QtxAmount <= 0) throw std::runtime_error("zero Tx");
    QHash qHash;
    std::string qmakesignet = qHash.QHashBlock(Qacc);
    const char* qgenesis = "Genesis_Hash";
    unsigned char* BPHash = (unsigned char*) qgenesis;
    uint64_t QBPHash = (uint64_t) BPHash;
    std::string qmakegenesis = qHash.QHashBlock(BPHash);
    QQBlock* qblock = new QQBlock();
    uint64_t hashsignet = std::stoi(qmakesignet);
    qblock->QBlockHash = hashsignet;
    qblock->QBlockId = hashsignet;
    qblock->QWalletBal = QtxAmount;
    qblock->QBlockUser = Qacc;
    qblock->QBlockPrevHash = QBPHash; 
    qblock->QBlockValidated = false;
    return qblock;
}

void QBlock::QPrintBlockData(QQBlock* qblock){
        std::cout << "blockId:" << 
                 qblock->QBlockId   << std::setw(2) << "QBlock_Hash\n" << 
                 qblock->QBlockHash << std::setw(2) << "QWallet_Bal\n" << 
                 qblock->QWalletBal << std::setw(2) << std::endl;
}

