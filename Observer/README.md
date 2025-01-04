# Observer Pattern:

## Summary

The **Observer Pattern** improves actor communication by enabling better, cleaner solutions. It reduces memory and processing costs by decoupling dependencies between objects.

## Concept

The Observer Pattern in Unreal Engine leverages the **Interface Design Pattern** to facilitate communication between classes without requiring type awareness. Interfaces provide common functions implemented via polymorphism.

One common approach is using **Blueprint Interfaces**, which eliminate the need for class-specific casting and rely on actor references instead.

### 1. Blueprint Interfaces

Blueprint Interfaces in Unreal Engine offer the following features:
- **Blueprint Display Name**: Defines how the interface appears in the Class Settings of a Blueprint.
- **Blueprint Description**: Provides a mouseover hint in the interface selection dropdown.
- **Event Function**: Requires a Return Node to mark the function's end.

### 2. Event Delegate

Event Delegates are essentially function pointers that enable dynamic logic flow at runtime. They broadcast signals to multiple program areas without the sender knowing the recipients. This is fundamental to event-driven programming in Unreal Engine.

## Interface Pattern within Unreal

When using interfaces, Unreal Engine assumes that references are typically generic (`AActor*`). If the reference is already of the correct type, the interface provides limited benefits, and the communication strategy should be reevaluated.

There are two primary ways to call functions via interfaces:
- Casting to the interface type and invoking instance functions.
- Static Calls to the function, bypassing the instance.

## Observer Pattern within Unreal

In Blueprint, **Event Dispatchers** simplify delegate usage. These must be defined in the broadcasting class. Blueprints can respond to their own dispatchers, similar to any other listening delegate.

To use a dispatcher:
- Create it in the broadcasting class.
- Bind it to an event that performs the desired response.

## Implementation

The following implementation demonstrates the Observer Pattern using Event Dispatchers and Event Delegates:

`BI_Test`: A Blueprint interface asset for exploration purposes.

`BP_Test`: A Blueprint class inheriting from `Object` and implementing the `BI_Test` interface.

`Flammable`: A custom interface for flammable actors.

`Tree`: A class inheriting from `AActor` and implementing `IFlammable`.

### Event Delegates in C++

C++ Event Delegates provide more control and flexibility compared to Blueprints. Key types include:
- **DYNAMIC**: Serialized in the editor for easy Blueprint binding.
- **MULTICAST**: Supports multiple listeners but does not allow return values.
- **SPARSE**: Uses memory only when subscribed, ideal for rarely used delegates (e.g., marketplace tools).

### Health Component Example

A custom `HealthComponent` class demonstrates how event delegates enable anonymous communication, eliminating the need for direct object references. This reduces code coupling, improving maintainability as the codebase grows.