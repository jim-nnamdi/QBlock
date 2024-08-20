#include <iostream>
#include <tuple>
#include <iomanip>
#include "../security/keygen.hh"
#include "../block/blocks.hh"
#include "../blockchain/chain.hh"
#include "../security/sha.hh"

unsigned char* uintToByteArray(uint64_t input, unsigned char* output){
    for(int x = 0; x < 8; ++x)  
        output[x] = (input  >> (8 * (7 - x))) & 0xFF;
    return output;
}

int main(void) {
    // create key pairs
    QKeygen* keyctx = new QKeygen();
    std::tuple<unsigned char*, unsigned char*> Qkeys =  keyctx->QGenKeyPairs();

    unsigned char* privateKey = std::get<0>(Qkeys);
    unsigned char* publicKey = std::get<1>(Qkeys);

    QBlock* Block = new QBlock();
    QQBlock* Blockcreated = Block->QcreateBlock(publicKey, 5000);

    std::tuple<unsigned char*, unsigned char*> QBData = keyctx->QGenKeyPairs();
    uint64_t xBlockId =  (uint64_t) std::get<0>(QBData);
    uint64_t xBlockHash = (uint64_t) std::get<1>(QBData);

    QHash* QHashAlgo = new QHash();
    unsigned char cnvResult[50]={0};
    
    std::string BId = QHashAlgo->QHashBlock(uintToByteArray(*(uint64_t*)xBlockId, cnvResult));
    std::string BHash = QHashAlgo->QHashBlock(uintToByteArray(*(uint64_t*)xBlockHash, cnvResult));
    std::cout << "____QBlockId_____" << std::endl << BId << std::endl << "___QBlock_Hash___" << std::endl << BHash << std::endl;
}