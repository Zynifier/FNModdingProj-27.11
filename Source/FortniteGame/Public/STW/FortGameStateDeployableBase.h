// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/FortGameStatePvE.h"
#include "FortGameStateDeployableBase.generated.h"

class AFortDeployableBaseManager;
class UFortQuestItemDefinition;
enum class EDeployableBaseUseType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeployableBaseManagerCreated);

USTRUCT(BlueprintType)
struct FHordeDifficultyTierInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HordeDifficultyTierInfo")
	FName DifficultyTierName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HordeDifficultyTierInfo")
	TObjectPtr<UFortQuestItemDefinition> QuestPrerequisite;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateDeployableBase : public AFortGameStatePvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DeployableBase")
	EDeployableBaseUseType GetDeployableBaseUseType() const;

	UFUNCTION(BlueprintPure, Category="DeployableBase")
	float GetStormShieldBreatherRadiusOverride() const;

	UFUNCTION(BlueprintPure, Category="DeployableBase")
	float GetStormShieldEndingRadiusOverride() const;

	UFUNCTION(BlueprintPure, Category="DeployableBase")
	float GetStormShieldStartingRadiusOverride() const;

	UFUNCTION(BlueprintPure, Category="DeployableBase")
	bool ShouldRespawnAtLastPawnLocation() const;

	UFUNCTION(BlueprintPure, Category="DeployableBase")
	bool ShouldUseStormShield() const;

protected:
	UFUNCTION()
	virtual void OnRep_DeployableBaseManager();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DeployableBaseManager)
	TObjectPtr<AFortDeployableBaseManager> DeployableBaseManager;

	UPROPERTY(BlueprintAssignable)
	FOnDeployableBaseManagerCreated OnDeployableBaseManagerCreated;

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	bool bFireEndOfDayDelegate;

private:
	UPROPERTY(EditDefaultsOnly, Category="Tier Config")
	TArray<FHordeDifficultyTierInfo> TierDifficultyConfig;

	UPROPERTY(EditDefaultsOnly, Category="Tier Config")
	TArray<FHordeDifficultyTierInfo> PrestigeTierDifficultyConfig;

};

