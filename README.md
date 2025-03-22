# 8-16bit RAM

RAM consists of data cells. For example:

- **2 GB RAM** = 2,000,000,000 bytes
- **2,000,000,000 bytes** = 16,000,000,000 bits

Hence, we would need **16,000,000,000 data cells**.

For this weekend project, I will design both 8-bit and 16-bit RAM.

---

## Designing Data Cells

For the data cells, we will use a **D-Type Flip-Flop** circuit.

### D-Type Flip-Flop Diagram

![D-Type Flip-Flop Diagram](diagrams/Datacell.png)  
_Figure 1: Schematic diagram of a D-Type Flip-Flop and Master-Slave Flip-Flop with a rising edge trigger_

### How the D-Type Flip-Flop Works

In this design, the operation depends on the enable signal (E) represented by a Clock signal (CLK):

- **E high:** The circuit is transparent, so the output (Q) directly follows the input (D).
- **E low:** Changes in D are ignored, and Q holds the last valid state.

---

## Master-Slave Flip-Flop

### Master-Slave Flip-Flop with Rising Edge Trigger

In a Master-Slave configuration:

- The **master** flip-flop captures the input on the rising edge of the clock.
- The **slave** flip-flop follows, updating its output on the falling edge.

This dual-stage process prevents unintended data changes during propagation delays, enhancing the circuit's reliability in timing-sensitive applications.

---

## Video Demonstration

<video width="640" height="360" controls>
  <source src="diagrams/video/D-Type Flip Flop compressed.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>
