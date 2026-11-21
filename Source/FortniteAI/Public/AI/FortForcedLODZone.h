// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI/FortAITypes.h"
#include "FortForcedLODZone.generated.h"

UCLASS()
class AFortForcedLODZone : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AI")
	EFortAILODLevel ForcedLODLevel;

};

