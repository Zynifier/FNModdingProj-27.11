// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortMissionStormShieldManager.generated.h"

class AFortMissionStormShield;
class UFortMissionStormShieldManager;
class UObject;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortMissionStormShieldManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortMissionStormShieldManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="Storm", meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static UFortMissionStormShieldManager* Get(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Storm", meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static AFortMissionStormShield* GetMissionStormShield(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Storm")
	AFortMissionStormShield* GetStormShield() const;

protected:
	UFUNCTION()
	void OnRep_StormShield();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StormShield)
	TObjectPtr<AFortMissionStormShield> StormShield;

};

