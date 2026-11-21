// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapCeiling.h"
#include "BuildingTrapCeiling_Falling.generated.h"

class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapCeiling_Falling : public ABuildingTrapCeiling
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Ceiling Trap Falling")
	void TrapActivated(const float CooldownDuration);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Ceiling Trap Falling", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> VisibleMeshComponent;

	UPROPERTY(BlueprintReadWrite, Category="Ceiling Trap Falling")
	TArray<FTransform> SpawnPoints;

};

