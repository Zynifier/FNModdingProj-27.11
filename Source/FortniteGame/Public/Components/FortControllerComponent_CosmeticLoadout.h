// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "CosmeticLoadout.h"
#include "FortControllerComponent_CosmeticLoadout.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CosmeticLoadout : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoadoutDynamicDelegate, const FCosmeticLoadout&, Loadout);

public:
	UFUNCTION(BlueprintPure)
	const FCosmeticLoadout& GetCosmeticLoadout() const;

private:
	UFUNCTION()
	void OnRep_CosmeticLoadout();

	UPROPERTY(ReplicatedUsing=OnRep_CosmeticLoadout)
	FCosmeticLoadout CosmeticLoadout;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="TRUE", DisplayName="On Cosmetic Loadout Changed"))
	FLoadoutDynamicDelegate BP_OnCosmeticLoadoutChanged;

};

