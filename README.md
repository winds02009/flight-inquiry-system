# Flight Inquiry System

C++ console application (SEHH2042) for managing and querying flight schedules: airlines and flights are modelled as structs and managed by a `FlightScheduleManagementSystem` class.

## Features
- Load and display airline and flight data
- Search flights, edit flights, sort flights (STL `sort` / `copy_if`)
- Menu-driven console interface

> Note: in this version the data is held in memory (STL `vector`), not in an external SQL database.

## Tech stack
C++ (STL), Visual Studio solution

## Structure
- `group project.sln` - Visual Studio solution
- `group project/FileName.cpp` - full source

## How to run
Open `group project.sln` in Visual Studio and press F5, or: `g++ -std=c++17 "group project/FileName.cpp" -o flight && ./flight`