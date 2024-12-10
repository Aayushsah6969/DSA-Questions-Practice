import os

# Define the directory path
folder_path = "C:/Users/KIIT0001/Desktop/AAYUSH/DSA-C/QUEUE"

# Iterate over all files in the directory
for root, dirs, files in os.walk(folder_path):
    for file in files:
        # Check if the file has a .exe extension
        if file.endswith(".exe"):
            # Construct the full file path
            file_path = os.path.join(root, file)
            # Attempt to remove the file
            try:
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            except OSError as e:
                print(f"Error deleting {file_path}: {e}")

print("Deletion process completed.")
