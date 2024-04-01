g++ -o program main.cpp Image-class/Image.cpp Image-class/Point.cpp Image-class/Rectangle.cpp Image-class/Size.cpp Image-processing-class/ImageProcessing.cpp Image-processing-class/ImageConvolution.cpp Drawing/Drawing.cpp -std=c++17

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    # Run the program
    ./program
else
    echo "Compilation failed."
fi
