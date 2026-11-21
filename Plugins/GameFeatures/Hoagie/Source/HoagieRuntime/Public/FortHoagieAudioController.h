// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortHoagieAudioController.generated.h"

class AFortHoagieVehicle;
class UFortLayeredAudioComponent;

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class AFortHoagieAudioController : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void CacheAudioComponents(UFortLayeredAudioComponent* InEngine, UFortLayeredAudioComponent* InRotor);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void CacheHoagieVehicle(AFortHoagieVehicle* InVehicle);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void Update();

protected:
	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	bool bHighQualityOverride;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	bool bLocalPlayerInHoagie;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	bool bCriticalDamageNative;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	bool bRotorHitNative;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	bool bIsRotorWashActiveNative;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	float RotorWashRelativeZOffset;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortHoagieVehicle> Vehicle;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> EngineAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> RotorAudio;

};

