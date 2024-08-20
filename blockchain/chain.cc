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
    for(int B =0 ; B < chain.blocks.size(); ++B)
        std::cout << chain.blocks[B] << std::endl;
}
