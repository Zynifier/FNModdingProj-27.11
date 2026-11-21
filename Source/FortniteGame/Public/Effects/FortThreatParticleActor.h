// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI/FortThreatVisualsManager.h"
#include "FortInitializationInterface.h"
#include "FortThreatParticleActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortThreatParticleActor : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	TArray<FThreatLocationInfo> GetThreatClouds() const;

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatVisuals")
	void OnThreatCloudsChanged(const TArray<FThreatLocationInfo>& ThreatLocationInfo);

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatVisuals")
	void OnThreatOverrideChanged(bool bForceThreatOn);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWorldReady();

};

