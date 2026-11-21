// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "AIComponent.generated.h"

class AAIController;
class AFortPawn;

UCLASS(ClassGroup=("Fortnite"))
class VERSEFORTNITE_API UAIComponent : public UEntityComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedPawn;

	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedAIController;

};

