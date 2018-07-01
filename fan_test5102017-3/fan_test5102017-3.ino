
//--------------------------------------------------------------------------------------Header Files-----------------------------------------------------------------------------------------
#include <LiquidCrystal.h>
#include <IRremote.h>


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#define button_pressed LOW;
//#define LED_RED 9
//#define LED_GREEN 10
//#define LED_BLUE 13

 int BUZZER_PIN=A5;
 int STOP_FLAG=0;
 int OK_FLAG=0;
 int START_FLAG=0;

 int temp_sensor_adc=0;
 int TEMP_SENSOR_PIN=A0;
 int temp_adc_sampling=0;
 int temp_adc=0;

 int smps_14_sense=0;
 int SMPS_14_PIN = A1;
 int smps_14adc_sampling=0;
 int smps_14_adc=0;

 int smps_33_sense=0;
 int SMPS_33_PIN=A2;
 int smps_33adc_sampling=0;
 int smps_33_adc=0;

 int i=0;
 int check=0;
 int y=0;
 float temp_sensor_offset=0.4;
 float ADC_VALUE=0.005;
 float temp_voltage=0.0;
 float temp_true_voltage=0.0;
 float temperature=0.0;

 float SMPS14_avg_voltage=0.0;
 float SMPS14_true_voltage=0.0;
 float SMPS14_voltage_offset=0.5;

 float SMPS33_avg_voltage =0.0;
 float SMPS33_true_voltage= 0.0;
 float SMPS33_voltage_offset =0.25;

IRsend irsend;

void setup()
{
     Serial.begin(115200);
     lcd.begin(16, 2);
   
//set timer2 interrupt every 1.02ms
/*
     TCCR2A = 0;// set entire TCCR2A register to 0
     TCCR2B = 0;// same for TCCR2B
     TCNT2  = 0;//initialize counter value to 0
     // set compare match register for 976hz increments
     OCR2A = 199;// = (16*10^6) / (976*64) - 1 (must be <256)
     // turn on CTC mode
     TCCR2A |= (1 << WGM21);
     // Set CS21 bit for 64 prescaler
     TCCR2B |= (0 << CS22) | (1 << CS21) | (0 << CS20);
     // enable timer compare interrupt
     TIMSK2 |= (1 << OCIE2A);
    
     sei();//allow interrupts

 */
  // TIMER 1 for interrupt frequency 100 Hz:(10ms)
cli(); // stop interrupts
TCCR1A = 0; // set entire TCCR1A register to 0
TCCR1B = 0; // same for TCCR1B
TCNT1  = 0; // initialize counter value to 0
// set compare match register for 1 Hz increments
OCR1A = 625; // = 16000000 / (256 * 1) - 1 (must be <65536)
// turn on CTC mode
TCCR1B |= (1 << WGM12);
// Set CS12, CS11 and CS10 bits for 256 prescaler
TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
// enable timer compare interrupt
TIMSK1 |= (1 << OCIE1A);
sei(); // allow interrupts


     //BUZZER
    pinMode(A5,OUTPUT);
  
     //LED
    //pinMode(9,OUTPUT); //R_outer+R_inner control
    //pinMode(10,OUTPUT);//G_outer+G_inner control
    //pinMode(13,OUTPUT);//B_outer+B_inner control
  
    //Switches
    pinMode(6,INPUT);//start button
    pinMode(5,INPUT);//stop button
    pinMode(4,INPUT);//ok button
}


void ir_senddata()
{

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1.Relay Test");
    delay(3000);
    lcd.clear();

  //speed 1
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 1..");
  delay(500);
 for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C3, 12);
      delay(500);
  }
  for (i = 0; i <=5; i++) 
  {
     
      irsend.sendRC5(0xEC3, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }



  
  //speed 2
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 2..");
  delay(500);
 for (i = 0; i <=5; i++) 
  {
     irsend.sendRC5(0x6C4, 12);
     delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
     
     irsend.sendRC5(0xEC4, 12);
     delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }



 //speed 3
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 3..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C5, 12);
      delay(500);
      
  }
  for (i = 0; i <=5; i++) 
  {
     
      irsend.sendRC5(0xEC5, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }



 //speed 4
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 4..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C6, 12);
      delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
      
      irsend.sendRC5(0xEC6, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }




//speed 5
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 5..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C6, 12);
      delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
      
      irsend.sendRC5(0xEC6, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }





//speed 6
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 6..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C6, 12);
      delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
      
      irsend.sendRC5(0xEC6, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }





//speed 7
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 7..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C6, 12);
      delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
      
      irsend.sendRC5(0xEC6, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }


//speed 8
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed 8..");
  delay(500);
for (i = 0; i <=5; i++) 
  {
      irsend.sendRC5(0x6C6, 12);
      delay(500);
     
  }
  for (i = 0; i <=5; i++) 
  {
      
      irsend.sendRC5(0xEC6, 12);
      delay(500);
  }
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {   
   lcd.setCursor(0,0);
    }




}


void Show_adc()
{
    smps_14_adc =0;
    smps_33_adc =0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1.Reglatn.Test");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connect->Dimmer");
    delay(3000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Vary-Input");
    delay(3000);
    lcd.setCursor(4,1);
    lcd.print("140-300");
    delay(3000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("PressOk");
    lcd.setCursor(3,1);
    lcd.print("Continue");
    delay(500);
    lcd.clear();
    
       //logic
       OK_FLAG=0;                        //clearing OK_FLAG=0;
         while(1)
            {
              
                  if(OK_FLAG)
                  {
                    OK_FLAG=0;
                     break;
                  }
                  
                    
              
                  if(OK_FLAG!=1)
                   {
                 
                  //14v
                  smps_14_sense=analogRead(SMPS_14_PIN);
                  SMPS14_avg_voltage =((5.0 *smps_14_sense)/1024);
                  SMPS14_true_voltage =(((18.8/1.8)* SMPS14_avg_voltage)+SMPS14_voltage_offset);
                   if(SMPS14_true_voltage>=13.5 && SMPS14_true_voltage<=14.5)
                    { 
                      
                    }
                   else
                    {
                      digitalWrite(BUZZER_PIN,HIGH);
                      delay(1000);
                      digitalWrite(BUZZER_PIN,LOW);
                      
                    }
                
                   //3.3v
                   smps_33_sense =analogRead(SMPS_33_PIN);
                   SMPS33_avg_voltage =((5.0 * smps_33_sense )/1024);
                   SMPS33_true_voltage =(((18.8/1.8)* SMPS33_avg_voltage)+SMPS33_voltage_offset);
            
                  if(SMPS33_true_voltage>=3.2 && SMPS33_true_voltage <= 3.4)
                     {
                     
                       
                     }
                    else
                    {
                      digitalWrite(BUZZER_PIN,HIGH);
                      delay(1000);
                      digitalWrite(BUZZER_PIN,LOW);
                     
                     }
               
                 lcd.setCursor(0,0);
                 lcd.print("SMPS14  -");
                 lcd.setCursor(10,0);
                 lcd.print(SMPS14_true_voltage);
                 lcd.setCursor(15,0);
                 lcd.print("V");
                  
                 lcd.setCursor(0,1);
                 lcd.print("SMPS3.3 -");
                 lcd.setCursor(10,1);
                 lcd.print(SMPS33_true_voltage);
                 lcd.setCursor(15,1);
                 lcd.print("V");
                  delay(200); 
              }
            
              
                  
        }                                                         //while

}                                                                 //close show adc



// Function for measuring Temperature

void temperature_sensor_measurment()
{
    lcd.setCursor(0, 0);
    lcd.print("Temp Value");
    delay(500);
   lcd.setCursor(9,0);
   lcd.print(".");
   delay(500);
    lcd.setCursor(10,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(11,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(12,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(13,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(14,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(15,0);
   lcd.print(".");
   delay(500);
    lcd.setCursor(0, 1);
    temp_adc_sampling=0;
    temp_adc=0;
     for(i=0;i<10;++i)
      {
     temp_sensor_adc=analogRead(TEMP_SENSOR_PIN);
     temp_adc_sampling+= temp_sensor_adc;
      }
    temp_adc= (temp_adc_sampling / 10);
    temp_voltage = (temp_adc*ADC_VALUE);
    temp_true_voltage =(temp_voltage-temp_sensor_offset);
    temperature =(temp_true_voltage/0.020);
    lcd.print(temperature);
    lcd.setCursor(6,1);
    lcd.print("oC");
    lcd.setCursor(0,0);
    delay(3000);
    lcd.clear();
    lcd.print("Press Ok..");
    delay(1000);
    OK_FLAG=0;
   while(OK_FLAG)
   {
  
   }
   OK_FLAG=0;
  while(digitalRead(4)!=LOW)
    {
      //lcd.clear();
        
   lcd.setCursor(0,0);
    }
  
}

//Function for SMPS_14v check

void smps_14_check()
{
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("14V Testing");
   delay(500);
   lcd.setCursor(11,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(12,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(13,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(14,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(15,0);
   lcd.print(".");
   delay(500);
   
   lcd.setCursor(0, 1);
   smps_14adc_sampling=0;
   smps_14_adc =0;
    for(i=0;i<10;++i)
    {
     smps_14_sense=analogRead(SMPS_14_PIN);
     smps_14adc_sampling = smps_14adc_sampling+smps_14_sense;
    }
     smps_14_adc = smps_14adc_sampling/10;
     SMPS14_avg_voltage =((5.0 *smps_14_adc)/1024);
     SMPS14_true_voltage =(((18.8/1.8)* SMPS14_avg_voltage)+SMPS14_voltage_offset);
  
  // if(smps_14_adc>248 && smps_14_adc<270)
     if(SMPS14_true_voltage>=13.5 && SMPS14_true_voltage<=14.5)
    {
      lcd.print("Tested Ok");
      lcd.setCursor(11,1);
      lcd.print(SMPS14_true_voltage);
      lcd.setCursor(15,1);
      lcd.print("V");
      lcd.setCursor(0,0);
      delay(3000);
    }
    else
    {
      lcd.print("Defect!");
      lcd.setCursor(11,1);
      lcd.print(SMPS14_true_voltage);
      lcd.setCursor(15,1);
      lcd.print("V");
      lcd.setCursor(0,0);
      delay(3000);
    }
    
   delay(1000);
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
   {
  
   }
   OK_FLAG=0;
  while(digitalRead(4)!=LOW)
    {
      //lcd.clear();
     
    }
 
}

//Function for SMPS_3.3v check

void smps_33_check()
{
    lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("3.3V Testing");
    delay(500);
   lcd.setCursor(12,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(13,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(14,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(15,0);
   lcd.print(".");
   delay(500);
   lcd.setCursor(0, 1);
   smps_33adc_sampling=0;
   smps_33_adc =0;
     for(i=0;i<10;++i)
    {
    smps_33_sense =analogRead(SMPS_33_PIN);
    smps_33adc_sampling+=smps_33_sense;
    }
     smps_33_adc = smps_33adc_sampling/10;
     SMPS33_avg_voltage =((5.0 *smps_33_adc )/1024);
     SMPS33_true_voltage =(((18.8/1.8)* SMPS33_avg_voltage)+SMPS33_voltage_offset);
     
    // if(smps_33_adc>57 && smps_33_adc<65) // (3.2-3.4) is set as cuttof for testing
    
     if(SMPS33_true_voltage>=3.1 && SMPS33_true_voltage<= 3.4)
   {
    lcd.print("Tested Ok");
    lcd.setCursor(11,1);
    lcd.print(SMPS33_true_voltage);
    lcd.setCursor(15,1);
    lcd.print("V");
    lcd.setCursor(0,0);
     delay(3000);
   }
   else
   {
    lcd.print("Defect!");
    lcd.setCursor(11,1);
    lcd.print(SMPS33_true_voltage);
    lcd.setCursor(15,1);
    lcd.print("V");
    lcd.setCursor(0,0);
     delay(3000);
   }
  
   delay(1000);
   lcd.clear();
   lcd.print("Press Ok..");
   delay(1000);
    OK_FLAG=0;
   while(OK_FLAG)
   {
  
   }
  
  while(digitalRead(4)!=LOW)
    {
      //lcd.clear();
        
   lcd.setCursor(0,0);
    }
}
// Function for LED blink pattern

void led_check()
{
  //RED LED
  lcd.clear();
  lcd.print("RED LED CHECK..");
  delay(500);
  //digitalWrite(LED_RED, HIGH);
  delay(3000);
 // digitalWrite(LED_RED, LOW);
  lcd.clear();
  lcd.print("Press Ok..");
  delay(1000);
   OK_FLAG=0;
   while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {
      //lcd.clear();
        
   lcd.setCursor(0,0);
    }

  
  //GREEN LED
  lcd.clear();
  lcd.print("GREEN LED CHECK");
  delay(500);
  //digitalWrite(LED_GREEN,HIGH);
  delay(3000);
 // digitalWrite(LED_GREEN,LOW);
  lcd.clear();
  lcd.print("Press Ok..");
  delay(1000);
   OK_FLAG=0;
  while(OK_FLAG)
    {
  
    }
  while(digitalRead(4)!=LOW)
    {
      //lcd.clear();
        
   lcd.setCursor(0,0);
    }

   //BLUE LED
   lcd.clear();
  lcd.print("BLUE LED CHECK");
  delay(500);
 // digitalWrite(LED_BLUE,HIGH);
  delay(3000);
  //digitalWrite(LED_BLUE,LOW);
  lcd.clear();
  lcd.print("Press Ok..");
  delay(1000);
   OK_FLAG=0;
  while(OK_FLAG)
   {
  
   }
  while(digitalRead(4)!=LOW)
    {
     // lcd.clear();
       
   lcd.setCursor(0,0);
    }
    
}

void exit_lcd()
{
  lcd.clear();
  lcd.setCursor(0,0);
  //Serial.print("Testing Stopped");
  lcd.print("TestStopped..!");
  delay(500);
  lcd.clear();
}


void startwait_lcd()
{
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("V-Guard Fan");
    delay(500);
    lcd.setCursor(2, 1);
    lcd.print("Press Start !");
    delay(500);
    lcd.clear();
}


void loop() 
{
      //Start button Press sensed only then proceed
    while(!START_FLAG)
     {
     Serial.print("Waiting to press Start..Press Start to start testing...\n");
     startwait_lcd();
     }
     
    while(1)
             {
             START_FLAG=0;
                                                       //clearing Start_Flag so that when the test is stopped the above loop executes,displays "V-Guard Fan press start"
            //if(!STOP_FLAG)
              // {
               // Show_adc();
              // }
           //if(!STOP_FLAG)
              // {
              // smps_14_check();
               //}
             //if(!STOP_FLAG)
              // {
               //smps_33_check();
               //}
              // if(!STOP_FLAG)
               // {
               //led_check();
               // }  
            // if(!STOP_FLAG)
              //  {
            //  temperature_sensor_measurment();
               // }
                
             if(!STOP_FLAG)
                {
             ir_senddata();
                }
             
            else if(STOP_FLAG)
               {
              STOP_FLAG=0;
              Serial.print("stoping...\n");
              goto exitloop;
               }
             }
  exitloop:exit_lcd();
  Serial.print("out the loop\n");
  delay(1000);
 
}

//Timer 2 (1ms)           //timer for sensing switch press,OK_FLAG,START_FLAG,STOP_FLAG

ISR(TIMER1_COMPA_vect)
{
  
  if(digitalRead(6)==LOW)
  START_FLAG=1;
  if(digitalRead(5)==LOW)
  STOP_FLAG=1;
  if(digitalRead(4)==LOW)
  OK_FLAG=1;
}

