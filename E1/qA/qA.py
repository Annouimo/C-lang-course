str = '''          *
        / \\
       /   \\
*_______   _______*
  \\             /
     \\       /
     /   *   \\
    / /     \ \\
   *           *'''
for i in str.split("\n"):
    print(f'printf("{i}\\n");')