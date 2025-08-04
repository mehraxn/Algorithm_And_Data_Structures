# README: Understanding `stack` in Kosaraju's Algorithm Implementation

## Purpose of the Program

This program implements **Kosaraju's algorithm** to find **Strongly Connected Components (SCCs)** in a directed graph using an adjacency matrix representation.

## Focus: Purpose of the `stack` Array

The `stack` array plays a critical role in **Kosaraju's two-pass depth-first search (DFS)** approach. Its purpose is to **store vertex indices in the order of their DFS finishing times** from the **first DFS pass on the original graph**.

### What the `stack` Contains

* The `stack` contains **vertex indices**, not their finishing times.
* These indices are pushed onto the stack **after the DFS finishes exploring all descendants of a vertex** (i.e., after the postorder traversal).
* This means a vertex with a later finish time is placed **closer to the top of the stack**.

### Why This is Important

The ordering in the `stack` ensures that during the **second DFS pass on the transposed graph**, we explore vertices in the **correct order** to identify SCCs. By starting with the vertex that finishes last (i.e., on top of the stack), we ensure that we explore each SCC fully before moving on to the next.

### Important Clarification

> **The `stack` does NOT store actual finish times.**
>
> Instead, it **implicitly represents** the finish time ordering by the order in which vertices are pushed.

So, even though the DFS does not explicitly compute or store finish times (like timestamps), the order in the `stack` serves the same purpose.

### Analogy

Think of the `stack` as a "schedule" that says:

> "After finishing all reachable nodes from vertex A, push A onto the stack."

This gives you the reverse of the actual finish time order, which is exactly what Kosaraju's algorithm needs.

## Summary

* The `stack` is used during the **first DFS pass only**.
* It stores **vertex indices** in the order of their **DFS finish times**.
* This order is used to guide the **second DFS pass** on the transposed graph.
* It does **not** store numeric timestamps or finish times directly.

This design ensures correct detection of all strongly connected components in linear time (relative to number of vertices and edges).

---

For further understanding, you may step through the code and observe how the stack changes as the DFS progresses.
