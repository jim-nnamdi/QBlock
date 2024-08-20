cmake_minimum_required(VERSION 3.14)
project(pharisee C CXX)
set(CMAKE_CXX_STANDARD 11)

set(OPENSSL_ROOT_DIR /opt/homebrew/bin/openssl)
find_package(OPENSSL REQUIRED)

add_executable(pharisee
              src/main.cc
              security/sha.hh
              security/sha.cc
              security/keygen.hh 
              security/keygen.cc
              block/blocks.hh 
              block/blocks.cc
              blockchain/chain.hh 
              blockchain/chain.cc
)
              
target_include_directories(pharisee PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(pharisee PRIVATE OpenSSL::SSL OpenSSL::Crypto)
