# Coursework 1 - L-Systems

## Hotkeys

| Key                   | Action                         |
|----------------------:|--------------------------------|
| right / left arrow    | Increase/Decrease iterations   |
| up / down arrow       | Increase/Decrease line length  |
| left square-bracket [ / right square-bracket ] | Increase/Decrease angle        |
| comma , / full stop . | Increase/Decrease random seed  |
| 0 - 9                 | Load L-system from config file |
| shift                 | Toggle L-system root location  |
| spacebar              | Display set of plants generated from same, stochastic L-system |

## Config File Format

| Line | Value            | Format              |
|-----:|------------------|---------------------|
| 1    | Name             | String              |
| 2    | Line length      | Int                 |
| 3    | Num Iterations   | Int                 |
| 4    | Angle            | Float               |
| 5    | Axiom            | String              |
| 6+   | Production Rules | Symbol(Char)\|Probability(Float)\|Successor(String) |
