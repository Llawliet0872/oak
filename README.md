# oak
Oak is a simple package manager for debian and debian based systems written in c++ and shell script.

### Version
1.1

### 32-bit
32-bit applications aren't supported yet.

### Installation
```bash
git clone https://github.com/Llawliet0872/oak.git
cd oak/
./install
[NOTE]: If you aren't able to execute install directly then do "chmod +x install" and then try again. 
```
### Updates
All packages installed through oak will be updated automatically when you do a system update.

### Uninstallation
```bash
rm -rf ~/.oak # To delete the directory which contains oak
# Do this only if you chose to place oak in /bin during installation!
sudo rm /bin/oak
```

### Support
If you like oak and want to help it develop you can contribute by adding more packages to https://github.com/Llawliet0872/scripts
