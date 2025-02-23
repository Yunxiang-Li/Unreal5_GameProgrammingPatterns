# Unreal5_GameProgrammingPatterns

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

The implementation of multiple game programming patterns within Unreal Engine 5.
You can check screenshots/GIFs and more information about this project from my [personal portfolio website](https://yunxiang-li.github.io./#/game-projects).

## Table of Contents

- [Overview](#Overview)
- [Install](#install)
- [Usage](#usage)
- [Structure](#Structure)
- [Maintainers](#Maintainers)
- [License](#license)

## Overview

This project include several Unreal projects about the implementation of multiple game programming patterns, inspired by the book **Game Programming Patterns** and **Game Development Patterns with Unreal Engine 5: Build maintainable and scalable systems with C++ and Blueprint**.

## Install

I use Unreal5.2.1 and JetBrains Rider for this project under Windows 10 environment.<br>
[Unreal download](https://www.unrealengine.com/en-US/download)<br>
[JetBrains Rider download](https://www.jetbrains.com/rider/download/#section=windows)<br>

## Usage

1. Download this repo, open(or zip and open) the **Unreal5_GameProgrammingPatterns** folder.

2. Double click related **uproject** file within each project folder.

3. Let the **Unreal Game Engine** rebuild the demo.

## Structure

Details of each project are explain within each project's Readme file.
1. [HelloPatterns](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/HelloPatterns)<br>
   Pure Blueprints project, contains 3 examples about how to optimize certain Blueprints to increase performance.
2. [DoubleBuffer](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/DoubleBuffer)<br>
   A brief introduction about double buffer pattern.
3. [Flyweight](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/Flyweight)<br>
   A brief introduction about flyweight pattern.
4. [SpatialPartitioning](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/SpatialPartitioning)<br>
   A brief introduction about spatial partitioning.
5. [Component](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/Component)<br>
   Create a custom health component which can track health, handle damage events and broadcast two key events.
6. [Update](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/Update)<br>
   A brief introduction about update pattern.
7. [BehaviorTree](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/BehaviorTree)<br>
   Build a behavior tree for a simple real-time strategy (RTS) AI Unit. Introduce various building blocks such as selectors, sequences, decorators, services, and tasks.
8. [EventDriven](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/EventDriven)<br>
   Make **3** iterations of one certain implementation to demonstrate techniques of Tick, Timers/Timelines and Event-Driven Systems.
9. [Observer](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/Observer)<br>
   Update previous implemented custom HealthComponent class to demonstrate how event delegates enable anonymous communication, eliminating the need for direct object references.
10. [DecoupledSystem](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/DecoupledSystem)<br>
   Decouple a small system using following rules:
   - Functions for downward communication
   - Events for upward communication
   - Interfaces for horizontal communication.
       
## Maintainers

[@Yunxiang-Li](https://github.com/Yunxiang-Li).

## License

[MIT license](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/LICENSE)
