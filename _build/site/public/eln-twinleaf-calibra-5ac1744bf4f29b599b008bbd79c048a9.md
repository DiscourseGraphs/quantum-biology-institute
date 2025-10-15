---
title: ELN - Calibrating the Twinleaf Hypomagnetic chamber
---
This page is dedicated to the procedure of calibrating the Twinleaf hypomagnetic chamber (I will write an SOP style thing once I am done with the work in LA) along with all the preparation steps that were taken in order to get to a point where we have the Twinleaf operational and in optimized conditions. 

### March 18, 2025

In order to perform degaussing on the twinleaf — the process of removing residual magnetization from the mu-metal — a cable system will be needed. Thinking about the mental sanity of Mike, I am developing a solution that will be as easy as possible to set up. Taking inspiration from this image on the twinleaf website, I bought a cheap plastic tube that I will modify to have a cable that effectively runs through the central hole of the twinleaf three times. I will then set up clips on the outside to have the wires running parallel, each at about a 120deg angle when looking at the twinleaf from the side (see fig).

To make sure it is as easy as possible to install every time, I designed a little piece that I am 3D printing that will host 3 banana-style connectors. the idea is to have custom cables attached to the internal part of the tube that can do the whole loop around the twinleaf and can be easily plugged in. These will be color coded for ease of use. 

![[Twinleaf_degaussing_adjusted.stl]]

Above is the STL file of the 3D printed piece that will be used for holding the banana connectors. Ideally, it should have 4 connectors, but the piece is only large enough to host 3. This is a minor inconvenience, but it can be easily overcome by adding one more cable clip close to the hole at the center of the circular cap.

While the explanation might be hard to understand, it will be easy to get once a prototype is built and I can take a video/picture.

### March 20, 2025

I received today all the materials I needed to finish up the degaussing setup. I managed to install the female banana connectors on the 3D printed cap I designed to be installed at one end of a plastic tube I bot on amazon. Then, I soldered 3 pieces of 12 gauge wire (probably a bit overkill but I want to make sure it doesn’t overheat or create a short) and cut two of those to the correct length to create a loop around the Twinleaf. I kept one long because it is going to go all the way to the power supply. I then installed male banana connectors to the loose end of the wires. I attached some cable organizers to the twinleaf to make sure cables stay in place. The setup seems to be pretty stable and easy to set up. Now it’s time to test how the degaussing performs. However, I need to find a good way to ensure the magnetometer (quspin) stays in a fixed position. I designed and 3D printed a support to keep the magnetometer in place. 

Here’s how the degaussing setup looks.

![IMG_1107.jpeg](attachments/IMG_1107.jpeg)

![IMG_1106.jpeg](attachments/IMG_1106.jpeg)

![IMG_1105.jpeg](attachments/IMG_1105.jpeg)

### March 21, 2025

After fixing the quspin holder at the center of the Twinleaf, I tested the residual magnetic field before performing any degaussing and then tested it after several degaussing procedure (DGx in figure). The results are plotted here, where you can see that there was a quite large residual magnetic field (around 100 nT) and that a single degaussing protocol took the value down to about 14 nT overall field. In figure, all the components of the field are plotted, along with the total magnitude, calculated as $Btot = \sqrt(Bx^2+By^2+Bz^2)$. For simplicity, I also included a chart with only Btot values. 

![Bx, By, Bz and Btot.png](attachments/Bx_By_Bz_and_Btot.png)

![Btot vs. Description.png](attachments/Btot_vs._Description.png)

As show by the plot, the degaussing procedure is extremely effective in reducing the residual magnetic field. Almost all of the effect is achieved in the first run of the procedure, making multiple runs probably overkill. The final value of the magnetic field is in the 12-14 nT range. 

