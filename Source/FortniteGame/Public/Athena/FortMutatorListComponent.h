// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortPropertyOverrideData.h"
#include "FortPropertyOverrideReplication.h"
#include "FortMutatorListComponent.generated.h"

class AFortGameplayMutator;
class AFortMinigame;
class UPlaylistUserOptions;

UENUM()
enum class EMutatorListInitState : int32
{
	Default = 0,
	Enabled = 1,
	Disabled = 2,
};

UENUM()
enum class EMutatorOverrideSource : uint8
{
	Default = 0,
	External = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMutatorListSettingsChanged, const FPropertyOverrideData&, OverrideData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMutatorListSettingsInitialized, const FPropertyOverrideData&, OverrideData);

USTRUCT()
struct FMutatorOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EMutatorOverrideSource OverrideSource;

	UPROPERTY()
	FPropertyOverrideData PropertyOverrideArray;

	UPROPERTY(NotReplicated)
	EMutatorOverrideSource CachedOverrideSource;

	UPROPERTY(NotReplicated)
	FPropertyOverrideData CachedExternalOverrides;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortMutatorListComponent : public UActorComponent, public IFortPropertyOverrideProvider, public IFortPropertyOverrideReplProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Modifiers")
	void AddOrUpdatePropertyOverrides(const TMap<FString, FString>& Properties);

	UFUNCTION(BlueprintPure, Category="Modifier")
	AFortGameplayMutator* GetMutatorByClass(TSubclassOf<AFortGameplayMutator> MutatorClass) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Modifiers")
	TMap<FString, FString> GetPropertyOverridesAsStrings() const;

	UFUNCTION()
	TMap<FString, FString> GetPropertyOverridesAsStringsRaw() const;

	UFUNCTION()
	void OnRep_PropertyOverrideArray();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Modifiers")
	bool RemovePropertyOverride(const FString& Property);

	UFUNCTION()
	void ResolvePendingRepOverrides();

	UFUNCTION(BlueprintCallable, Category="Modifier")
	void SetMutatorsActive(bool bActive);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Modifiers")
	void SetPropertyOverrides(const TMap<FString, FString>& Properties);

	UPROPERTY(EditAnywhere, Category="Modifiers")
	EMutatorListInitState InitState;

	UPROPERTY(EditAnywhere, Category="Modifiers")
	TArray<TSoftClassPtr<AFortGameplayMutator>> MutatorDefs;

	UPROPERTY(EditAnywhere, Category="Modifiers")
	TObjectPtr<UPlaylistUserOptions> UserOptions;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="FortMutatorListComponent")
	TArray<TObjectPtr<AFortGameplayMutator>> Mutators;

	UPROPERTY()
	FOnMutatorListSettingsInitialized OnSettingsInitialized;

	UPROPERTY()
	FOnMutatorListSettingsChanged OnSettingsChanged;

protected:
	UFUNCTION()
	void RegisterMinigameMutators();

	UFUNCTION()
	void UnregisterMinigameMutators();

	UPROPERTY(EditDefaultsOnly, Category="Modifiers")
	bool bShouldMakeMutatorsDormant;

private:
	UFUNCTION()
	void OnMinigameSetUp(AFortMinigame* Minigame);

	UPROPERTY(ReplicatedUsing=OnRep_PropertyOverrideArray)
	FMutatorOverrideData OverrideData;

};

