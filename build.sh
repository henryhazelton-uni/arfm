#!/usr/bin/env bash

set -euo pipefail
IFS=$'\n\t'

echo "Building Aircraft Fuel and Range Management project..."

cmake -S . -B build

cmake --build build -j

echo "Build completed"

echo "Starting application"

flight_file="data/simple_fuel_flights.csv"

./build/arfm "$flight_file"