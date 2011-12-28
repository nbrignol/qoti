
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
   
	// Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "The Quest of the Incrementalist 2");
	sf::Color backgroundColor = sf::Color(50, 50, 50);
	
	sf::Image Image;
	Image.SetSmooth(false); //to avoid any antialias

	if (!Image.LoadFromFile("hero.png"))
	{
		return EXIT_FAILURE;
	}
	
	sf::Sprite Sprite;
	Sprite.SetImage(Image);
	Sprite.SetX((App.GetWidth() - Image.GetWidth()) / 2);
	Sprite.SetY((App.GetHeight() - Image.GetHeight()) / 2);
	
	float move = 200;
	
    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }
		
		//sf::Sleep(0.4f);
		
		// Get elapsed time for this frame
		float ElapsedTime = App.GetFrameTime();
		//float Framerate = 1.f / ElapsedTime;
		
		// Move the sprite
		if (App.GetInput().IsKeyDown(sf::Key::Left))  Sprite.Move(-1 * move * ElapsedTime, 0);
		if (App.GetInput().IsKeyDown(sf::Key::Right)) Sprite.Move( move * ElapsedTime, 0);

        // Clear screen
        App.Clear(backgroundColor);

		App.Draw(Sprite);

        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
