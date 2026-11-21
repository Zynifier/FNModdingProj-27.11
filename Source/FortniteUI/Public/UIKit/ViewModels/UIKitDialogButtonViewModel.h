// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortDialogTypes.h"
#include "UIKitDialogButtonViewModel.generated.h"

class UDataTable;

UCLASS(MinimalAPI, meta=(DisplayName="UI Kit Dialog Button View Model"))
class UUIKitDialogButtonViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitDialogButtonViewModel")
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitDialogButtonViewModel")
	EFortDialogResult ActionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitDialogButtonViewModel")
	TSoftObjectPtr<UDataTable> DataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitDialogButtonViewModel")
	FName InputAction;

};

