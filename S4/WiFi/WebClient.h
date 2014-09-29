#ifndef WebsocketClient_h
#define WebsocketClient_h

#include <WiFi.h>
#include <WiFiClient.h>
//#include <EthernetClient>

typedef void (*onMessage)(char* msg);

class WebsocketClient
{
  private:
  onMessage _fnc;
  WiFiClient client;
//  EthernetClient client;
  uint16_t _port;
  char* _host;
  char* _path;
  char _key[25];
  boolean _connected;
  uint8_t _connectionTimer;
  
  boolean sendPong();
  void connectRetry();

  public:
  WebsocketClient(char* host, uint16_t port, char* path, onMessage fnc);
  void connect();
  int run();
  boolean sendPing();
  boolean sendMessage(char* msg, uint16_t length);
};
#endif

