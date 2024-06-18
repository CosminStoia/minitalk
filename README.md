# Minitalk

## Overview

The `Minitalk` project is a communication exercise from the 42 School curriculum, designed to introduce students to inter-process communication using signals in Unix-based systems. The project consists of two programs: a client and a server. The client sends a string message to the server using signals, and the server receives and displays the message.

## Features

- Simple client-server model using Unix signals (`SIGUSR1` and `SIGUSR2`).
- Efficient and lightweight communication protocol.
- Handles basic error checking and validation.
- Demonstrates asynchronous communication between processes.

## Usage

### Compilation

To compile the `Minitalk` project, ensure that all necessary source files and headers are in your project directory. Use the following compilation command:

```sh
gcc -Wall -Wextra -Werror -o server server.c
gcc -Wall -Wextra -Werror -o client client.c
