// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationifSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"


UBTService_PlayerLocationifSeen::UBTService_PlayerLocationifSeen() 
{
        NodeName = "Update Player Location if Seen";
        //AAIController* AIController = 
}

void UBTService_PlayerLocationifSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) 
{
    	Super::TickNode(OwnerComp,NodeMemory, DeltaSeconds);
       
        APawn* PlayerPawn =  UGameplayStatics::GetPlayerPawn(GetWorld(),0); 
        if (PlayerPawn == nullptr)
        {
            return;
        }
        

        if (OwnerComp.GetAIOwner() == nullptr)
        {
            return;
        }
        
        if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
     {
    
        // OwnerComp.GetAIOwner()->SetFocus(PlayerPawn);
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(),PlayerPawn);
        
        //OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerPawn->GetActorLocation());
     }
     else
     {
         OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
     }
}
