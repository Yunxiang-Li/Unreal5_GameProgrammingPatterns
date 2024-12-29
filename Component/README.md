# Component Pattern:

## Summary

The Component Pattern is a design approach that encapsulates repeatable behaviors or functionality within self-contained classes, called components. This modular architecture reduces code duplication, enhances maintainability, and ensures updates can be made in one place, affecting all references to the component. Components follow the Single Responsibility Principle, handling one specific task and reducing unintended behavior.

## Concept
Components act as reusable building blocks that encapsulate logic related to a specific behavior or functionality. They simplify development by:
- Reducing code duplication across objects or entities.
- Centralizing logic for easy updates and maintainability.
- Keeping functionalities modular and focused, avoiding unintended cross-behavior effects.

For example, a collision component encapsulates logic to handle shape collisions, making collision checks independent of the shape type. A rendering component manages linking model and texture assets, abstracting away the need to check for these details elsewhere.

## Component Pattern within Unreal
Unreal Engine 5 is built on the **Entity Component System** (ECS), where:
- All game world objects are entities (e.g., actors).
- Entities are composed of various components encapsulating specific behaviors or functionalities.

For instance, a default character in Unreal might include:
- **Capsule Component**: Defines the shape of the object for the physics engine.
- **Mesh Component**: Contains rendering data for displaying the object on the screen.
- **Spring Arm Component**: Dynamically holds objects at a distance (e.g., for camera attachment).
- **Camera Component**: Determines camera position and settings for screen rendering.

## Implementation

Created a custom health component, which allowed designers to easily add features such as health tracking and damage notifications to any actor.

The custom `HealthComponent` class manages an actor's health system. It tracks current and max health, handles damage events, and broadcasts two key events:
- `OnComponentDamaged`: Triggered when the actor takes damage.
- `OnComponentDead`: Triggered when the actor's health reaches zero.
