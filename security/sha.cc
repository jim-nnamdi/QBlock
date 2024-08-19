#include <iostream>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include "sha.hh"

std::string QHashBlock(const char* blockInfo) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if(EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1) {
        std::cerr << "EVP_DigestInit_Error" << std::endl;
        EVP_MD_CTX_free(context);
        std::string exiterror = std::to_string(EXIT_FAILURE);
        return exiterror;
    }
    if(EVP_DigestUpdate(context, blockInfo, std::strlen(blockInfo)) != 1){
        std::cerr << "EVP_DigestUpdate_Error" << std::endl;
        EVP_MD_CTX_free(context);
        std::string exiterror = std::to_string(EXIT_FAILURE);
        return exiterror;
    }   
    if(EVP_DigestFinal(context, hash, nullptr) != 1){
        std::cerr << "EVP_DigestFinal_Error" << std::endl;
        EVP_MD_CTX_free(context);
        std::string exiterror = std::to_string(EXIT_FAILURE);
        return exiterror;
    }
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) 
        ss << std::hex << std::setfill('0') << static_cast<int>(hash[i]);
    return ss.str();
}