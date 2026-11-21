// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "WarEffortMeshActor.generated.h"

class UMeshNetworkComponent;

USTRUCT()
struct FWarEffortFundingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag FundingTag;

	UPROPERTY()
	float FundedPercent;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AWarEffortMeshActor : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMeshNetworkComponent> MeshNetworkComponent;

protected:
	UFUNCTION()
	void OnRep_ActiveFundedItems();

	UFUNCTION()
	void OnRep_ActiveTryBeforeYouBuyItems();

	UFUNCTION()
	void OnRep_CurrentFundingData();

	UPROPERTY(ReplicatedUsing=OnRep_ActiveFundedItems)
	TArray<FGameplayTag> ActiveFundedItems;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveTryBeforeYouBuyItems)
	TArray<FGameplayTag> ActiveTryBeforeYouBuyItems;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentFundingData)
	TArray<FWarEffortFundingData> CurrentFundingData;

};

