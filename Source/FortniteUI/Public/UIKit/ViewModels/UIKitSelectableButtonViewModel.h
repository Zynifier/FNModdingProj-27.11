// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitSelectableButtonViewModel.generated.h"

class UTexture2D;

UCLASS(EditInlineNew, CollapseCategories, MinimalAPI, meta=(DisplayName="UI Kit Selectable Button View Model"))
class UUIKitSelectableButtonViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitSelectableButtonViewModel", meta=(AllowPrivateAccess))
	FText Label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitSelectableButtonViewModel", meta=(AllowPrivateAccess))
	TObjectPtr<UTexture2D> Icon;

};

