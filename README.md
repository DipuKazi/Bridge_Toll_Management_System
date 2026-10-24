# 🌉 Bridge Toll Management System

A console-based toll collection and reporting system for a bridge toll booth, written in **C++**. It was developed as a university (varsity) software development project.

The program lets a toll operator collect tolls from different vehicle types, fine overweight trucks, change toll rates, and view daily reports and total collection, all from a simple menu-driven interface.

---

## ✨ Features

- **Toll collection** for five vehicle types: Bus, Bike, Car, Pickup and Truck
- **Bus categories**: long route bus and local bus, each with its own toll rate
- **Overweight truck detection**: trucks heavier than **40 tons** are not allowed through and are fined instead
- **Editable toll rates**: change any toll amount or the fine amount at runtime
- **Persistent rates**: toll amounts are saved to a text file and loaded again the next time the program starts
- **Detailed daily report**: per-vehicle details (name, code, type, toll paid) plus a summary for each vehicle category
- **Total collection**: shows the day's total of all tolls and fines
- **Date entry**: the operator enters the date, which is shown on the report

---

## 🛠️ Built With

- **Language:** C++
- **Concepts used:** classes and objects, arrays, file handling (`fstream`), switch/menu logic, loops

---

## 📁 Project Structure

```
Bridge_Toll_Management_System/
├── bridge toll management system.cpp   # Main source code
├── bridge toll management system.exe   # Compiled Windows executable
├── bridge toll management system.o     # Compiled object file
├── toll amounts of vehicles.txt        # Saved toll rates (read/written by the program)
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

A C++ compiler such as **g++** (MinGW on Windows, or GCC on Linux/macOS), or an IDE like Code::Blocks / Dev-C++.

### Run on Windows (quick way)

Double-click `bridge toll management system.exe`, or run it from the terminal inside the project folder.

### Compile and run yourself

```bash
# 1. Clone the repository
git clone https://github.com/DipuKazi/Bridge_Toll_Management_System.git
cd Bridge_Toll_Management_System

# 2. Compile
g++ "bridge toll management system.cpp" -o toll_system

# 3. Run (from the project folder so it can find the toll rates file)
./toll_system          # Linux / macOS
toll_system.exe        # Windows
```

> ⚠️ Run the program from the project folder. It reads and writes `toll amounts of vehicles.txt` in the current directory.

---

## 📖 How to Use

When the program starts, it asks for today's date and then shows the main menu:

```
Enter 1 for Toll collection
Enter 2 for see the report
Enter 3 for checking the toll amounts
Enter 4 for changing the toll amounts
Enter 5 for today's total toll collections
Enter 0 to exit the program
```

| Option | What it does |
|--------|--------------|
| **1** | Open the toll collection menu and register vehicles (Bus, Bike, Car, Pickup, Truck) |
| **2** | Show the full daily report |
| **3** | Show the current toll rates |
| **4** | Change a toll or fine amount (saved automatically) |
| **5** | Show the total amount collected today |
| **0** | Exit |

### Collecting a toll

1. Choose **1** from the main menu, then pick the vehicle type.
2. Enter the driver/rider name and the vehicle code.
3. For buses, choose long route or local. For trucks, enter the weight in tons.
4. The toll is displayed. Enter `1` to confirm collection.

### Overweight trucks

If a truck weighs **more than 40 tons**, it is marked overweight, no toll is charged, and the fixed **fine amount** is collected instead. These trucks appear in the "Banned Truck" section of the report.

---

## 💰 Toll Rates

Rates are stored in `toll amounts of vehicles.txt`, one value per line, in this order (amounts in **Taka**):

| Line | Category |
|------|----------|
| 1 | Long route bus |
| 2 | Local bus |
| 3 | Bike |
| 4 | Car |
| 5 | Pickup |
| 6 | Truck |
| 7 | Fine (overweight truck) |

You can edit rates from inside the program (option 4) or by editing the text file directly.

---

## 🧾 Sample Report Sections

The report (option 2) includes:

- Individual bus, bike, car, pickup, truck and banned-truck records
- Count and total toll collected for each vehicle category
- Total fines collected from banned trucks
- Total number of vehicles entered

---

## ⚠️ Known Limitations

This is a student project, so there is room to improve:

- Data is kept in memory only; vehicle records and reports reset when the program closes (only toll rates are saved to a file)
- Names and codes are read with `cin >>`, so they cannot contain spaces
- Each category is limited to 500 records per run (fixed-size arrays)
- Truck driver names are not stored, so they do not appear in the truck report
- No input validation for non-numeric menu input

---

## 🔮 Future Improvements

- Save daily vehicle records and reports to a file or database
- Input validation and better error handling
- Support for names with spaces
- A graphical interface (GUI)
- Login system for toll operators
- Replace fixed arrays with `std::vector` and refactor the code into smaller classes

---

## 👤 Author

**Dipu Kazi**
GitHub: [@DipuKazi](https://github.com/DipuKazi)

Developed as a software development project during university studies.

---

## 📄 License

This project was created for educational purposes. Feel free to use it as a learning reference.
