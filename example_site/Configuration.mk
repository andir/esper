## WiFi configuration to use
WIFI_SSID = my-esper-wifi 
WIFI_PWD = super-secret
## MQTT Server to use
MQTT_HOST = mqtt
MQTT_PORT = 1883

MQTT_REALM = my-home/esper 

# Heartbeat configuation
HEARTBEAT_TOPIC =  $(MQTT_REALM)/heartbeat

# Updater configuration
UPDATER_URL = http://$(MQTT_HOST):80/firmware/
UPDATER_TOPIC = $(MQTT_REALM)/update
UPDATER_INTERVAL = 86400
