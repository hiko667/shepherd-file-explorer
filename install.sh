# !/bin/bash

echo "Installing shepherd"
echo "Checking if git is installed"
if dpkg -l pulseaudio >/dev/null; then 
    echo "Git is installed";
    
else 
    echo Checking package manager;
    declare -A osInfo;
    osInfo[/etc/redhat-release]=yum
    osInfo[/etc/arch-release]=pacman
    osInfo[/etc/gentoo-release]=emerge
    osInfo[/etc/SuSE-release]=zypp
    osInfo[/etc/debian_version]=apt-get
    osInfo[/etc/alpine-release]=apk
    for f in ${!osInfo[@]}
    do
        if [[ -f $f ]];then
            echo Identified: ${osInfo[$f]}
        fi
    done
fi

mkdir /home/


# sudo apt update
# sudo apt install libcairo2-dev libgdk-pixbuf2.0-dev libglib2.0-dev
# sudo apt install libgtk-3-dev