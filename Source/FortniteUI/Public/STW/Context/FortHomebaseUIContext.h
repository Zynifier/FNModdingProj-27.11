// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "BlueprintContextBase.h"
#include "FortMultiSize.h"
#include "FortUITypes.h"
#include "FortHomebaseUIContext.generated.h"

class APlayerController;
class UDataTable;
class UFortCampaignHeroLoadoutItem;
class UFortCollectionBookData;
class UFortGadgetItemDefinition;
class UFortHero;
class UFortItem;
class UFortMcpProfileCampaign;
class UFortQuestItemDefinition;
class UFortWorldItem;
class UGameInstance;
enum class EFortDialogResult : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEarlyGameFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlottingPreviewChangedDelegate);

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortDisableAutoSlottingPromptAction : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CompleteExecution(const EFortDialogResult Result, const FName ResultName);

	UFUNCTION(BlueprintImplementableEvent)
	void Execute();

	UPROPERTY(BlueprintReadOnly, Category="FortDisableAutoSlottingPromptAction")
	TWeakObjectPtr<APlayerController> OwningPlayerController;

private:
	UPROPERTY()
	TWeakObjectPtr<UGameInstance> RegisteredWithGameInstance;

};

UCLASS()
class FORTNITEUI_API UFortHomebaseUIContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDifferentHeroLoadoutSlotFocused, FName, SlotName);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDifferentHeroLoadoutViewed, const UFortCampaignHeroLoadoutItem*, PreviousLoadout, const UFortCampaignHeroLoadoutItem*, NewLoadout);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNodesPurchased, FName, NodeId);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShouldAutoSlotSurvivorSquadsChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSlottedPrimaryHeroChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSquadSlotChanged, FName, SquadName, int32, SlotIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSurvivorSquadsAutoSlotted);

public:
	UFUNCTION(BlueprintCallable, Category="Homebase")
	void AutoSlotAllSurvivorSquads();

	UFUNCTION(BlueprintPure, Category="Collection Book")
	UFortCollectionBookData* GetCollectionBookData() const;

	UFUNCTION(BlueprintPure, Category="Hero Loadout")
	FName GetCurrentlyFocusedHeroLoadoutSlotName() const;

	UFUNCTION(BlueprintPure, Category="Hero Loadout")
	UFortCampaignHeroLoadoutItem* GetCurrentlyViewedHeroLoadout() const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	UFortItem* GetItemInSquadSlot(FName SquadName, int32 SlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	TArray<UFortItem*> GetItemsInSquad(const FName SquadId, bool bRemoveEmptySquadSlots = true) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool GetShouldAutoSlotSurvivorSquads() const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	UFortHero* GetSlottedPrimaryHero() const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	FFortMultiSizeBrush GetSquadIcon(const FName SquadId) const;

	UFUNCTION(BlueprintPure, Category="Homebase Gadgets")
	bool GetUnlockedGadgets(TArray<UFortItem*>& UnlockedGadgets) const;

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	UFortQuestItemDefinition* GetUnlockingQuestDefinitionForHeroLoadoutSlot(const FName& SlotName, const UFortCampaignHeroLoadoutItem* Loadout) const;

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	UFortQuestItemDefinition* GetUnlockingQuestDefinitionForSquadSlot(const FName& SquadName, const int32 SlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	void GetWorkerSetBonusEffectModifiers(const FGameplayTag& SetBonusTag, TArray<FFortAttributeModifierDisplayData>& OutModifiers) const;

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	bool IsAnySquadSlotUnlocked(const FName SquadId) const;

	UFUNCTION(BlueprintPure, Category="Hero Loadout")
	bool IsHeroLoadoutSlotUnlocked(const FName& SlotName, const UFortCampaignHeroLoadoutItem* Loadout) const;

	UFUNCTION(BlueprintCallable, Category="Hero Loadout")
	void SetCurrentlyFocusedHeroLoadoutSlotName(const FName& SlotName);

	UFUNCTION(BlueprintCallable, Category="Hero Loadout")
	void SetCurrentlyViewedHeroLoadout(const UFortCampaignHeroLoadoutItem* Loadout);

	UFUNCTION(BlueprintCallable, Category="Homebase")
	void SetShouldAutoSlotSurvivorSquads(const bool Value);

	UPROPERTY(BlueprintAssignable, Category="Homebase")
	FOnShouldAutoSlotSurvivorSquadsChanged OnShouldAutoSlotSurvivorSquadsChanged;

	UPROPERTY(BlueprintAssignable, Category="Homebase")
	FOnSquadSlotChanged OnSquadSlotChanged;

	UPROPERTY(BlueprintAssignable, Category="Homebase")
	FOnSurvivorSquadsAutoSlotted OnSurvivorSquadsAutoSlotted;

	UPROPERTY(BlueprintAssignable, Category="Homebase")
	FOnNodesPurchased OnNodePurchased;

	UPROPERTY(BlueprintAssignable)
	FOnSlottedPrimaryHeroChanged OnSlottedPrimaryHeroChanged;

	UPROPERTY(BlueprintAssignable, Category="Hero Loadout")
	FOnDifferentHeroLoadoutViewed OnDifferentHeroLoadoutViewed;

	UPROPERTY(BlueprintAssignable, Category="Hero Loadout")
	FOnDifferentHeroLoadoutSlotFocused OnDifferentHeroLoadoutSlotFocused;

private:
	UFUNCTION()
	void HandleDifferentHeroLoadoutActivated(UFortMcpProfileCampaign* Profile);

	UPROPERTY(Transient)
	TSoftObjectPtr<UDataTable> SquadIconDataTableAsset;

	UPROPERTY()
	TMap<TObjectPtr<UFortGadgetItemDefinition>, TObjectPtr<UFortWorldItem>> GadgetDefinitionToInstanceMap;

};

