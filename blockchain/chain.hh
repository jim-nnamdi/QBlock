#ifndef QBLOCKCHAIN_H
#define QBLOCKCHAIN_H
#include <iostream>
#include <vector>
#include <memory>
#include "../block/blocks.hh"

class QBlockchain {
    std::vector<std::unique_ptr<QQBlock > > blocks;
    public:
    QBlockchain();
    QBlockchain(const QBlockchain& blockchain);
    std::vector<std::unique_ptr<QQBlock > >& QAddBlock(std::unique_ptr<QQBlock> block);
    void LogBlock(const QBlockchain &chain);
    ~QBlockchain();
};
#endif