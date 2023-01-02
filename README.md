# Arduino Component Setups

### Brief

This repository contains schematics and code describing how to setup and control numerous Arduino components.

I have layed out this information in the following document: [Components.md](/Components.md).

### Adding More Components

To add a new component, please follow these steps:

1. In the ```/Components/``` directory, create a directory and name it after your component.
2. Within this new directory, create a ```.ino``` file containing your example code. Ensure this file has the same name as your new directory (excluding the file extension).
3. Create a schematic of your component's wiring and save it as an image to your new directory.
4. While maintaining alphabetical order, add an entry to [Components.md](https://github.com/Daniel-Ian-Robinson/Arduino_Component_Setups/blob/main/Components.md) with your component's name as the heading, a brief description of what it does, and your schematic. Also, embed your code at the end.
5. Finally, while maintaining alphabetical order, add a hyperlink at the top of [Components.md](https://github.com/Daniel-Ian-Robinson/Arduino_Component_Setups/blob/main/Components.md) that jumps to your component's section.
