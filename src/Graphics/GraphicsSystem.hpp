#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <string>
#include <vector>


/*
Elijah Kibler
The purpose of the Graphics System is to manage the entirity of the graphics system withen the game
It will create an abstraction so that all SDL communication are handled through here
The purpose of this is to maintain a reference monitor gurentee for the graphics
This ensures that if later down the line a library change is needed the rest of the code dosn't need to be changed
*/

//Sprite Renderer: Every game object has one, game object initializes it by passing it a string pointing to it's file location
//The graphics Renderer loads up the sprite and passes it to SpriteRenderer to hold onto
class SpriteRenderer{
    //Concurrency: Once threading is added, locks will be used to control access
    public:
        SpriteRenderer(std::string FilePath);
        ~SpriteRenderer();
        //classes for setting and getting a object's position. When adding concurrency, implement locks inside the getters and setters
        void SetPosition(int x, int y);
        void SetX(int x);
        void SetY(int y);
        std::vector<int> GetPosition();
        int GetX();
        int GetY();
        //classes for changing and getting the textures of a sprite
        bool ChangeSprite(std::string FilePath);//Called by not the graphics system
        SDL_Texture* GetTexture();//exclusivly called by the GraphicsSystem 
    private:
        int X;
        int Y;
        SDL_Texture* Texture;
};

//Core Graphics System. Initialize should only be called in the main thread

class GraphicsSystem{
    //Strategy For memory saftey 
    //The graphics system will be created on the stack and will use it's contructors and distructor for initialization and deinitialization 
    //The grpahics system will contain pointers, these pointers will be allocated in the constructor and freed in the distructor
    public:
        GraphicsSystem();
        ~GraphicsSystem();
        bool AddGraphicsComponent(SpriteRenderer sprite);
        bool RemoveGraphicsComponent(SpriteRenderer sprite);
        bool ChangeSprite(SpriteRenderer sprite);
        void UpdateFrame();//Iterate through each sprite, if it has a lock, lock it, else just skip and try next frame
    private:
        std::vector<SpriteRenderer*> Sprits;// All The Sprites in the game are stored here
        void DestroySpriteList();
};