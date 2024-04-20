# Movie Manager Applicaton 

## Pre-requiriments 

### For compile and run in local host machine without the container install the following depencies: 

- Goolge the Test framework :
```
mkdir /home/gtest  
cd /home/gtest          
git clone https://github.com/google/googletest.git 
cd /home/gtest/googletest 
mkdir build 
cd build 
cmake .. 
make -j8
make install
```
- The Crow Framework
```
mdir /home/crow 
cd /home/crow          
git clone https://github.com/CrowCpp/Crow.git 
cd /home/crow/Crow 
mkdir build 
cd build 
cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF 
make -j8 
make install
```
## To build and run the Application
```
mkdir /home/gitroot       
cd /home/gitroot         
git clone https://github.com/KellerW/movietheathermanager.git 
cd movietheathermanager 
rm -r build  
mkdir build 
cd build 
cmake .. 
make -j8
```
## Install depencies for Docker Container

- Install the dependences for docker to use the docker container: 
```
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```
## To biuld the Container 
```
docker build -t moviemanager .
```
## To run the container 
```
docker container run -it -p 8888:8888 moviemanager
```