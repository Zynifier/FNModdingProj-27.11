// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "CreativeQuickbarComponent.generated.h"

class AActor;
class AFortWeapon;
class UFortCreativeUserPrefabItemDefinition;
class UFortItemDefinition;
class UFortPlaysetPropItemDefinition;
class UFortPlaysetWorldItemDefinition;
class UInputComponent;
class ULevelSaveRecord;
class UObjectInteractionBehavior;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickBarRequestSubItemsReceived, const TArray<UFortPlaysetPropItemDefinition*>&, PlaysetPropItems);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickbarActiveChanged, bool, bIsQuickbarActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativeQuickbarClutchReleasedNoAction);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickbarEquippedChanged, bool, bIsQuickbarEquipped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAddedToCreativeQuickbar, int32, SlotIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemAddedToMoveTool);

USTRUCT()
struct FCreativeItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	FGuid Guid;

	UPROPERTY(Transient)
	int32 DesiredSlot;

	UPROPERTY(Transient)
	bool bUseVolumeToSpawn;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UCreativeQuickbarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleCreativeQuickbarPressed(int32 SlotIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleCreativeQuickbarReleased(int32 SlotIndex);

	UFUNCTION(BlueprintPure)
	bool IsQuickbarActive() const;

	UFUNCTION(BlueprintCallable)
	void SetIsQuickbarEquipped(bool bIsEquipped);

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarActiveChanged OnCreativeQuickbarActiveChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarEquippedChanged OnCreativeQuickbarEquippedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarClutchReleasedNoAction OnCreativeQuickbarClutchReleasedNoAction;

	UPROPERTY(BlueprintAssignable)
	FOnItemAddedToMoveTool OnItemAddedToMoveTool;

	UPROPERTY(BlueprintAssignable)
	FOnItemAddedToCreativeQuickbar OnItemAddedToCreativeQuickbar;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActivateQuickbarSlot(int32 SlotIndex);

	UFUNCTION(Client, Reliable)
	void ClientAddToQuickBarComplete(const int32 SlotPutIn, FGuid ItemGuid, const UFortItemDefinition* Playset, bool UseDelayedAddToQuickbar, bool bUseVolumeToSpawn);

	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType CurrentInputType);

	UFUNCTION()
	void HandleMoveToolInteractionEnded();

	UFUNCTION()
	void HandleMoveToolInteractionStarted(UObjectInteractionBehavior* InteractionMode);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleQuickbarClutchPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleQuickbarClutchReleased();

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PopulateQuickbarSlotFromSelection(int32 SlotIndex);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAddItemToQuickBar(const UFortItemDefinition* ItemDefinition, const int32 DesiredSlotIndexconst, FGuid PreviousItemGuid, bool bUseVolumeToSpawn);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAddToQuickBar(const TArray<AActor*>& Actors, const int32 DesiredSlotIndex);

	UPROPERTY(BlueprintReadOnly, Category="CreativeQuickbarComponent")
	bool bIsCreativeQuickbarActive;

	UPROPERTY(BlueprintReadOnly, Category="CreativeQuickbarComponent")
	bool bIsCreativeQuickbarEquipped;

	UPROPERTY(EditDefaultsOnly, Category="Quickbar")
	TArray<TObjectPtr<UFortCreativeUserPrefabItemDefinition>> QuickbarSlotItemDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="Quickbar")
	TObjectPtr<UFortPlaysetWorldItemDefinition> QuickbarSlotPlaysetItemDefinition;

	UPROPERTY()
	TObjectPtr<ULevelSaveRecord> CurrentQuickbarRequestSaveRecord;

private:
	UFUNCTION()
	void ExecuteDelayedAddItemToMoveTool(const UFortItemDefinition* ItemDefinition, bool bUseVolume);

	UFUNCTION()
	void ExecuteDelayedAddItemToQuickbar(const UFortItemDefinition* ItemDefinition, const int32 DesiredSlotIndex, bool bUseVolumeToSpawn);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeQuickbarInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeQuickbarActiveInputComponent;

};

