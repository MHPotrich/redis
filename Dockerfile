FROM gcc:latest
WORKDIR /build
COPY ./src/data.h .
COPY ./src/command.h .
COPY ./src/database.h .
COPY ./src/cli.h .
COPY ./src/cli.cpp .
COPY ./src/execution.h .
COPY ./src/execution.cpp .
COPY ./src/main.cpp .
RUN g++ -o redis cli.cpp execution.cpp main.cpp
CMD ["./redis"]
