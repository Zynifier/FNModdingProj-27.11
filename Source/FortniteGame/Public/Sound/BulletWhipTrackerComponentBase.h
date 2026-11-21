// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "BulletWhipTrackerComponentBase.generated.h"

class UAudioComponent;
class USceneComponent;
class USoundBase;

USTRUCT(BlueprintType)
struct FBulletWhipTrackerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	uint8 bAttachSoundToOwner : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	float PassByRadiusMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	float PassByRadiusMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	TObjectPtr<USoundBase> PassByFarSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	TObjectPtr<USoundBase> PassByCloseSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	float MinimumTriggerDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerData")
	float TriggerAheadDistance;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> CurrentAudioComp;

	UPROPERTY(Transient)
	float PreviousPlaneDotProd;

	UPROPERTY(Transient)
	float CachedPassDistance;

	UPROPERTY(Transient)
	FVector CachedPassLocation;

	UPROPERTY(Transient)
	float PassByClosenessIntensity;

	UPROPERTY(Transient)
	bool bActive;

};

UCLASS(Abstract, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UBulletWhipTrackerComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Disable();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Reset(FVector StartLocationIn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UpdateVelocity(FVector CurrentVelocity);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerComponentBase")
	TArray<FBulletWhipTrackerData> WhipTrackerData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerComponentBase")
	uint8 bEnableGravityCheck : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerComponentBase")
	float FadeTimeOnProjectileStop;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CachedPassByPawn;

};

