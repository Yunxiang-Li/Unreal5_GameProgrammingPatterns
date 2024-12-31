# Tick, Timelines, and Event-Driven Systems

## Summary

This section explores the use of **Tick**, **Timers/Timelines**, and **Event-Driven Systems** in Unreal Engine to address inefficiencies and improve CPU performance. By examining the evolution of a guard tower system in an RTS game, we reduce reliance on Tick for continuous updates and leverage better solutions to optimize resource usage and gameplay behavior.

## Concept

### 1. Tick:

- A per-frame update mechanism often used to execute repetitive logic.
- Challenges: High CPU overhead, reliance on hardware-specific frame rates, and inefficient polling.

### 2. Timers and Timelines:

- Timers: Execute functions after specific delays or intervals, reducing constant checks.
- Timelines: Manage dynamic behaviors (e.g., animations, rotations) over time using curves and tracks, reducing polling overhead while improving gameplay responsiveness.

### 3. Event-Driven Systems:

- React to specific events rather than constantly checking conditions.
- Efficient and scalable, with minimal per-frame processing.

## Tick, Timelines, and Event-Driven Systems Within Unreal

Unreal Engine provides multiple approaches for implementing recurring or conditional logic in games, including **Tick**, **Timers/Timelines**, and **Event-Driven Systems**. These mechanisms differ in how they process events, manage computational resources, and integrate into gameplay.

### Tick

The **Tick** event allows code to run every frame, making it a straightforward option for continuous updates like movement, physics, or checking conditions. However, its frame-dependent nature can lead to inefficiencies:

- **Issues**: It executes logic every frame, whether or not it's necessary, which can strain performance in complex systems.
- **When to Use**: Ideal for continuous, frame-sensitive behaviors (e.g., updating animations or calculating physics).

### Timelines

Timelines are designed for time-based behaviors using curves and tracks to control properties dynamically. They offer a better alternative to Tick for specific use cases:

- **Key Features**:
  - Curve-driven logic for precise control over movement, rotation, or animations.
  - Multiple synchronized tracks for complex behaviors.
- **Advantages**: Reduce redundant per-frame checks and improve gameplay design by introducing telegraphing through dynamic curves.
- **When to Use**: Best for animations, smooth transitions, or predictable time-based behaviors.

### Event-Driven Systems
Event-Driven Systems process logic only when specific events occur, avoiding the overhead of constant per-frame polling:

- **How They Work**: Use collision events, input events, or other triggers to initiate logic.
- **Advantages**:
  - Highly efficient, as they avoid redundant checks.
  - Scale well in systems with many actors or components.
- **When to Use**: Ideal for discrete actions like collision detection or triggering abilities.

## Implementation

To demonstrate the evolution of these techniques, we explore three iterations of a guard tower system in an RTS game. Each iteration addresses specific issues by leveraging Unreal's systems to reduce performance costs and improve gameplay.

### 1. Tick-Based System (`GuardTower_CH5_1`)

**Description**: The initial implementation relies entirely on `Tick` for all logic, leading to inefficiencies:

- **Behavior**: The guard tower continuously rotates its searchlight and performs a sphere trace every frame to detect players.
- **Issues**:
1. **Expensive Sphere Traces**: Running a sphere trace every frame for every guard tower consumes significant CPU resources.
2. **Repeated Getter Calls**: Locations and world references are repeatedly fetched instead of being cached.
3. **Unoptimized Casting**: Direct casting to classes inflates memory usage when larger classes are involved.
4. **Gated Polling**: Polling conditions (e.g., player detection) on every frame wastes computational resources when conditions fail.
5. **Hardcoded Values**: Rotation speed and limits are constants, making them inflexible and frame-rate-dependent.

**Solution**:

- Cache frequently accessed data like world pointers.
- Use `DeltaTime` to ensure frame-rate independence for values like rotation speed.
- Replace hardcoded constants with configurable variables exposed to designers.

### 2. Timeline-Based System (`GuardTower_CH5_2`)

**Description**: This version replaces `Tick` with Timelines for managing the searchlight's rotation, significantly improving efficiency:

- **Behavior**:

  - A Timeline drives the searchlight's rotation using a predefined curve, reducing reliance on per-frame checks.
  - Designers can modify rotation speed and limits via the curve.

- **Improvements**:

1. Eliminates constant polling for rotation updates.
2. Introduces **telegraphing**: The curve slows down the rotation near direction changes, signaling the next action to the player.
3. Designers gain control over behavior by tweaking the Timeline curve.

**Limitations**:

- The system still uses a sphere trace every frame to detect players, which mirrors the polling issue from the previous implementation.

### 3. Event-Driven System (`GuardTower_CH5_3`)

**Description**: The final iteration fully replaces frame-based polling with an Event-Driven System, eliminating unnecessary per-frame checks:

- **Behavior**:

  - A sphere collider is attached to the searchlight, triggering overlap events when a player enters or exits the detection zone.
  - When overlap begins, a line trace verifies if the player is visible (e.g., no obstacles block the line of sight).

- **Improvements**:

1. **Sphere Collider**: Uses collision events (OnComponentBeginOverlap, OnComponentEndOverlap) to detect player presence instead of running traces every frame.
2. **Line Trace**: Verifies visibility only when the player is detected, avoiding unnecessary computations.
3. **Flipped Logic**: Instead of the guard tower querying the world every frame, the world notifies the guard tower only when relevant.

**Advantages**:

- Drastically reduces computational overhead.
- Scales efficiently with multiple guard towers or players.
- Maintains accurate detection without relying on per-frame checks.