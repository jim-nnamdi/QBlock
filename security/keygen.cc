#include "keygen.hh"
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

std::tuple<unsigned char*, unsigned char*> QKeygen::QGenKeyPairs()
{   
    EVP_PKEY_CTX* keyctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    EVP_PKEY_keygen_init(keyctx);
    EVP_PKEY_CTX_set_rsa_keygen_bits(keyctx, 4096);
    EVP_PKEY* key = nullptr;
    EVP_PKEY_keygen(keyctx, &key);
    EVP_PKEY_CTX_free(keyctx);

    BIO* privatebio = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(privatebio, key, nullptr, nullptr, 0, nullptr, nullptr);
    int privateKeyLen = BIO_pending(privatebio);
    unsigned char* privatekey = new unsigned char[privateKeyLen + 1];
    BIO_read(privatebio,privatekey, privateKeyLen);
    privatekey[privateKeyLen] = '\0';

    BIO* publicbio = BIO_new(BIO_s_mem());
    PEM_write_bio_PUBKEY(publicbio, key);
    int publicKeyLen = BIO_pending(publicbio);
    unsigned char* publickey = new unsigned char[publicKeyLen + 1];
    BIO_read(publicbio,publickey, publicKeyLen);
    publickey[publicKeyLen] = '\0';
    return std::make_tuple(privatekey, publickey);
}