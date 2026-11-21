// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UIStateSettings.generated.h"

UENUM()
enum class EWidgetStateComponentUnloadDefaultBehavior : int32
{
	WaitForAnimations = 0,
	DoNotWaitForAnimations = 1,
};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="UI State Machine Settings"))
class UICHART_API UUIStateSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="UIStateSettings")
	float StateLoadTimeout;

	UPROPERTY(EditAnywhere, Config, Category="UIStateSettings")
	float StateUnloadTimeout;

	UPROPERTY(EditAnywhere, Config, Category="UIStateSettings")
	float WidgetStateComponentLoadTimeout;

	UPROPERTY(EditAnywhere, Config, Category="UIStateSettings")
	float WidgetStateComponentUnloadTimeout;

	UPROPERTY(EditAnywhere, Config, Category="UIStateSettings")
	EWidgetStateComponentUnloadDefaultBehavior WidgetStateComponentDefaultUnloadBehavior;

};

