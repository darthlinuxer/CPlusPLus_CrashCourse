if ! command -v g++ &> /dev/null; then
	echo "g++ not found. Installing build-essential..."
	sudo apt update
	sudo apt install build-essential -y
fi

cmake -S . -B build
cmake --build build