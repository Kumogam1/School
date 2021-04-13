#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <vector>

namespace Graphics
{
	class GraphicsObject;
}
namespace Graphics
{

class SceneManager
{

public:
	
	static SceneManager& get();

	void addGraphicsObject( GraphicsObject* g );
	void removeGraphicsObject( GraphicsObject* g );

	const GraphicsObject* const getGraphicsObject( int i ) const;
	GraphicsObject* editGraphicsObject( int i );
	const std::vector< GraphicsObject* >& getGraphicsObjects();
	std::vector< GraphicsObject* >& editGraphicsObjects();

	/*void registerListener( Listener* l );
	void unregisterListener( Listener* l );*/

protected:

private:

	SceneManager();

	static SceneManager* instance_;

	std::vector< GraphicsObject* > graphicsObjects_;

	//std::vector< Listener* > listeners_;
	
};

}

#endif