Now, I wanted to test how much the internal field changes when we open and close the twinleaf. I did some opening and closing of the twinleaf and each time tested the field inside once the twinleaf was sealed again. Plotted down here are the values of the field after opening and closing 3 times, starting with the degaussed twinleaf. While Btot doesn’t seem to change much and looks like it gets even better, the values of Bx, By and Bz are a bit all over the place and change quite a bit. This is most likely due to the fact that the twinleaf has a pretty tight fit and mechanical stress can induce slight changes in the materials’ magnetization. On top of this, removing the internal caps of the twinleaf exposes them to Earth’s magnetic field, resulting in a partial magnetization of the material. In the large hypomagnetic chamber, the change in residual magnetic field is usually pretty consistent and not drastic - I imagine that being due to the door being fixed on a hinge with a fixed path and no mechanical stress. The change in residual magnetization seems to be all over the place in the case of the twinleaf, making the estimation of residual field in experiments way trickier. 

![Bx, By, Bz and Btot (1).png](attachments/Bx_By_Bz_and_Btot_(1).png)

 

On top of all this, quspin magnetometers have an intrinsic offset that needs to be taken into account and that varies slowly over time. The offset was calibrated before in the big hypomagnetic chamber and found to be usually between 2 and 5 nT. Since the field seems to be way more variable in the twinleaf, it is harder to estimate the current intrinsic offset of the magnetometer. This is because it involves physically rotating the quspin by 180deg. Physical rotation implies opening the twinleaf, which messes up the internal field. 

To make it clearer, the offset can be found by assuming that the true internal residual magnetic field stays the same (let’s call it Btrue). The following process applies to each direction of the field (Bx, By, Bz). The quspin will measure a field Bmeas which can be expressed as $Bmeas = Btrue + Boff$, where Boff is the intrinsic offset in the measured direction. If we physically flip the magnetometer, we will measure the opposite value of the true residual field, while the intrinsic offset will stay the same: $Bmeasflip = -Btrue +Boff$. This means that, by adding the two equations (term to term) and dividing by 2 we can get the value of the offset: $Boff = (Bmeas + Bmeasflip)/2$. Once we know the offset, we can take that into account in our measurement and we will know the value of the residual field with a much better accuracy. However, this all relies on the true residual field being constant, which is not really the case for the twinleaf. My first line of thinking here was to jus perform a degaussing each time I flip the magnetometer, but when I tried to do that (even without flipping the quspin) it gave me a residual field value that was wildly different from the one I got before. I did a bunch of tests but I cannot seem to find a solution that gives me a stable enough value of the field to perform a good offset calibration. My current idea is to just use active compensation to get as close to zero as possible in the measured field (meaning we will settle around the intrinsic offset of the magnetometer, being between 2 and 5 nT). That is probably good enough for the experiments we want to perform in Maryland - to be fair, most hypomagnetic experiments I have seen recently have residual fields that go from 30 nT at the lowest to about 1 uT, meaning that the residual value would be still many times lower than the average hypomagnetic experiment. However, I will still do some tests and figure out if I can find a better solution for this. 

Another consideration is that ideally we might want to leave the quspin inside of the twinleaf all the time to get an active feedback. However, there is a chance the quspin will generate a tiny tiny magnetic field, although I believe that would be negligible. The real problem with this is that the quspin needs to be heated to work, meaning there will be generation of heat inside the little chamber. This would likely create a temperature difference with respect to a control.. not good. At the same time, you wouldn’t need to leave the quspin on all the time so you could just think of adjusting the active compensation whenever the twinleaf is opened and closed and then immediately turning the quspin off. If we want to really minimize the field, this might be the way to go. If we want to prioritize no temperature changes and we are willing to have a factor 10 more uncertainty in the magnetic field value, then we should rely on a first calibration, taking the quspin out of the twinleaf and just hope it stays as close to zero as possible.

### March 24, 2025

#### Active compensation

