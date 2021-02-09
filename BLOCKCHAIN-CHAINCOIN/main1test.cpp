#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//Transation Data
struct TransactionData {
    double amount;
    string senderKey;
    string receiveKey;
    time_t timestamp;
}

//Block Class
class Block 
{    
   private:
      init index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash;

   public:
        //Constructor
        Block(int idx, TransactionData d, size_t prevHash);

        //Get Original Previous Hash  
        size_t getHash();

        //Get Previous Hash
        size_t getPreviousHash();

        // Transaction Data
        TransactionData data;

        //Validate Hash
        bool isHashValid();

};

//Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash =prevHash;
    blockHash = generateHash();
} 

//private functions
size_t Block:generateHash()
{
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    string toHash = to_string(data,amount) +data.receiveKey + data.senderKey + to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
};

//Public Functions
size_t Block::getHash()
{
    return blockchain;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == blockHash;
}

//Blockchain Class
class Blockchain
{
    private;
       Block createGenesisBlock();

    public:
       //Public Chain
       vector<Block> chain;

       //Constructor 
       Blockchain();

       //Public Functions
       void addBlock(TransactionData data);
       bool isChainValid();

       //Contrived Example For Demo Only!!!
       Block *getLastestBlock();  
};


//Blockchain Constructor
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock()
{
    time_t current;
    TransactionData d;
    d.amount = 0;
    d.receiverKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);

    hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}
//Bad !! only for demo!
Block *Blockchain::getLastestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, getLastestBlock()->getHash());
}

bool Blockchain::isChainValid()
{
    vector<Block>::iterator it;
    int chainLen = (int)chain.size();

    for(it = chain.begin();it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            //INVALID!!
            return false;
        }

        if(chainLen > 1)
        {
            Block previousBlock = *(it - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                //INVALID!!
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //Start Blockchain!
    Blockchain ChainCoin;

    //Data for first added block
    TransactionData data1;
    time_t dataTime;
    data1.amount = 1.5;
    data1.receiverKey = "J001";
    data1.senderKey = "S002";
    data1.timestamp = time(&dataTime);
    
    ChainCoin.addBlock(data1);

    cout <<"Is chain valid"<< endl;
         <<ChainCoin.isChainValid() <<endl;

    TransactionData data2;
    time_t dataTime;
    data2.amount = 0.0009666;
    data2.receiverKey = "M003";
    data2.senderKey = "F004";
    data2.timestamp = time(&dataTime);

    ChainCoin.addBlock(data2);

    cout <<"Now Is The Chain Valid"<< endl;
         <<ChainCoin.isChainValid() <<endl;      

    //Checking...
    Block *hackBlock = ChainCoin.getLastestBlock();
    hackBlock->data.amount = 1000;
    hackBlock->data.receiverKey = "J001 - from Crypto";

    cout<<"Valid?"<<endl;
    cout<< ChainCoin.isChainValid()<<enl;  
}