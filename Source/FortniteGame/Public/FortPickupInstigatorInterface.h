// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "Math/MathFwd.h"
#include "Creative/FortCreativeItemTemplate.h"
#include "Items/FortItemEntry.h"
#include "FortPickupInstigatorInterface.generated.h"

class AFortPawn;
class AFortPickup;
class APlayerController;
class IFortPickupEventHandler;
class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FPickupInstigatorData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="PickupInstigatorData")
	uint8 TeamIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="PickupInstigatorData")
	TEnumAsByte<ETeamAttitude::Type> TargetAttitude;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="PickupInstigatorData")
	float AccentColorParam;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="PickupInstigatorData")
	int32 ScoreValue;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, NotReplicated, Category="PickupInstigatorData")
	TSubclassOf<AFortPickup> OverridePickupClass;

};

UINTERFACE(BlueprintType)
class UFortPickupEventHandler : public UInterface
{
	GENERATED_BODY()
};

class IFortPickupEventHandler
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void HandleItemAdded(APlayerController* PlayerController, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleItemCaptured(APlayerController* PlayerController, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleItemRemoved(APlayerController* PlayerController, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupCaptured(AFortPickup* Pickup);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupClaimed(AFortPickup* Pickup, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* ItemDefinition, FVector PickupLocation);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupDespawned(AFortPickup* Pickup);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupDestroyed(AFortPickup* Pickup);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupDropped(AFortPickup* Pickup);

	UFUNCTION(BlueprintNativeEvent)
	void HandlePickupSpawned(AFortPickup* Pickup);

};

UINTERFACE(BlueprintType)
class UFortPickupInstigator : public UInterface
{
	GENERATED_BODY()
};

class IFortPickupInstigator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetInstigatorData(FPickupInstigatorData& InstigatorData, int32 ItemIndex = 0) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetItemTemplateData(FCreativeItemTemplateData& TemplateData, int32 ItemIndex = 0) const;

	UFUNCTION(BlueprintNativeEvent)
	TScriptInterface<IFortPickupEventHandler> GetPickupEventHandler() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetTrackedIndex(int32 ItemIndex = 0) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<int32> GetTrackedIndices() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetTrackedItemCount() const;

	UFUNCTION(BlueprintNativeEvent)
	void SetTrackedIndex(int32 TrackedIndex, int32 ItemIndex);

};

