// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerData.h"
#include "FortAthenaAIBotSpawnerData.generated.h"

class UFortAthenaAISpawnerDataComponent_ConstructionBase;
class UFortAthenaAISpawnerDataComponent_CoverBase;
class UFortAthenaAISpawnerDataComponent_PerksBase;
class UFortAthenaAISpawnerDataComponent_SkillsetBase;
class UFortAthenaAISpawnerDataComponent_VehicleBase;

UCLASS(MinimalAPI)
class UFortAthenaAIBotSpawnerData : public UFortAthenaAISpawnerData
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_ConstructionBase* GetConstructionComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_CoverBase* GetCoverComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_PerksBase* GetPerksComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_SkillsetBase* GetSkillSetComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_VehicleBase* GetVehicleComponent() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="AI Bot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_SkillsetBase> SkillSetComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_ConstructionBase> ConstructionComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_VehicleBase> VehicleComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_CoverBase> CoverComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_PerksBase> PerksComponent;

};

