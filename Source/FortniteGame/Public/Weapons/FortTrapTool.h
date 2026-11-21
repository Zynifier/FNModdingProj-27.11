// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortDecoTool.h"
#include "FortTrapTool.generated.h"

class AFortWeapon;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortTrapTool : public AFortDecoTool
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void OnEquip(AFortWeapon* OldWeapon);

protected:
	UPROPERTY(Config)
	bool bRecalculateTrapPositionOnServer;

};

