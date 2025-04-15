# 🧠 Memory Management Simulation in C

This is a simple **Memory Management System** simulation written in C. It demonstrates basic memory allocation and deallocation using the **First-Fit Algorithm**. The program simulates memory usage across a number of time units, tracking fragmentation and wasted memory blocks.

## 🛠️ Features

- First-Fit Memory Allocation Strategy
- Dynamic Process Allocation and Deallocation
- Tracks Fragmentation and Wasted Memory
- Console-based simulation output

## 📁 File Structure

- `memory_management.c` – Main program file containing simulation logic

## 🔧 How It Works

1. Memory is represented as an array of blocks (`MEMORY_SIZE = 1000`).
2. Each time unit:
   - A new process is created and assigned a random size (1–200).
   - Memory is allocated using the first-fit strategy.
   - On every even time unit, a random process is deallocated.
   - Fragmentation and memory status are printed.

## 📌 Limitations

- Simulated memory block logic is simplistic and may not reflect actual OS-level memory management.
- The implementation does not handle merging of free blocks (coalescing).
