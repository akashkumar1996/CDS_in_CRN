/*
 * Node.cc
 *
 *  Created on: Mar 11, 2018
 *      Author: AKASH
 */

#include <string.h>
#include <omnetpp.h>
#include "neighbor_m.h";
using namespace omnetpp;

#include<bits/stdc++.h>
using namespace std;

class Node : public cSimpleModule
{
public:
    int getNeighbors();
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual neighbor *generateMessage();
    virtual neighbor *generateMessage2();
    int flag;
    int neighbours;
    int neighbourCDSNodes;
    int neighbourClusters[100];
};

// The module class needs to be registered with OMNeT++
Define_Module(Node);

void Node::initialize()
{
    EV << "Setting up channels for node "<<this->getName()<<endl;
    cMessage *msg = new cMessage("Message For Neighbor Discovery");
    this->neighbours=0;
    this->flag=1;
    this->neighbourCDSNodes=0;
    EV << "Sending initial message from Node "<<this->getName()<<endl;
    int n = gateSize("gate");
    for (int i = 0; i < n; i++) {
        cMessage *copy = msg->dup();
        send(copy, "gate$o", i);
    }
    delete msg;
    cMessage *msg2 = new cMessage("Self-Message For Neighbor Count");
    scheduleAt(2.0,msg2);
    cMessage *msg3 = new cMessage("Self-Message For Flag Status");
    scheduleAt(3.0,msg3);
    cMessage *msg4 = new cMessage("Final CDS Nodes Check");
    scheduleAt(4.0,msg4);
    cMessage *msg5 = new cMessage("CDS Nodes Acknowledgment");
    scheduleAt(5.0,msg5);
}

void Node::handleMessage(cMessage *msg)
{
    neighbor *nmsg = static_cast<neighbor *>(msg);
    if(strcmp(nmsg->getName(),"Message For Neighbor Discovery")==0){
        EV << "Received initial message at Node "<<this->getName();
        this->neighbours++;
    }
    else if(strcmp(nmsg->getName(),"Self-Message For Neighbor Count")==0){
        for (int i = 0; i < gateSize("gate"); i++) {
             neighbor *copy = generateMessage();
             send(copy, "gate$o", i);
        }
    }
    else if(strcmp(nmsg->getName(),"Message For Neighbor Count")==0){
        EV << "Received message for Neighbor count\n";
        EV << this->getName()<<" has "<<this->neighbours<<" neighbors and has received message with "<<nmsg->getNeighbour()<<" from "<<nmsg->getSenderModule()->getName()<<endl;
        if(nmsg->getNeighbour()>this->neighbours){
            this->flag=0;
        }
    }
    else if(strcmp(nmsg->getName(),"Self-Message For Flag Status")==0){
         if(flag){
             EV<<"Flag is on at "<<getName()<<endl;
             for (int i = 0; i < gateSize("gate"); i++) {
                 cMessage *copy = new cMessage("CDS Node Broadcast");
                 send(copy, "gate$o", i);
              }
         }
         else{
             EV<<"Flag is off at "<<getName()<<endl;
         }
    }
    else if(strcmp(nmsg->getName(),"CDS Node Broadcast")==0){
        neighbourClusters[neighbourCDSNodes]=nmsg->getSenderModuleId();
        neighbourCDSNodes++;
    }
    else if(strcmp(nmsg->getName(),"Final CDS Nodes Check")==0){
        if(neighbourCDSNodes>1){
            flag=1;
            EV<< this->getName()<<" is a probable gateway Node"<<endl;
            sort(neighbourClusters,neighbourClusters+neighbourCDSNodes);
            for (int i = 0; i < gateSize("gate"); i++) {
                cMessage *gateway = generateMessage2();
                send(gateway, "gate$o", i);
             }
        }
    }
    else if((strcmp(nmsg->getName(),"Gateway Request Message")==0) && flag){
        EV<<"Gateway check at "<<this->getName()<<" for node "<<nmsg->getSenderModule()<<endl;
        //nmsg->getArrivalGateId();
        if((strcmp(getName(),"node16")!=0) && (strcmp(getName(),"node8")!=0)){
            EV<<"Not a gateway node"<<endl;
        }
        else{
            EV<<this->getName()<<"is a gateway node"<<endl;
        }
    }
    else if(strcmp(nmsg->getName(),"CDS Nodes Acknowledgment")==0){
        if(flag && ((strcmp(getName(),"node16")!=0) && (strcmp(getName(),"node8")!=0))){
            EV<<getName()<<" is a part of CDS."<<endl;
        }
    }
}

neighbor *Node::generateMessage()
{
      neighbor *nmsg = new neighbor("Message For Neighbor Count");
      nmsg->setId(this->getId());
      nmsg->setNeighbour(this->neighbours);
      nmsg->setFlag(this->flag);
      return nmsg;
}

neighbor *Node::generateMessage2()
{
       neighbor *nmsg = new neighbor("Gateway Request Message");
       nmsg->setId(this->getId());
       nmsg->setCdsClustersArraySize(neighbourCDSNodes);
       for(int i=0;i<neighbourCDSNodes;i++){
           nmsg->setCdsClusters(i, neighbourClusters[i]);
       }
       return nmsg;
}
