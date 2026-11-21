// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FabricInteractableViewModel.generated.h"

UCLASS(BlueprintType, meta=(Category="Fabric UI"))
class UFabricInteractableViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FabricInteractableViewModel")
	FText Label;

	UPROPERTY(BlueprintReadWrite, Category="FabricInteractableViewModel")
	FText Value;

	UPROPERTY(BlueprintReadWrite, Category="FabricInteractableViewModel")
	bool bEnabled;

	UPROPERTY(BlueprintReadWrite, Category="FabricInteractableViewModel")
	bool bVisible;

};

