# Decoupled System:

## Summary

This section shows one example of how to decouple a certain system.

## Implementation

In Unreal, everything below the `PlayerController` can be spawned at runtime. All spawned objects can be cached as `TObjectPtr<T>` variables, with `T` being the exact type we need. When a new level loads, it creates new Controllers automatically, but it does so using multiplayer terminology and a networked method. Overriding the `PostLogin` and `Logout` functions of `AGameModeBase`, `PlayerController`s can be cached in a `TArray<TObjectPtr<APlayerController>>` for later use. `PlayerController`s can be cached via the `PostLogin` function with a cast to the respective base type as needed, but `AIController`s must be cached when the AI-controlled pawn is spawned and accessed via the instigator reference. `PostLogin` only fires for `PlayerController`s, yet `Logout` deals with all controller types, including AI. This makes defensive coding important in `Logout`.

- **Public functions** are used for communication when there is a cached variable reference of
the correct type.
- **Event delegates** allow anonymous communication when the listener has a cached variable reference for the event’s class. This ends up being the exact opposite of the public function calls, allowing communication to back up.
- **Interfaces** are the final tool and allow communication between different branches without creating a link. Providing an `AActor*` reference that can be gained at runtime, usually via some kind of collision event, the interface can be used to invoke some kind of function without needing to know the exact type of the receiver.

This boils down to a simple communication rule: **functions down, events up, and interfaces sideways**. The result is a decoupled system in which each class only has reference to the one layer below it and yet signals can be sent all over with ease.