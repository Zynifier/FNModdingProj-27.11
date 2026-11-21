// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/SpecialActor/FortEventLevelNavigationActor.h"
#include "FortNavigationActor_EventGraphItem.generated.h"

class UAthenaRewardEventGraph;

UCLASS(Abstract, MinimalAPI)
class AFortNavigationActor_EventGraphItem : public AFortEventLevelNavigationActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTag GetNodeTag();

protected:
	UFUNCTION()
	void CosmeticVariantAssets_PostLoad();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplayMeshToOpened();

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	FGameplayTag ParentNavObject;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	FGameplayTagContainer LevelDefinedNodeToRollFor;

	UPROPERTY(Transient)
	FGameplayTag NodeTag;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaRewardEventGraph> RewardGraphToReprisent;

	UPROPERTY(Transient)
	bool bInitializedCalled;

	UPROPERTY(EditInstanceOnly, Category="FortNavigationActor_EventGraphItem")
	bool CanNavigateToWhenClaimed;

};

