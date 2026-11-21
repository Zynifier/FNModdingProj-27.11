// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortBuildingAddStructuralSupportComponent.generated.h"

class ABuildingSMActor;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortBuildingAddStructuralSupportComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void PrepareToSpawnBuildings();

	UPROPERTY()
	TArray<TWeakObjectPtr<ABuildingSMActor>> AddedStructuralBuildingActors;

protected:
	UFUNCTION()
	void DestroyAddedStructuralBuildingActors();

};

