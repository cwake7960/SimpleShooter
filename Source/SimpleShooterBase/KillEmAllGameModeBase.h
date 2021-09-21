// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterBaseGameModeBase.h"
#include "KillEmAllGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERBASE_API AKillEmAllGameModeBase : public ASimpleShooterBaseGameModeBase
{
	GENERATED_BODY()
	public:
		virtual void PawnKilled(APawn* PawnKilled) override; 

	private:

	void EndGame(bool bIsPlayerWinner);
};
