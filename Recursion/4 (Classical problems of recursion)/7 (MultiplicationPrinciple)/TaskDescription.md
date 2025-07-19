**Section 6.4.1 – The Multiplication Method**

Given *n* sets $S_i$ (with $i \in [0, n)$), each of cardinality $|S_i|$, the number of ordered *t*-tuples $(s_0, s_1, \ldots, s_{n-1})$, where:

* $s_0 \in S_0$
* $s_1 \in S_1$
* $\ldots$
* $s_{n-1} \in S_{n-1}$

the total number of such tuples can be calculated using the following formula:

$\text{Total Tuples} = |S_0| \times |S_1| \times \cdots \times |S_{n-1}|$

---

Alternatively, if:

* an object $x_0$ can be selected in $p_0$ ways from a group,
* an object $x_1$ can be selected in $p_1$ ways,
* and so on up to $x_{n-1}$, which can be selected in $p_{n-1}$ ways,

then the total number of ways to choose a *t*-tuple $(x_0, x_1, \ldots, x_{n-1})$ is:

$p_0 \cdot p_1 \cdot \ldots \cdot p_{n-1}$

---

### Example 6.1

In a game, it is necessary to select 3 symbols, each one from a different set of symbols. The sets are:

* $S_0 = \{ A, B \}$
* $S_1 = \{ 0, 1 \}$
* $S_2 = \{ X, Y, Z \}$

We calculate the number of possible combinations by multiplying the sizes of the sets:

$|S_0| = 2$, $|S_1| = 2$, $|S_2| = 3$

$	ext{Total Combinations} = 2 	imes 2 	imes 3 = 12$

We select one symbol from each set. The number of possible combinations (ordered 3-tuples) is:

The 12 combinations can be neatly listed as follows:

* (A, 0, X)  (A, 0, Y)  (A, 0, Z)
* (A, 1, X)  (A, 1, Y)  (A, 1, Z)
* (B, 0, X)  (B, 0, Y)  (B, 0, Z)
* (B, 1, X)  (B, 1, Y)  (B, 1, Z)
