// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CosmeticLoadout.h"
#include "FortCosmeticLoadoutComponent.generated.h"

UCLASS(MinimalAPI)
class UFortCosmeticLoadoutComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoadoutDynamicDelegate, const FCosmeticLoadout&, Loadout);

public:
	UFUNCTION(BlueprintPure)
	const FCosmeticLoadout& GetCosmeticLoadout() const;

	UFUNCTION(BlueprintCallable)
	void SetCosmeticLoadout(const FCosmeticLoadout& NewCosmeticLoadout);

private:
	UFUNCTION()
	void OnRep_CosmeticLoadout();

	UPROPERTY(ReplicatedUsing=OnRep_CosmeticLoadout)
	FCosmeticLoadout CosmeticLoadout;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="TRUE", DisplayName="On Cosmetic Loadout Changed"))
	FLoadoutDynamicDelegate BP_OnCosmeticLoadoutChanged;

};

