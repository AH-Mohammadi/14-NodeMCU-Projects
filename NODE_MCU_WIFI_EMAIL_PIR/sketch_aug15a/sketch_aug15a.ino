#include <ESP8266WiFi.h>  // Use WiFi.h for ESP32
 
 #include <ESP_Mail_Client.h>

#define ssid "N1"
#define password "DON'TDOIT"
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "amirnirvaan@gmail.com"
#define AUTHOR_PASSWORD "iissxdevbuihzqwb"
#define RECIPIENT_EMAIL "numberone1378@gmail.com"

#define LED_PIN 12
#define PIR_PIN 13

//SMTPSession smtp;

//void smtpCallback(SMTP_Status status);
void setup(void) {

    Serial.begin(9600);  // Start serial communication for debugging
    Serial.print("Connecting to ");
    Serial.println(ssid);        // Print the Wi-Fi network name being connected to
    WiFi.begin(ssid, password);  // Connect to the Wi-Fi network

    delay(700);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println(".");
    Serial.println("Connected To the Wifi");  // Wi-Fi connection successful

    Serial.println("IP ADDRESS");
    Serial.println(WiFi.localIP());  // Print the local IP address of the ESP8266
}


void loop() {
    // aa
}
//     smtp.debug(1);
//     smtp.callback(smtpCallback);

//     Session_Config config;
//     config.server.host_name = SMTP_HOST;
//     config.server.port = SMTP_PORT;
//     config.login.email = AUTHOR_EMAIL;
//     config.login.password = AUTHOR_PASSWORD;

//     if (!smtp.connect(&config)) {
//         Serial.println("Connection error");
//         return;
//     }
// }

// void loop() {
//     char PIR_DETECT = digitalRead(PIR_PIN);

//     if (PIR_DETECT == 1) {
//         SMTP_Message message;
//         message.sender.name = F("ESP");
//         message.sender.email = AUTHOR_EMAIL;
//         message.subject = F("Security-Home-System");
//         message.addRecipient(F("Dear Amir"), RECIPIENT_EMAIL);

//         String textMsg = "Your System Detect some motion in the room please check the room";
//         message.text.content = textMsg.c_str();
//         message.text.charSet = "us-ascii";
//         delay(500);

//         digitalWrite(LED_PIN, HIGH);
//         if (!MailClient.sendMail(&smtp, &message)) {
//             Serial.println("Error sending email");
//             delay(60000);

//             // Delay for 1 minute before sending the next email
//         }
//     }
// }

// void smtpCallback(SMTP_Status status) {
//     if (status.success()) {
//         Serial.println("Email sent successfully");
//     } else {
//         Serial.println("Email sending failed");
//     }
// }
