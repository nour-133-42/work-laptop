*This project has been created as part of the 42 curriculum by helfayez, nalshmai.*

# minishell

## Description

`minishell` is a simplified re-implementation of a Unix shell (similar in spirit to
`bash`), written in C from scratch as part of the 42 school curriculum. The goal of
the project is to understand, at a low level, how a command-line interpreter actually
works: reading input, tokenizing and parsing it, expanding variables, handling quotes,
wiring up pipes and redirections between processes, and executing built-in and
external commands while managing signals and exit statuses correctly.

The shell supports:

- An interactive prompt (`minishell> `) built on the `readline` library, including
  command history.
- Parsing of a command line into tokens, handling single quotes (`'...'`, no expansion)
  and double quotes (`"..."`, with expansion), and pipeline splitting (`|`).
- Redirections: input (`<`), output/truncate (`>`), append (`>>`), and heredoc (`<<`)
  with a delimiter.
- Environment variable expansion (`$VAR`), the exit status variable (`$?`), and
  expansion inside double quotes.
- Execution of pipelines of any length, forking one child process per command and
  connecting them with `pipe`/`dup2`.
- External command execution via `execve`, resolved against the `PATH` environment
  variable.
- The following built-in commands, implemented internally (no fork required when run
  alone): `echo` (with `-n` support), `cd` (including `~`, `-`, and updating
  `OLDPWD`/`PWD`), `pwd`, `export`, `unset`, `env`, `exit`.
- Signal handling for `SIGINT` (Ctrl-C) and `SIGQUIT` (Ctrl-\\), matching bash's
  interactive behavior (redisplaying the prompt, not killing the shell).
- Correct propagation of exit statuses, including for signals and pipelines.

This repository also contains `libft`, a personal reimplementation of a subset of the
C standard library (string, memory, and `printf`-family functions) plus `get_next_line`,
used internally by `minishell` instead of relying on external dependencies (aside from
`readline`).

## Instructions

### Requirements

- A C compiler (`cc`/`gcc`) and `make`.
- The `readline` development library (e.g. `libreadline-dev` on Debian/Ubuntu).
- Optionally, `valgrind` for memory/file-descriptor leak checking.

### Compilation

```sh
make        # builds libft, then compiles and links minishell
```

This produces a `minishell` executable at the root of the repository.

Other Makefile targets:

```sh
make clean   # remove object files (project + libft)
make fclean  # remove object files and binaries (project + libft)
make re      # fclean + all
make run     # build (if needed) and launch minishell
```

### Running

```sh
./minishell
```

You will get a `minishell> ` prompt behaving like a regular shell. Type commands,
pipelines, and redirections as you would in `bash`, and `exit` (or Ctrl-D) to quit.

### Memory / file descriptor checking

The project ships with a Valgrind suppression file (`readline.supp`) to silence known,
harmless leaks from the `readline` library itself, so real leaks in the shell's own
code stand out:

```sh
make supp    # run valgrind with the readline suppressions
make vrun    # run valgrind without suppressions
make rerun   # re + vrun
```

## Resources

- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) — reference for shell grammar, quoting, expansion, and built-in semantics.
- [GNU Readline Library documentation](https://tiswww.case.edu/php/chet/readline/readline.html) — `readline()`/`add_history()` API used for the interactive prompt.
- [POSIX Shell & Utilities specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) — the formal grammar and behavior a POSIX-compliant shell should follow.
- [The Linux Programming Interface](https://man7.org/tlpi/) by Michael Kerrisk — chapters on `fork`, `exec`, pipes, signals, and process groups.
- Manual pages: `execve(2)`, `fork(2)`, `pipe(2)`, `dup2(2)`, `wait(2)`/`waitpid(2)`, `signal(2)`, `readline(3)`.
- [Valgrind Memcheck manual](https://valgrind.org/docs/manual/mc-manual.html) — used for the leak/fd-checking Makefile targets.

### AI usage

An AI assistant (Claude) was used during this project strictly as a support tool, not
to author the shell's core logic:

- Helping debug specific, hard-to-spot issues (e.g. file descriptor leaks around
  heredocs and pipes, edge cases in quote/expansion handling) by discussing symptoms
  and reasoning through the relevant code together.
- Explaining POSIX/bash semantics for edge cases (quoting rules, exit status
  propagation, signal behavior) to clarify what the correct behavior should be before
  implementing it.
- Assisting with writing and formatting this `README.md`.

All parsing, execution, and built-in logic was designed and implemented by the
project's authors.
