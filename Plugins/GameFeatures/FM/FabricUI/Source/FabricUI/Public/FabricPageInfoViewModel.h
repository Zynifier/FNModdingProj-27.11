// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FabricPageInfoViewModel.generated.h"

UCLASS(BlueprintType, meta=(Category="Fabric UI"))
class UFabricPageInfoViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FabricPageInfoViewModel")
	bool bHasContent;

	UPROPERTY(BlueprintReadWrite, Category="FabricPageInfoViewModel")
	bool bActivePage;

};

