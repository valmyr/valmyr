int codificadorBCD[] = {0,1,2,3};//BCD
int decodificadorBD[] ={4,5,6,7};//decoder
int *  catodobin = new int[4];
int *  bin = new int[4];
int contador;
void setup() {
    for(char i = 0; i < 8; i++){
        pinMode(i,OUTPUT);
        digitalWrite(i,LOW);
    }

}
int dec2bin(int * bin, int dec){
    //ant bug;
    bin[0] = 0;
    bin[1] = 0;
    bin[2] = 0;
    bin[3] = 0;
    while(dec){
        *(bin++)= dec%2;
        dec/=2;
    }
    return bin;
}
void display7segmentos(int catodoComum,int nDecimal){
    dec2bin(catodobin,catodoComum);
    digitalWrite(decodificadorBD[0],catodobin[0]);
    digitalWrite(decodificadorBD[1],catodobin[1]);
    digitalWrite(decodificadorBD[2],catodobin[2]);
    digitalWrite(decodificadorBD[3],catodobin[3]);
    dec2bin(bin,nDecimal);
    digitalWrite(codificadorBCD[0],bin[0]);
    digitalWrite(codificadorBCD[1],bin[1]);
    digitalWrite(codificadorBCD[2],bin[2]);
    digitalWrite(codificadorBCD[3],bin[3]);
    delay(2);
}
void loop() {
  //Separando os dígitos da variável contador
    display7segmentos(7,(contador/int(pow(10,0)))%10);
    display7segmentos(6,(contador/int(pow(10,1)))%10);
    display7segmentos(5,(contador/int(pow(10,2)))%10);
    display7segmentos(4,(contador/int(pow(10,3)))%10);
    display7segmentos(3,(contador/int(pow(10,4)))%10);
    display7segmentos(2,(contador/int(pow(10,5)))%10);
    display7segmentos(1,(contador/int(pow(10,6)))%10);
    display7segmentos(0,(contador++/int(pow(10,7)))%10);

}
