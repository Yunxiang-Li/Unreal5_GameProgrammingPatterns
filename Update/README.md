# Update:

## Summary
The Update pattern centralizes the game logic for entities by defining a shared `Update()` method, which is called for each entity during the main game loop. This reduces complexity in the main loop by delegating entity-specific behavior to individual entities, making the code more modular and scalable.

## Concept
- **Naïve Approach**: The main loop directly handles the logic for each entity, causing the loop to grow unwieldy as more entities and behaviors are added.
- **Improved Approach**: Each entity implements its own `Update()` method, encapsulating its behavior. The main loop simply iterates through all entities and calls their `Update()` methods, simplifying the loop and promoting abstraction.
- This pattern shifts responsibility from the main loop to individual entities, making the system more maintainable and modular.

## Update within Unreal
In Unreal Engine, the `Update()` method is implemented as `Tick`. The `Tick` method:
- Executes once every rendered frame for any actor or component that has `Tick` enabled.
- Allows each actor or component to define its own behavior, independent of the main game loop.
- Provides a highly flexible and extensible way to manage per-frame logic within the Unreal Engine framework.
