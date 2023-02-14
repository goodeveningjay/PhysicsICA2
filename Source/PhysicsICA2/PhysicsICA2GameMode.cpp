// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhysicsICA2GameMode.h"
#include "PhysicsICA2Character.h"
#include "UObject/ConstructorHelpers.h"

APhysicsICA2GameMode::APhysicsICA2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
