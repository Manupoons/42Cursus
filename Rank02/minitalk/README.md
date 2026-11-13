# minitalk

A tiny client/server program that sends text between two processes using only UNIX signals (`SIGUSR1` and `SIGUSR2`). Each character is sent bit by bit.

```
make            # builds server and client
make bonus      # builds server_bonus and client_bonus
```

```
./server                 # prints its PID
./client <PID> "hello"   # sends the message to the server
```

The server prints each message as it arrives and answers the client with a signal to confirm reception. The `*_bonus` files are the same code under the bonus targets.
