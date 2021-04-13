// Include class definition
#include "SceneManager.h"

#include "GraphicsObject.h"

#include <algorithm>

using namespace Graphics;

SceneManager* SceneManager::instance_ = nullptr;

SceneManager& Graphics::SceneManager::get()
{
	if ( instance_ == nullptr )
	{
		instance_ = new SceneManager();
	}

	return *instance_;
}

SceneManager::SceneManager()
:	graphicsObjects_()
//,	listeners_()
{
}

void SceneManager::addGraphicsObject( GraphicsObject* g )
{
	graphicsObjects_.push_back( g );

	//// Tell other "listeners"
	//for ( auto& l : listeners_ )
	//{
	//	l->onGraphicsObjectAdded( g );
	//}
}

void SceneManager::removeGraphicsObject( GraphicsObject* g )
{
	//graphicsObjects_.erase( g );
	//auto object = std::find( graphicsObjects_.begin(), graphicsObjects_.end(), g );
	//// Check if founf object
	//if ( object != graphicsObjects_.end() )
	//{
	//	graphicsObjects_.erase( g );
	//}
}

const GraphicsObject* const SceneManager::getGraphicsObject( int i ) const
{
	return graphicsObjects_[ i ];
}

GraphicsObject* SceneManager::editGraphicsObject( int i )
{
	return graphicsObjects_[ i ];
}

const std::vector< GraphicsObject* >& SceneManager::getGraphicsObjects()
{
	return graphicsObjects_;
}

std::vector< GraphicsObject* >& SceneManager::editGraphicsObjects()
{
	return graphicsObjects_;
}

//void SceneManager::registerListener( Listener* l )
//{
//	listeners_.push_back( l );
//}
//
//void SceneManager::unregisterListener(Listener* l)
//{
//}

//class UserInterface : public Listener
//{
//	void init()
//	{
//		SceneManager::get().registerListener( this );
//	}
//
//	/*virtual void onGraphicsObjectAdded(GraphicsObject* g)
//	{
//		QTreeWidget* treeWidget;
//		treeWidget->addItem(g->getName());
//	}*/
//};

//using namespace Graphics;
//
//SceneManager* SceneManager::_instance = nullptr;
//
//SceneManager& SceneManager::get()
//{
//	if ( _instance == nullptr )
//	{
//		_instance = new SceneManager();
//	}
//
//	return *_instance;
//}
//
//SceneManager::SceneManager()
//{
//}
//
//void SceneManager::addGraphicsObject( GraphicsObject* g )
//{
//	_graphicsObjects.push_back( g );
//
//	/*for ( auto l : _listener )
//	{
//		l->onGraphicsObjectAdded( g );
//	}*/
//}
//
//void SceneManager::removeGraphicsObject(GraphicsObject* g)
//{
//	//_graphicsObjects.erase( g );
//	auto object = std::find( _graphicsObjects.begin(), _graphicsObjects.end(), g );
//	// Found object
//	if (object != _graphicsObjects.end())
//	{
//
//	}
//}
//
//const GraphicsObject* const SceneManager::getGraphicsObject( int i ) const
//{
//	return _graphicsObjects[ i ];
//}
//
//GraphicsObject* SceneManager::editGraphicsObject( int i )
//{
//	return _graphicsObjects[ i ];
//}
//
//const std::vector< GraphicsObject* >& SceneManager::getGraphicsObjects() const
//{
//	return _graphicsObjects;
//}
