// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortCTAButtonViewModel.generated.h"

UCLASS(meta=(DisplayName="CTA Button Viewmodel"))
class FORTCOREUI_API UFortCTAButtonViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Category="Button", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category="Button", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText SecondaryText;

};

