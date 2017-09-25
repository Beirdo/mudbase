# mudbase
C++/Boost-based MUD framework


## Compiling under Ubuntu (16.0.4 LTS or newer)

```
$ sudo apt-get install build-essential cmake libicu-dev libbz2-dev zlib1g-dev \
      libssl-dev libcurl4-openssl-dev libpulse-dev

$ git clone --recursive https://github.com/BeirdoMud/mudbase.git
$ cd mudbase
(or
$ git clone https://github.com/BeirdoMud/mudbase.git
$ cd mudbase
$ git submodule update --init
)
$ mkdir build-aws
$ cd build-aws
$ cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_ONLY="dynamodb" ../aws-sdk-cpp
$ make
$ sudo make install
$ echo /usr/local/lib | sudo tee -a /etc/ld.so.conf.d/local.conf
$ sudo ldconfig
$ cd ..
$ mkdir build
$ cd build
$ cmake ..
$ make
```

More info to come later
