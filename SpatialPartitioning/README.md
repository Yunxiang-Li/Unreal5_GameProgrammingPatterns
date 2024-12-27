# Spatial Partitioning:

## Summary

Collision checks among a large number of objects within a vast game world can be computationally expensive. The raw time complexity of collision detection is approximately O(n^2), and even optimized approaches like O(n*log(n)) can become a bottleneck for large-scale games. **Spatial Partitioning** addresses this issue by dividing the game world into smaller cells and limiting collision checks to objects in the same or neighboring cells, drastically reducing the number of comparisons required.

## Concept

### Divide the World into Cells

#### 1. Cell Division

- The game world is divided into multiple small cells, each representing a subsection of the world.
- Objects are assigned to cells based on their position.

#### 2. Handle Large Objects

If an object spans multiple cells, it is either:
- Assigned to the **smallest parent cell** that fully contains it (modern version, common for rendering optimizations).
- Or **duplicated across multiple child cells** for precise spatial queries (traditional version, common in physics).

#### Tree Structure for Efficiency:

- Cells are organized into a **hierarchical tree structure** for optimized queries:
  - Rendering Octree:
    - A **traditional** octree is used for lighting and rendering, where objects crossing cell boundaries are promoted to the smallest parent cell.
    - This simplifies traversal and reduces memory overhead for render-related calculations.
    - the query scope is limited to objects in the same cell and objects in adjacent cells (to account for edge cases).
  - Physics Octree:
    - A more **modern** octree or similar structure is likely used for physics collision detection, where boundary-crossing objects may be duplicated or referenced in multiple child cells for greater spatial precision.
    - the query scope is limited to objects in the same cell and direct parent or child cells.

## 2D and 3D Spatial Partitioning

- In 2D, this approach often uses a structure called a **quadtree**, where each cell is divided into four smaller quadrants.
- In 3D, the equivalent is an **octree**, where each cubic region is divided into eight smaller cubes.

## Spatial Partitioning within Unreal

### 1. Octree for Render Optimization

Unreal Engine 5 uses a **traditional 3D octree** structure to optimize rendering and lighting calculations. The octree divides the game world into cubic regions and recursively subdivides them into eight smaller cubes along the x, y, and z axes. Objects crossing cell boundaries are promoted to the smallest parent cell that fully contains them. This hierarchical partitioning ensures efficient culling for lighting and rendering.

#### Lighting Calculations:
- The octree resides in the `FScene` class and is primarily used by the render thread.
- It determines quickly whether an object exists within a light's area of effect, drastically reducing the number of lighting calculations required.
- By skipping irrelevant regions, the rendering engine avoids unnecessary computation and improves performance.

### 2. World Partition for Large-Scale World

Unreal Engine 5 introduces **World Partition**, a system specifically designed to manage large open worlds. It provides:

#### Single-Layer Cell Division:
- Users define the size of each cell (or "grid") in the world.
- Unlike the octree, World Partition does not create a hierarchical tree structure. Instead, it uses a **flat**, **single-layer grid** for managing world visibility.

#### Integration with Level of Detail (LOD):
- World Partition hooks into the LOD system, ensuring that only the necessary level of detail is rendered for objects visible on-screen.
- Objects farther away appear with lower detail, improving rendering performance without sacrificing visual quality.
