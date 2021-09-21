// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterBaseGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERBASE_API ASimpleShooterBaseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	public:
	virtual void PawnKilled(APawn* PawnKilled);

};
