// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitTabGroupViewModel.generated.h"

class UUIKitTabGroupButtonViewModel;

UCLASS(MinimalAPI, meta=(DisplayName="UI Kit Tab Group View Model"))
class UUIKitTabGroupViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitTabGroupViewModel", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitTabGroupButtonViewModel>> Tabs;

};

