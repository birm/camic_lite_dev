docker build -t slider .
docker run -v $(pwd)/dist:/src/dist slider:latest
