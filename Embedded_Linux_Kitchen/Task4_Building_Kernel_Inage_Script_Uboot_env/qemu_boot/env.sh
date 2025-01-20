#!/bin/bash

# Check if env.txt is provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <path_to_env.txt>"
  exit 1
fi

# Path to the input env.txt
env_file="$1"

# Check if the file exists
if [ ! -f "$env_file" ]; then
  echo "Error: File '$env_file' not found!"
  exit 1
fi

# Remove trailing spaces from the beginning and end of the lines
echo "Removing trailing spaces..."
sed -i 's/[[:space:]]*$//' "$env_file"

# Convert to Unix line endings
echo "Converting to Unix line endings..."
dos2unix "$env_file"

# Verify the content of env.txt
echo "Content of env.txt after cleanup:"
cat -A "$env_file"

# Create uboot.env using mkenvimage
echo "Creating uboot.env..."
mkenvimage -s 0x40000 -o uboot.env "$env_file"

# Check if uboot.env was created successfully
if [ $? -eq 0 ] && [ -f "uboot.env" ]; then
  echo "uboot.env created successfully."
else
  echo "Error: Failed to create uboot.env."
  exit 1
fi
