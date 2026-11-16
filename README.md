# Inverted Search in C

## Project Overview
The Inverted Search project is implemented in C using **Hash Tables and Linked Lists**.

It creates an inverted index of words from multiple text files, allowing users to search for words and identify the files in which they occur.

## Features
- Create an inverted database from multiple text files.
- Store words using a hash table.
- Maintain file and word information using linked lists.
- Search for a word in the database.
- Display the database contents.
- Update the database.
- Save the database for future use.

## Technologies Used
- C Programming
- Data Structures
- Hash Tables
- Singly Linked Lists
- File Handling

## Project Files
- `main.c` – Main program
- `inverted_Search.h` – Header file and declarations
- `create_database.c` – Database creation
- `display_database.c` – Display database
- `search.c` – Search operation
- `update_database.c` – Update database
- `save_database.c` – Save database
- `hash_function.c` – Hash function
- `insert_last.c` – Linked list insertion
- `file_validation.c` – File validation

## How to Compile and Run

Compile the project:

```bash
gcc *.c -o inverted_search
```

Run the executable:

```bash
./inverted_search
```

## Learning Outcomes
- Practical implementation of hash tables.
- Understanding linked list operations.
- File handling in C.
- Applying data structures to solve real-world search problems.
