// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/CurveTable.h"
#include "GameplayTagContainer.h"
#include "FortPropertyOverrideData.h"
#include "FortPropertyOverrideReplication.h"
#include "FortUserOptionDefinitions.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortActorOptionsComponent.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class UPlaylistUserOptions;

UENUM()
enum class EFortLabelOverrideForceFixUpMode : uint8
{
	NONE = 0,
	FROM_LABEL_OVERRIDE = 1,
	FROM_BASE_LABEL = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnyPropertyChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRestoreDefaultsDelegate);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortActorOptionsComponent : public UActorComponent, public ILevelSaveSpawnable, public IUserOptionDefinitionContainerInterface, public IFortPropertyOverrideProvider, public IFortPropertyOverrideReplProvider, public IFortPropertyOverrideDataAccessor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	bool BlueprintGetInteractionTime(const AFortPawn* InteractingPawn, float& OutInteractionTime) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Interaction")
	bool BlueprintOnLocalInteract(AFortPlayerPawn* InteractingPawn);

	UFUNCTION(BlueprintPure, Category="Interaction")
	bool CanEditOptionsComponent(AFortPawn* InteractingPawn);

	UFUNCTION(BlueprintPure, Category="Option Data")
	bool GetPropertyOverrides(TMap<FString, FString>& CurrentOptions) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Interaction")
	bool OnLocalInteract(AFortPlayerPawn* InteractingPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Option Data")
	void RefreshPropertyOverrides();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Option Data")
	void RemovePropertyOverrides(const TArray<FString>& Options);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Option Data")
	bool SetPropertyOverrides(const TMap<FString, FString>& NewOptions);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Option Data")
	bool SetPropertyOverrideValues(const TMap<FString, FString>& NewOptions);

	UFUNCTION()
	void TryToLocalizeStrings();

	UPROPERTY(EditInstanceOnly, SaveGame, ReplicatedUsing=OnRep_PlayerOptionData, Category="Option Data")
	FPropertyOverrideData PlayerOptionData;

	UPROPERTY(BlueprintAssignable, Category="Option Data")
	FAnyPropertyChangedDelegate OnAnyPropertyChanged;

	UPROPERTY(BlueprintAssignable, Category="Option Data")
	FAnyPropertyChangedDelegate OnPropertiesLoaded;

	UPROPERTY()
	FAnyPropertyChangedDelegate OnPreAnyPropertyChanged;

	UPROPERTY()
	FAnyPropertyChangedDelegate OnPropertiesReadyForLocalization;

	UPROPERTY(BlueprintAssignable, Category="Option Data")
	FRestoreDefaultsDelegate OnRestoreDefaults;

	UPROPERTY(EditAnywhere, Category="Option Data")
	bool bRedirectInteractToParent;

protected:
	UFUNCTION()
	void HandlePlaylistLoadedForLocalization(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_PlayerOptionData();

	UFUNCTION()
	void ResolvePendingRepOverrides();

private:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FCurveTableRowHandle K2_GetInteractionSpeed() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FText K2_GetInteractionText() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FText K2_GetOptionsDescription() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FText K2_GetOptionsDisplayName() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	const UPlaylistUserOptions* K2_GetPlayerOptions() const;

	UPROPERTY(EditAnywhere, BlueprintGetter=K2_GetOptionsDisplayName, Category="Option Data", meta=(DisplayName="Options Display Name", AllowPrivateAccess="true"))
	FText Internal_OptionsDisplayName;

	UPROPERTY(EditAnywhere, BlueprintGetter=K2_GetOptionsDescription, Category="Option Data", meta=(DisplayName="Options Description", AllowPrivateAccess="true"))
	FText Internal_OptionsDescription;

	UPROPERTY(EditAnywhere, BlueprintGetter=K2_GetInteractionText, Category="Option Data", meta=(DisplayName="Interaction Text", AllowPrivateAccess="true"))
	FText Internal_InteractionText;

	UPROPERTY(EditAnywhere, BlueprintGetter=K2_GetInteractionSpeed, Category="Option Data", meta=(DisplayName="Interaction Speed", AllowPrivateAccess="true"))
	FCurveTableRowHandle Internal_InteractionSpeed;

	UPROPERTY(EditAnywhere, BlueprintGetter=K2_GetPlayerOptions, Category="Option Data", meta=(DisplayName="Player Options", AllowPrivateAccess="true"))
	TObjectPtr<UPlaylistUserOptions> Internal_PlayerOptions;

};

