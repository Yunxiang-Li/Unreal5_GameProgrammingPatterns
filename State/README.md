# State Pattern:

## Summary

The State pattern allows behavior to be separated based on different states an object can be in. This pattern is widely used in game development, particularly in animation state machines, AI logic, and player control systems. It helps manage complex behaviors by structuring transitions between states, ensuring that each state is responsible for its own logic.

State machines are essential in many game systems, from character animations (walking, jumping, attacking) to AI decision-making and contextual interactions. The pattern can be implemented in multiple ways, ranging from simple enum-based state machines to pushdown automata that manage hierarchical state transitions.

## Concept

A state machine consists of states and transitions:

- **State**: Represents a specific behavior or output (e.g., an animation state defining which animation should play).
- **Transition**: Defines when and how a state changes based on input, conditions, or external triggers.
Transitions help control the flow between states. For example, in an animation state machine:
- A JumpStart state transitions into JumpLoop when the jump animation is nearly finished.
- JumpLoop transitions into JumpEnd when the player lands.
- JumpEnd transitions into Idle or Run depending on the character's velocity.
State machines can be refined by introducing conduits, hierarchies, and concurrent states to better manage complex behaviors.

## Limitations

While state machines provide structure, they also introduce challenges:

- **Scalability Issues**: A naive implementation can lead to state explosion, where every possible transition must be explicitly defined.
- **Complexity**: As the number of states and conditions grows, managing transitions becomes difficult.
- **Interdependent State Transitions**: If a state’s behavior depends on multiple previous states, a pushdown automata or hierarchical state machine is required.
- **Performance Concerns**: Running multiple concurrent state machines (e.g., AI behavior + animation + movement) can increase CPU overhead if not optimized.

## Implementation

1. Enum/Switch Implementation (Basic State Machine)
- Uses an enum to represent different states, with a switch statement to handle logic.
- Suitable for simple, mutually exclusive logic (e.g., toggling between Idle, Run, and Jump).
- Limitation: As complexity increases, the switch statement becomes harder to maintain.

2. Stateful States (Instance-Based)
- Instead of handling logic in a switch, each state is a separate class with its own variables and behaviors.
- Can be static (single instance) or instanced (unique per actor).
Static states are useful for AI state machines shared across multiple characters.
Instanced states are needed when states hold unique data (e.g., a charge attack that depends on the actor).
- Works well for animation state machines and complex gameplay mechanics.

3. Concurrent State Machines
- Used when multiple independent behaviors need to be managed simultaneously.
- Example: A character movement state machine (Idle, Run, Jump) running alongside an attack state machine (Light Attack, Heavy Attack).
- Avoids state explosion by keeping different concerns in separate state machines.

4. Hierarchical State Machines
- Introduces state inheritance, allowing common behaviors to be centralized.
- Example: A Grounded state can serve as a parent for Idle, Run, and Crouch, reducing redundant code.
- Improves maintainability and code reuse, making it easier to expand behavior.

5. Pushdown Automata (Stack-Based State Machine)
- Allows states to push and pop from a stack, enabling temporary state changes.
- Example: A character attack animation temporarily overrides movement but should return to the previous movement state afterward. This ensures that the game remembers where it left off before an interruption.
- Commonly used for: Animation state machines or Context-sensitive player actions (e.g., pausing combat to enter a menu and returning seamlessly)
