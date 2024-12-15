#!/bin/bash

# Define variables
BASHRC="$HOME/.bashrc"

# Check if .bashrc exists
if [ -f "$BASHRC" ]; then
    echo ".bashrc found. Appending new environment variables..."
    
    # Append environment variables
    echo "export HELLO=\$HOSTNAME" >> "$BASHRC"
    echo "LOCAL=\$(whoami)" >> "$BASHRC"
    echo "Environment variables added successfully."
else
    echo ".bashrc not found in the home directory."
fi

# Open a new terminal
echo "Opening a new terminal..."
gnome-terminal &  