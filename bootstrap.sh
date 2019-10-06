#!/bin/sh

if [[ $(command -v brew) == "" ]]; then
	echo "--------------------------------------------------"
	echo "You will need to close this terminal and restart it once Brew is installed."
	echo "Once terminal is restarted, run this script again!"
	echo "--------------------------------------------------"
    echo "Installing Homebrew"
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
else
    echo "Updating Homebrew"
    brew update
fi

if [[ $(command -v brew) != "" ]]; then
    echo "Installing Dependencies"
	brew install SDL2 SDL2_gfx SDL2_image SDL2_ttf
fi
