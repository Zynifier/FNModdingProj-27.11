// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "Creative/CreativeMoveToolTarget.h"
#include "OnlineLinkId.h"
#include "FortCreativeDeviceProp.generated.h"

class AFortPawn;
class UFortActorOptionsComponent;
class UFortMinigameProgressComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeDeviceProp : public ABuildingProp, public ICreativeMoveToolTarget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BP_SetVisibility(bool bVisible);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(CallInEditor="true", DisplayName="GetAssetRegistryTags"))
	FORTNITEGAME_API void BP_GetAssetRegistryTags(TMap<FName, FString>& OutTags) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="PostDuplicate"))
	FORTNITEGAME_API void BP_PostDuplicate(bool bDuplicateForPie);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API bool BP_ShouldSuppressInteractionWidget() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static FOnlineLinkId CreateLinkId(const FString& LinkString);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static FOnlineLinkId CreateLinkIdWithVersion(const FString& LinkString, const int32 Version);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static const FString LinkIdToString(const FOnlineLinkId& LinkString);

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(DisplayAfter="bSuppressSimpleInteractionWidgetForTouch"))
	bool bSuppressPlayTimeSimpleInteractionWidgetForTouch;

private:
	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static bool BPCanInteractNativeHelper(const AFortPawn* InteractingPawn, const UFortActorOptionsComponent* ToyOptionsComponent, const UFortMinigameProgressComponent* MinigameProgressComponent);

};

