#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particle.h"
#include "Proyectil.h"
#include "Floor.h"
#include "Esfera.h"

#include"ParticleSystem.h"
#include <iostream>

std::string display_text = "SPACE TO START";
std::string start = "KEEP ALIVE FOR 60 SECONDS";
std::string start2 = "DO NOT TOUCH LIMITS WALL AND SPHERES";
std::string start3 = "KEY 1&2 FOR SKILL,ONCE PER GAME,PENALTY IF BOTH IS USED";
std::string start4 = "LEFT/J RIGHT/L STOP/K";
std::string winlose = "";
using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;
Particle* p;
std::vector<Proyectil*> vP;
//Floor* f;
//Esfera* e;
ParticleSystem* pSym;
bool gameStart = false;
// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, 0.0f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	pSym = new ParticleSystem(gPhysics, gScene);
	//pSym->testForceGenerators();
	//pSym->testbuoyancy(1, 100);
	//pSym->testGenerators();
	//pSym->shootFirework(1);
	//f = new Floor(Vector3(0, -10, 0));
	//e = new Esfera(Vector3(0, 20, -100));
	//pSym->solidRigid(gPhysics, gScene);
	//pSym->game();
}
void setText() {
	start = "KEEP ALIVE FOR 60 SECONDS";
	start2 = "DO NOT TOUCH LIMITS WALL AND SPHERES";
	start3 = "KEY 1&2 FOR SKILL,ONCE PER GAME,PENALTY IF BOTH IS USED";
	start4 = "LEFT/J RIGHT/L STOP/K";
}
void clearText() {
	start = "";
	start2 = "";
	start3 = "";
	start4 = "";
}

// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);
	pSym->update(t);
	if (gameStart && !pSym->isFinish()) {
		clearText();
		display_text = to_string(pSym->getTime());
	}
	else {
		setText();
		display_text = "SPACE TO START";
	}
	if (pSym->isFinish()) {
		if (pSym->isWin()) {
			winlose = "WIN";
		}
		else
			winlose = "LOSE";
	}
	//for (Proyectil* e : vP) e->integrate(t);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();

	//delete e;
	//delete f;
	delete pSym;
	for (auto e : vP) delete e;
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case 'J':
	{
		pSym->goLeft();
		break;
	}
	case 'L':
	{
		pSym->goRight();
		break;
	}
	case 'K':
	{
		pSym->clearForce();
		break;
	}
	case '1':
	{
		pSym->explode();
		break;
	}
	case '2':
	{
		pSym->wind();
		break;
	}
	case '3':
	{
		pSym->generateFireworkSystem();
		break;
	}
	case '9':
	{
		pSym->forcedWin();
		break;
	}
	case ' ':
	{
		pSym->cleanScene();
		gameStart = true;
		winlose = "";
		break;
	}
	case 'F':
	{
		break;
	}
		
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}



int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}