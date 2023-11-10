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




