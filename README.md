# Master-Slave timesync in C

>!Important: This program was developed to run on Raspberry Pi, but could be use on any Linux System (not tested with windows). But every System running this program need to have the same size for integer. Short: Every System needs to run the same bit size (32 or 64 bit). Mixing is not possible because of the size of an timestamp. The timestamp is send directly as binary, so save the time of conversion. 

This project was developed to sync time via different Raspberry Pi and to get a higher accuracy as with python and ntp. 

The main function starts different threads. One of this, ask if there is an other PC with this program is running on the network. If there is no replay, it get the master. As Master it sends a timestamp to all registered slaves. If there is an other master in the local network, it gets slaves and waiting for trigger of the Master. 

This trigger starts a round trip time measurement, to get a timestamp. After getting a time from master (with calculated round trip time) the slave set the new time as its own time. 

If round trip time is to high the time stamp is ignored. 
If slave get no message from master after x (to set in code) minutes and three times, it will ask again after random time if there is an other master. 
If master get no answer from a slave, it will remove it from list of registered slaves. The slave will not get anymore messages and have to ask again for an existing master. The Master has two threads, one for sending messages and one for register new slaves, both running on separate processor cores and with fifo scheduling on highest priority.
