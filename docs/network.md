# Network
Two fully connected adject layers of activations \f$(x_1,y_1)\f$ \f$(a_i)\f$ \f$(a_i)\f$ and \f$a_{i+1}\f$, connected by weights  \f$w_{i}\f$ are shown below.

<br>
image here
<br>

\f$a_{i+1}\f$ is calculated  with the equation below

<br>
<br>
\f[
\begin{bmatrix}
w_{11}^{i} & w_{12}^{i} & w_{13}^{i} & \cdot \cdot \cdot & w_{1n}^{i}\\
w_{21}^{i} & w_{22}^{i} & w_{23}^{i} & \cdot \cdot \cdot & w_{2n}^{i}\\
w_{31}^{i} & w_{32}^{i} & w_{33}^{i} & \cdot \cdot \cdot & w_{3n}^{i}\\
\cdot & \cdot & \cdot && \cdot \\
\cdot & \cdot & \cdot && \cdot \\
\cdot & \cdot & \cdot && \cdot \\
w_{m1}^{i} & w_{m2}^{i} & w_{m3}^{i} & \cdot \cdot \cdot &  w_{mn}^{i}
\end{bmatrix}
\begin{bmatrix}
a_{1}^{i} \\
a_{2}^{i} \\
a_{2}^{i} \\
\cdot \\
\cdot \\
\cdot \\
a_{n}^{i} \\
\end{bmatrix}
=
\begin{bmatrix}
w_{11}^{i}a_{1}^{i} + w_{12}^{i}a_{2}^{i} + w_{13}^{i}a_{3}^{i} + \cdot\cdot\cdot + w_{1n}^{i}a_{n}^{i} \\
w_{21}^{i}a_{1}^{i} + w_{22}^{i}a_{2}^{i} + w_{23}^{i}a_{3}^{i} + \cdot\cdot\cdot + w_{2n}^{i}a_{n}^{i} \\
w_{31}^{i}a_{1}^{i} + w_{32}^{i}a_{2}^{i} + w_{33}^{i}a_{3}^{i} + \cdot\cdot\cdot + w_{3n}^{i}a_{n}^{i} \\
\cdot \\
\cdot \\
\cdot \\
w_{m1}^{i}a_{1}^{i} + w_{m2}^{i}a_{2}^{i} + w_{m3}^{i}a_{3}^{i} + \cdot\cdot\cdot + w_{mn}^{i}a_{n}^{i}
\end{bmatrix}
=
\begin{bmatrix}
a_{1}^{i+1} \\
a_{1}^{i+1} \\
a_{1}^{i+1} \\
\cdot \\
\cdot \\
\cdot \\
a_{m}^{i+1}
\end{bmatrix}
\f]
<br>
<br>

Each row of the weights matrix is shown below