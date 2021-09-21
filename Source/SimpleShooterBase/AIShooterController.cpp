// Fill out your copyright notice in the Description page of Project Settings.


#include "AIShooterController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


void AAIShooterController::BeginPlay() 
{
    Super::BeginPlay();

    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        APawn* PlayerPawn =  UGameplayStatics::GetPlayerPawn(GetWorld(),0); 
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
        
    }


  // 
    
   

}

void AAIShooterController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

//       APawn* PlayerPawn =  UGameplayStatics::GetPlayerPawn(GetWorld(),0);

//     if(LineOfSightTo(PlayerPawn))
//      {
    
//          SetFocus(PlayerPawn);
//          GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),PlayerPawn->GetActorLocation());
//          GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"),PlayerPawn->GetActorLocation());
// //     MoveToActor(PlayerPawn,AccptanceRaidus);   
//      }
//     else
//         {
//             GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
// //        ClearFocus(EAIFocusPriority::Gameplay);
// //        StopMovement();
//         }
   
}

bool AAIShooterController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if(ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}
