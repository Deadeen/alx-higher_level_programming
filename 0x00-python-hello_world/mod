#!/bin/bash

# Find the last file created in the current directory
last_file=$(ls -t | head -n 1)

# Check if a file was found
if [ -n "$last_file" ]; then
	  # Give execute permission to the last file created
	    chmod +x "$last_file"
	      echo "Execute permission granted to: $last_file"
      else
	        echo "No files found in the current directory."
fi

