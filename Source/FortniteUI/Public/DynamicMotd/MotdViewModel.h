// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "DynamicMotd/DynamicMotdTypes.h"
#include "MotdViewModel.generated.h"

UCLASS()
class UMotdViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FText FullScreenTitle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FText FullScreenBody;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FText TeaserTitle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FText FullScreenTabTitle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FMotdBackground FullScreenBackground;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	FMotdBackground TeaserBackground;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdViewModel", meta=(AllowPrivateAccess="true"))
	TArray<FMotdButton> Buttons;

};

