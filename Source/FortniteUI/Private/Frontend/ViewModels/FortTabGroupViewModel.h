// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIKit/ViewModels/UIKitTabGroupViewModel.h"
#include "FortTabGroupViewModel.generated.h"

class UUIKitTabGroupButtonViewModel;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort Tab Group Viewmodel"))
class UFortTabGroupViewModel : public UUIKitTabGroupViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<UUIKitTabGroupButtonViewModel>> UnfilteredTabs;

	UPROPERTY(BlueprintReadWrite, Category="FortTabGroupViewModel")
	bool bShowingGameGroup;

};

