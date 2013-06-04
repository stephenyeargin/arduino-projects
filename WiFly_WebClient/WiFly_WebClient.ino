#include "SPI.h"
#include "WiFly.h"
#include "Credentials.h"

WiFlyClient client( pingserver, 80 );

int looped = 0;

void setup() {
  Serial.begin(9600);

  WiFly.begin();
  
  if (!WiFly.join(ssid, passphrase)) {
    Serial.println("Association failed.");
    while (1) {
      // Hang on failure.
    }
  }
}

void loop() {

  String PostData="";
  unsigned char i;
  for(i=0;i<6;i++) {
    PostData=PostData+"pin";
    PostData=String(PostData+i);
    PostData=PostData+"=";
    PostData=String(PostData + String(analogRead(i)));
    if(i!=5) {
      PostData=PostData+"&";
    }
  }
  
  if( client.connect() )  {
    Serial.println( PostData );

    client.print( "POST " );
    client.print( pingpath );
    client.println( " HTTP/1.1" );
    client.print( "Host: " );
    client.println( pingserver );
    client.println( "Content-Type: application/x-www-form-urlencoded" );
    client.println( "Connection: close" );
    client.print( "Content-Length: " );
    client.println( PostData.length() );
    client.println();
    client.print( PostData );
    client.println();
  }
  
  delay( 5000 );
}
