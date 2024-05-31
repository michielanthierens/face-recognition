## credits
A big part of this repository was written by Wouter Anthierens. Thank you for helping me with this project.

# face recognition program
this project is about making a connection between a raspberry pi and an arduino circuit. The arduino contains a facecam and has the face recognition program. using i2c it gives a name to the arduino, which is displayed on the screen.

# how to use
## installing requirements on raspberry pi

```
sudo apt update
sudo apt upgrade
sudo apt install python3-opencv
sudo apt install libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev
sudo apt install libjpeg-dev libtiff5-dev libjasper-dev libpng13-dev
sudo apt install libjpeg-dev libtiff5-dev libjasper-dev libpng-dev
sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt install libxvidcore-dev libx264-dev
sudo apt install libgtk2.0-dev
sudo apt install python3-pip
sudo apt install python3-opencv
sudo apt install arduino
```

## raspberry files

stappenplan gezichtsherkenning:

iemand in het systeem toevoegen:
1. maak een folder in ```~/cam/facial/dataset``` met de nieuwe naam
2. in de parent folder facial, edit het ```headshot.py``` bestand en verwissel de huidige naam met de nieuwe naam (dezelfde als de vorige stap)
4. draai ```headshot.py``` en wacht tot de webcam tevoorschijn komt
5. druk op spatie om foto's te nemen van meerdere zijdes van het gezicht. (circa 10 foto's)
6. druk op esc om te stoppen
7. check de nieuwe foto's in de dataset folder onder de juiste naam

train de data:
1. ga naar de folder facial_recognition ```cd ~/cam/facial/facial_recognition```
2. draai het command: ``` python train_model.py ```

testen:
draai het command: ``` python facial_req.py ```


## arduino files

```arduino/ic2.ino``` moet op raspberry pi gedraaid worden. Daarvoor moet arduino geïnstaleerd zijn.

arduino/i2c_i2c.png bevat het arduino schema, en hoe deze verbonden moet zijn met de raspberry pi.

voor proberen met arduino, zie: https://docs.arduino.cc/software/ide-v1/tutorials/Windows
