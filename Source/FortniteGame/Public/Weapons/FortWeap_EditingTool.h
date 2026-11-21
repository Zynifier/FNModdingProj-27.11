// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortWeap_BuildingToolBase.h"
#include "FortWeap_EditingTool.generated.h"

class ABuildingSMActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Projectile", "Projectile", "Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeap_EditingTool : public AFortWeap_BuildingToolBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_EditActor)
	TObjectPtr<ABuildingSMActor> EditActor;

	UPROPERTY(Transient)
	bool bEditConfirmed;

private:
	UFUNCTION()
	void OnRep_EditActor();

};

