Assignment #1 - Channel Networking
Server Client Applications.
 Using Channels and buffers implement the following :
1. Write a server that accepts file requests from a client.  The server searches its file directory, read the file and transfers its contents to the client. The server should have many files available.
2. When the file is received by the client it should be displayed and written to a file in the clients file system.
3. If the file isn't available on the server it should indicate this to the client by sending it a message.
4. The client should keep looping asking for server files until the user inputs 'quit'.
5. Use Exception handing and Logging throughout your code and don't forget to close all opened channels. 
6. Upload ONE project file that has both the server and client classes. Also include  the server files that you are transferring