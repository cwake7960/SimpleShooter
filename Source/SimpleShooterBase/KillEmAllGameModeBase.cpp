// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "AIShooterController.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    UE_LOG(LogTemp, Warning, TEXT("A Pawn was killed"));
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        //PlayerController->GameHasEnded(nullptr,false);
        EndGame(false);
    }
    
         //for loop world aicontrollers
         for(AAIShooterController* AIController: TActorRange<AAIShooterController>(GetWorld()))
         {
               if (!AIController->IsDead())
               {
                  return;   
               }

         }  
                  
        EndGame(true);
      
}

void AKillEmAllGameModeBase::EndGame(bool bIsPlayerWinner) 
{
   for(AController* Controller: TActorRange<AController>(GetWorld()))
   {
      bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
      Controller->GameHasEnded(Controller->GetPawn(),bIsWinner);
   }
}
