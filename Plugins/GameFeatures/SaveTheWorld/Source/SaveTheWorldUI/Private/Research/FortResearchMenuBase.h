// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortResearchMenuBase.generated.h"

class UFortItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResearchMenuBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	bool AreResearchRespecTokensAvailable() const;

	UFUNCTION(BlueprintCallable, Category="ResearchMenu")
	int32 GetClaimableResearchPointEstimate();

	UFUNCTION(BlueprintPure, Category="FortUpgradeScreen")
	int32 GetResearchRespecTokenCount() const;

	UFUNCTION(BlueprintImplementableEvent, Category="ResearchMenu")
	void OnPurchaseResearchLevelCompleted();

	UFUNCTION(BlueprintImplementableEvent, Category="ResearchMenu")
	void OnPurchaseResearchLevelStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeScreen")
	void OnUseResearchRespecTokenComplete();

	UFUNCTION(BlueprintCallable, Category="ResearchMenu")
	void RequestPurchaseResearchLevel(const FString& StatId);

	UFUNCTION(BlueprintCallable, Category="FortUpgradeScreen")
	void UseResearchRespecToken();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUpgradeScreen")
	TObjectPtr<UFortItemDefinition> ResearchRespecToken;

};

