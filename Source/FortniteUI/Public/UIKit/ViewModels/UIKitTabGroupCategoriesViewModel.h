// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitTabGroupCategoriesViewModel.generated.h"

class UUIKitTabGroupCategoryViewModel;

UCLASS(MinimalAPI, meta=(DisplayName="UI Kit Tab Group Categories View Model"))
class UUIKitTabGroupCategoriesViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitTabGroupCategoriesViewModel", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitTabGroupCategoryViewModel>> Categories;

};

