#!/bin/bash

PROJECT_NUM=$1

# Create project root directory
mkdir -p project_${PROJECT_NUM}

# Change into project directory
cd project_${PROJECT_NUM}

# Create subdirectories
mkdir data include lib src

# Move into src directory
cd src

# Create source files in src directory (with .cxx extension)
touch data_ingestion.cxx trend_analysis.cxx geographical_analysis.cxx product_categorization.cxx data_visualization_prep.cxx 
main.cpp

# Move back to top-level directory
cd ../

# Move into data directory
cd data

#create consumer file
touch consumer_report.json

cd ../

cd lib

touch json.hpp

cd ../

cd include

touch utilities.h


echo "Directory structure created!"
