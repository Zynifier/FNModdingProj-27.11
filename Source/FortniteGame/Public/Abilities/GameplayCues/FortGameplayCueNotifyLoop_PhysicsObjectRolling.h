// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyTypes.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_PhysicsObjectRolling.generated.h"

class UFXSystemAsset;
class UFortLayeredAudioComponent;
class UFortPhysicsObjectComponent;

USTRUCT()
struct FWaterFXData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WaterFXData")
	bool bLinkToPontoonBySocket;

	UPROPERTY(EditDefaultsOnly, Category="WaterFXData", meta=(EditCondition="bLinkToPontoonBySocket"))
	FName PontoonSocketName;

	UPROPERTY(EditDefaultsOnly, Category="WaterFXData")
	FVector SpawnLocationOffset;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TSoftObjectPtr<UFXSystemAsset> FXSystemAsset;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Physics Object Rolling", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_PhysicsObjectRolling : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Physics Object Movement")
	FVector GetHitLocation() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyLoop_PhysicsObjectRolling", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComp;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float MaxRollSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortGameplayCueNotifyLoop_PhysicsObjectRolling", meta=(EditInline="true"))
	TObjectPtr<UFortPhysicsObjectComponent> PhysicsObject;

	UPROPERTY(Transient)
	FHitResult CachedHitResult;

	UPROPERTY(EditDefaultsOnly, Category="Water FX")
	TArray<FWaterFXData> WaterFX;

private:
	UFUNCTION()
	void HandlePontoonEnteredWaterBody(const FSphericalPontoon& Pontoon);

	UFUNCTION()
	void HandlePontoonExitedWaterBody(const FSphericalPontoon& Pontoon);

};

