# 💎 Bijouterie Management System

A modern, secure desktop application for managing the daily operations of a jewelry store — built with **Qt Creator (C++)** and enhanced with **Arduino-based hardware integrations** for access control and fire safety simulation.

![C++](https://img.shields.io/badge/C++-Qt5.12-00599C?logo=cplusplus)
![Arduino](https://img.shields.io/badge/Arduino-IDE%201.8.19-00979D?logo=arduino)
![MySQL](https://img.shields.io/badge/Database-MySQL%208.0-4479A1?logo=mysql)
![License](https://img.shields.io/badge/status-academic%20project-lightgrey)

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Installation](#-installation)
- [Arduino Setup](#-arduino-setup)
- [Testing Guide](#-testing-guide)
- [Contact](#-contact)

## 🚀 Overview
This application streamlines the internal management of a jewelry shop by digitizing and securing its core operations — from inventory and client tracking to physical security, combining a full-featured desktop GUI with real hardware simulation.

## ✨ Features

**Software**
- 👤 **Client Management** — add, update, search, and delete client records
- 📦 **Product Inventory** — real-time tracking of jewelry items
- 🧑‍💼 **Employee Management** — role-based access and data control
- 🛒 **Order Management** — purchases, delivery tracking, and invoicing
- 📈 **Dashboard & Reports** — real-time overview of shop activity
- 🎨 **Modern UI** — built with Qt signals, slots, and custom styling

**Hardware (Arduino Simulation)**
- 🔐 **Access Control** — card-based unlock for the VIP storage area
- 🔥 **Fire Alarm System** — smoke detection (MQ2 sensor) with simulated sprinklers
- 🚨 **Emergency Alerts** — buzzer activation for intrusions or fire events

## 🧰 Tech Stack

| Technology | Version | Purpose |
|---|---|---|
| Qt Creator (C++) | Qt 5.12.10 | GUI and application logic |
| Arduino IDE | 1.8.19 | Hardware simulation & security |
| WampServer (PHP/MySQL) | 3.2.6 | Local database server |

## 📦 Installation

```bash
git clone https://github.com/Hiba-B-Soltan/Smart_bijoux.git
cd Smart_bijoux
```

1. **Open the project** — launch Qt Creator and open the project`
2. **Set up the database** — start WampServer, go to `http://localhost/phpmyadmin`, create a database (e.g. `bijouterie`), and import `database/bijouterie.sql`

3. **Run** — press `Ctrl+R` in Qt Creator

> ✅ Make sure the **MySQL ODBC 8.0 Driver** is installed before running the app.

## 🔌 Arduino Setup

1. Connect the Arduino board via USB
2. Open `arduino/arduino_main.ino` in Arduino IDE
3. Select the correct COM port
4. Click **Upload** to flash the board

## 🧪 Testing Guide

| Feature | How to Test |
|---|---|
| 🔐 Access Control | Scan the card → buzzer sounds and LED indicates unlock |
| 🔥 Fire Alarm | Trigger the MQ2 sensor → alarm sounds and sprinklers activate |
| 👨‍💼 Employee Access | Register an employee → verify secure VIP area access |
| 📊 Reports | Perform actions → check real-time dashboard updates |

## 📫 Contact
**Hiba Ben Soltan** — hiba.bensoltan@esprit.tn
