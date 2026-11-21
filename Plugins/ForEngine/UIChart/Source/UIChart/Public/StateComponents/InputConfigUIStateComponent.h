// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputModeTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "StateComponents/StackingUIStateComponent.h"
#include "UIStateComponent.h"
#include "InputConfigUIStateComponent.generated.h"

class UInputConfigUIStateComponentConfiguration;

UCLASS()
class UICHART_API UInputConfigUIStateComponent : public UStackingUIStateComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UInputConfigUIStateComponentConfiguration* Configuration;

};

UCLASS()
class UICHART_API UInputConfigUIStateComponentConfiguration : public UUIStateComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	ECommonInputMode InputMode;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	EMouseCaptureMode MouseCaptureMode;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	bool bHideCursorDuringCapture;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	bool bIgnoreLookInput;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	bool bIgnoreMovementInput;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	bool bFlushPlayerInputWhenActivating;

	UPROPERTY(EditAnywhere, Category="InputConfigUIStateComponentConfiguration")
	bool bFlushPlayerInputWhenDeactivating;

};

