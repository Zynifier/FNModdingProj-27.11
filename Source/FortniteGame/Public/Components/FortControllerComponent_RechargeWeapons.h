// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_RechargeWeapons.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FCachedRechargeAmmoData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ServerStartTime;

	UPROPERTY()
	float ChargeRate;

	UPROPERTY()
	int32 AmountToRecharge;

	UPROPERTY()
	int32 ItemLevel;

	UPROPERTY()
	FGuid WeaponItemGuid;

	UPROPERTY()
	TSoftObjectPtr<UFortWorldItemDefinition> AmmoItemDefinition;

	UPROPERTY()
	bool bShouldRechargeAmmoToClip;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortControllerComponent_RechargeWeapons : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(Client, Reliable)
	void ClientItemStartedRecharging(const FGuid& ItemGuid, const float InServerStartTime);

	UFUNCTION(Server, Reliable)
	void ServerSetPreventRecharging(bool bInPreventRecharging);

private:
	UPROPERTY(Transient)
	TMap<FGuid, FCachedRechargeAmmoData> WeaponToRechargeDataMap;

	UPROPERTY(Transient)
	TMap<FGuid, float> PendingGuidToServerStartTimeMap;

	UPROPERTY(Transient)
	bool bPreventRecharging;

};

