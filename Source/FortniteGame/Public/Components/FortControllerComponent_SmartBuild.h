// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SmartBuild.generated.h"

class UFortBuildingItemDefinition;
class UFortSmartBuildingItemDefinition;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SmartBuild : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void ServerSetUseSmartBuild(const bool bInUseSmartBuild);

protected:
	UFUNCTION(Client, Reliable)
	void ClientEquipBuildingItems();

	UFUNCTION()
	void OnRep_UseSmartBuild();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_UseSmartBuild)
	bool bUseSmartBuild;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_SmartBuild")
	TArray<TObjectPtr<UFortBuildingItemDefinition>> BuildItemDefinitions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_SmartBuild")
	TArray<TObjectPtr<UFortBuildingItemDefinition>> SmartBuildItemDefinitions;

	UPROPERTY(Transient)
	TObjectPtr<UFortSmartBuildingItemDefinition> LastBuildItem;

	UPROPERTY(Config)
	float TurboFirstInterval;

	UPROPERTY(Config)
	float TurboInterval;

};

