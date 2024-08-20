#include "chain.hh"
#include "../security/sha.hh"
#include <iostream>

std::vector<std::unique_ptr<QQBlock > >& QBlockchain::QAddBlock(std::unique_ptr<QQBlock> block)
{
    blocks.push_back(std::move(block));
    LogBlock(*this);
    return blocks;
}

void QBlockchain::LogBlock(const QBlockchain &chain)
{
    for(int i = 0; i < chain.blocks.size(); ++i) 
        std::cout << chain.blocks[i] << std::endl;
}
