# Decoupled System

## Overview

This section demonstrates an example of how to decouple a system effectively in Unreal Engine.

## Key Concept

In Unreal Engine, systems can be decoupled using the following rule:  
**Functions for downward communication, events for upward communication, and interfaces for horizontal communication.**

This approach ensures a clean architecture where each class interacts only with the layer directly below it while maintaining robust signaling capabilities across the entire system.

## Implementation

### Player and Controller Management
- **Runtime Spawning:** 
  - Below the `PlayerController`, all objects can be spawned at runtime.
  - Spawned objects are cached using `TObjectPtr<T>` variables (`T` being the specific type).
- **PlayerController Caching:** 
  - New `PlayerController`s are automatically created when levels load.
  - `PostLogin` and `Logout` in `AGameModeBase` handle caching:
    - Use `PostLogin` to cache `PlayerController`s in a `TArray<TObjectPtr<APlayerController>>`.
    - Cache `AIController`s upon AI pawn spawning using the instigator reference.

> **Note:** `PostLogin` only triggers for `PlayerController`s, while `Logout` handles all controller types. Defensive coding is crucial in `Logout`.

### Communication Tools
1. **Public Functions:**  
   - Direct communication using cached variable references of the appropriate type.
2. **Event Delegates:**  
   - For anonymous communication when a listener has a reference to the event's class.
   - Useful for signaling back up the hierarchy.
3. **Interfaces:**  
   - Enables communication across branches without direct references.
   - Allows invoking functions on `AActor*` references obtained at runtime (e.g., via collision events).

### Visual Representation

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/UML.png" alt="UML Diagram"/>
</div>

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/SequenceDiagram.png" alt="Sequence Diagram"/>
</div>

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/SignalPath.png" alt="Signal Path"/>
</div>

### Class Structure
1. **`GameMode_CH7`:**  
   Inherits from `AGameModeBase`. Acts as the high-level class managing `PlayerController_CH7` and AI Controllers.
2. **`PlayerController_CH7`:**  
   Inherits from `APlayerController`. Represents the player's controller.
3. **`AIController_CH7`:**  
   Inherits from `AAIController`. Represents AI controllers in the level.
4. **`AIUnit_CH7`:**  
   Inherits from `APawn`. Represents each enemy.
5. **`Character_CH7`**
   Inherits from `ACharacter`. Represents the player.
4. **`Widget_Score_CH7`:**  
   Inherits from `UUserWidget`. Used to display player's current socre.