# Media player
A CLI application for Linux that serves as a basic media files and video files browser/player(advance) using C/C++ player(advance) using C/C++ [BASIC]
## 1. Your application should be able to runs:
- From any directory on your computer
- From external: USB ( must to mount device and parse file in USB) 

## 2. Avaiable options:
### View list of media files in that folder and all sub-folder (audio and video)
+ Pagination, 25 per page

### Playlists:
+ List of playlist
+ View a playlist
+ Create/Update/Delete a playlist

### Metadata of a file (Taglib): [MAIN FEATURE]
- Available from either media list or a playlist
- Show metadata of a media file (pretty much anything you can think of as metadata): <br>
    `Audio`: Track name, Album, Artist, Duration, Genre, Publisher, Publish Year,.. <br>
    `Video`: Name, Size, Duration, Bitrate, Codec,..
- Edit metadata: change value, add new keys,...
 
### Play music from your application using SDL2 libary on other thread.
+ Play/Pause
+ Next/Previous
+ Automatically move to the next song when current song finish
+ Display current time and duration time
  
### Can change volume of device
