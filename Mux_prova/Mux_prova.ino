//Pin di controllo Mux 
int s0 =  15 ; 
int s1 =  16 ; 
int s2 =  17 ; 
int s3 =  18 ;

int y0 =  2 ; 
int y1 =  3 ; 
int y2 =  4 ; 
int y3 =  5 ;
int y4 =  6 ; 
int y5 =  7 ; 
int y6 =  8 ; 
int y7 =  9 ;

//Mux in "SIG" pin 
int SIG_pin =  19 ;
//Mux in "EN" pin 
int EN_pin =  14 ;


void setup( ) { 
  pinMode( s0 ,  OUTPUT ) ;  
  pinMode( s1 ,  OUTPUT ) ;  
  pinMode( s2 ,  OUTPUT ) ;  
  pinMode( s3 ,  OUTPUT ) ; 
  pinMode( SIG_pin ,  OUTPUT ) ;
  pinMode( EN_pin ,  OUTPUT ) ;

  digitalWrite( s0 ,  LOW ) ; 
  digitalWrite( s1 ,  LOW ) ; 
  digitalWrite( s2 ,  LOW ) ; 
  digitalWrite( s3 ,  LOW ) ;
  digitalWrite( SIG_pin ,  HIGH ) ;
  digitalWrite( EN_pin ,  LOW ) ;

  pinMode( y0 ,  INPUT_PULLUP ) ;  
  pinMode( y1 ,  INPUT_PULLUP ) ;  
  pinMode( y2 ,  INPUT_PULLUP ) ;  
  pinMode( y3 ,  INPUT_PULLUP ) ; 
  pinMode( y4 ,  INPUT_PULLUP ) ;  
  pinMode( y5 ,  INPUT_PULLUP ) ;  
  pinMode( y6 ,  INPUT_PULLUP ) ;  
  pinMode( y7 ,  INPUT_PULLUP ) ;



  Serial.begin(9600) ; 




}


void loop( ) {

  //Esegui il loop e leggi tutti i 16 valori 
  //Riporta il valore sul canale 6 è: 346 
  for ( int i =  2 ; i <  10 ; i ++ ) { 
    Serial.print (digitalRead(i)) ; 
    Serial.print (" ") ;    
  }
  Serial.println() ;

}


int readMux ( int canale ) { 
  int controlPin [ ]  =  { s0 , s1 , s2 , s3 } ;

  int muxChannel [ 16 ] [ 4 ] = { 
    { 0 , 0 , 0 , 0 } ,  //canale 0 
    { 1 , 0 , 0 , 0 } ,  //canale 1 
    { 0 , 1 , 0 , 0 } ,  // canale 2 
    { 1 , 1 , 0 , 0 } ,  // canale 3 
    { 0 , 0 , 1 , 0 } ,  // canale 4 
    { 1 , 0 , 1 , 0 } ,  // canale 5 
    { 0 , 1 , 1 , 0 } ,  //canale 6 
    { 1 , 1 , 1 , 0 } ,  //canale 7 
    { 0 , 0 , 0 , 1 } ,  //canale 8 
    { 1 , 0 , 0 , 1 } ,  //canale 9 
    { 0 , 1 , 0 , 1 } ,  //canale 10 
    { 1 , 1 , 0 , 1 } ,  //canale 11 
    { 0 , 0 , 1 , 1 } ,  //canale 12 
    { 1 , 0 , 1 , 1 } ,  //canale 13 
    { 0 , 1 , 1 , 1 } ,  //canale 14 
    { 1 , 1 , 1 , 1 }   //canale 15 
  } ;

  // esegue un ciclo attraverso i 4 sig 
  for ( int i =  0 ; i <  4 ; i ++ ) { 
    digitalWrite ( controlPin [ i ] , muxChannel [ canale ] [ i ] ) ; 
  }

  //legge il valore sul pin SIG 
  int val =  analogRead ( SIG_pin ) ;

  //restituisce il valore 
  return val ; 
}