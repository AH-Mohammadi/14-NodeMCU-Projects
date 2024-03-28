#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>


#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "amirnirvaan@gmail.com"
#define AUTHOR_PASSWORD "iissxdevbuihzqwb"
#define RECIPIENT_EMAIL "numberone1378@gmail.com"

#define LED_PIN 12
#define PIR_PIN 13

#define BUZZER_PIN 2


const char *ssid = "N1";
const char *password = "DON'TDOIT";

WiFiServer server(8080);

SMTPSession smtp;


void smtpCallback(SMTP_Status status);


void setup(void){
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, OUTPUT);

  
  Serial.begin(9600);
  Serial.print("Conecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  delay(700);


  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println(".");
  Serial.println("Connected To the Wifi");


}


void loop() {
    if (digitalRead(PIR_PIN) == HIGH) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        tone(BUZZER_PIN, 500, 220);
        Serial.println("Motion Detected");
        // Set up SMTP configuration
        Session_Config config;
        config.server.host_name = SMTP_HOST;
        config.server.port = SMTP_PORT;
        config.login.email = AUTHOR_EMAIL;
        config.login.password = AUTHOR_PASSWORD;
        config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
        config.time.gmt_offset = 3;
    
        // Create the email message
        SMTP_Message message;
        message.sender.name = F("Secured Home System");
        message.sender.email = AUTHOR_EMAIL;
        message.subject = F(" Home Security System");
        message.addRecipient(F("Amir"), RECIPIENT_EMAIL);
        
        // Set the email content
        String textMsg = "Hello Amir - This is an Alert Email from Your Secured Home System So we detect some motion in your room and so you should check the home for any probelms\nwith Respect Your security System";
        message.text.content = textMsg.c_str();
        message.text.charSet = "us-ascii";
        message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
      
        message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
        message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;
    
        // Connect to the server and send the email
        if (smtp.connect(&config)) {
            if (!smtp.isLoggedIn()) {
                Serial.println("\nNot yet logged in.");
            } else {
                Serial.println("\nSuccessfully logged in.");
            }
            
            if (MailClient.sendMail(&smtp, &message)) {
                Serial.println("\nAlert Email Sent");

                delay(60000); // Delay after sending email
            } else {
                ESP_MAIL_PRINTF("Error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
                delay(500); // Delay on error
            }
        } else {
            ESP_MAIL_PRINTF("Connection error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
        }
    }
    digitalWrite(LED_PIN, LOW);
}
