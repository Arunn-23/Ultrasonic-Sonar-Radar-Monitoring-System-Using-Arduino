# Ultrasonic-Sonar-Radar-Monitoring-System-Using-Arduino
Arduino-based Ultrasonic Sonar/Radar Monitoring System for real-time object detection, distance measurement, and servo-controlled scanning using an HC-SR04 ultrasonic sensor
# 🔭 Ultrasonic Sonar/Radar Monitoring System Using Arduino

An Arduino-based ultrasonic monitoring system designed to detect objects, measure distance, and monitor the surrounding area using an ultrasonic sensor and servo motor.

## 📌 Overview

The project uses an **Arduino UNO**, **HC-SR04 Ultrasonic Sensor**, **Servo Motor**, **16×2 LCD Display**, and **LED indicator** to create a low-cost object detection and monitoring system.

The ultrasonic sensor sends a high-frequency sound pulse toward an object and receives the reflected echo. Arduino measures the echo time and calculates the approximate distance of the detected object.

The servo motor allows the ultrasonic sensor to scan different directions, creating a simple sonar/radar-style monitoring system.

---

## 🎯 Objectives

- Detect objects without physical contact.
- Measure the distance of detected objects.
- Provide real-time distance information.
- Scan different directions using a servo motor.
- Display distance information on an LCD.
- Provide visual indication using an LED.
- Demonstrate practical applications of embedded systems.
- Develop a low-cost ultrasonic monitoring prototype.

---

## ⚙️ Working Principle

The system works on the principle of **ultrasonic wave transmission and reflection**.

1. The HC-SR04 sensor transmits an ultrasonic pulse.
2. The pulse travels through the surrounding environment.
3. When the pulse strikes an object, it is reflected back.
4. The sensor receives the reflected echo.
5. Arduino measures the echo time.
6. The distance is calculated from the measured time.
7. The distance is displayed on the LCD.
8. The LED provides an indication according to the programmed detection condition.
9. The servo motor rotates the sensor for directional scanning.

### Distance Calculation

```text
Distance = (Echo Time × Speed of Sound) / 2
