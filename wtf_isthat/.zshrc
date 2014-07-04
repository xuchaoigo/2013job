#!/bin/zsh
#
# .zshrc
#

## This is a multiple move based on zsh pattern matching.  To get the full
## power of it, you need a postgraduate degree in zsh.
## Read /path_to_zsh_functions/zmv for some basic examples.
autoload -U zmv

autoload -U colors
colors

autoload -U zcalc
autoload -U run-help
autoload -U promptinit 

. $SHELL_DIR/shared_rc
. $SHELL_DIR/shared_func
. $SHELL_DIR/shared_alias

. $SHELL_DIR/zsh_module
. $SHELL_DIR/zsh_option
. $SHELL_DIR/zsh_func
. $SHELL_DIR/zsh_alias
. $SHELL_DIR/zsh_key
. $SHELL_DIR/zsh_completion

[[ -f $SHELL_DIR/shared_personal ]] && . $SHELL_DIR/shared_personal

. $SHELL_DIR/zsh_prompt

true
