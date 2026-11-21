// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PapayaLiveEventComponent.generated.h"

class UAthenaDanceItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UPapayaLiveEventComponent : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> ActiveCustomEmotes;

};

