// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitContextMenuViewModel.generated.h"

class UUIKitSelectableButtonViewModel;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="UIKit Context Menu Viewmodel"))
class UUIKitContextMenuViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitContextMenuViewModel", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitSelectableButtonViewModel>> Buttons;

};

