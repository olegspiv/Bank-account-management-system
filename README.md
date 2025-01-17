
# Project Name: **Bank Account Management System**  

This project implements a **Bank Account Management System** using C++ and adheres to the **SOLID** principles of object-oriented programming. Below, you'll find an overview of the project, its structure, and its design principles.

---

## **Overview**  

The Bank Account Management System simulates basic banking functionalities such as opening accounts, depositing and withdrawing money, balance inquiries, and account closures. Users interact with the system through a command-line interface, which ensures user-friendly operation and straightforward interaction.

---

## **Features**  

1. **Open and close bank accounts**  
2. **Deposit and withdraw funds**  
3. **Balance inquiry**  
4. **Print all account details**  
5. **Save data to and restore from a CSV file**

---

## **Project Structure**  

The project is composed of the following files:  

- **`main.cpp`**: Entry point of the application, which initializes the user interface and controls the application's main loop.  
- **`user_interface.hpp` / `user_interface.cpp`**: Handles user interactions and routes commands to relevant functionalities.  
- **`singleton.hpp`**: Implements a Singleton class to manage account data shared across different components.  

Additional files (e.g., `open_bank.hpp`, `csv_file_management.hpp`) handle specific operations like file management and account manipulations.

---

## **Special Note: PIN Number for Bank Operations**  

Currently, the default PIN number for bank operations is **1234**.  
If you want to change this value, you can modify it in the file **`password_protection.hpp`** under the constant **`PASSWORD`**.

---

## **Design Principles (SOLID)**  

### **S - Single Responsibility Principle**  
Each class has a single, well-defined responsibility:
- `user_interface`: Manages user interactions and input/output.  
- `singleton`: Manages shared state and account data.  
- Helper classes (e.g., `open_bank`, `csv_file_management`) manage specific operations related to banking functionalities.

### **O - Open/Closed Principle**  
The system is designed to be open for extension but closed for modification:
- Enumerations and switch cases in `user_interface` enable easy addition of new functionalities without altering existing ones.  

### **L - Liskov Substitution Principle**  
Wherever base class objects or derived interfaces are used, derived types ensure the expected behavior, maintaining consistency.

### **I - Interface Segregation Principle**  
The system uses tailored classes and modular functions, ensuring classes only implement methods they directly need.

### **D - Dependency Inversion Principle**  
High-level modules like `user_interface` do not depend on low-level modules; instead, they rely on abstractions to ensure flexibility and modularity.

---

## **Usage Instructions**  

### **Compilation and Execution**  
1. Compile the program:  
   ```bash
   g++ *.cpp -o bank_system
   ```
2. Run the program:  
   ```bash
   ./bank_system
   ```

### **Commands**  
Follow the prompts to interact with the system. For example:
- **Open the Bank** (0)  
- **Deposit Funds** (3)  
- **Save and Exit** (7)  

---

## **Future Extensions**  

- **GUI Implementation**: Introduce a graphical interface for enhanced user experience.  
- **Transaction History**: Add detailed transaction tracking for each account.  
- **Security Enhancements**: Implement advanced authentication mechanisms.  

---

This project demonstrates the power of the **SOLID** principles, creating a robust, extendable, and maintainable system.
