// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaFPSBase.generated.h"

class UCommonTextBlock;

UCLASS()
class UAthenaFPSBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleShowFPSChanged(bool bInShowFPS);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> FPS;

};

