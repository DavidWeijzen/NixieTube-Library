# NixieTube-Library
A simple library to display a number on a single nixie tube on arduino platforms.

## How it works:
Create a class off nixie driver and define it's pins.
For example:
```
NixieTube tube1(driverA, driverB, driverC, driverD, annode1, decimal1);
```
Set up all the corrosponding pins with ```tube1.init();```

To tun on a tube and display a number use:
```
setNumberToDisplay({byte numberToDisplay}, {bool Decimal Point}, [byte brightness(default 255)]);
```
To tun the tube completely off use the off() function.

## How to install the library:
1. Download this library as a zip
2. Go to your arduino IDE
3. On the top left, click "sketch"
4. Hover over the "Include Library" button and click the "add .ZIP library..." button.
5. Select the file you just downloaded.
6. enjoy :smiley:
