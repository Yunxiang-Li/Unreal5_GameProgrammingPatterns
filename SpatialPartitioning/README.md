# Spatial Partitioning

## Summary

Collision checks and rendering computations in a large game world can become computationally expensive. **Spatial Partitioning** divides the game world into smaller, more manageable regions (cells), reducing the number of comparisons required for spatial queries like collision detection, visibility culling, and light influence calculations. This technique helps achieve better performance in games by localizing queries to relevant regions instead of processing the entire game world.

## Concept

### Divide the World into Cells

- The game world is divided into smaller cells, each representing a subsection of space.
- Objects are assigned to these cells based on their position.

### Handle Large Objects

Large objects spanning multiple cells are handled in two primary ways:
- **Promotion to Parent Cells**: Assigned to the smallest parent cell that fully contains them, simplifying traversal but reducing precision. Common for rendering and lighting.
- **Referenced in Multiple Cells**: Duplicated or referenced in all overlapping cells, ensuring precise spatial queries. Common for physics and collision detection.

### Octree Overview

An **octree** is a hierarchical data structure used to partition 3D space. Each cubic region is recursively subdivided into eight smaller cubes (octants).
####  Benefits
  - Efficiently reduces the search space for spatial queries.
  - Useful for dynamic or static objects, with different update strategies.
####  Applications
**Rendering and Lighting**:
- Objects are promoted to parent nodes to simplify traversal.
- Often used for visibility culling and determining light influence.

**Physics and Collision Detection**:
- Objects are referenced in all overlapping nodes for precision.
- Ensures accurate narrow-phase collision detection.

## Spatial Partitioning within Unreal

### Octree for Rendering/Lighting/Physics

Unreal Engine uses spatial partitioning techniques to optimize rendering, lighting and physics. These techniques include **hierarchical structures**, such as octrees, depending on the system. For instance, one octree within Unreal resides in the `Fscene` class and is used by the render thread to determine quickly whether an object exists in the light’s area of effect. This way, the number of lighting calculations is drastically reduced

### World Partition for Large-Scale Worlds

Unreal Engine 5 introduced **World Partition**, a system designed for managing open worlds efficiently.
**Flat Grid System**:
- Unlike octrees, World Partition uses a **single-layer grid** to divide the game world into cells.
- Cells are streamed in and out of memory dynamically based on the player’s position.
**Integration with Level of Detail (LOD)**:
- Adjusts the level of detail dynamically for objects based on distance from the player.
- Reduces rendering cost without sacrificing visual quality.
