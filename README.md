# sdl2-circles
Circle rasterization stuff

## Build from source: 
### Using VSCODE + coderunner extension: 
1. Install [coderunner vscode extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)


2. Edit the following line to your "code-runner.executorMap" within settings.json:
~~~
"cpp": "g++ -std=c++17 $fullFileName -o bin/$fileNameWithoutExt `sdl2-config --cflags --libs` && ./bin/$fileNameWithoutExt",
~~~
It should look something like:
~~~
"code-runner.executorMap": {
        ... // other langs and their configs
        "cpp": "g++ -std=c++17 $fullFileName -o bin/$fileNameWithoutExt `sdl2-config --cflags --libs` && ./bin/$fileNameWithoutExt",
        ... // other langs and their configs
}
~~~


## References: 
1. wikipedia page for the Midpoint Circle Algorithm:
   https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
