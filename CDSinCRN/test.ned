import ned.IBidirectionalChannel;


//
// TODO documentation
//
simple Node
{
    @display("i=device/satellite");
    gates:
        inout gate[];
}

//
// TODO documentation
//
network Network
{
    
    @display("bgb=741,323");
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        node: Node {
            @display("p=133,128");
        }
        node1: Node {
            @display("p=57,61");
        }
        node2: Node {
            @display("p=57,177");
        }
        node3: Node {
            @display("p=205,128");
        }
        node4: Node {
            @display("p=338,128");
        }
        node5: Node {
            @display("p=284,61");
        }
        node6: Node {
            @display("p=284,177");
        }
        node7: Node {
            @display("p=413,177");
        }
        node8: Node {
            @display("p=413,61");
        }
        node9: Node {
            @display("p=493,128");
        }
        node12: Node {
            @display("p=444,258");
        }
        node13: Node {
            @display("p=323,258");
        }
        node14: Node {
            @display("p=394,226");
        }
        node15: Node {
            @display("p=603,177");
        }
        node16: Node {
            @display("p=603,100");
        }
        node17: Node {
            @display("p=671,128");
        }
        node18: Node {
            @display("p=716,61");
        }
    connections:
        node.gate++ <--> Channel <-->node1.gate++;
        node.gate++ <--> Channel <--> node2.gate++;
        node3.gate++ <--> Channel <--> node4.gate++;
        node5.gate++ <--> Channel <--> node4.gate++;
        node4.gate++ <--> Channel <--> node6.gate++;
        node4.gate++ <--> Channel <--> node8.gate++;
        node4.gate++ <--> Channel <--> node7.gate++;
        node7.gate++ <--> Channel <--> node9.gate++;
        node8.gate++ <--> Channel <--> node9.gate++;
        node9.gate++ <--> Channel <--> node16.gate++;
        node9.gate++ <--> Channel <--> node15.gate++;
        node16.gate++ <--> Channel <--> node17.gate++;
        node15.gate++ <--> Channel <--> node17.gate++;
        node17.gate++ <--> Channel <--> node18.gate++;
        node7.gate++ <--> Channel <--> node14.gate++;
        node14.gate++ <--> Channel <--> node13.gate++;
        node14.gate++ <--> Channel <--> node12.gate++;
        node1.gate++ <--> Channel <--> node2.gate++;
        node.gate++ <--> Channel <--> node3.gate++;
}

