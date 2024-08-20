#include <iostream>
#include <vector>
#include <memory>
#include "../block/blocks.hh"

class QBlockchain {
    std::vector<std::unique_ptr<QQBlock>> blocks;
    public:
    QBlockchain() = default;
    QBlockchain(const QBlockchain& blockchain) = default;
    std::vector<std::unique_ptr<QQBlock > >& QAddBlock(std::unique_ptr<QQBlock> block);
    void QBlockchain::LogBlock(const QBlockchain &chain)    
    ~QBlockchain();
};