# Arduino Component Setups

### Brief

This repository contains schematics and code describing how to setup and control numerous Arduino components.

### Adding More Components

To add a new component, please follow these steps:

1. In the ```/Components/``` directory, create a directory and name it after your component.
2. Within this new directory, create a ```.ino``` file containing your example code. Ensure this file has the same name as your new directory (excluding the file extension).
3. Create a schematic of your component's wiring, preferably using an Arudino Uno, and save it as an image to your new directory.
4. Edit this version of [Components.md](https://github.com/Daniel-Ian-Robinson/Arduino_Component_Setups/blob/main/Markdown_Code_Embedder/Components.md) by including your component's name as the heading, a brief description of what it does, and your schematic.
5. To add your code, please add a comment in the form ```<!--FileName.abc-->``` and run ```python embed_code_in_markdown.py```. This will automatically embed your code in the main version of [Components.md](https://github.com/Daniel-Ian-Robinson/Arduino_Component_Setups/blob/main/Components.md). This is helpful because it keeps the markdown document up to date with the code.
