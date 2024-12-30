# Behavior Tree:

Reused `HealthComponent` class from [Component pattern](https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/tree/main/Component)

## Summary
The Behavior Tree pattern is a decision-making tool for AI that organizes logic into a tree structure. It uses reusable nodes to evaluate conditions and determine actions dynamically. This approach simplifies complex AI behavior by modularizing tasks and logic into composites and tasks.

## Concept
- **Structure**:
  - Behavior Trees start at a root and evaluate nodes in a specific order (left-to-right, top-to-bottom).
  - Nodes are categorized into:
    - **Composite Nodes**: Control the flow of logic.
      - **Selector Node**: Stops when a child succeeds.
      - **Sequence Node**: Stops when a child fails.
      - **Simple Parallel Node** (not covered): Allows simultaneous execution of two child nodes.
    - **Task Nodes**: Perform specific actions or checks. These cannot have children and either succeed or fail.

- **Reusability**:
  - Behavior Trees favor fragmentation and modularity, allowing nodes to be reused across different AI units.
  - Microsoft used this technique in *Halo 2*, where different enemy types shared reusable nodes but had unique behavior trees based on their priorities.

- **Execution**:
  - The Behavior Tree traverses nodes in order until it finds a node that succeeds or the tree fails entirely. The order of nodes is critical as it determines AI priorities.

## Behavior Tree within Unreal
- Unreal Engine 5 supports Behavior Trees natively with tools like:
  - **Behavior Tree Editor**: Visualizes the tree structure for easy editing.
  - **Blackboard Assets**: Stores contextual data for decision-making and enables communication between nodes.
  - **Selector and Sequence Nodes**: Core composite nodes used to guide logic.
  
- Tasks are implemented using Blueprint or C++, allowing flexible and customized AI behavior.
- Unreal integrates these tools seamlessly with AI Controllers, enabling dynamic, reusable, and efficient decision-making for AI entities.


## Implementation

A behavior tree is built for a simple real-time strategy (RTS) AI in the RTS framework.
Various building blocks of behavior trees, including selectors, sequences, decorators, services, and tasks are introduced.

1. `GM_RTS`: This is the game mode. It contains references to the various classes for the framework
to work.

2. `PC_RTS`: This is the player controller. It contains the functionality to left-click selectable units and right-click on the world in order to tell the unit where to go.

3. `BP_CameraPawn`: This is our pawn. It is a simple pawn blueprint with a camera that is set up to be placed directly in the center of the map.

4. `BPI_Units`: This is our Blueprint interface. It contains three functions: `SetMoveLocation`, `Stop`, and `AttackTarget`:
- `SetMoveLocation` has a vector input, Target Location
- `AttackTarget` has an object input, TargetToAttack
- `Stop` is just a function name and does not have any inputs or outputs

5. `BP_EliteUnit`: This is our character blueprint. It extends from the Unreal base character class and implements the BPI_Units Blueprint interface. We are making use of the standard mannequin character mesh here.<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BP_EliteUnit_One.png"/> </div>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BP_EliteUnit_Two.png"/> </div>

6. `BP_EnemyUnit`: This is a second character blueprint.<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BP_EnemyUnit.png"/> </div>

7. `AIC_EliteUnit`: child of `AIController`, an AI unit that the player will be able to control. The player will only be able to tell the unit where to move. They will do this by first selecting the unit using a left-click and then selecting a desired location for the unit to move to by right-clicking on the floor. The unit will then move to the location. When not moving, the unit will search to see if any enemy units are within a radius of its current location. If it finds an enemy, the unit will then turn to face the enemy and shoot at it.<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/AIC_EliteUnit.png"/> </div>

8. `BB_EliteUnit`: A Blackboard asset is a shared memory space for AI in Unreal Engine. It stores key-value pairs that represent the AI's knowledge of the world and supports decision-making in Behavior Trees.

9. `BT_EliteUnit`: The overall behavior tree used in this project.<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BT_EliteUnit.png"/> </div>

10. `BTT_ShootTarget`: A Blueprint task within behavior tree that enables the character to shoot enemies. It utilizes the **Event Receive Execute AI** node, which runs when the task is executed by an AI Controller and gives direct access to both the AI Controller and the Controlled Pawn, allowing to customize AI-specific logics (e.g., moving to a target or playing animations).<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BTT_ShootTarget.png"/> </div>

11. `BTS_FindNearestTarget`: A service within behavior tree which finds nearest target.<br>
<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal5_GameProgrammingPatterns/blob/main/Screenshots/BTS_FindNearestTarget.png"/> </div>
