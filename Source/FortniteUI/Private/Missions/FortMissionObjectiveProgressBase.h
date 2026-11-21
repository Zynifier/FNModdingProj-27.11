// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMissionObjectiveProgressBase.generated.h"

class AFortObjectiveBase;
class UCommonTextBlock;
class UProgressBar;

UCLASS(meta=(DisableNativeTick))
class UFortMissionObjectiveProgressBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	float GetHeightEstimate() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Update(AFortObjectiveBase* Objective, int32 BarIndex);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionObjectiveProgressBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ObjectiveProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionObjectiveProgressBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ProgressBarText;

};

