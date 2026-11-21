// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UIKitDialogViewModel.generated.h"

class USoundBase;
class UTexture2D;
class UUIKitDialogButtonViewModel;
enum class EFortDialogResult : uint8;

UCLASS(EditInlineNew, MinimalAPI, meta=(DisplayName="UI Kit Dialog View Model"))
class UUIKitDialogViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SendResult(EFortDialogResult Result, FName ResultName);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitDialogViewModel")
	FText DialogTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitDialogViewModel", meta=(MultiLine="true"))
	FText DialogInfoText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitDialogViewModel")
	TObjectPtr<UTexture2D> DialogImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="UIKitDialogViewModel")
	TArray<TObjectPtr<UUIKitDialogButtonViewModel>> Buttons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitDialogViewModel")
	float DisplayTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIKitDialogViewModel")
	TObjectPtr<USoundBase> ShowSound;

};

