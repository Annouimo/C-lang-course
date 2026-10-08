from pathlib import Path

lesson = input("Lesson name: ")
name = input("Question name: ")

code = """#include <stdio.h>

int main(){

    return 0;
}
"""

for i in name:
    folder = Path(f"{lesson}/q{i}")
    folder.mkdir(parents=True, exist_ok=True)
    with open(f"{lesson}/q{i}/q{i}.c", 'w', encoding="utf-8") as file:
        file.write(code)
    print(f"Successfully create: {lesson}/q{i}/q{i}.c")
