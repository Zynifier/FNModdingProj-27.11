// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaPlayerVitalityBarBase.generated.h"

class UAthenaPlayerViewModel;

UCLASS(Abstract)
class UAthenaPlayerVitalityBarBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaPlayerVitalityBarBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void SetDataSource(UAthenaPlayerViewModel* PlayerViewModel);

private:
	UPROPERTY()
	TObjectPtr<UAthenaPlayerViewModel> PlayerVM;

};

