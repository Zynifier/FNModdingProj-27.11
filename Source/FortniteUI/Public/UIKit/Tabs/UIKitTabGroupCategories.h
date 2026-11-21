// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "UIKitTabGroupCategories.generated.h"

class UUIKitTabGroupCategoryViewModel;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UUIKitTabGroupCategories : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="UIKit|Tab Categories", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitTabGroupCategoryViewModel>> LocalCategoriesViewModels;

};

