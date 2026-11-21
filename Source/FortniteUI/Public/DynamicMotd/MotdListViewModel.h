// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MotdListViewModel.generated.h"

class UMotdViewModel;

UCLASS()
class UMotdListViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdListViewModel", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UMotdViewModel>> Motds;

};

