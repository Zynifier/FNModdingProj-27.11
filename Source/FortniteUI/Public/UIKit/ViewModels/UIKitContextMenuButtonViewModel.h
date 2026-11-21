// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIKit/ViewModels/UIKitSelectableButtonViewModel.h"
#include "UIKitContextMenuButtonViewModel.generated.h"

UCLASS()
class UUIKitContextMenuButtonViewModel : public UUIKitSelectableButtonViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ExecuteInteraction();

};

