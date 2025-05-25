# 💎 Bijouterie Management System

A modern and secure desktop application for managing the operations of a jewelry store, developed using **Qt Creator (C++)** and enhanced with **Arduino-based hardware integrations**.

---

## 🚀 Project Overview

This application is designed to **streamline and innovate** the internal management of a jewelry shop, covering all essential aspects such as:

- 👤 Client Management  
- 📦 Product Inventory Management  
- 🧑‍💼 Employee Management  
- 🛒 Order Management  
- 📈 Dashboard & Reports  
- 🔐 Security System Integration  
- 🔥 Fire Alarm System Simulation  

All functionalities are wrapped in a **modern, intuitive GUI**, making daily operations smoother and more efficient.

---

## 🛠️ Features

### 🖥️ Software (Qt Creator)

- **Client Management** – Add, update, search, and delete clients  
- **Product Management** – Manage jewelry items with real-time updates  
- **Employee Management** – Control employee data and access  
- **Order Management** – Handle purchases, delivery, and invoices  
- **Scanning card for VIP Access** – Only employees can unlock VIP storage  
- **Modern UI** – Built with Qt signals, slots, and custom styles

### 🔌 Hardware (Arduino Simulation)

- **Access Control** – Simulated with a card and buzzer  
- **Fire Alarm System** – Detects smoke and simulates water sprinklers  
- **Emergency Alert** – Activates buzzer for intrusions or fire  
- **Sensor Simulation** – MQ2 sensor, Servo motor, LEDs, etc.

---

## 🧰 Technologies Used

| Technology             | Version            | Purpose                        | Notes                                                                |
| ---------------------- | ------------------ | ------------------------------ | -------------------------------------------------------------------- |
| Qt Creator (C++)       | Qt 5.12.10         | GUI and application logic      | Stable version with good support for QSerialPort and cross-platform  |
|                        |                    |                                |                                                                      | 
| Arduino                | Arduino IDE 1.8.19 | Hardware simulation & security | Last stable 1.x version, widely compatible with libraries and boards |
|                        |                    |                                |                                                                      |
| WampServer (PHP/MySQL) | 3.2.6              | Database & local server        | PHP 7.4, Apache 2.4, MySQL 8.0; stable and widely compatible     |
|                        |                    |                                |                                                                      | 
| C++                    | —                  | Main programming language      | —                                                                    |


---

## 🎬 Application Presentation

👉 Check out the full project presentation:  
[🔗Canva](https://www.canva.com/design/DAFwTWjroDM/vlxWiKhmTLtvSAmznBw2Ow/edit?utm_content=DAFwTWjroDM&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

---

## 📦 Installation

1- Open a terminal or command prompt and run:
```bash
git clone https://github.com/Ameny323/Smart-Jewelry-.git
cd Smart-Jewelry

2. Open the Project in Qt Creator
Launch Qt Creator.

Open the Gestion_Produit.pro file located in produis Directory.

3. Set Up the Database
Start WampServer.

Open your browser and go to http://localhost/phpmyadmin.

Create a new database (e.g., bijouterie).

Import the SQL dump file located at:
database/bijouterie.sql

🔄 Update Database Connection
You will find a file named connection.cpp, which is responsible for configuring the database connection to MySQL.

To connect the application to your local MySQL database, follow these steps:

📁 Step 1: Open the File
Navigate to:
src/connection.cpp

🧩 Step 2: Locate the Following Code
#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("Gestion_Produit");  // Replace with your DB name
    db.setUserName("amani");                // Replace with your username
    db.setPassword("amani");                // Replace with your password

    if (db.open())
        test = true;

    return test;
}

void Connection::closeConnection() {
    db.close();
}

🛠️ Step 3: Customize the Configuration

| Code Line                               | Replace With                              |
| --------------------------------------- | ----------------------------------------- |
| `db.setDatabaseName("Gestion_Produit")` | Your database name (e.g., `"bijouterie"`) |
| `db.setUserName("amani")`               | Your MySQL username                       |
| `db.setPassword("amani")`               | Your MySQL password                       |


✅ Final Checklist: Ensure Successful Database Connection
Before running the application, make sure the following are in place:

✅ WampServer is running
Launch WampServer and verify that the icon is green in the system tray.

✅ MySQL ODBC 8.0 Driver is installed
You can download it from the official MySQL website if not already installed.

✅ Database exists in phpMyAdmin
Go to http://localhost/phpmyadmin and confirm that your database (e.g., bijouterie) has been created and imported.

✅ Qt connection settings are correctly updated
Ensure you've modified connection.cpp with the correct database name, username, and password.

✅ Rebuild and launch the application
Press Ctrl + R or click Run in Qt Creator to start the app.


🔌 ARDUINO SETUP

🧩 Steps
Connect Arduino to PC via USB

Open arduino/arduino_main.ino in Arduino IDE

Select correct COM port

Click Upload to flash the board


🧪 Feature Testing Guide

| 🔧 **Feature**             | 🧪 **Test Description**                                                |
| -------------------------- | ----------------------------------------------------------------------  |
| 🔐 **Access Button**       | Scan the card → Buzzer sounds and **LED indicates unlock**           |
| 🔥 **Fire Alarm**          | Simulate smoke with MQ2 sensor → **Alarm** and **sprinklers activate**  |
| 👨‍💼 **Employee Section**    | Register a new employee → **Verify secure VIP area access**             |
| 📊 **Reports**             | Perform actions → Check **real-time dashboard** for updates             |


📫 Contact
For any queries or suggestions, contact:
Hiba.bensoltan@esprit.tn

