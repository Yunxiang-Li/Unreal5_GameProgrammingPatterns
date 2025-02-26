# Command Pattern:

## Summary

The Command pattern introduces a layer of separation between requesting an action and executing it. This allows actions to be stored, executed, undone, or replayed, making it highly useful in game development. It is commonly used for undo functionality, input replays, queued actions, and AI behavior planning. In Unreal Engine, the Command pattern can be integrated into Blueprint Utilities for editor tools or implemented in C++ for gameplay mechanics.

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/CommandPatternClassBase.jpg" alt="Command Pattern Class Base"/>
</div>

## Concept

The core idea of the Command pattern is to reify actions into objects, allowing them to be stored in a list or queue. This provides several benefits:

- **Undo Mechanism**: Actions can be stored and reversed using an undo queue (e.g., Ctrl + Z functionality).
- **Input Replay**: Actions are recorded and can be played back for deterministic replays.
- **Queued Actions**: Useful for strategy games where actions are performed in sequence.
- **AI Planning (GOAP)**: AI can pre-generate a sequence of commands and execute them strategically.
In Unreal Engine, the Command pattern can be implemented in Blueprint Utilities using transaction nodes to enable undo functionality for editor tools. For gameplay, it can be implemented in C++, where commands are stored in a queue and executed dynamically.

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/HowCommandPatternWork.jpg" alt="How Command Pattern Work"/>
</div>

## Limitations

While powerful, the Command pattern has some drawbacks:

- **Memory Overhead**: Storing every command for undo/replay can consume a lot of memory, especially for complex games.
- **Complexity**: Managing command execution, undo operations, and AI command queues adds design complexity.
- **Determinism Issues**: Input replay only works if the game state is fully deterministic (e.g., no randomness).
- **Implementation Overhead**: In Unreal Engine, using UObject for command storage can introduce unnecessary engine-specific constraints if not handled properly.

## Implementation

1. Command Pattern for Editor Tools in Unreal (Blueprint Utilities)

- Use Blueprint Utilities to create editor tools that manipulate assets and actors.
- Implement transaction nodes in Blueprints to allow undo functionality when modifying the level (e.g., rotating objects by 45 degrees).

`IsActionForBlueprints`: An Editor Utility Blueprint that checks if input object is of `Actor` type.

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/IsActionForBlueprints.png" alt="Is Action For Blueprints"/>
</div>

`RotateSelected45`: A Blueprint function that rotate selected actor(s) by 45 degress around z axis.

<div align="center"> 
  <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/RotateSelected45.png" alt="Rotate Selected 45"/>
</div>

2. Command Pattern for Gameplay in Unreal (C++)

`CommandBase`: A base command class derived from `UObject`, marked as abstract.
`Command_UnitMove`: A child concrete command class derived from `CommandBase`, which has an `Execute` function to perform moving into certain location.
`EliteUnit`: Contains a queue of commands, which allows execution in sequence.

The Command pattern is a versatile and reusable design pattern in game development, providing structured control over actions, undo mechanics, and AI-driven behavior.