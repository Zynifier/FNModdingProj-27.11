// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaBTTask_MoveTo.h"
#include "FortAthenaBTTask_BotMoveTo.generated.h"

UCLASS()
class FORTNITEAISERVER_API UFortAthenaBTTask_BotMoveTo : public UFortAthenaBTTask_MoveTo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName NoSmashMoveGoalActorKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Wobble", meta=(AllowPrivateAccess="true"))
	uint8 bAllowRandomWobble : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Speed", meta=(AllowPrivateAccess="true"))
	uint8 bIsUrgentMovement : 1;

};

