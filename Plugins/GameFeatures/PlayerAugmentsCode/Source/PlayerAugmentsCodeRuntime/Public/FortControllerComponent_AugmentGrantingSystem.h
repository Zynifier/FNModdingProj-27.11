// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "Items/FortItemEntry.h"
#include "FortControllerComponent_AugmentGrantingSystem.generated.h"

class AController;
class APawn;
class IFortInventoryOwnerInterface;
class UFortControllerComponent_AugmentGrantingSystem;
class UFortItemDefinition;
class UFortPlayerAugmentItemDefinition;
class UFortWeaponItemDefinition;
class UFortWorldItem;
class UInputComponent;
class UObject;

USTRUCT(BlueprintType)
struct FFortAugmentRerollCost
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAugmentRerollCost")
	TObjectPtr<UFortItemDefinition> ResourceCurrency;

	UPROPERTY(EditDefaultsOnly, Category="FortAugmentRerollCost")
	FScalableFloat Amount;

};

USTRUCT(BlueprintType)
struct FPlayerAugmentChoiceDatum
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="PlayerAugmentChoiceDatum")
	TObjectPtr<UFortPlayerAugmentItemDefinition> ItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="PlayerAugmentChoiceDatum")
	FGameplayTagContainer ChoiceMetaTags;

};

UCLASS(MinimalAPI)
class UAugmentFuctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Augment")
	static const UFortWorldItem* GiveAugmentWithPreventDropping(UFortPlayerAugmentItemDefinition* ChosenAugmentDef, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner);

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_AugmentGrantingSystem : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCanSelectAugmentChangedDelegate, bool, bCanSelectAugment);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorityRequestAugmentChoicesDelegate, const TArray<UFortPlayerAugmentItemDefinition*>&, IgnoreInRoll);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAvailableAugmentsForGrantingUpdatedDelegate, UFortControllerComponent_AugmentGrantingSystem*, GrantingComponent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFreeRerollsUpdatedDelegate, int32, NewNumFreeRerolls);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalRerollDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumLockedSelectionChoicesUpdatedDelegate, int32, NewNumFreeRerolls);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReplicateNumPendingAugmentsToGrantDelegate, int8, NumPendingAugmentsToGrant);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectedAugmentForGrantDelegate, UFortPlayerAugmentItemDefinition*, SelectedAugment);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthorityGrantFreeReroll();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthorityGrantNewAugment();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthorityIncrementLockedSelectionChoices(const int32 NumLocksToAdd = 1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(DefaultToSelf="Instigator"))
	void AuthorityRequestSelectionToolItemGrant(UObject* Instigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthorityResetAugmentData();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthoritySetAvailableAugmentChoices(const TArray<FPlayerAugmentChoiceDatum>& AvailableAugmentsToGrant);

	UFUNCTION(BlueprintPure)
	bool CanReroll() const;

	UFUNCTION(BlueprintCallable)
	void ClientSelectAvailableAugmentToGrant(UFortPlayerAugmentItemDefinition* ChosenAugmentDef);

	UFUNCTION(BlueprintCallable)
	static UFortControllerComponent_AugmentGrantingSystem* GetAugmentGrantingComponentFromController(const AController* Controller);

	UFUNCTION(BlueprintPure)
	TArray<FPlayerAugmentChoiceDatum> GetAvailableAugmentsToGrant() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumFreeRerolls() const;

	UFUNCTION(BlueprintPure)
	int32 GetPendingAugmentsToGrant() const;

	UFUNCTION(BlueprintPure)
	bool IsSelectionChoicesLocked() const;

	UFUNCTION(BlueprintPure)
	bool IsSelectionItemEquipped() const;

	UPROPERTY(BlueprintAssignable)
	FCanSelectAugmentChangedDelegate OnCanSelectAugmentChanged;

	UPROPERTY(BlueprintAssignable)
	FOnSelectedAugmentForGrantDelegate OnSelectedAugmentForGrant;

	UPROPERTY(BlueprintAssignable)
	FOnAvailableAugmentsForGrantingUpdatedDelegate OnAvailableAugmentsForGrantingUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnAuthorityRequestAugmentChoicesDelegate OnAuthorityRequestAugmentChoices;

	UPROPERTY(BlueprintAssignable)
	FOnLocalRerollDelegate OnLocalReroll;

	UPROPERTY(BlueprintAssignable)
	FOnReplicateNumPendingAugmentsToGrantDelegate OnReplicateNumPendingAugmentsToGrant;

protected:
	UFUNCTION()
	void HandleChangedBuildMode(bool bEnteredBuildMode);

	UFUNCTION()
	void HandleHolsteredEvent();

	UFUNCTION()
	void HandleUnHolsteredEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalEquipAugmentSelectionPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalUnequipAugmentSelectionPressed();

	UFUNCTION()
	void OnMinigameStarted();

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	TObjectPtr<UFortWeaponItemDefinition> AugmentSelectionModeItem;

	UPROPERTY(BlueprintReadOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	TWeakObjectPtr<UFortItemDefinition> CachedResourceCurrencyOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> SelectionModeWorldItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	FScalableFloat Enabled;

private:
	UFUNCTION()
	void HandlePossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bVisible);

	UFUNCTION()
	void OnRep_NumFreeRerolls();

	UFUNCTION()
	void OnRep_NumLockedSelectionChoices();

	UFUNCTION()
	void OnRep_ReplicatedAugmentChoices();

	UFUNCTION()
	void OnRep_ReplicatedNumPendingAugmentsToGrant();

	UFUNCTION()
	void OnRep_SelectorItemEntry();

	UFUNCTION(Server, Reliable)
	void ServerGrantAugment(UFortPlayerAugmentItemDefinition* ChosenAugmentDef);

	UFUNCTION(Server, Reliable)
	void ServerRequestReroll();

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedNumPendingAugmentsToGrant)
	int8 ReplicatedNumPendingAugmentsToGrant;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedAugmentChoices)
	TArray<FPlayerAugmentChoiceDatum> ReplicatedAugmentChoices;

	UPROPERTY(ReplicatedUsing=OnRep_NumFreeRerolls)
	int8 NumFreeRerolls;

	UPROPERTY(ReplicatedUsing=OnRep_NumLockedSelectionChoices)
	int8 NumLockedSelectionChoices;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PrimaryInputComponentWeaponMode;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PrimaryInputComponentBuildMode;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> TemporaryInputComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	FScalableFloat AugmentSelectInputPriority;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	FGameplayTagContainer SelectionBlockedPlayerTags;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	FGameplayTagContainer AugmentSelectInputDisablePlayerTags;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_AugmentGrantingSystem")
	TArray<FFortAugmentRerollCost> RerollCosts;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SelectorItemEntry)
	FFortItemEntry SelectorItemEntry;

	UPROPERTY(Transient)
	FFortItemEntry LocalCachedPreviousWeapon;

};

