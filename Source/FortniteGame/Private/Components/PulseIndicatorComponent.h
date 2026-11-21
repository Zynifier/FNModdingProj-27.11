// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "PulseIndicatorComponent.generated.h"

class AFortPlayerControllerAthena;
class USoundBase;

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UPulseIndicatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanUseComponentIndicators() const;

	UFUNCTION(BlueprintCallable)
	void SetDisplayTeam(uint8 NewDisplayTeam);

	UFUNCTION(BlueprintCallable)
	void SetIndicatingController(AFortPlayerControllerAthena* Controller);

	UFUNCTION(BlueprintCallable)
	void StartPulseMarkers();

	UFUNCTION(BlueprintCallable)
	void StopPulseMarkers();

protected:
	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	TArray<FIndicatedActorDataWithFilter> IndicatedActorFilters;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FString IndicatorGroupIdentifierOverride;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FString StencilGroupIdentifierOverride;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	TObjectPtr<USoundBase> PlayerPingSound;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FIndicatedActorParticleSystemData PlayerParticleSystemData;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FScalableFloat PulseTime;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FScalableFloat MarkRadius;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FScalableFloat MarkDuration;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FScalableFloat StepTime;

	UPROPERTY(EditDefaultsOnly, Category="PulseIndicatorComponent")
	FString PlayerGroupIdentifier;

	UPROPERTY(BlueprintReadWrite, Category="PulseIndicatorComponent")
	FOnIndicatedActorAdded OnActorAdded;

	UPROPERTY(BlueprintReadWrite, Category="PulseIndicatorComponent")
	FOnIndicatedActorRemoved OnActorRemoved;

	UPROPERTY()
	TObjectPtr<AFortPlayerControllerAthena> IndicatingController;

};

