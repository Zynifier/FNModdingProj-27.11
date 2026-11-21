// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortCombatTypes.h"
#include "FortAIDirectorEventManager.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAIDirectorEventFired, const FFortAIDirectorEvent&, Event);

UCLASS(MinimalAPI)
class AFortAIDirectorEventManager : public AActor
{
	GENERATED_BODY()

};

