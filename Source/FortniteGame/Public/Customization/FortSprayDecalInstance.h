// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "FortSprayDecalInstance.generated.h"

class AFortPlayerController;
class UAthenaSprayItemDefinition;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FFortSprayDecalRepPayload
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, SaveGame, Category="FortSprayDecalRepPayload")
	TObjectPtr<UAthenaSprayItemDefinition> SprayAsset;

	UPROPERTY(BlueprintReadOnly, Category="FortSprayDecalRepPayload")
	FName BannerName;

	UPROPERTY(BlueprintReadOnly, Category="FortSprayDecalRepPayload")
	FName BannerColor;

	UPROPERTY(BlueprintReadOnly, Category="FortSprayDecalRepPayload")
	int32 SavedStatValue;

	UPROPERTY(BlueprintReadOnly, Category="FortSprayDecalRepPayload")
	int32 SortOrder;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AFortSprayDecalInstance : public ABuildingSMActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetSpraySortOrder() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBounceOccurs();

	UFUNCTION()
	void OnRep_SprayInfo();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnSprayInfoReady();

	UFUNCTION(BlueprintCallable)
	void SetSprayParameters(AFortPlayerController* SpawningPC, UAthenaSprayItemDefinition* InSprayAsset);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartSprayFadeOutDueToNewPlacement();

protected:
	UPROPERTY(BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_SprayInfo, Category="FortSprayDecalInstance")
	FFortSprayDecalRepPayload SprayInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSprayDecalInstance")
	uint8 bDestroyOnNearbyDestruction : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSprayDecalInstance")
	uint8 bDestroyOnNearbyDamageTaken : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSprayDecalInstance")
	uint8 bDestroyOnNearbyBounce : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortSprayDecalInstance")
	TArray<TObjectPtr<UMaterialInstanceDynamic>> SprayMIDsThatCanBounce;

};

