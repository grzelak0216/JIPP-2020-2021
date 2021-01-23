#!/bin/bash

echo "kompilacja"
echo "kelner:"
echo `g++ ./kelner/header.h ./kelner/kelner.cpp -pthread -o prog_kel`
echo "zaglodzenie"
echo `g++ ./zaglodzenie/header.h ./zaglodzenie/zaglodz.cpp -pthread -o prog_zag`
echo "zakleszczenie"
echo `g++ ./zakleszcz/header.h ./zakleszcz/zakleszcz.cpp -pthread -o prog_zak`

echo "koniec"

exit 0