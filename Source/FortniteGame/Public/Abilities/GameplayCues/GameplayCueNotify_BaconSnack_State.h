// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "GameplayCueNotify_BaconSnack_State.generated.h"

class AFortPlayerPawn;
class UFortAthenaAlertStateComponent;
class UStaticMeshComponent;

UCLASS(HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AGameplayCueNotify_BaconSnack_State : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="GameplayCueNotify_BaconSnack_State")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(EditDefaultsOnly, Category="GameplayCueNotify_BaconSnack_State")
	int32 MeshDataIndex;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="GameplayCueNotify_BaconSnack_State", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(BlueprintReadWrite, Transient, Category="GameplayCueNotify_BaconSnack_State")
	float StealthMeter;

	UPROPERTY(BlueprintReadWrite, Transient, Category="GameplayCueNotify_BaconSnack_State")
	float StealthMeterTime;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAlertStateComponent> CachedAlertStateComp;

};