Before moving to the calibration of other parameters, I wanted to test out the active compensation of magnetic fields, just to make sure it will be working nicely. I hooked up the [low noise coil driver from quspin](https://quspin.com/low-noise-coil-driver/), a power supply that can give out low amounts of currents with high precision. It has 3 independent outputs and these are used to control the field in the x, y, and z directions. Note that it can give out both positive and negative current and putting the dial in the 5.0 position gives out 0V. The active compensation works fine and it’s possible to get close enough to 0 in all three axes (less than 1 nT) in a pretty stable way. The one thing that is annoying is that it is hard to tune the field with good precision. This is because the amount of current required is extremely low and to achieve that, the voltage required is also very low. This means that just barely touching the dial creates nT differences in residual field. For this reason, it might be a good idea to add some resistors to the line. Here is the rationale behind this: the coil driver can output up to ~4 V but right now we need less than 0.1 V for compensation. The relation between voltage and current is: $V=R\cdot I$ or $I=V/R$. Currently, the resistance is defined by the wire and the coils ad it is pretty low (R ~ 2 Ohm). If we add a resistor (let’s say 50 Ohm), the required voltage to get the same current will be much higher. This is going to be helpful for our application, because we always have the same level of control on the voltage (via the analog dial) but having the absolute voltage output being much larger gives us a much finer control.  Something like [this load resistor from Amazon](https://www.amazon.com/Bandwidth-Resistor-Terminator-Connector-Accessories/dp/B0BJ76LTHN/ref=sr_1_5?crid=2PKO3CVOS5UUO&dib=eyJ2IjoiMSJ9.2c-7QEtD6wUKZ1DgHlO9A5eYixYwEXbMs0G97mNFHgNfQ_c1eIa66JCEGoAGu6H5BNEdLxeOL6adaiOoqqBuXnw1Dk_K0sizX3nEcq-izjOE5FxDnzRlFCtXVWzdqeP8WeD7qb5X3flJJM3AamwB5pMwGuuwiTWNxGoBh4Rbi6BkyNIIAPDctPDdu03hm8vnAloxVXjmsXP2A0uoSlZqDVMtZhLONtf3pJDx_OBAF3U.Z9OGZXumuzvUk_qUUwDDSFI9SZupWEKB0MKV-16bUPg&dib_tag=se&keywords=50+ohm+bnc+resistor&qid=1743790884&sprefix=50+ohm+bnc+resistor%2Caps%2C124&sr=8-5) would work great for this purpose. The final resistance will be the sum of the intrinsic resistance of the setup and the load resistance, improving our control by a factor of ~25. 

#### Testing temperature, humidity and light

Now that we have a decent idea of how to deal with magnetic fields  in the twinleaf, we need to make sure all other relevant environmental conditions are calibrated in the hypomagnetic and control environment. 

*Quick ramble on my overall philosophy on building things and prototyping - because I feel like it.* Now, this could be done in a much cleaner BUT always keep in mind that overoptimization is a very bad thing. Currently, I have less than 2 days to come up with a solution that works and is reliable so I don’t need to make it nice or extremely user-friendly; I just want it to work well. Optimizing is great when you have a process that you are building something that you will need to build a bunch of times and especially when you plan on building a commercial product. However, when you want things to get done fast, cheap and well, you just need to drop all the “good to haves” and optimize the process around necessities. If there’s something that is low effort and can make life easier when operating the device it is absolutely worth doing. If the effort outweighs the necessity for speed and low cost, just forget about it.

Ok, now that I am done with that, let’s talk business. I decided to create some sensors with things that were already in the lab and that I could repurpose for this specific task. I played around with some sensors in the past and I had a pair of temperature and humidity sensors (Adafruit HTU21DF) as well as a pair of light sensors (Adafruit VEML7700). Having sensors that are exactly the same is very important here because we want to measurement to be as consistent as possible in the two environments. Also, it is very important for the measurement to be simultaneous and not sequential (meaning calibrating the environments at the same time and not one before the other). Now, understanding these requirements, we can come up with a simple setup that gathers data from the sensors every x amount of time (where x can be decided). However, this requires other hardware components to be able to read the data from the sensors and also some coding to read the data as well as store it in a good format and eventually plotting it. These sensors can be hooked up to an Arduino board, probably the most popular microcontroller on the market for DIY projects. This is connected to a PC via USB cable, which also serves as power source. Now, if we had one set of different sensors, we could just connect all of them to the Arduino directly. However, in our case we have two sets of sensors that are exactly the same. This creates a conflict in the way Arduino interacts with the sensors, creating the need for another hardware component: a multiplexer. Quick description of how this works: the Arduino uses two lines to communicate with the sensors, SDA (data) and SCL (clock). Each type of sensor has a unique address, so that the Arduino knows what kind of sensor it is talking to. The same sensor has the same address and the Arduino gets confused if there is more than one connected, resulting in the inability to read any data. This is the reason we use a multiplexer, which is a piece of hardware whose function is to basically split the SDA and SCL signal in a bunch of independent SDA and SCL channels that can be addressed sequentially. What this means is that, if we use a multiplexer, we can establish a connection with only one set of sensors at a time, ultimately resolving the conflict of calling an overrepresented address. This is the way the communication between the sensor and Arduino works in the calibration setup. Apart from these connections, the sensors and multiplexer need to be powered up, and this can be done via pins in the Arduino corresponding to some amount of voltage and some connected to ground. In particular, the sensors are powered up with 3.3 V and the multiplexer with 5 V. Here is the scheme for the electrical connections that need to happen in the setup. 

![[image1.png]]

I went on and created some cables to make these connections as easy and straight forward as possible. I kept the same color coding that I used in the schematic, where all the ground wires are green, all the power wires are black, all the SCL wires are red and all the SDA wires are blue. Here is what the final setup looks like: 

![[image2.png]]

I made sure to have a very long cable since we want to have the sensors inside of an incubator but we want to keep all the rest outside close to the PC. I introduced a connector close to the sample to make it easy to plug and unplug the sensors. This is particularly useful because incubators usually have just a tiny hole for cables to pass through, where the sensors wouldn’t fit. Lastly, as you can see from the image, I designed a simple holder for the sensors to make sure they stay in place. This can be screwed to the twinleaf platform just like the one I designed for the quspin magnetometer. 

### March 25, 2025

#### Temp, humidity, light calibration — software

Now that the hardware is ready for the temperature, humidity and light measurements, it’s time to hook everything up to a computer and write some software to read, store and plot the data. Personally, I am not a big fan of the Arduino language (which I believe is based on C++) so, whenever I use it, I tend to do the minimum amount of coding required there and then use python for all the rest. This means writing and uploading a simple script that reads the sensor data in the Arduino IDE, then using python to access it via serial connection, write it down in a .csv file and do some plotting of the results. This is probably the least optimized portion of the whole project, but again… it gets the job done. Also, one note for all the fellow DIY enthusiasts… if in 2025 you are still coding by yourself for some super straight forward project like this, you are definitely wasting your time. Just ask any AI to code this for you (I use chatGPT for instance). I gotta be honest, sometimes it just makes some dumb mistakes or it structures the thing in a way that is far from optimized, but for some simple tasks like this it works very well and it saves you from the hustle of actually writing the code and having to remember the syntax. It is always good to go through the code and understand how it was set up, but it is by far a much more optimized option. Having said that here are the codes that I used to make this setup work. 

Arduino code: ![[arduino_sensor_reading.ino]]

```arduino
#include <Wire.h>
#include "Adafruit_VEML7700.h"
#include "Adafruit_HTU21DF.h"

#define TCAADDR 0x70  // I2C address of PCA9548A

Adafruit_VEML7700 veml = Adafruit_VEML7700();
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);  // Select channel
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  delay(2000);  // Let Serial initialize
  Serial.println("Setup complete. Starting loop...");
}

void loop() {
  Serial.println("---------- New Reading Loop ----------");

  for (uint8_t channel = 1; channel <= 2; channel++) {
    Serial.print("Selecting multiplexer channel "); Serial.println(channel);
    tcaSelect(channel);
    delay(50); // Pause after switching channels

    Serial.println("Initializing VEML7700...");
    if (!veml.begin()) {
      Serial.print("⚠️  VEML7700 NOT FOUND on channel "); Serial.println(channel);
      continue;
    }

    Serial.println("Initializing HTU21DF...");
    if (!htu.begin()) {
      Serial.print("⚠️  HTU21DF NOT FOUND on channel "); Serial.println(channel);
      continue;
    }

    float lux = veml.readLux();
    float temp = htu.readTemperature();
    float humidity = htu.readHumidity();

    Serial.print("✅ Data from channel "); Serial.println(channel);
    Serial.print("Temp (°C): "); Serial.println(temp);
    Serial.print("Humidity (%): "); Serial.println(humidity);
    Serial.print("Lux: "); Serial.println(lux);

    // CSV-style output
    Serial.print(channel); Serial.print(",");
    Serial.print(temp); Serial.print(",");
    Serial.print(humidity); Serial.print(",");
    Serial.println(lux);
  }

  delay(10000); // Wait 10 seconds before next read
}

```

This gets a reading every 10 seconds from the sensors and prints it out. Note that for this script to work you will need to install the Adafruit VEML7700 and the Adafruit HTU21DF libraries in the Arduino IDE. 

Python code (structured as a Jupyter Notebook): 
![[get_sensor_readings.ipynb]]

Import

```python
import serial
import time
import csv
from datetime import datetime
import pandas as pd
import matplotlib.pyplot as plt

# Optional: set pandas to show all columns
pd.set_option("display.max_columns", None)

```

Write Data

```python
# Adjust port as needed, e.g., "COM3" or "/dev/ttyUSB0"
SERIAL_PORT = "COM4"
BAUD_RATE = 9600
CSV_FILENAME = f"env_data_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv"

ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # Wait for Arduino to reset

# Open CSV for writing
with open(CSV_FILENAME, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["timestamp", "environment", "temperature_C", "humidity_percent", "lux"])

    print(f"Logging to {CSV_FILENAME}... Press Ctrl+C to stop.\n")

    try:
        while True:
            line = ser.readline().decode("utf-8", errors="ignore").strip()
            if not line:
                continue
            try:
                parts = line.split(",")
                if len(parts) != 4:
                    print("Skipping malformed line:", line)
                    continue

                channel = int(parts[0])
                temp = float(parts[1])
                humidity = float(parts[2])
                lux = float(parts[3])

                timestamp = datetime.now().isoformat()
                environment = "Environment 1" if channel == 1 else "Environment 2"

                writer.writerow([timestamp, environment, temp, humidity, lux])
                print(f"{timestamp} | {environment} | Temp: {temp:.1f}°C | Hum: {humidity:.1f}% | Lux: {lux:.1f}")
            except ValueError:
                print("Parsing error for line:", line)

    except KeyboardInterrupt:
        print("\nStopped logging.")
        ser.close()

```

Plot data

```python
# Replace with the latest CSV filename or keep reusing one
csv_to_plot = CSV_FILENAME  # or hardcode: 'env_data_20250325_134200.csv'

df = pd.read_csv(csv_to_plot)
df["timestamp"] = pd.to_datetime(df["timestamp"])

# Optional: show first few rows
df.head()

# Plot Temperature
plt.figure(figsize=(10, 4))
for env in df["environment"].unique():
    env_df = df[df["environment"] == env]
    plt.plot(env_df["timestamp"], env_df["temperature_C"], label=env)
plt.title("Temperature Over Time")
plt.xlabel("Time")
plt.ylabel("°C")
plt.legend()
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Plot Humidity
plt.figure(figsize=(10, 4))
for env in df["environment"].unique():
    env_df = df[df["environment"] == env]
    plt.plot(env_df["timestamp"], env_df["humidity_percent"], label=env)
plt.title("Humidity Over Time")
plt.xlabel("Time")
plt.ylabel("%")
plt.legend()
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Plot Lux
plt.figure(figsize=(10, 4))
for env in df["environment"].unique():
    env_df = df[df["environment"] == env]
    plt.plot(env_df["timestamp"], env_df["lux"], label=env)
plt.title("Light (Lux) Over Time")
plt.xlabel("Time")
plt.ylabel("Lux")
plt.legend()
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

```

I tested this a few times and it seems to be working just fine. The main limitation of this is that the plotting and data taking cannot be done simultaneously, just because they are in the same notebook and for some reason plotting works only if you stop the script that is taking the data. This is very easy to overcome.. you can just create a separate python script that has the plotting part (+ the needed imports) and it will work just fine without the need of stopping the data taking. Anyways, this is good enough for our purposes, meaning that, unless we feel the need to improve the script at some point, this is what we will use. 

We will have full-day interviews with candidates for the head of biology position for the next four days and we will host an event on Sunday, so I won’t have time to work on this before I fly to Maryland on Monday. However, I can keep the script running for all this time to make sure it doesn’t have problems and it is reliable for long term measurements. 

#### Shipping everything to MD

While the setup for calibrating temperature, humidity and light is pretty compact and easy to transport on a flight, all the other components are bulky, heavy and delicate. For this reason, I took everything that is needed for the Maryland (MD) operation and I shipped it via FedEx, making sure they would take care of the packaging. Everything is supposed to get there on Monday, which works great because I will be in the MD lab helping Mike to set up on Tuesday and Wednesday. 

 

### March 30, 2025

As mentioned before, I left the script running for multiple days and it does look like it worked just fine! Here are the graphs for temperature, humidity and light: #evd-candidate

![[image3.png]]

![[image4.png]]

![[image5.png]]

As you can see, we have a very similar behavior in the two environments. The thing that changes the most is the light condition, but I think that is because the sensors were not fixed in place and the light sensors were oriented a bit differently, making one more sensitive to environmental light than the other. The behavior might look weird but it does make sense. Note that the measurement covers multiple days — it’s easy to see when it was daytime by the high values of light. You can also observe that temperature tends to be higher during the day and lower at night. Also, the zigzag pattern is caused by the HVAC system. The way we have it set up at the moment works in the following way: if temperature gets too cold the heat will be activated to get above a threshold value (this is what happens at night); if the temperature is too high the AC will be activated to get temperature below a certain threshold (this is what happens during the day). It is actually interesting to notice that cooling (AC) has a much higher impact on humidity than heating, as you can observe by the difference in the height of the zigzag pattern between the heating and cooling process. I guess it makes sense, but I actually never thought about it so hey, we learned something new today (at least I did). 

Now that I know that the sensors work pretty reliably, I can pack everything up and get ready for my trip to Maryland! 

### April 2, 2025

Yesterday, we unpacked everything, talked to a bunch of people at JCVI and I walked through the initial steps of the degaussing procedure with Mike. Today, he successfully reproduced all the steps following the notes he took. On top of that, I installed the Arduino IDE on his laptop, as well as python and my preferred python IDE (Visual Studio Code). I made sure all the necessary libraries were installed and I showed him how to run the calibration for temperature, humidity and light as well as how to set up the wiring for the sensors. On top of this, we tried reproducing Earth’s field inside of the Twinleaf, but we encountered some technical difficulties when trying to read the magnetic field. My idea was to use a cellphone: there is a pretty cool app called physics toolbox that allows you to read a bunch of parameters with your phone’s sensors, including magnetic fields. Since it works pretty well in Earth’s field range, I though it would be a decent, zero cost way of reading the field inside and outside of the Twinleaf. I had Mike download the app and it turns out that his phone reads a different value with respect to mine. Also, the readings don’t seem to be very consistent, so we decided to find an alternative and cleaner solution for that purpose. I will try to find a cheap but good magnetometer that is easy to use and can read the field in 3 dimensions and buy it for Mike.0 

### April 7, 2025

After the trip to JCVI, we have a much clearer idea of what we need for the experiment.







