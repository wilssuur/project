FROM fstlx/qt5:ubuntu18

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY *.cpp /root/server/
COPY *.h /root/server/
COPY *.pro /root/server/
COPY *.db /root/server/

RUN qmake echoserver.pro
RUN make

ENTRYPOINT ["./echoserver"]