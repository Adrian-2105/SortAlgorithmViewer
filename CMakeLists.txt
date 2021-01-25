cmake_minimum_required(VERSION 3.15)
project("SortAlgorithmViewer")
set(CMAKE_PROJECT_NAME)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/VisualVector.cpp include/VisualVector.h
        src/SortAlgorithms.cpp include/SortAlgorithms.h
        src/VisualWindow.cpp include/VisualWindow.h
        #OriginalSortAlgorithms/SelectionSort.cpp
        #OriginalSortAlgorithms/BubbleSort.cpp
        #OriginalSortAlgorithms/HeapSort.cpp
        )

target_link_libraries (${CMAKE_PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)