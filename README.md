| Tested Targets | ESP32 | ESP32-S3 |
| -------------- | ----- | -------- |

# _Traffic Light_

This is the a simple traffic light system example. The model can be simulated using the CADMIUM DEVS simulator, and can be executed on the ESP32S3

## How to use example
For building and simulating the project, run the following command from the root directory:
```sh
make sim
```
For building, flashing and monitoring the execution of the model on an ESP32S3, run the following command:
```sh
. ~/esp/esp-idf/export.sh #or wherever you have installed ESP-IDF
idf.py set-target esp32s3
make embedded #Assumes your ESP32 is connected to port /dev/ttyACM0
```

## Example folder contents

The source files of this project can be found in the **main** directory. The entry point file is the [main.cpp](main/main.cpp) file.

The submodels can be found in the **include** directory

```
├── main
│   ├── include
│   └── main.cpp
└── README.md                  This is the file you are currently reading
```
