//#include "header.h"

/*
  setiap ganti fungsi jalan, lakukan init_bot()
*/
//barubanget
boolean condition = true;
int i=17,j,z,a; // increment
int rangeD, rangeK,rangeL, rangeH,rangeHR, detectGaris,rangeSL;
char statee;
float jarak_depan=25, jarak_kanan=25, jarak_kiri=25,jarak_handle=17,jarak_handleR=38; 
float jarakD,jarakK,jarakL,handleL,handleR;
double srf[8][2] = {{24,26},{30,32},{36,38},{35,37},{25,23},{31,29},{43,41},{49,47}};
 
double bacaGaris;
char state[17]= {'s','m','r', 'l', 'k', '2', 't' , '1','3','4','5','6','7','8','9','0','q'};

//void setup()
//{
//  ax12a.begin(BaudRate, DirectionPin, &Serial);
//  Serial.begin(1000000);
//  
//  
//  pinMode(d1, INPUT);
//  pinMode(d2, INPUT);
//  pinMode(d3, INPUT);
//  pinMode(d4, INPUT);  
//  pinMode(d5, INPUT);
//  pinMode(A8, OUTPUT);
//  pinMode(24, INPUT); //D
//  pinMode(36, INPUT); //SR
//  pinMode(30, INPUT); //R
//  pinMode(25, INPUT); //SL
//  pinMode(35, INPUT); //SL
//  pinMode(26, OUTPUT); 
//  pinMode(38, OUTPUT);
//  pinMode(32, OUTPUT);
//  pinMode(23, OUTPUT);
//  pinMode(37, OUTPUT);
//  digitalWrite(A8, HIGH);
//  init_bot();
//  i=0;
//  delay(500);
//}
//
//void loop()
//{ 
// while(condition){
////  bacaGaris = analogRead(garis);
////  if(bacaGaris<600){
////    detectGaris = 1;
////  }else{
////    detectGaris = 0;
////  }
//
////Hitung Jarak pembacaan SRF05
//  jarakD=hitung_jarak(srf[0][0],srf[0][1]);
//  jarakK=hitung_jarak(srf[2][0],srf[2][1]);
//  jarakL=hitung_jarak(srf[3][0],srf[3][1]);
//  handleL=hitung_jarak(srf[1][0],srf[1][1]);
//  handleR=hitung_jarak(srf[4][0],srf[4][1]);
//
//  /*Deklarasi aturan untuk menentukan boolean
//  Apakah ada objek atau tidak, jika nilai pembacaan sensor > jarak(harusnya batas_depan/kanan/dst)
//  maka dianggap tidak ada objek dan bernilai 0. Jika hasil pembacaan Sensor < batas maka dianggap 
//  ada objek dan nilai boolean range akan bernilai 1
//  */
//  if(jarakD > jarak_depan){
//    rangeD = 0;
//  }else if(jarakD <= jarak_depan){
//    rangeD = 1;
//  } 
//  Serial.print("range :");
//  if(jarakL > jarak_kiri){
//    rangeL =  0;
//  }else if(jarakL <= jarak_kiri){
//    rangeL = 1;
//  }
//  Serial.println(rangeD);
//  if(jarakK > jarak_kanan){
//    rangeK =  0;
//  }else if(jarakK <= jarak_kanan){
//    rangeK = 1;
//  }
//
//  if(handleL > jarak_handle){
//    rangeH = 0;
//  }else if(handleL <= jarak_handle){
//    rangeH = 1;
//  }
//  Serial.print("rangeK :");
//  Serial.println(rangeK);
//
//  //Aturan untuk PID manual tanpa rumus hehe :)
//  if(handleR > jarak_handle){
//    rangeHR = 0;
//  }
//  else if(handleR <= jarak_handle){
//    rangeHR=1;
//  }
//
//  if(handleR > jarak_handleR){
//    rangeSL = 0;
//  }
//  else if(handleR <= jarak_handleR){
//    rangeSL=1;
//  }
//  Serial.print("state:");
//  Serial.println(state);
//  
////
////  bacaGaris = analogRead(garis);
////  Serial.print("garis:");
////  Serial.println(bacaGaris);
//
////Switch cas untuk perpindahan case dengan metode FSM
//switch(state[i]) {
//
//  //case start
//    case 's' :    if(rangeH == 1 && rangeHR == 0)
//                  {
//                    handle_kiri();
//                  } 
//                  else if(rangeH==0 && rangeHR ==1){
//                    handle_kanan();
//                  }
//                  else{
//                    if(rangeD ==0 && rangeK ==1){
//                    maju();
//                  }else if(rangeD == 0 && rangeK ==  0){
//                    maju();
//                    belok_kanan();
//                    i++;
//                    break;
//                  }else if(rangeD == 1 && rangeK ==  0){
//                    maju();
//                    belok_kanan();
//                    i++;
//                    break;  
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kiri();
//                  }
//                  }
//                  
//                  break;
//    //case maju ke R1
//    case 'm' :
//                 if(rangeH == 1 && rangeHR == 0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                 else{
//                    if (rangeD == 0 && rangeK ==  0){
//                    maju();
//                   }else if (rangeD == 0 && rangeK == 1){
//                    maju();
//                   }else if(rangeD == 1 && rangeK ==  0){
//                    belok_kanan();
//                    i++;
//                   }else if(rangeD == 1 && rangeK == 1){
//                    belok_kanan();
//                   }
//                 }
//                
//                 break;
//     //case masuk R1
//     case 'r' :
//                if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                else{
//                       for(a=0;a<7;a++){
//                          if(rangeH == 1 && rangeHR ==0 )
//                          {
//                            handle_kiri();
//                          }
//                          else if(rangeH==0 && rangeHR==1){
//                            handle_kanan();
//                          }
//                          else{
//                            maju();
//                          }
//                        }
//                      delay(100);
//                      
//                      ke_kiri();
//                      delay(100);
//                     // digitalWrite(pompaRelay, HIGH);
//                      ke_kanan();
//                    
//                      ke_kanan();
//                      ke_kiri();
//                      // delay(100);
//                     // digitalWrite(pompaRelay, LOW);
//                      delay(400);
//                      mundur();
//                      mundur();
//                      mundur();
//                      muter_kiri();
//                      i++;
//                      }
//                                  
//                break;
//    //case keluar R1
//     case 'l' :
//                 if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                  else{
//                     if(rangeD == 0 && rangeK == 0){
//                      maju();
//                    }else if(rangeD == 0 && rangeK == 1){
//                      maju();
//                    }else if(rangeD == 1 && rangeK ==  0){
//                      belok_kiri();
//                      i++;
//                    }else if(rangeD == 1 && rangeK == 1){
//                      belok_kiri();
//                      i++;
//                    }
//                  }
//               
//                break;
//    //case menuju R2
//     case 'k' :
//               if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK == 0){
//                    maju();
//                    belok_kanan();
//                    i++;
//                  }else if(rangeD == 0 && rangeK == 1){
//                    maju();
//                  }else if(rangeD == 1 && rangeK ==  0){
//                    belok_kiri();
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kiri();
//                  }
//               }
//               
//                break;
//
//      case '2' :
//                if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                else{
//                  if(rangeD == 0 && rangeK == 0){
//                    maju();
//                  }else if(rangeD == 0 && rangeK == 1){
//                    maju();
//                  }else if(rangeD == 1 && rangeK ==  0){
//                  
//                    maju();
//                    belok_kanan();
//                    i++;
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kanan();
//                  }
//                }
//                
//                break;
//      case 't' :
//                if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                  else{
//                    maju();
//                    maju();
//                    maju();
//                    maju();
//                    maju();
//                    belok_kanan();
//                    maju();
//                    maju();
//                    
//                    delay(200);
//                 //   digitalWrite(pompaRelay, HIGH);
//                    ke_kiri();
//                    ke_kanan();
//                    ke_kanan();
//                 //   digitalWrite(pompaRelay, LOW);
//                    ke_kiri();
//                    delay(150);
//                    muter_kiri();
//                    maju();
//                    maju();
//                    maju();
//                    maju();
//                    belok_kiri();
//                    i++;
//                  
//                }
//                break;
//
//     case '1' : if(rangeH == 0 && rangeHR ==1 )
//                  {
//                    handle_kiri();
//                  }
////                  else if(rangeH==0 && rangeHR==1){
////                    handle_kanan();
////                  }
//                  else{
//                     if(rangeD == 0 && rangeK == 0){
//                      maju();
//                    }else if(rangeD == 0 && rangeK == 1){
//                      maju();
//                    }else if(rangeD == 1 && rangeK ==  0){
//                      belok_kiri();
//                      i++;
//                    }else if(rangeD == 1 && rangeK == 1){
//                      belok_kiri();
//                      i++;
//                    }
//                  }
//               
//                break;
//
//      case '3' : if(rangeH == 1 && rangeHR == 0)
//                  {
//                    handle_kiri();
//                  } 
//                  else if(rangeH==0 && rangeHR ==1){
//                    handle_kanan();
//                  }
//                  else{
//                    if(rangeD ==0 && rangeK ==1){
//                    maju();
//                  }else if(rangeD == 0 && rangeK ==  0){
//                    maju();
//                    maju();
//                    belok_kanan();
//                    i++;
//                    break;
//                  }else if(rangeD == 1 && rangeK ==  0){
//                    maju();
//                    belok_kanan();
//                    i++;
//                     
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kiri();
//                  }
//                }
//                  
//                  break;
//      //di R1
//     case '4' :  if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                else{
//                      
//                          if(rangeH == 0 && rangeHR ==1 )
//                          {
//                            handle_kanan();
//                          }
//                          
//                          else{
//                            for(a=0;a<8 ;a++){
//                              if(rangeH == 0 && rangeHR ==1 )
//                              {
//                                handle_kanan();
//                              }
//                              else{
//                                maju();
//                              }
//                            
//                          }
//                        }
//                      delay(100);
//                      
//                      ke_kiri();
//                      delay(100);
//                     // digitalWrite(pompaRelay, HIGH);
//                      ke_kanan();
//                    
//                      ke_kanan();
//                      ke_kiri();
//                      // delay(100);
//                     // digitalWrite(pompaRelay, LOW);
//                      delay(400);
//                      mundur();
//                      mundur();
//                      mundur();
//                      muter_kiri();
//                      i++;
//                      }
//                                  
//                break;
//
//     case '5' : if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                  else{
//                     if(rangeD == 0 && rangeK == 0){
//                      maju();
//                    }else if(rangeD == 0 && rangeK == 1){
//                      maju();
//                    }else if(rangeD == 1 && rangeK ==  0){
//                      belok_kanan();
//                      i++;
//                    }else if(rangeD == 1 && rangeK == 1){
//                      belok_kanan();
//                      i++;
//                    }
//                  }
//               
//                break;
//
//     case '6' :  if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK == 0 && rangeSL == 0){
//                   maju();
//                   maju();
//                   maju(); 
//                    belok_kanan();
//                    i++;
//                  }
//                  else{
//                    if(rangeD == 0 && rangeK == 1){
//                      maju();
//                    }else if(rangeD == 1 && rangeK ==  0){
//                      belok_kiri();
//                    }else if(rangeD == 1 && rangeK == 1){
//                      belok_kiri();
//                    }
//                    else{
//                      maju();
//                    } 
//                  }
//                }
//                    
//            
//               
//                break;
//
//     case '7' : if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK == 0 && rangeL == 0){
//                    maju();
//                  }else if(rangeD == 0 && rangeK == 1 && rangeL == 0){
//                    maju();
//                    maju();
//                    maju();
//                    maju(); 
//                    belok_kiri();
//                    i++; 
//                  }else {
//                    belok_kiri();
//                  }
//                  
//               }
//               
//                break;
//      //masuk R4
//     case '8' :  if(rangeH == 1 && rangeHR ==0 )
//                  { 
//                    handle_kiri();
//                  }
//                  else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//                else{
//                     for(a=0;a<8;a++){
//                      if(rangeHR == 1)
//                        {
//                          handle_kanan();
//                        }
//                        else{
//                          maju();
//                        }
//                     }
//                        
//                      
//                        ke_kiri();
//                        ke_kanan();
//                        ke_kanan();
//                        ke_kiri();
//                        muter_kiri();
//                        i++;
//                  
//                }
//                      break;
//      case '9' :
//                if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK == 0){
//                    maju();
//                  }else if(rangeD == 0 && rangeK == 1){
//                    maju();
//       
//                  }else if(rangeD == 1 && rangeK ==  0){
//                   maju();
//                    belok_kanan();
//                    i++;
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kiri();
//                  }
//               }
//               
//          break;
//              
//      case '0' :if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK == 0){
//                    maju();
//                    maju();
//                    maju();
//                    belok_kanan();
//                    i++;
//                  }else if(rangeD == 0 && rangeK == 1){
//                    maju();
//       
//                  }else if(rangeD == 1 && rangeK ==  0){
//                    belok_kanan();
//                  }else if(rangeD == 1 && rangeK == 1){
//                    belok_kanan();
//                  }
//               }
//               
//          break;
//
//     case 'q' : if(rangeH == 1 && rangeHR ==0 )
//                  {
//                    handle_kiri();
//                  }
//               else if(rangeH==0 && rangeHR==1){
//                    handle_kanan();
//                  }
//               else{
//                  if(rangeD == 0 && rangeK== 0){
//                    maju();
//                    
//                  }else if(rangeD == 0 && rangeK == 1){
//                    maju();
//                  }else if(rangeD == 1 && rangeK==  0){
//                    belok_kanan();
//                    belok_kanan();
//                    init_bot();
//                    condition=false; 
//                  }else if(rangeD == 1 && rangeK== 1){
//                    belok_kanan();
//                  }
//               }
//               
//          break;
//
//// 
//      
//
//  }
//
//
////  if(jarakD > jarak_depan )
////  {
////      if( jarakK< jarak_kanan)
////      {
////       maju();
////      }
////      else
////      {
////       belok_kanan();
////       maju();
////      }
////  }
////  if(jarakD <= jarak_depan)
////  {
////    if(jarakK> jarak_kanan)
////    {
////      belok_kanan();
////      maju();
////    }
////    else
////    {
////      belok_kanan();
////    }
////  }
// }
//  
//  
////  Serial.println(statee);
////    Serial.print("jarak:");
////    Serial
//    
//    
// delay(10);
//}
