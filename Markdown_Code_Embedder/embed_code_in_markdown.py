input_file_name = "Components.md"
output_file_name = "../Components.md"

markdown_file = open(input_file_name)
input_lines = markdown_file.readlines()
output_lines = []

for line in input_lines:
    if line[0:4] == "<!--":
        if line[len(line)-3:] == "-->":
            code_file_name = line[4:len(line)-3]
        elif line[len(line)-4:] == "-->\n":
            code_file_name = line[4:len(line)-4]
            
        code_file = open(code_file_name)
        code_lines = code_file.readlines()
        code_file.close()
        
        file_type = code_file_name[code_file_name.index("."):]
        #output_lines.append(line)
        output_lines.append("```" + file_type + "\n\n")
        
        for code_line in code_lines:
            output_lines.append(code_line)
        
        output_lines.append("\n```\n")
    else:
        output_lines.append(line)
        
output_file = open(output_file_name, "w")

for line in output_lines:
    output_file.write(line)
    
output_file.close()
markdown_file.close()