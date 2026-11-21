// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CRDPlayerTrackerUIComponent.generated.h"

class UCRDPlayerTrackerWidget;

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class CRDPLAYERTRACKERUI_API UCRDPlayerTrackerUIComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCRDPlayerTrackerWidget> SpawnedWidget;

};

