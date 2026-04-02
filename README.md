# ESP32-Enviro-Monitor-LCD
local automated environment monitoring system using ESP32. It reads temperature/humidity (DHT11), monitors light levels (LDR), displays real-time data on an I2C LCD, and automatically triggers a relay-controlled water pump based on light thresholds


⚠️ Safety & Hardware Disclaimer

This project is provided for educational purposes only. It involves interfacing an ESP32 with a relay to control a potentially high-voltage load (water pump). 

Please be aware:
  Water & Electricity: 
    Combining water pumps with electrical circuits carries severe inherent risks, including electrical shock, short circuits, and fire hazards.
    Mains Voltage:If your pump uses mains AC voltage (e.g., 110V/220V), extreme caution is required. Never leave exposed wires, always use proper enclosures, and ensure Earth       grounding and fuses are in place.

  Limitation of Liability:
    By replicating this hardware build or using this software, you agree that you are doing so entirely at your own risk. The author is not responsible for any personal injury,     hardware damage, leaks, or property loss that may result from the use, misuse, or misunderstanding of this documentation.
