// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassRewardChallengesEntry.generated.h"

class UCommonTextBlock;
class UFortLazyImage;
class UProgressBar;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassRewardChallengesEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetChallenge();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ObjectiveDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ObjectivesCompleted;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_ObjectivesCompleted;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_CompletedObjective;

};

