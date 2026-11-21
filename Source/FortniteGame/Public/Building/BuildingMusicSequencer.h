// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingMusicSequencer.generated.h"

class AController;
class USoundAttenuation;
class USoundBase;
class USoundConcurrency;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingMusicSequencer : public ABuildingTrapFloor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HitActorsAsync(const FTransform& Transform, const FBoxSphereBounds& Bounds);

	UFUNCTION(BlueprintCallable)
	void ResetHitActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="BuildingMusicSequencer")
	TObjectPtr<AController> TriggerInstigator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="BuildingMusicSequencer")
	TObjectPtr<AController> CachedTriggerInstigator;

};

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortMusicSequencerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMusicSequencerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetMusicSequencerHitSound(const AController* InstigatedBy, USoundBase*& Sound, int32& SoundIndex, USoundAttenuation*& Attenuation, TSet<USoundConcurrency*>& Concurrency) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetMusicSequencerHitSoundLocation(const AController* InstigatedBy) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnHitByMusicSequencer(const AController* InstigatedBy);

};

