import glob
import os
import subprocess

# Specify the constant background image.
BACKGROUND_FILENAME = "background.xpm"

# Loop through all XPM files in the current directory.
for filepath in glob.glob("*.xpm"):
    # Skip the background image itself
    if os.path.basename(filepath) == BACKGROUND_FILENAME:
        continue

    print(f"Processing {filepath}...")

    # Create a temporary filename to hold the composite result.
    temp_filepath = filepath + ".tmp"

    # Build the ImageMagick composite command:
    # This overlays 'filepath' (foreground) on top of the background.
    command = [
        "convert",
        BACKGROUND_FILENAME,
        filepath,
        "-composite",
        temp_filepath,
    ]

    # Run the command
    subprocess.run(command, check=True)

    # Replace the original foreground image with the composite result.
    os.replace(temp_filepath, filepath)

print("All images have been processed and layered with the background.")
