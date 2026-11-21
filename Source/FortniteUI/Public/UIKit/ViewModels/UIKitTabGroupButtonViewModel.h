// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIKit/ViewModels/UIKitSelectableButtonViewModel.h"
#include "UIKitTabGroupButtonViewModel.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="UI Kit Tab Group Button View Model"))
class UUIKitTabGroupButtonViewModel : public UUIKitSelectableButtonViewModel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitTabGroupButtonViewModel", meta=(AllowPrivateAccess, InlineEditConditionToggle))
	bool bEnableTabID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitTabGroupButtonViewModel", meta=(AllowPrivateAccess, EditCondition="bEnableTabID"))
	FName TabID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitTabGroupButtonViewModel", meta=(AllowPrivateAccess, InlineEditConditionToggle))
	bool bEnableSubGroupID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitTabGroupButtonViewModel", meta=(AllowPrivateAccess, EditCondition="bEnableSubGroupID"))
	FName SubGroupID;

};

