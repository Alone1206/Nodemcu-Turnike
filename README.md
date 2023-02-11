# Nodemcu-Turnike
Nodemcu İle Turnike Sistemi

const char* ssid = Wifi SSID

const char* password = wifi password

String getapidata = //your domain adress to pull data from | Alan adınız- datanın okunacağı

Sistem amaacı = Getapidata üzerinden okunan 1 veya 0 değerini okuyup gelen değere göre röleyi teitklemektedir. 

Röle sinyal bacağı -> Nodemcu GPIO 14
Röle güç <+> bacağı -> Nodemcu 3.3v
Röle gnd <-> bacağı -> Nodemcu GND
