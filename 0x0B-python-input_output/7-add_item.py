import sys
import json

def save_to_json_file(my_obj, filename):
    """Save a Python object to a JSON file."""
    with open(filename, 'w') as file:
        json.dump(my_obj, file)

def load_from_json_file(filename):
    """Load a Python object from a JSON file."""
    with open(filename, 'r') as file:
        return json.load(file)

# Get the existing data from the file, or create an empty list
try:
    existing_data = load_from_json_file('add_item.json')
except FileNotFoundError:
    existing_data = []

# Add command-line arguments to the list
arguments = sys.argv[1:]  # Exclude the script name from the arguments
existing_data.extend(arguments)

# Save the updated list to the file
save_to_json_file(existing_data, 'add_item.json')

print(f"Arguments added to 'add_item.json': {arguments}")
