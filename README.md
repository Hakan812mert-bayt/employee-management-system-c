
# Employee Management System (C-CLI)

A lightweight, console-based Employee Management System implemented in procedural C. This application allows organizations to manage employee records dynamically within a structured in-memory table.

## Features
- **Table Initialization:** Batch initialization of employee datasets with predefined boundary checks.
- **Record Insertion:** Adding new employees with auto-incremented storage.
- **Record Deletion:** Removing employees by unique ID with automated array repositioning (O(n) shifting).
- **Search & Query:** Fast single-record retrieval using linear search.
- **Formatted Tabular Display:** Clean CLI reporting of all active records.

## Technical Details
- **Language:** C (C99 Standard)
- **Data Structures:** Custom `struct` array, dynamic index trackers
- **Memory Safety:** Buffer-overflow protected string scanning (`%19s`) and non-recursive state control.

## Compilation & Execution

Using GCC / Clang:
```bash
gcc -Wall -Wextra main.c -o employee_system
./employee_system
