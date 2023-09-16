cmake_minimum_required(VERSION 3.26)
project(Functionality/Hotel)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        Functionality/Rooms/Room.cpp
        Functionality/Date/Date.cpp
        Functionality/Rooms/RoomStandard.cpp
        Functionality/Rooms/RoomLux.cpp
        Functionality/Hotel/Hotel.cpp
        Functionality/Reservation/Reservation.cpp
        main.cpp
)
