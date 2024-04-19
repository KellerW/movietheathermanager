FROM ubuntu:22.04
SHELL ["/bin/bash", "-xec"]
LABEL Description="Build environment"
MAINTAINER Wagner Keller"wagner.keller@gmail.com"
#ENV HOME /root
RUN echo 'APT::Install-Suggests "0";' >> /etc/apt/apt.conf.d/00-docker
RUN echo 'APT::Install-Recommends "0";' >> /etc/apt/apt.conf.d/00-docker
RUN DEBIAN_FRONTEND=noninteractive \
  apt-get update \
  && apt install -y build-essential cmake libasio-dev git python3 \
  && rm -rf /var/lib/apt/lists/*
RUN useradd -ms /bin/bash apprunner
RUN mkdir -p /home/gitroot \      
           cd /home/gitroot  \       
RUN git clone https://github.com/KellerW/movietheathermanager.git

#RUN mkdir -p /var/maven
#USER apprunner
WORKDIR /home/gitroot
VOLUME ["/home/gitroot"]
