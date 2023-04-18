#include <iostream>
using namespace std;
/*
我们有一个 MediaPlayer 接口和一个实现了 MediaPlayer 接口的实体类 AudioPlayer。默认情况下，AudioPlayer 可以播放 mp3 格式的音频文件。

我们还有另一个接口 AdvancedMediaPlayer 和实现了 AdvancedMediaPlayer 接口的实体类。该类可以播放 vlc 和 mp4 格式的文件。

我们想要让 AudioPlayer 播放其他格式的音频文件。为了实现这个功能，我们需要创建一个实现了 MediaPlayer 接口的适配器类 MediaAdapter，并使用 AdvancedMediaPlayer 对象来播放所需的格式。

AudioPlayer 使用适配器类 MediaAdapter 传递所需的音频类型，不需要知道能播放所需格式音频的实际类。
*/
//简单媒体播放器抽象类
class MediaPlayer{
public:
    virtual void play(string audioType, string filename) = 0;
};
//高级媒体播放器抽象类
class AdvancedMediaPlayer{
public:
    virtual void playVlc(string filename) = 0;
    virtual void playMp4(string filename) = 0;
};
//具体高级播放器类1
class VlcPlayer:public AdvancedMediaPlayer{
public:
    void playVlc(string filename){
        cout << "Playing vlc file. Name:" << filename << endl;
    }
    void playMp4(string filename){
        //什么也不做
    }
};
//具体高级播放器2
class Mp4Player:public AdvancedMediaPlayer{
public:
    void playMp4(string filename){
        cout << "Playing mp4 file. Name:" << filename << endl;
    }
    void playVlc(string filename){
        //什么也不做
    }
};
//创建实现了 MediaPlayer 接口的适配器类
class MediaAdapter:public MediaPlayer{
public:
    AdvancedMediaPlayer* advancedMusicPlayer;

    MediaAdapter(string audioType){
        if(audioType == "vlc"){
            advancedMusicPlayer = new VlcPlayer();
        }
        else if(audioType == "mp4"){
            advancedMusicPlayer = new Mp4Player();
        }
    }

    void play(string audioType, string filename){
        if(audioType == "vlc"){
            advancedMusicPlayer->playVlc(filename);
        }
        else if(audioType == "mp4"){
            advancedMusicPlayer->playMp4(filename);
        }
    }
};

//创建实现了 MediaPlayer 接口的实体类。
class AudioPlayer:public MediaPlayer{
public:
    MediaAdapter* mediaAdapter;
    void play(string audioType, string filename){
        //播放MP3音乐文件的内置支持
        if(audioType == "mp3"){
            cout << "Playing mp3 file. Name:" << filename << endl;
        }
        //mediaAdapter提供了播放其他文件格式的支持
        else if(audioType == "vlc" || audioType == "mp4"){
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, filename);
        }
        else{
            cout << "Invalid media." << audioType <<" format not surpported." << endl;
        }
    }
};