# Overview
Embedded Systems (ES)
* real time constraints important like functional requirements for real-time systems
  * Ex: if GPS correctly computes waypoints but not soon enough, then the information may be useless
* most embedded system (like fridge controller) cannot run debugger, resource constrained
* ES require high reliability. example if system has requirement of 4 nines (99.99% uptime) then even 9s downtime is too much
* efficient utilization of space challenge
* power mgmt - switch to LPM (low power mode) when needed
* host platform = where development occurs. target platform = what we develop for

![Alt text](image.png)

# hardware arch

* abstraction of the machine which contains microprocessors, memory, peripherals (clocks, controllers, actuators, sensors etc)
* Some common design factors
  * processing power - how fast of a cpu needed? power consumption limits? MIPS per MW
  * mem reqs - what type of RAM, NVM. how much on eval board, how much on target system
  * peripherals - what needed? SOC has many built-in.
    * need debugging iface - serial port
    * perf more imp than cost
  * realibility - how much failure can we tolerate
  * upgrade - how can field upgrades be done

# SW design

* how do diff func modules interact and synchronize
* how many tasks? how to prioritize them? how to document design and timing constraints?
* schdulability analysis - how to schedule tasks

# system programming concepts

## scope regions

* filename/namespace scope - gloabl/file scope when declared in namespace declaration
* func scope
* func prototype scope
* block scope
* class scope

## storage duration

* static - size and addr determined at compile time. Lifetime is for duration of process. Var declared at file/namespace scope.
* automatic - local var at block scope. stored in run-time stack frame of block. Removed when exiting block.
* dynamic - allocation via malloc/new. slower. user has to free/delete to avoid leaks.

## linkage

whether name declarations in diff scopes refer to the same defn. applies to vars and funcs.

* no linkage - declared in block scope/struct/class. can only be referenced within scope. Func params and local vars normally have no linkage.
* internal linkage - name defined in file/namespace scope. can be used within translation unit. outside of the translation unit same name refers to different 

![Alt text](image-1.png)

## code  transformation process

![Alt text](image-2.jpg)

* object file contains symbol table
* you can use `readelf`, `nm`, `objdump` commands

read more at https://flint.cs.yale.edu/cs422/doc/ELF_Format.pdf

## linker

* a complete prog consists of multiple object files each of which cross-reference the defns of data or funcs in other object files
* process of combining several object files into a single object file is called static linkage
* linker has two major jobs:
  * symbol resolution
  * symbol relocation


Using this example
![Alt text](<Screenshot 2023-11-10 at 18-00-43 Chapter 2 Cross-Platform Development.jpg>)

* both one.c and two.c define sb. Both of these are independent and represent two different values. compiler uses namespace
to distinguish vars. local var is tagged by func to which it belongs and a global by filename.



