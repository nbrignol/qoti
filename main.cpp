
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
    sf::RenderWindow App(sf::VideoMode(800, 600), "The Quest of the Incrementalist 1");
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

        // Clear screen
        App.Clear(backgroundColor);

		App.Draw(Sprite);

        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
