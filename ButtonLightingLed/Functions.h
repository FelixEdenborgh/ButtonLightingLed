void initWifi(char *ssid, char *pass){
  Serial.printf("Connecting to SSID: %s.\r\n", ssid);
  WiFi.begin(ssid, pass);
  Serial.print("Loading.");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(10000);
  }
  Serial.println("\n");
  Serial.printf("Connected to Wifi Network %s \r\n", ssid);
  Serial.print("IP-Address: ");
  Serial.println(WiFi.localIP()); 
}
