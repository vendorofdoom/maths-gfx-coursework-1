# Coursework 1 - L-Systems

## Hotkeys

| Key                   | Action                         |
|----------------------:|--------------------------------|
| Right / Left arrow    | Increase/Decrease iterations   |
| Up / Down arrow       | Increase/Decrease line length  |
| [ bracket / ] bracket | Increase/Decrease angle        |
| , comma / . full stop | Increase/Decrease random seed  |
| 1 - 9                 | Load l-system from config file |
| Shift                 | Toggle l-system root location  |
| Spacebar              | Display set of plants generated from same, stochastic L-system |

## Config File Format

| Line | Value            | Format              |
|-----:|------------------|---------------------|
| 1    | Name             | String              |
| 2    | Line length      | Int                 |
| 3    | Num Iterations   | Int                 |
| 4    | Angle            | Float               |
| 5    | Axiom            | String              |
| 6+   | Production Rules | Symbol(Char)\|Probability(Float)\|Successor(String) |
