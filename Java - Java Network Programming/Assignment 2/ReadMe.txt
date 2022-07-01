Assignment #2
From Wikipedia …

The observer pattern is a software design pattern in which an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.

It is mainly used to implement distributed event handling systems, in "event driven" software. In those systems, the subject is usually called a "stream of events" or "stream source of events", while the observers are called "sink of events". The stream nomenclature simulates or adapts to a physical setup where the observers are physically separated and have no control over the emitted events of the subject/stream-source. This pattern then perfectly suits any process where data arrives through I/O, that is, it can arrive "randomly" ( user input from keyboard/).
While not mandatory most 'observers' implementations will use background threads.

Use the Observer design pattern code that was discussed in class to implement Sports broadcast over a
TCP/IP network using SocketChannels to any number of clients.

The Server and Client should have GUI front ends.

Upload your code to Moodle by :

Group A : Mon 1.11.2021
Group B : Wed 3.11.2021

You will have to demo your code in class.