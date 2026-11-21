// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceConfigComponent.generated.h"

class UEntityActorPlayerComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class VERSEPLAYSPACE_API UPlayspaceConfigComponent : public UPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player")
	TSubclassOf<UEntityActorPlayerComponent> PlayerComponentClass;

};

