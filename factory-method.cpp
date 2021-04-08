#include <iostream>
#include <map>

using namespace std;

// This is ITyre interface (We can also use class with all methods as public)
struct ITyre
{
    virtual void run() = 0;
    
    virtual ~ITyre(){
        
    }
};


// Implement Apollo tyre
class ApolloTyre : public ITyre
{
    public:
        //implement run method 
        void run()
        {
            //write logic to build Apollo tyre based on its requirements
            cout<<"Apollo tyre is great!"<<endl;
        }
        
        ~ApolloTyre(){
            
        }
};

// Implement CEAT tyre
class CeatTyre : public ITyre
{
    public:
        //implement run method 
        void run()
        {
            //write logic to build Ceat tyre based on its requirements
            cout<<"Ceat tyre is the Best!"<<endl;
        }
        
        ~CeatTyre(){
            
        }
};

// Implement MRF tyre
class MRFTyre : public ITyre
{
    public:
        //implement run method 
        void run()
        {
            //write logic to build MRF tyre based on its requirements
            cout<<"MRF tyre is awsome!"<<endl;
        }
        
        ~MRFTyre(){
            
        }
};

// Implement Bridgstone tyre
class BridgestoneTyre : public ITyre
{
    public:
        //implement run method 
        void run()
        {
            //write logic to build Bridgstone tyre based on its requirements
            cout<<"Bridgestone tyre runs on snow!"<<endl;
        }
        
        ~BridgestoneTyre(){
            
        }
};


struct ITyreObjectCreator
{
    virtual ITyre* CreateObject() = 0;
};

class ApolloTyreObjectCreator : public ITyreObjectCreator
{
    public:
        ITyre* CreateObject()
        {
            return new ApolloTyre();
        }
};

class CeatTyreObjectCreator : public ITyreObjectCreator
{
    public:
        ITyre* CreateObject()
        {
            return new CeatTyre();
        }
};

class MRFTyreObjectCreator : public ITyreObjectCreator
{
    public:
        ITyre* CreateObject()
        {
            return new MRFTyre();
        }
};

class BridgestoneTyreObjectCreator : public ITyreObjectCreator
{
    public:
        ITyre* CreateObject()
        {
            return new BridgestoneTyre();
        }
};

enum TyreCompany{
    APOLLO = 0,
    CEAT,
    MRF,
    BRIDGESTONE
};


// this is a factory class for tyre companies
class TyreFactory
{
    private: 
        std::map<TyreCompany,ITyreObjectCreator*> m_mapObjectCreators;
        
    public:
        // register all the tyre company creators in Map 
        void RegisterCreator(TyreCompany tyreCompany, ITyreObjectCreator* ptrObjectCreator)
        {
            m_mapObjectCreators[tyreCompany] = ptrObjectCreator;
        }
        
        // create factory method which takes inputs and returns tyres based on 
        // that inputs
        ITyre* getTyre(TyreCompany tyreCompany)
        {
            std::map<TyreCompany,ITyreObjectCreator*>::iterator itr;
            itr = m_mapObjectCreators.find(tyreCompany);
            
            if(itr != m_mapObjectCreators.end())
            {
                return itr->second->CreateObject();
            }
        }
};

int main()
{

    TyreFactory fact;
    
    // first register object creator
    fact.RegisterCreator(TyreCompany::APOLLO,new ApolloTyreObjectCreator());
    fact.RegisterCreator(TyreCompany::CEAT,new CeatTyreObjectCreator());
    fact.RegisterCreator(TyreCompany::MRF,new MRFTyreObjectCreator());
    fact.RegisterCreator(TyreCompany::BRIDGESTONE,new BridgestoneTyreObjectCreator());
    
    // create object based on your requirement
    ITyre *ptrApollo1 = fact.getTyre(TyreCompany::APOLLO);
    ptrApollo1->run();
    
    ITyre *ptrApollo2 = fact.getTyre(TyreCompany::APOLLO);
    ptrApollo2->run();
    
    ITyre *ptrCeat = fact.getTyre(TyreCompany::CEAT);
    ptrCeat->run();
    
    ITyre *ptrMRF = fact.getTyre(TyreCompany::MRF);
    ptrMRF->run();
    
    ITyre *ptrBS = fact.getTyre(TyreCompany::BRIDGESTONE);
    ptrBS->run();


    delete ptrApollo1;
    delete ptrApollo2;
    delete ptrCeat;
    delete ptrMRF;
    delete ptrBS;

    return 0;
}
