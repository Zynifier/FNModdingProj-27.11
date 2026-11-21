// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Building/BuildingTypes.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeResourceNodeComponent.generated.h"

class ABuildingSMActor;
class AFortPlayerController;
enum class EFortCreativeResourceNodeDepletionMode : uint8;

UENUM(BlueprintType)
enum class EFortCreativeResourceNodeDepletionMode : uint8
{
	Destroy = 0,
	RestockOnDelay = 1,
	RestockOverTime = 2,
	StayEmpty = 3,
	None = 4,
};

USTRUCT()
struct FFortCreativeResourceNodePropData
{
	GENERATED_BODY()

};

UCLASS(Config=Game, BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativeResourceNodeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearAffectedProps();

	UFUNCTION(BlueprintPure)
	TArray<ABuildingSMActor*> GetAffectedProps() const;

	UFUNCTION(BlueprintPure)
	EFortResourceType::Type GetOriginalResourceType(ABuildingSMActor* InProp) const;

	UFUNCTION(BlueprintCallable)
	void SetAffectedProps(TArray<ABuildingSMActor*> InAffectedProps);

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddInventoryItemWithoutAnimation(AFortPlayerController* InInstigatorController, const FFortItemEntry& ItemDescription);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Added Affected Prop"))
	void BP_OnAddedAffectedProp(ABuildingSMActor* InAddedProp);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Modify Resources Remaining On Prop"))
	void BP_OnModifyResourcesRemainingOnProp(ABuildingSMActor* InProp, const int32 InDeltaChange);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Removed Affected Prop"))
	void BP_OnRemovedAffectedProp(ABuildingSMActor* InRemovedProp);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Set Resources Remaining On Prop"))
	void BP_OnSetResourcesRemainingOnProp(ABuildingSMActor* InProp, const int32 InResourcesRemaining);

	UFUNCTION(BlueprintPure)
	int32 GetResourcesRemainingOnProp(ABuildingSMActor* InProp) const;

	UFUNCTION(BlueprintCallable)
	void ModifyResourcesRemainingOnAllProps(const int32 InDeltaChange);

	UFUNCTION(BlueprintCallable)
	void ModifyResourcesRemainingOnProp(ABuildingSMActor* InPropToSet, const int32 InDeltaChange);

	UFUNCTION(BlueprintCallable)
	static void ReportDamagedResourceBuildingOnClient(AFortPlayerController* InInstigatorController, ABuildingSMActor* InBuilding, const EFortResourceType::Type InResourceType, const int32 InResourcesToDistribute, const bool bIsDestroyed, const bool bJustHitWeakspot);

	UFUNCTION(BlueprintCallable)
	void SetResourcesRemainingOnAllProps(const int32 InResourcesRemaining);

	UFUNCTION(BlueprintCallable)
	void SetResourcesRemainingOnProp(ABuildingSMActor* InPropToSet, const int32 InResourcesRemaining);

	UFUNCTION(BlueprintCallable)
	void SetRestockTimer(ABuildingSMActor* InPropToRestock, const EFortCreativeResourceNodeDepletionMode InDepletionMode, const int32 RestockDelay, const int32 RestockAmount);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeResourceNodeComponent")
	int32 PartialRestockDelay;

};

