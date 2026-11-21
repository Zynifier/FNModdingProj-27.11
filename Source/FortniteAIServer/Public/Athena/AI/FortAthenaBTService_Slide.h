// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortAthenaBTService_Slide.generated.h"

class AFortPlayerPawn;

UCLASS()
class UFortAthenaBTService_Slide : public UBTService
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnStopSliding(AFortPlayerPawn* Pawn);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SlideExecutionStatusName;

};

