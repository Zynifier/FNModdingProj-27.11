// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortPoiManager.generated.h"

class AFortPlayerControllerGameplay;
class AFortPoiVolume;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPoiManagerMinimalStateInitialized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPoiEventDelegateMulticast, const FGameplayTag&, PoiTag, AFortPlayerControllerGameplay*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPoiEventDelegateSingle, const FGameplayTag&, PoiTag, AFortPlayerControllerGameplay*, PlayerController);

USTRUCT()
struct FFortPoiGridInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector2D WorldGridStart;

	UPROPERTY()
	FVector2D WorldGridEnd;

	UPROPERTY()
	FVector2D WorldGridSpacing;

	UPROPERTY()
	int32 GridCountX;

	UPROPERTY()
	int32 GridCountY;

	UPROPERTY()
	FVector2D WorldGridTotalSize;

};

USTRUCT()
struct FFortPoiVolumeGridCell
{
	GENERATED_BODY()

};

UCLASS(Config=Game, Transient, NotPlaceable, MinimalAPI)
class AFortPoiManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BindOnPoiEntered(FGameplayTag PoiTag, FPoiEventDelegateSingle Event);

	UFUNCTION(BlueprintCallable)
	void BindOnPoiExited(FGameplayTag PoiTag, FPoiEventDelegateSingle Event);

	UFUNCTION(BlueprintPure)
	const TArray<AFortPoiVolume*>& GetAllPoiVolumes() const;

	UFUNCTION(BlueprintCallable)
	const TArray<AFortPoiVolume*>& GetNamedOnMapPoiVolumes();

	UFUNCTION(BlueprintCallable)
	const AFortPoiVolume* GetVolumeWithTag(const FGameplayTag& TagToCheck);

	UFUNCTION(BlueprintPure)
	bool HasInitialized() const;

	UFUNCTION(BlueprintCallable)
	void UnbindOnPoiEntered(FGameplayTag PoiTag, FPoiEventDelegateSingle Event);

	UFUNCTION(BlueprintCallable)
	void UnbindOnPoiExited(FGameplayTag PoiTag, FPoiEventDelegateSingle Event);

	UPROPERTY(ReplicatedUsing=OnRep_FortPoiGridInfo)
	FFortPoiGridInfo FortPoiGridInfo;

	UPROPERTY(BlueprintAssignable)
	FOnPoiManagerMinimalStateInitialized OnMinimalStateInitializedEvent;

private:
	UFUNCTION()
	void MinimalInitPostEventsReady(const TArray<FString>& NewEvents);

	UFUNCTION()
	void OnRep_FortPoiGridInfo();

	UFUNCTION()
	void OnRep_PoiGridForDebugDisplay();

	UFUNCTION()
	void OnRep_PoiTagContainerTable();

	UPROPERTY()
	TArray<TObjectPtr<AFortPoiVolume>> SmallTickUpdatedPoi;

	UPROPERTY()
	TArray<TObjectPtr<AFortPoiVolume>> LargePoiVolumes;

	UPROPERTY()
	TArray<TObjectPtr<AFortPoiVolume>> PendingLargePoiVolumes;

	UPROPERTY()
	TArray<TObjectPtr<AFortPoiVolume>> NamedOnMapPoiVolumes;

	UPROPERTY()
	TArray<TObjectPtr<AFortPoiVolume>> AllPoiVolumes;

	UPROPERTY()
	int32 TestPlayerIndex;

	UPROPERTY(Config)
	TArray<FName> POIsExcludedFromBeginGolden;

	UPROPERTY(Config)
	int32 MaxNumTestsPerFrame;

	UPROPERTY(ReplicatedUsing=OnRep_PoiTagContainerTable)
	TArray<FGameplayTagContainer> PoiTagContainerTable;

	UPROPERTY(ReplicatedUsing=OnRep_PoiTagContainerTable)
	int32 PoiTagContainerTableSize;

	UPROPERTY(Transient)
	bool bIsReinitializingGrid;

	UPROPERTY(Transient)
	bool bHasInitialized;

	UPROPERTY()
	int32 PoiGridPrevSizeForDebugDisplay;

	UPROPERTY(ReplicatedUsing=OnRep_PoiGridForDebugDisplay)
	TArray<int16> PoiGridForDebugDisplay;

	UPROPERTY()
	TArray<int16> FortPoiGridCellsTagContainerTableIds;

	UPROPERTY()
	TArray<FFortPoiVolumeGridCell> FortPoiGridCellsLargeVolume;

};

