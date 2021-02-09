#include <iostream>
#include <ctime>
#include <vector>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

int main()
{
    // Start Blockchain
    Blockchain ChainCoin;
    
    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "J001", "S002", time(&data1Time));
    ChainCoin.addBlock(data1);
    
    time_t data2Time;
    TransactionData data2(0.2233, "M003", "F004", time(&data2Time));
    ChainCoin.addBlock(data2);
    
    // Let's see what's in the ChainCoin blockchain!
    ChainCoin.printChain();
    
    // Is it valid?
    printf("\nIs chain still valid? %d\n", ChainCoin.isChainValid());
    
    // Someone's getting sneaky
    Block *hackBlock = ChainCoin.getLatestBlock();
    hackBlock->data.amount = 100000; // Oh yeah!
    hackBlock->data.receiverKey = "J001"; // WTF!

    // Let's look at data
    ChainCoin.printChain();

    // Why is it not valid?
    printf("\nIs chain still valid? %d\n", ChainCoin.isChainValid());
    
    return 0;
}