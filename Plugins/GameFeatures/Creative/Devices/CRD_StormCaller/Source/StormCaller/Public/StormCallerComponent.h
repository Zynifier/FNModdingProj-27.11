// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "StormCallerComponent.generated.h"

class AFortPoiVolume;
class UFortActorOptionsComponent;
class UPlaylistUserOptions;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class STORMCALLER_API UStormCallerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyPOINamesToDataRegistry(const UPlaylistUserOptions* UserOptions, const FGameplayTag& GameplayTagForPOI, const FText& MapCenterText, const FText& RandomText, const FText& BeaconText);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ApplySavedPoiOptions(const TArray<FString>& PoiSavedOptionKeys, const TArray<FText>& PoiSavedOptionName, UFortActorOptionsComponent* ToyOptionsComponent);

	UFUNCTION(BlueprintCallable)
	AFortPoiVolume* GetPoiVolumeFromOptionIndex(int32 OptionIndex);

	UFUNCTION(BlueprintCallable)
	AFortPoiVolume* GetRandomPoiVolume();

	UFUNCTION(BlueprintPure)
	const TArray<FVector4>& GetSafeZoneLocationBlockList() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SpawnInitialSafeZone();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdatePoiSavedOptions(UPARAM(ref) TArray<FString>& InOutPoiSavedOptionKeys, UPARAM(ref) TArray<FText>& InOutPoiSavedOptionNames, const UPlaylistUserOptions* UserOptions, const FGameplayTag& GameplayTagForPOI);

};

