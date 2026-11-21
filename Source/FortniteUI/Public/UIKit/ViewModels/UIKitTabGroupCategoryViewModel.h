// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitTabGroupCategoryViewModel.generated.h"

class UUIKitTabGroupButtonViewModel;

UCLASS(EditInlineNew, CollapseCategories, MinimalAPI, meta=(DisplayName="UI Kit Tab Group Category View Model"))
class UUIKitTabGroupCategoryViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="UIKitTabGroupCategoryViewModel", meta=(AllowPrivateAccess))
	TObjectPtr<UUIKitTabGroupButtonViewModel> Category;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="UIKitTabGroupCategoryViewModel", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitTabGroupButtonViewModel>> Tabs;

};

