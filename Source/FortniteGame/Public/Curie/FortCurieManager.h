// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CurieManager.h"
#include "FortCurieManager.generated.h"

class UActorComponent;
class UCurieManagerComponentConfig;
class UFortCurieComponent;
class UFortCurieFXManager;
class UFortCurieSettings;
class UFortCurieToggleComponent;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurieComponentRegisteredSignatureInternal, UFortCurieComponent*, RegisteredCurieComponent);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FCurieComponentRegisteredSignature, UFortCurieComponent*, RegisteredCurieComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCurieToggleGroupMemberStateChangeSignatureInternal, UFortCurieToggleComponent*, ToggleComponent, bool, bActive);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FCurieToggleGroupMemberStateChangeSignature, UFortCurieToggleComponent*, ToggleComponent, bool, bActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurieToggleGroupSameStateSignatureInternal, UFortCurieToggleComponent*, LastToggleComponent);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FCurieToggleGroupSameStateSignature, UFortCurieToggleComponent*, LastToggleComponent);

USTRUCT()
struct FCurieToggleComponentGroup
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCurieToggleComponent>> GroupComponents;

	UPROPERTY()
	FCurieToggleGroupSameStateSignatureInternal OnToggleGroupFullyActive;

	UPROPERTY()
	FCurieToggleGroupSameStateSignatureInternal OnToggleGroupFullyInactive;

	UPROPERTY()
	FCurieToggleGroupMemberStateChangeSignatureInternal OnToggleGroupMemberStateChange;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortCurieManager : public UCurieManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void BindDelegateOnToggleGroupFullyActive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void BindDelegateOnToggleGroupFullyInactive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void BindDelegateOnToggleGroupMemberActiveStateChange(FGameplayTag ToggleGroup, FCurieToggleGroupMemberStateChangeSignature Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void UnbindDelegateOnToggleGroupFullyActive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void UnbindDelegateOnToggleGroupFullyInactive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ToggleGroup")
	void UnbindDelegateOnToggleGroupMemberActiveStateChange(FGameplayTag ToggleGroup, FCurieToggleGroupMemberStateChangeSignature Delegate);

protected:
	UFUNCTION()
	void InternalPhysicsComponentAwakeChanged(UPrimitiveComponent* SimulatingComponent, const bool bIsAwake);

	UFUNCTION()
	virtual void OnRep_ValidStateIdentifiers();

	UFUNCTION()
	void OnToggleGroupComponentActivated(UActorComponent* InComponent, bool bReset);

	UFUNCTION()
	void OnToggleGroupComponentDeactivated(UActorComponent* InComponent);

	UPROPERTY(Transient)
	TMap<FGameplayTag, FCurieToggleComponentGroup> ToggleComponentGroups;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieFXManager> FXManager;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ValidStateIdentifiers)
	TArray<FGameplayTag> ValidStateIdentifiers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, int32> StateIdentifierToIdxMap;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieSettings> CurieSettings;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCurieManagerComponentConfig>> ConfigOverrides;

	UPROPERTY(Transient)
	int32 CurrentlyUpdatingOverlapHandle;

	UPROPERTY(Transient)
	int32 ElementOverlapMaximumTestActorsPerFrame;

	UPROPERTY(Transient)
	float ElementOverlapMaximumDelayBetweenChecks;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieManager")
	bool bAllowCurieApplicationViaDamageFormulaTags;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieManager")
	bool bCurieElementsBlockBuildingEdit;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieManager")
	bool bCurieElementsBlockBuildingRepair;

};

