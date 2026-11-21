// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Building/BuildingProp.h"
#include "FortItemAndCount.h"
#include "FortItemQuantityPair.h"
#include "FortPickupInstigatorInterface.h"
#include "GameData/FortGameplayFeedbackEventData.h"
#include "BuildingProp_CaptureItemSpawner.generated.h"

class AFortPawn;
class UFortWorldItemDefinition;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_CaptureItemSpawner : public ABuildingProp, public IFortPickupEventHandler
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanTakeFlag(AFortPawn* InteractingPawn) const;

protected:
	UFUNCTION(BlueprintCallable, Category="CaptureItemSpawner")
	int32 AddItemRef();

	UFUNCTION(BlueprintImplementableEvent, Category="CaptureItemSpawner", meta=(DisplayName="Notify Feedback Event"))
	void K2_NotifyFeedbackEvent(const FGameplayFeedbackEventParams& EventParams, bool bFriendlyEvent);

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_NotifyFeedbackEvent(const FGameplayFeedbackEventParams& EventParams, const FFortItemQuantityPair& ItemEntry, const FGuid& ItemVariantGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureItemSpawner")
	void RegisterSpecialActor(UFortWorldItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="CaptureItemSpawner")
	int32 RemoveItemRef();

	UFUNCTION(BlueprintCallable, Category="CaptureItemSpawner")
	void ResetItemRefCount();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureItemSpawner")
	void SendCaptureItemFeedbackEvent(const FGameplayFeedbackEventParams& EventParams, const FItemAndCount& ItemEntry);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureItemSpawner")
	void UnregisterSpecialActor();

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureItemSpawner")
	int32 ItemRefCount;

	UPROPERTY(Transient)
	bool bPickupWasClaimed;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions")
	bool bShowCaptureMessages;

};

